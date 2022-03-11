///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/tglbtn.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define ID_ToggleDrawer 1000

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxBoxSizer* m_InputLineLayout;
		wxTextCtrl* m_ExprInput;
		wxButton* m_ExecuteButton;
		wxButton* m_ClearResult;
		wxButton* m_ToggleDrawer;
		wxBoxSizer* m_DrawerLayout;
		wxToggleButton* m_ToggleTop;
		wxButton* m_About;
		wxTextCtrl* m_Result;

	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Caculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 622,301 ), long style = wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxTAB_TRAVERSAL, const wxString& name = wxT("Calculator") );

		~MainFrame();

};

