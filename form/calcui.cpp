///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "calcui.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxSize( 400,200 ), wxDefaultSize );

	m_MainLayout = new wxFlexGridSizer( 3, 1, 0, 0 );
	m_MainLayout->AddGrowableRow( 1 );
	m_MainLayout->SetFlexibleDirection( wxBOTH );
	m_MainLayout->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_InputLineLayout = new wxBoxSizer( wxHORIZONTAL );

	m_ExprInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,100 ), wxTE_MULTILINE|wxTE_PROCESS_ENTER );
	m_InputLineLayout->Add( m_ExprInput, 20, wxALL|wxEXPAND, 0 );

	m_ExecuteButton = new wxButton( this, wxID_ANY, wxT("="), wxDefaultPosition, wxSize( 40,-1 ), 0 );

	m_ExecuteButton->SetDefault();
	m_InputLineLayout->Add( m_ExecuteButton, 1, wxALL|wxEXPAND, 1 );

	m_ClearResult = new wxButton( this, wxID_ANY, wxT("&Clear"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	m_InputLineLayout->Add( m_ClearResult, 1, wxALL|wxEXPAND, 1 );


	m_MainLayout->Add( m_InputLineLayout, 1, wxEXPAND, 0 );

	m_ResultSizer = new wxBoxSizer( wxHORIZONTAL );

	m_Result = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_ResultSizer->Add( m_Result, 3, wxALL|wxEXPAND, 0 );

	m_ToggleHistory = new wxButton( this, wxID_ANY, wxT(">"), wxDefaultPosition, wxSize( 16,-1 ), 0 );
	m_ToggleHistory->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_ToggleHistory->SetToolTip( wxT("Toggle History Window") );

	m_ResultSizer->Add( m_ToggleHistory, 0, wxALL|wxEXPAND, 0 );

	m_HistoryList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB );
	m_ResultSizer->Add( m_HistoryList, 4, wxALL|wxEXPAND, 0 );


	m_MainLayout->Add( m_ResultSizer, 1, wxEXPAND, 0 );


	this->SetSizer( m_MainLayout );
	this->Layout();
	m_MainMenuBar = new wxMenuBar( wxMB_DOCKABLE );
	m_Window = new wxMenu();
	m_StayOnTop = new wxMenuItem( m_Window, wxID_ANY, wxString( wxT("Stay On &Top") ) + wxT('\t') + wxT("CTRL+T"), wxEmptyString, wxITEM_CHECK );
	m_Window->Append( m_StayOnTop );

	wxMenuItem* m_NewWindow;
	m_NewWindow = new wxMenuItem( m_Window, wxID_ANY, wxString( wxT("&New Window") ) + wxT('\t') + wxT("CTRL+N"), wxEmptyString, wxITEM_NORMAL );
	m_Window->Append( m_NewWindow );

	wxMenuItem* m_CloseWindow;
	m_CloseWindow = new wxMenuItem( m_Window, wxID_ANY, wxString( wxT("Close Window") ) + wxT('\t') + wxT("CTRL+Q"), wxEmptyString, wxITEM_NORMAL );
	m_Window->Append( m_CloseWindow );

	m_MainMenuBar->Append( m_Window, wxT("&Window") );

	m_EditMenu = new wxMenu();
	wxMenuItem* m_Clear;
	m_Clear = new wxMenuItem( m_EditMenu, wxID_ANY, wxString( wxT("&Clear") ) + wxT('\t') + wxT("CTRL-L"), wxEmptyString, wxITEM_NORMAL );
	m_EditMenu->Append( m_Clear );

	wxMenuItem* m_ClearHistory;
	m_ClearHistory = new wxMenuItem( m_EditMenu, wxID_ANY, wxString( wxT("Clear &History") ) + wxT('\t') + wxT("CTRL+D"), wxEmptyString, wxITEM_NORMAL );
	m_EditMenu->Append( m_ClearHistory );

	m_EvalEngine = new wxMenu();
	wxMenuItem* m_EvalEngineItem = new wxMenuItem( m_EditMenu, wxID_ANY, wxT("&Engine"), wxEmptyString, wxITEM_NORMAL, m_EvalEngine );
	m_EngineExprtk = new wxMenuItem( m_EvalEngine, wxID_ANY, wxString( wxT("&exprtk") ) , wxEmptyString, wxITEM_RADIO );
	m_EvalEngine->Append( m_EngineExprtk );
	m_EngineExprtk->Check( true );

	m_EngineLua = new wxMenuItem( m_EvalEngine, wxID_ANY, wxString( wxT("&Lua") ) , wxEmptyString, wxITEM_RADIO );
	m_EvalEngine->Append( m_EngineLua );

	m_EditMenu->Append( m_EvalEngineItem );

	m_MainMenuBar->Append( m_EditMenu, wxT("&Edit") );

	m_HelpMenu = new wxMenu();
	wxMenuItem* m_About;
	m_About = new wxMenuItem( m_HelpMenu, wxID_ANY, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	m_HelpMenu->Append( m_About );

	m_MainMenuBar->Append( m_HelpMenu, wxT("&Help") );

	this->SetMenuBar( m_MainMenuBar );


	this->Centre( wxBOTH );

	// Connect Events
	m_ExprInput->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::m_ExprInputOnTextEnter ), NULL, this );
	m_ExecuteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ExecuteButtonOnButtonClick ), NULL, this );
	m_ClearResult->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ClearResultOnButtonClick ), NULL, this );
	m_ToggleHistory->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ToggleHistoryOnButtonClick ), NULL, this );
	m_HistoryList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( MainFrame::m_HistoryListOnListBoxDClick ), NULL, this );
	m_Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_NewWindowOnMenuSelection ), this, m_NewWindow->GetId());
	m_Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_CloseWindowOnMenuSelection ), this, m_CloseWindow->GetId());
	m_EditMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_ClearOnMenuSelection ), this, m_Clear->GetId());
	m_EditMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_ClearHistoryOnMenuSelection ), this, m_ClearHistory->GetId());
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_ExprInput->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::m_ExprInputOnTextEnter ), NULL, this );
	m_ExecuteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ExecuteButtonOnButtonClick ), NULL, this );
	m_ClearResult->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ClearResultOnButtonClick ), NULL, this );
	m_ToggleHistory->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ToggleHistoryOnButtonClick ), NULL, this );
	m_HistoryList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( MainFrame::m_HistoryListOnListBoxDClick ), NULL, this );

}
