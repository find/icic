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
#include <wx/stattext.h>
#include <wx/choice.h>
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
		wxStaticText* m_staticText1;
		wxChoice* m_EvaluatorChoice;
		wxButton* m_About;
		wxTextCtrl* m_Result;

		// Virtual event handlers, override them in your derived class
		virtual void m_ExecuteButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_ClearResultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_ToggleDrawerOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
        virtual void m_ExprInputOnTextEnter( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Caculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 622,301 ), long style = wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxTAB_TRAVERSAL, const wxString& name = wxT("Calculator") );

		~MainFrame();

};

