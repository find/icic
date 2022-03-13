#include "wx/wx.h"
#include "form/calcui.h"

#include "lua.h"
#include "lualib.h"
#include "exprtk.hpp"

using Real = double;

class RealMainFrame: public MainFrame
{
  using parser_t = exprtk::parser<Real>;
  using symtable_t = exprtk::symbol_table<Real>;
  using expr_t = exprtk::expression<Real>;

  bool m_DrawerShown = true;
  symtable_t m_Symbols;
  std::string m_ResultString;

public:
  RealMainFrame(): MainFrame(nullptr) {
    m_Symbols.add_constants();
    toggleHistory();
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
  }

  void m_NewWindowOnMenuSelection(wxCommandEvent& evt) override {
    (new RealMainFrame())->Show(true);
  }
  void m_CloseWindowOnMenuSelection(wxCommandEvent& evt) override {
    this->Close();
  }

  void m_ExecuteButtonOnButtonClick(wxCommandEvent& evt) override {
    evalExpr();
  }
  void m_ExprInputOnTextEnter( wxCommandEvent& evt) override {
    evalExpr();
  }
  void evalExpr() {
    auto wxexprstr = m_ExprInput->GetValue();
    auto exprstr = wxexprstr.ToStdString();
    if (exprstr=="")
      return;

    expr_t expr;
    expr.register_symbol_table(m_Symbols);
    parser_t parser;
    parser.compile(exprstr, expr);
    auto res = std::to_string(expr.value());
    if (!m_ResultString.empty())
      m_ResultString = "-------------------------------\n" + m_ResultString; 
    m_ResultString = exprstr + " = " + res + "\n" + m_ResultString;
    m_Result->SetValue(m_ResultString);
    m_HistoryList->InsertItems(1, &wxexprstr, 0);
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

