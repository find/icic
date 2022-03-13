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
  }
  void m_ToggleDrawerOnButtonClick(wxCommandEvent& evt) override {
    m_DrawerShown = !m_DrawerShown;
    m_InputLineLayout->Show(m_DrawerLayout, m_DrawerShown);
    m_InputLineLayout->Layout();
    if (m_DrawerShown)
      m_ToggleDrawer->SetLabel(wxT(">"));
    else
      m_ToggleDrawer->SetLabel(wxT("<"));
  }
  void m_ClearResultOnButtonClick(wxCommandEvent& evt) {
    m_ExprInput->SetValue(wxT(""));
    m_Result->SetValue(wxT(""));
    m_ResultString = "";
  }
  void m_ExecuteButtonOnButtonClick(wxCommandEvent& evt) override {
    evalExpr();
  }
  void m_ExprInputOnTextEnter( wxCommandEvent& evt) override {
    evalExpr();
  }

  void evalExpr() {
    auto exprstr = m_ExprInput->GetValue().ToStdString();
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
    wxCommandEvent evt;
    Frame->m_ToggleDrawerOnButtonClick(evt);
    Frame->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(CalcApp);

