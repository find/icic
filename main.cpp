#include "wx/wx.h"
#include "form/qjscalc_ui.h"

class RealMainFrame: public MainFrame
{
  bool m_DrawerShown = true;
  wxDECLARE_EVENT_TABLE();

public:
  RealMainFrame(): MainFrame(nullptr) {}
  void OnToggleDrawer(wxCommandEvent& evt) {
    m_DrawerShown = !m_DrawerShown;
    m_InputLineLayout->Show(m_DrawerLayout, m_DrawerShown);
    m_InputLineLayout->Layout();
    if (m_DrawerShown)
      m_ToggleDrawer->SetLabel(wxT(">"));
    else
      m_ToggleDrawer->SetLabel(wxT("<"));
  }
};

wxBEGIN_EVENT_TABLE(RealMainFrame, wxFrame)
    EVT_BUTTON(ID_ToggleDrawer, RealMainFrame::OnToggleDrawer)
wxEND_EVENT_TABLE()

class QJSCalcApp : public wxApp
{
public:
  bool OnInit() override
  {
    if (!wxApp::OnInit())
      return false;
    auto *Frame = new RealMainFrame();
    wxCommandEvent evt;
    Frame->OnToggleDrawer(evt);
    Frame->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(QJSCalcApp);

