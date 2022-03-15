#include "wx/wx.h"
#include "form/ui.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "exprtk.hpp"

#include <stdio.h>
#include <stdlib.h>

using Real = double;

static void* _myLuaAlloc(void*, void* ptr, size_t osize, size_t nsize)
{
  return realloc(ptr, nsize);
}

class RealMainFrame: public MainFrame
{
  using parser_t = exprtk::parser<Real>;
  using symtable_t = exprtk::symbol_table<Real>;
  using expr_t = exprtk::expression<Real>;

  enum class EvaluationEngine {
    Exprtk,
    Lua
  };

  bool             m_DrawerShown = true;
  symtable_t       m_Symbols;
  std::string      m_ResultString;
  wxString         m_PreviousExpr = "";
  EvaluationEngine m_Engine = EvaluationEngine::Exprtk;
  lua_State*       L = nullptr;

public:
  RealMainFrame(): MainFrame(nullptr) {
    m_Symbols.add_constants();
    toggleHistory();
    initLua();
  }
  ~RealMainFrame() {
    lua_close(L);
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
  void m_EngineExprtkOnMenuSelection(wxCommandEvent& evt) override {
    m_Engine = EvaluationEngine::Exprtk;
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

  void m_HistoryListOnListBoxDClick(wxCommandEvent& evt) override {
    auto sel = m_HistoryList->GetSelection();
    if (sel != wxNOT_FOUND) {
      m_ExprInput->SetValue(m_HistoryList->GetString(sel));
    }
  }
  void m_ClearHistoryOnMenuSelection(wxCommandEvent& evt) override {
    m_HistoryList->Clear();
    initLua();
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
    if (m_Engine == EvaluationEngine::Exprtk)
      res = evalExprtk(exprstr);
    else
      res = evalLua(exprstr);

    if (!m_ResultString.empty())
      m_ResultString = "----------------------------------------\n" + m_ResultString; 
    m_ResultString = res + "\n" + m_ResultString;
    m_Result->SetValue(m_ResultString);
    if (wxexprstr != m_PreviousExpr)
      m_HistoryList->InsertItems(1, &wxexprstr, 0);
    m_PreviousExpr = std::move(wxexprstr);
  }
  std::string evalExprtk(std::string const& input)
  {
    expr_t expr;
    expr.register_symbol_table(m_Symbols);
    parser_t parser;
    parser.compile(input, expr);
    return input + " = " + std::to_string(expr.value());
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
    lua_pop(L, 1);
    for (int i=1, n=lua_gettop(L); i<=n; ++i) {
      size_t slen = 0;
      char const* s = lua_tolstring(L, i, &slen);
      if (i>1)
        out+="\t";
      out+=std::string(s, s+slen);
    }
    lua_pop(L, lua_gettop(L));
    static const std::string iprompt1 = "lua> ";
    static const std::string iprompt2 = "------ lua code ------\n";
    static const std::string oprompt1 = "\n---> ";
    static const std::string oprompt2 = "\n------ returns ------ \n";
    std::string prt = "";
    if (printed_len>0)
      prt = "\n------ prints ------\n" + std::string(printed_txt, printed_txt+printed_len); 
    return (input.find('\n')==std::string::npos?iprompt1:iprompt2) + input +
           prt +
           (  out.find('\n')==std::string::npos?oprompt1:oprompt2) + out;
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

wxIMPLEMENT_APP(CalcApp);

