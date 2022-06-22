///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ui.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxSize( 400,200 ), wxDefaultSize );

	m_MainLayout = new wxFlexGridSizer( 1, 1, 0, 0 );
	m_MainLayout->AddGrowableCol( 0 );
	m_MainLayout->AddGrowableRow( 0 );
	m_MainLayout->SetFlexibleDirection( wxBOTH );
	m_MainLayout->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_WindowSplitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE|wxSP_NOBORDER|wxSP_THIN_SASH );
	m_WindowSplitter->SetSashGravity( 0.5 );
	m_WindowSplitter->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_WindowSplitterOnIdle ), NULL, this );
	m_WindowSplitter->SetMinimumPaneSize( 50 );

	m_InputPanel = new wxPanel( m_WindowSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_InputPanel->SetMinSize( wxSize( 100,50 ) );

	m_InputPanelLayout = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* m_InputLineLayout;
	m_InputLineLayout = new wxBoxSizer( wxHORIZONTAL );

	m_HistorySizer = new wxBoxSizer( wxVERTICAL );

	m_ExprInput = new wxTextCtrl( m_InputPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_MULTILINE );
	m_ExprInput->SetFont( wxFont( 14, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier New") ) );

	m_HistorySizer->Add( m_ExprInput, 3, wxALL|wxEXPAND, 0 );

	m_ToggleHistory = new wxButton( m_InputPanel, wxID_ANY, wxT("History"), wxDefaultPosition, wxSize( -1,10 ), 0 );
	m_ToggleHistory->SetFont( wxFont( 6, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_ToggleHistory->SetToolTip( wxT("Toggle History Window (Ctrl + H)") );

	m_HistorySizer->Add( m_ToggleHistory, 0, wxALL|wxEXPAND, 0 );

	m_HistoryList = new wxListBox( m_InputPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB );
	m_HistoryList->SetMinSize( wxSize( -1,30 ) );

	m_HistorySizer->Add( m_HistoryList, 6, wxALL|wxEXPAND, 0 );


	m_InputLineLayout->Add( m_HistorySizer, 10, wxEXPAND, 0 );

	m_ExecuteButton = new wxButton( m_InputPanel, wxID_ANY, wxT("="), wxDefaultPosition, wxSize( 40,-1 ), 0 );

	m_ExecuteButton->SetDefault();
	m_ExecuteButton->SetFont( wxFont( 22, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	m_ExecuteButton->SetToolTip( wxT("Ctrl + Enter") );

	m_InputLineLayout->Add( m_ExecuteButton, 1, wxALL|wxEXPAND, 0 );

	m_ClearResult = new wxButton( m_InputPanel, wxID_ANY, wxT("&Clear"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
	m_ClearResult->SetToolTip( wxT("Ctrl + L") );

	m_InputLineLayout->Add( m_ClearResult, 1, wxALL|wxEXPAND, 0 );


	m_InputPanelLayout->Add( m_InputLineLayout, 10, wxEXPAND, 0 );


	m_InputPanel->SetSizer( m_InputPanelLayout );
	m_InputPanel->Layout();
	m_InputPanelLayout->Fit( m_InputPanel );
	m_OutputPanel = new wxPanel( m_WindowSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_OutputPanel->SetMinSize( wxSize( 100,50 ) );

	m_ResultSizer = new wxBoxSizer( wxHORIZONTAL );

	m_Result = new wxTextCtrl( m_OutputPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	m_Result->SetFont( wxFont( 12, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier New") ) );

	m_ResultSizer->Add( m_Result, 3, wxALL|wxEXPAND, 0 );


	m_OutputPanel->SetSizer( m_ResultSizer );
	m_OutputPanel->Layout();
	m_ResultSizer->Fit( m_OutputPanel );
	m_WindowSplitter->SplitHorizontally( m_InputPanel, m_OutputPanel, 100 );
	m_MainLayout->Add( m_WindowSplitter, 1, wxEXPAND, 0 );


	this->SetSizer( m_MainLayout );
	this->Layout();
	m_MainMenuBar = new wxMenuBar( wxMB_DOCKABLE );
	m_Window = new wxMenu();
	m_StayOnTop = new wxMenuItem( m_Window, wxID_ANY, wxString( wxT("Stay On &Top") ) + wxT('\t') + wxT("Ctrl+T"), wxEmptyString, wxITEM_CHECK );
	m_Window->Append( m_StayOnTop );

	wxMenuItem* m_MenuToggleHistory;
	m_MenuToggleHistory = new wxMenuItem( m_Window, wxID_ANY, wxString( wxT("Toggle &History Window") ) + wxT('\t') + wxT("Ctrl+H"), wxEmptyString, wxITEM_NORMAL );
	m_Window->Append( m_MenuToggleHistory );

	wxMenuItem* m_NewWindow;
	m_NewWindow = new wxMenuItem( m_Window, wxID_ANY, wxString( wxT("&New Window") ) + wxT('\t') + wxT("Ctrl+N"), wxEmptyString, wxITEM_NORMAL );
	m_Window->Append( m_NewWindow );

	wxMenuItem* m_CloseWindow;
	m_CloseWindow = new wxMenuItem( m_Window, wxID_ANY, wxString( wxT("Close Window") ) + wxT('\t') + wxT("Ctrl+Q"), wxEmptyString, wxITEM_NORMAL );
	m_Window->Append( m_CloseWindow );

	m_MainMenuBar->Append( m_Window, wxT("&Window") );

	m_EditMenu = new wxMenu();
	m_EvalEngine = new wxMenu();
	wxMenuItem* m_EvalEngineItem = new wxMenuItem( m_EditMenu, wxID_ANY, wxT("En&gine"), wxEmptyString, wxITEM_NORMAL, m_EvalEngine );
	m_EngineQuickJS = new wxMenuItem( m_EvalEngine, wxID_ANY, wxString( wxT("Quick&JS") ) + wxT('\t') + wxT("Alt+Shift+J"), wxEmptyString, wxITEM_RADIO );
	m_EvalEngine->Append( m_EngineQuickJS );
	m_EngineQuickJS->Check( true );

	m_EngineLua = new wxMenuItem( m_EvalEngine, wxID_ANY, wxString( wxT("&Lua") ) + wxT('\t') + wxT("Alt+Shift+L"), wxEmptyString, wxITEM_RADIO );
	m_EvalEngine->Append( m_EngineLua );

	m_EditMenu->Append( m_EvalEngineItem );

	wxMenuItem* m_MenuEval;
	m_MenuEval = new wxMenuItem( m_EditMenu, wxID_ANY, wxString( wxT("&Evaluate") ) + wxT('\t') + wxT("Ctrl+Enter"), wxEmptyString, wxITEM_NORMAL );
	m_EditMenu->Append( m_MenuEval );

	wxMenuItem* m_Clear;
	m_Clear = new wxMenuItem( m_EditMenu, wxID_ANY, wxString( wxT("&Clear") ) + wxT('\t') + wxT("Ctrl+L"), wxEmptyString, wxITEM_NORMAL );
	m_EditMenu->Append( m_Clear );

	wxMenuItem* m_ClearHistory;
	m_ClearHistory = new wxMenuItem( m_EditMenu, wxID_ANY, wxString( wxT("Clear &History") ) + wxT('\t') + wxT("Ctrl+Alt+L"), wxEmptyString, wxITEM_NORMAL );
	m_EditMenu->Append( m_ClearHistory );

	m_MainMenuBar->Append( m_EditMenu, wxT("&Edit") );

	m_HelpMenu = new wxMenu();
	wxMenuItem* m_About;
	m_About = new wxMenuItem( m_HelpMenu, wxID_ANY, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	m_HelpMenu->Append( m_About );

	m_MainMenuBar->Append( m_HelpMenu, wxT("&Help") );

	this->SetMenuBar( m_MainMenuBar );


	this->Centre( wxBOTH );

	// Connect Events
	m_ToggleHistory->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ToggleHistoryOnButtonClick ), NULL, this );
	m_HistoryList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( MainFrame::m_HistoryListOnListBoxDClick ), NULL, this );
	m_ExecuteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ExecuteButtonOnButtonClick ), NULL, this );
	m_ClearResult->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ClearResultOnButtonClick ), NULL, this );
	m_Result->Connect( wxEVT_CHAR, wxKeyEventHandler( MainFrame::m_ResultOnChar ), NULL, this );
	m_Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_StayOnTopOnMenuSelection ), this, m_StayOnTop->GetId());
	m_Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_MenuToggleHistoryOnMenuSelection ), this, m_MenuToggleHistory->GetId());
	m_Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_NewWindowOnMenuSelection ), this, m_NewWindow->GetId());
	m_Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_CloseWindowOnMenuSelection ), this, m_CloseWindow->GetId());
	m_EvalEngine->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_EngineQuickJSOnMenuSelection ), this, m_EngineQuickJS->GetId());
	m_EvalEngine->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_EngineLuaOnMenuSelection ), this, m_EngineLua->GetId());
	m_EditMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_MenuEvalOnMenuSelection ), this, m_MenuEval->GetId());
	m_EditMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_ClearOnMenuSelection ), this, m_Clear->GetId());
	m_EditMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_ClearHistoryOnMenuSelection ), this, m_ClearHistory->GetId());
	m_HelpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_AboutOnMenuSelection ), this, m_About->GetId());
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_ToggleHistory->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ToggleHistoryOnButtonClick ), NULL, this );
	m_HistoryList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( MainFrame::m_HistoryListOnListBoxDClick ), NULL, this );
	m_ExecuteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ExecuteButtonOnButtonClick ), NULL, this );
	m_ClearResult->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ClearResultOnButtonClick ), NULL, this );
	m_Result->Disconnect( wxEVT_CHAR, wxKeyEventHandler( MainFrame::m_ResultOnChar ), NULL, this );

}

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("A Calculator"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText31->Wrap( -1 );
	m_staticText31->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer6->Add( m_staticText31, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticText* m_staticText3;
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Proudly made with\nwxWidgets  (<i>wxwidgets.org</i>)\nQuickJS (<i>bellard.org/quickjs</i>)\nLua (<i>lua.org</i>)"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTER_HORIZONTAL );
	m_staticText3->SetLabelMarkup( wxT("Proudly made with\nwxWidgets  (<i>wxwidgets.org</i>)\nQuickJS (<i>bellard.org/quickjs</i>)\nLua (<i>lua.org</i>)") );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticText* m_staticText2;
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Copyright (C) 2022 yuguo"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );
}

AboutDialog::~AboutDialog()
{
}
