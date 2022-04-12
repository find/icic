#include "wx/wx.h"
#include "form/ui.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "quickjs.h"

// defined in qjscalc.c
const char*  qjscalc_src();
const size_t qjscalc_src_len();
}

#include <stdio.h>
#include <stdlib.h>
#include <fstream>



using Real = double;

static void* _myLuaAlloc(void*, void* ptr, size_t osize, size_t nsize)
{
  return realloc(ptr, nsize);
}

class RealMainFrame: public MainFrame
{
  enum class EvaluationEngine {
    QuickJS,
    Lua
  };

  bool             m_DrawerShown = true;
  std::string      m_ResultString;
  wxString         m_PreviousExpr = "";
  EvaluationEngine m_Engine = EvaluationEngine::Lua;
  lua_State*       L = nullptr;
  JSRuntime*       rt = nullptr;
  JSContext*       ctx = nullptr;
  std::string      jserr = "";

public:
  RealMainFrame(): MainFrame(nullptr) {
    toggleHistory();
    initLua();
    initQJS();
#ifdef __WXMSW__
    SetIcon(wxIcon(wxT("Icon")));
#endif
  }
  ~RealMainFrame() {
    lua_close(L);
    if (ctx)
      JS_FreeContext(ctx);
    if (rt)
      JS_FreeRuntime(rt);
  }
  void initLua() {
    if (L)
      lua_close(L);
    L = lua_newstate(_myLuaAlloc, nullptr);
    luaL_openlibs(L);
    luaL_dostring(L, R"(
for i,v in pairs(math) do _G[i]=v end
__printbuf = ''
print = function(...)
  local n=select('#',...)
  for i=1,n do
    __printbuf = __printbuf .. tostring(select(i,...)) .. (i<n and '\t' or '\n')
  end
end)");
  }
  static JSContext* newJSContext(JSRuntime* rt) {
    JSContext* ctx = JS_NewContext(rt);
    JS_AddIntrinsicBigFloat(ctx);
    JS_AddIntrinsicBigDecimal(ctx);
    JS_AddIntrinsicOperators(ctx);
    JS_EnableBignumExt(ctx, true);
    return ctx;
  }
  void js_std_eval_binary(JSContext *ctx, const uint8_t *buf, size_t buf_len) {
    JSValue obj, val;
    obj = JS_ReadObject(ctx, buf, buf_len, JS_READ_OBJ_BYTECODE);
    if (JS_IsException(obj))
      goto exception;
    val = JS_EvalFunction(ctx, obj);
    if (JS_IsException(val)) {
      goto exception;
    }
    JS_FreeValue(ctx, val);
    return;
exception:
    //js_std_dump_error(ctx);
    JSValue e = JS_GetException(ctx);
    char const* msg = JS_ToCString(ctx, e);
    jserr = msg;
    JS_FreeCString(ctx, msg);
    JS_FreeValue(ctx, e);
  }
  void initQJS() {
    if (rt && ctx) {
      JS_FreeContext(ctx);
      JS_FreeRuntime(rt);
    }
    rt = JS_NewRuntime();
    //js_std_set_worker_new_context_func(newJSContext);
    //js_std_init_handlers(rt);
    ctx = newJSContext(rt);
    //JS_SetModuleLoaderFunc(rt, nullptr, js_modeule_loader, nullptr);
    //js_std_eval_binary(ctx, qjsc_qjscalc, qjsc_qjscalc_size);
    if (qjscalc_src_len()>0)
      evalQuickJSRaw(std::string(qjscalc_src(), qjscalc_src()+qjscalc_src_len()), "qjscalc");
  }

  void toggleHistory() {
    m_DrawerShown = !m_DrawerShown;
    m_ResultSizer->Show(m_HistoryList, m_DrawerShown);
    m_ToggleHistory->SetLabel(m_DrawerShown?">":"<");
    m_ResultSizer->Layout();
  }
  void m_ToggleHistoryOnButtonClick(wxCommandEvent& evt) override {
    toggleHistory();
  }
  void m_MenuToggleHistoryOnMenuSelection(wxCommandEvent& evt) override {
    toggleHistory();
  }

  void m_EngineLuaOnMenuSelection(wxCommandEvent& evt) override {
    m_Engine = EvaluationEngine::Lua;
  }
  void m_EngineQuickJSOnMenuSelection(wxCommandEvent& evt) override {
    m_Engine = EvaluationEngine::QuickJS;
  }

  void m_ClearResultOnButtonClick(wxCommandEvent& evt) override {
    clearResult();
  }
  void m_ClearOnMenuSelection(wxCommandEvent& evt) override {
    clearResult();
  }
  void clearResult() {
    m_ExprInput->SetValue(wxT(""));
    m_Result->SetValue(wxT(""));
    m_ResultString = "";
  }

  void m_ResultOnChar(wxKeyEvent& evt) override {
    if (evt.GetModifiers()==0) {
      m_ExprInput->SetFocus();
      //m_ExprInput->OnChar(evt); // TODO
    } else {
      m_Result->OnChar(evt);
    }
  }

  void m_HistoryListOnListBoxDClick(wxCommandEvent& evt) override {
    auto sel = m_HistoryList->GetSelection();
    if (sel != wxNOT_FOUND) {
      m_ExprInput->SetValue(m_HistoryList->GetString(sel));
    }
  }
  void m_ClearHistoryOnMenuSelection(wxCommandEvent& evt) override {
    m_HistoryList->Clear();
    initLua();
    initQJS();
  }

  void m_NewWindowOnMenuSelection(wxCommandEvent& evt) override {
    (new RealMainFrame())->Show(true);
  }
  void m_CloseWindowOnMenuSelection(wxCommandEvent& evt) override {
    this->Close();
  }
  void m_AboutOnMenuSelection(wxCommandEvent& evt) override {
    (new AboutDialog(this))->Show(true);
  }
  void m_StayOnTopOnMenuSelection(wxCommandEvent& evt) override {
    bool stayOnTop = m_StayOnTop->IsChecked();
    auto style = GetWindowStyle();
    if (stayOnTop)
      style |= wxSTAY_ON_TOP;
    else
      style &= ~wxSTAY_ON_TOP;
    SetWindowStyle(style);
  }

  void m_ExecuteButtonOnButtonClick(wxCommandEvent& evt) override {
    evalExpr();
  }
  void m_MenuEvalOnMenuSelection(wxCommandEvent& evt) override {
    evalExpr();
  }
  void evalExpr() {
    auto wxexprstr = m_ExprInput->GetValue();
    auto exprstr = wxexprstr.ToStdString();
    if (exprstr=="")
      return;

    std::string res;
    if (m_Engine == EvaluationEngine::QuickJS)
      res = evalQuickJS(exprstr);
    else
      res = evalLua(exprstr);

    if (!m_ResultString.empty())
      m_ResultString = "----------------------------------------\n" + m_ResultString; 
    m_ResultString = res + "\n" + m_ResultString;
    m_Result->SetValue(m_ResultString);
    if (wxexprstr != m_PreviousExpr)
      m_HistoryList->InsertItems(1, &wxexprstr, 0);
    m_PreviousExpr = std::move(wxexprstr);
    m_ExprInput->SetFocus();
    m_ExprInput->SelectAll();
  }
  std::string evalQuickJSRaw(std::string const& input, std::string const& file="<input>") {
    if (!jserr.empty())
      return jserr;
    JSValue val = JS_Eval(ctx, input.c_str(), input.size(), file.c_str(), 0);
    if (JS_IsException(val)) {
      val = JS_GetException(ctx);
    }
    const char* jstr;
    jstr = JS_ToCString(ctx, val);
    std::string str = jstr;
    JS_FreeValue(ctx, val);
    JS_FreeCString(ctx, jstr);
    return str;
  }

  std::string evalQuickJS(std::string const& input) {
    auto str = evalQuickJSRaw("\"use math\"; void 0; " + input);

    static const std::string iprompt1 = "qjs> ";
    static const std::string iprompt2 = "------ js code ------\n";
    static const std::string oprompt1 = "\n";
    static const std::string oprompt2 = "\n------ returns ------ \n";
    bool input_singleline = input.find('\n')==std::string::npos;
    return (input_singleline?iprompt1:iprompt2) + input +
           ((input_singleline&&str.find('\n')==std::string::npos)?oprompt1:oprompt2) + str;
  }
  std::string evalLua(std::string const& input)
  {
    std::string out;
    //luaL_dostring(L, input.c_str());
    std::string addReturn = "return " + input;
    auto status = luaL_loadbuffer(L, addReturn.c_str(), addReturn.size(), "=input");
    if (status == LUA_ERRSYNTAX) {
      lua_pop(L, 1);
      status = luaL_loadbuffer(L, input.c_str(), input.size(), "=input");
    }
    if (status == LUA_OK) {
      lua_pushglobaltable(L);
      lua_pushliteral(L, "");
      lua_setfield(L, -2, "__printbuf");
      lua_pop(L,1);
      status = lua_pcall(L, 0, LUA_MULTRET, 0);
    }
    if (status != LUA_OK)
      out += "ERROR\n";
    size_t printed_len = 0;
    char const*  printed_txt = nullptr;
    lua_pushglobaltable(L);
    lua_getfield(L, -1, "__printbuf");
    printed_txt = lua_tolstring(L, -1, &printed_len);
    lua_pop(L, 2);
    if (int n=lua_gettop(L)) {
      for (int i=1; i<=n; ++i) {
        if (i>1)
          out+="\t";
        size_t slen = 0;
        char const* s = luaL_tolstring(L, i, &slen);
        out+=std::string(s, s+slen);
        lua_pop(L, 1);
      }
      lua_pop(L, n);
    } else {
      out += "nil";
    }
    static const std::string iprompt1 = "lua> ";
    static const std::string iprompt2 = "------ lua code ------\n";
    static const std::string oprompt1 = "\n";
    static const std::string oprompt2 = "\n------ returns ------ \n";
    bool input_singleline = input.find('\n')==std::string::npos;
    std::string prt = "";
    if (printed_len>0)
      prt = "\n------ prints ------\n" + std::string(printed_txt, printed_txt+printed_len); 
    return (input_singleline?iprompt1:iprompt2) + input +
           ((input_singleline&&out.find('\n')==std::string::npos)?oprompt1:oprompt2) + out +
           prt;
  }
};

class CalcApp : public wxApp
{
public:
  bool OnInit() override
  {
    if (!wxApp::OnInit())
      return false;
    auto *Frame = new RealMainFrame();
    Frame->Show(true);
    return true;
  }
};

#ifdef DEBUG
wxIMPLEMENT_APP_CONSOLE(CalcApp);
#else
wxIMPLEMENT_APP(CalcApp);
#endif

