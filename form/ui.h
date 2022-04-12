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
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxFlexGridSizer* m_MainLayout;
		wxBoxSizer* m_InputLineLayout;
		wxTextCtrl* m_ExprInput;
		wxButton* m_ExecuteButton;
		wxButton* m_ClearResult;
		wxBoxSizer* m_ResultSizer;
		wxTextCtrl* m_Result;
		wxButton* m_ToggleHistory;
		wxListBox* m_HistoryList;
		wxMenuBar* m_MainMenuBar;
		wxMenu* m_Window;
		wxMenuItem* m_StayOnTop;
		wxMenu* m_EditMenu;
		wxMenu* m_EvalEngine;
		wxMenuItem* m_EngineLua;
		wxMenuItem* m_EngineQuickJS;
		wxMenu* m_HelpMenu;

		// Virtual event handlers, override them in your derived class
		virtual void m_ExecuteButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_ClearResultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_ResultOnChar( wxKeyEvent& event ) { event.Skip(); }
		virtual void m_ToggleHistoryOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_HistoryListOnListBoxDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_StayOnTopOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_MenuToggleHistoryOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_NewWindowOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_CloseWindowOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_EngineLuaOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_EngineQuickJSOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_MenuEvalOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_ClearOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_ClearHistoryOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_AboutOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Caculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 622,301 ), long style = wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxTAB_TRAVERSAL, const wxString& name = wxT("Calculator") );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDialog
///////////////////////////////////////////////////////////////////////////////
class AboutDialog : public wxDialog
{
	private:

	protected:

	public:

		AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 354,191 ), long style = wxDEFAULT_DIALOG_STYLE );

		~AboutDialog();

};

