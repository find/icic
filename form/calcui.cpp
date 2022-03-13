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

	wxFlexGridSizer* MainLayout;
	MainLayout = new wxFlexGridSizer( 2, 1, 0, 0 );
	MainLayout->AddGrowableRow( 1 );
	MainLayout->SetFlexibleDirection( wxBOTH );
	MainLayout->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_InputLineLayout = new wxBoxSizer( wxHORIZONTAL );

	m_ExprInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_MULTILINE );
	m_InputLineLayout->Add( m_ExprInput, 20, wxALL|wxEXPAND, 1 );

	m_ExecuteButton = new wxButton( this, wxID_ANY, wxT("="), wxDefaultPosition, wxSize( -1,80 ), 0 );

	m_ExecuteButton->SetDefault();
	m_InputLineLayout->Add( m_ExecuteButton, 1, wxALL|wxEXPAND, 2 );

	m_ClearResult = new wxButton( this, wxID_ANY, wxT("&Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	m_InputLineLayout->Add( m_ClearResult, 1, wxALL|wxEXPAND, 2 );

	m_ToggleDrawer = new wxButton( this, ID_ToggleDrawer, wxT("<"), wxDefaultPosition, wxSize( 12,-1 ), 0 );
	m_ToggleDrawer->SetMinSize( wxSize( 12,-1 ) );
	m_ToggleDrawer->SetMaxSize( wxSize( 12,-1 ) );

	m_InputLineLayout->Add( m_ToggleDrawer, 1, wxBOTTOM|wxEXPAND|wxTOP, 2 );

	m_DrawerLayout = new wxBoxSizer( wxVERTICAL );

	m_ToggleTop = new wxToggleButton( this, wxID_ANY, wxT("Stay On Top"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DrawerLayout->Add( m_ToggleTop, 0, wxALL|wxEXPAND, 2 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Engine"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALL, 5 );

	wxString m_EvaluatorChoiceChoices[] = { wxT("exprtk"), wxT("lua") };
	int m_EvaluatorChoiceNChoices = sizeof( m_EvaluatorChoiceChoices ) / sizeof( wxString );
	m_EvaluatorChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_EvaluatorChoiceNChoices, m_EvaluatorChoiceChoices, 0 );
	m_EvaluatorChoice->SetSelection( 0 );
	bSizer3->Add( m_EvaluatorChoice, 0, wxALL|wxEXPAND, 2 );


	m_DrawerLayout->Add( bSizer3, 1, wxEXPAND, 5 );

	m_About = new wxButton( this, wxID_ANY, wxT("&About"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DrawerLayout->Add( m_About, 1, wxALL|wxEXPAND, 2 );


	m_InputLineLayout->Add( m_DrawerLayout, 1, wxEXPAND, 5 );


	MainLayout->Add( m_InputLineLayout, 1, wxEXPAND, 2 );

	m_Result = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	MainLayout->Add( m_Result, 3, wxALL|wxEXPAND, 1 );


	this->SetSizer( MainLayout );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_ExecuteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ExecuteButtonOnButtonClick ), NULL, this );
	m_ClearResult->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ClearResultOnButtonClick ), NULL, this );
	m_ToggleDrawer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ToggleDrawerOnButtonClick ), NULL, this );
    m_ExprInput->Connect( wxEVT_TEXT_ENTER, wxCommandEventHandler( MainFrame::m_ExprInputOnTextEnter ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_ExecuteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ExecuteButtonOnButtonClick ), NULL, this );
	m_ClearResult->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ClearResultOnButtonClick ), NULL, this );
	m_ToggleDrawer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ToggleDrawerOnButtonClick ), NULL, this );
    m_ExprInput->Disconnect( wxEVT_TEXT_ENTER, wxCommandEventHandler( MainFrame::m_ExprInputOnTextEnter ), NULL, this );

}
