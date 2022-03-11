///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "qjscalc_ui.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxSize( 400,200 ), wxDefaultSize );

	wxBoxSizer* MainVerticalLayout;
	MainVerticalLayout = new wxBoxSizer( wxVERTICAL );

	m_InputLineLayout = new wxBoxSizer( wxHORIZONTAL );

	m_ExprInput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_MULTILINE );
	m_InputLineLayout->Add( m_ExprInput, 20, wxALL|wxEXPAND, 1 );

	m_ExecuteButton = new wxButton( this, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0 );

	m_ExecuteButton->SetDefault();
	m_InputLineLayout->Add( m_ExecuteButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 2 );

	m_ClearResult = new wxButton( this, wxID_ANY, wxT("&Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	m_InputLineLayout->Add( m_ClearResult, 1, wxALL|wxEXPAND, 2 );

	m_ToggleDrawer = new wxButton( this, ID_ToggleDrawer, wxT("<"), wxDefaultPosition, wxSize( 4,-1 ), 0 );
	m_InputLineLayout->Add( m_ToggleDrawer, 1, wxBOTTOM|wxEXPAND|wxTOP, 2 );

	m_DrawerLayout = new wxBoxSizer( wxVERTICAL );

	m_ToggleTop = new wxToggleButton( this, wxID_ANY, wxT("Stay On Top"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DrawerLayout->Add( m_ToggleTop, 0, wxALL, 2 );

	m_About = new wxButton( this, wxID_ANY, wxT("&About"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DrawerLayout->Add( m_About, 1, wxALL|wxEXPAND, 2 );


	m_InputLineLayout->Add( m_DrawerLayout, 1, wxEXPAND, 5 );


	MainVerticalLayout->Add( m_InputLineLayout, 1, wxEXPAND, 5 );

	m_Result = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	MainVerticalLayout->Add( m_Result, 3, wxALL|wxEXPAND, 1 );


	this->SetSizer( MainVerticalLayout );
	this->Layout();

	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}
