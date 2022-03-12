#include "wx/wx.h"
#include "form/calcui.h"

#include "lua.h"
#include "lualib.h"

class RealMainFrame: public MainFrame
{
  bool m_DrawerShown = true;

public:
  RealMainFrame(): MainFrame(nullptr) {}
  void m_ToggleDrawerOnButtonClick(wxCommandEvent& evt) override {
    m_DrawerShown = !m_DrawerShown;
    m_InputLineLayout->Show(m_DrawerLayout, m_DrawerShown);
    m_InputLineLayout->Layout();
    if (m_DrawerShown)
      m_ToggleDrawer->SetLabel(wxT(">"));
    else
      m_ToggleDrawer->SetLabel(wxT("<"));
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

