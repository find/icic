#include "wx/wx.h"
#include "form/ui.h"

#include <stdlib.h>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "quickjs.h"

// defined in qjscalc.c
const char*  qjscalc_src();
const size_t qjscalc_src_len();
}

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
  EvaluationEngine m_Engine = EvaluationEngine::QuickJS;
  lua_State*       m_Lua = nullptr;
  JSRuntime*       m_JsRuntime = nullptr;
  JSContext*       m_JsContext = nullptr;
  std::string      m_JsError = "";

public:
  RealMainFrame(): MainFrame(nullptr) {
    m_ToggleHistory->MoveAfterInTabOrder(m_ClearResult);
    toggleHistory();
    initLua();
    initQJS();
#ifdef __WXMSW__
    SetIcon(wxIcon(wxT("Icon")));
#endif
  }
  ~RealMainFrame() {
    lua_close(m_Lua);
    if (m_JsContext)
      JS_FreeContext(m_JsContext);
    if (m_JsRuntime)
      JS_FreeRuntime(m_JsRuntime);
  }
  void initLua() {
    if (m_Lua)
      lua_close(m_Lua);
    m_Lua = lua_newstate(_myLuaAlloc, nullptr);
    luaL_openlibs(m_Lua);
    luaL_dostring(m_Lua, R"(
for i,v in pairs(math) do _G[i]=v end
__printbuf = ''
print = function(...)
  local n=select('#',...)
  for i=1,n do
    __printbuf = __printbuf .. tostring(select(i,...)) .. (i<n and '\t' or '\n')
  end
end)");
  }
  static JSContext* newJSContext(JSRuntime* m_JsRuntime) {
    JSContext* ctx = JS_NewContext(m_JsRuntime);
    JS_AddIntrinsicBigFloat(ctx);
    JS_AddIntrinsicBigDecimal(ctx);
    JS_AddIntrinsicOperators(ctx);
    JS_EnableBignumExt(ctx, true);
    return ctx;
  }
  void initQJS() {
    if (m_JsRuntime && m_JsContext) {
      JS_FreeContext(m_JsContext);
      JS_FreeRuntime(m_JsRuntime);
    }
    m_JsRuntime = JS_NewRuntime();
    //js_std_set_worker_new_context_func(newJSContext);
    //js_std_init_handlers(m_JsRuntime);
    m_JsContext = newJSContext(m_JsRuntime);
    //JS_SetModuleLoaderFunc(m_JsRuntime, nullptr, js_modeule_loader, nullptr);
    if (qjscalc_src_len()>0)
      evalQuickJSRaw(std::string(qjscalc_src(), qjscalc_src()+qjscalc_src_len()), "qjscalc");
  }

  void toggleHistory() {
    m_DrawerShown = !m_DrawerShown;
    m_HistorySizer->Show(m_HistoryList, m_DrawerShown);
    m_HistorySizer->Layout();
    m_InputPanelLayout->Layout();
    m_ExprInput->SetFocus();
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
    if (!m_JsError.empty())
      return m_JsError;
    JSValue val = JS_Eval(m_JsContext, input.c_str(), input.size(), file.c_str(), 0);
    if (JS_IsException(val)) {
      val = JS_GetException(m_JsContext);
    }
    std::string str = "";
    if (const char* jstr = JS_ToCString(m_JsContext, val)) {
      str = jstr;
      JS_FreeCString(m_JsContext, jstr);
    }
    JS_FreeValue(m_JsContext, val);
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
    //luaL_dostring(m_Lua, input.c_str());
    std::string addReturn = "return " + input;
    auto status = luaL_loadbuffer(m_Lua, addReturn.c_str(), addReturn.size(), "=input");
    if (status == LUA_ERRSYNTAX) {
      lua_pop(m_Lua, 1);
      status = luaL_loadbuffer(m_Lua, input.c_str(), input.size(), "=input");
    }
    if (status == LUA_OK) {
      lua_pushglobaltable(m_Lua);
      lua_pushliteral(m_Lua, "");
      lua_setfield(m_Lua, -2, "__printbuf");
      lua_pop(m_Lua,1);
      status = lua_pcall(m_Lua, 0, LUA_MULTRET, 0);
    }
    if (status != LUA_OK)
      out += "ERROR\n";
    size_t printed_len = 0;
    char const*  printed_txt = nullptr;
    lua_pushglobaltable(m_Lua);
    lua_getfield(m_Lua, -1, "__printbuf");
    printed_txt = lua_tolstring(m_Lua, -1, &printed_len);
    lua_pop(m_Lua, 2);
    if (int n=lua_gettop(m_Lua)) {
      for (int i=1; i<=n; ++i) {
        if (i>1)
          out+="\t";
        size_t slen = 0;
        char const* s = luaL_tolstring(m_Lua, i, &slen);
        out+=std::string(s, s+slen);
        lua_pop(m_Lua, 1);
      }
      lua_pop(m_Lua, n);
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

