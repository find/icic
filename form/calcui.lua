----------------------------------------------------------------------------
-- Lua code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
-- http://www.wxformbuilder.org/
----------------------------------------------------------------------------

-- Load the wxLua module, does nothing if running from wxLua, wxLuaFreeze, or wxLuaEdit
package.cpath = package.cpath..";./?.dll;./?.so;../lib/?.so;../lib/vc_dll/?.dll;../lib/bcc_dll/?.dll;../lib/mingw_dll/?.dll;"
require("wx")

ID_ToggleDrawer = 1000

UI = {}


-- create MainFrame
UI.MainFrame = wx.wxFrame (wx.NULL, wx.wxID_ANY, "Caculator", wx.wxDefaultPosition, wx.wxSize( 622,301 ), wx.wxDEFAULT_FRAME_STYLE + wx.wxSYSTEM_MENU+wx.wxTAB_TRAVERSAL, "Calculator" )
	UI.MainFrame:SetSizeHints( wx.wxSize( 400,200 ), wx.wxDefaultSize )

	UI.MainLayout = wx.wxFlexGridSizer( 2, 1, 0, 0 )
	UI.MainLayout:AddGrowableRow( 1 )
	UI.MainLayout:SetFlexibleDirection( wx.wxBOTH )
	UI.MainLayout:SetNonFlexibleGrowMode( wx.wxFLEX_GROWMODE_SPECIFIED )

	UI.m_InputLineLayout = wx.wxBoxSizer( wx.wxHORIZONTAL )

	UI.m_ExprInput = wx.wxTextCtrl( UI.MainFrame, wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxSize( -1,-1 ), wx.wxTE_MULTILINE )
	UI.m_InputLineLayout:Add( UI.m_ExprInput, 20, wx.wxALL + wx.wxEXPAND, 1 )

	UI.m_ExecuteButton = wx.wxButton( UI.MainFrame, wx.wxID_ANY, "=", wx.wxDefaultPosition, wx.wxSize( -1,80 ), 0 )

	UI.m_ExecuteButton:SetDefault()
	UI.m_InputLineLayout:Add( UI.m_ExecuteButton, 1, wx.wxALL + wx.wxEXPAND, 2 )

	UI.m_ClearResult = wx.wxButton( UI.MainFrame, wx.wxID_ANY, "&Clear", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_InputLineLayout:Add( UI.m_ClearResult, 1, wx.wxALL + wx.wxEXPAND, 2 )

	UI.m_ToggleDrawer = wx.wxButton( UI.MainFrame, ID_ToggleDrawer, "<", wx.wxDefaultPosition, wx.wxSize( 12,-1 ), 0 )
	UI.m_ToggleDrawer:SetMinSize( wx.wxSize( 12,-1 ) )
	UI.m_ToggleDrawer:SetMaxSize( wx.wxSize( 12,-1 ) )

	UI.m_InputLineLayout:Add( UI.m_ToggleDrawer, 1, wx.wxBOTTOM + wx.wxEXPAND + wx.wxTOP, 2 )

	UI.m_DrawerLayout = wx.wxBoxSizer( wx.wxVERTICAL )

	UI.m_ToggleTop = wx.wxToggleButton( UI.MainFrame, wx.wxID_ANY, "Stay On Top", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_DrawerLayout:Add( UI.m_ToggleTop, 0, wx.wxALL + wx.wxEXPAND, 2 )

	UI.bSizer3 = wx.wxBoxSizer( wx.wxHORIZONTAL )

	UI.m_staticText1 = wx.wxStaticText( UI.MainFrame, wx.wxID_ANY, "Engine", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText1:Wrap( -1 )

	UI.bSizer3:Add( UI.m_staticText1, 0, wx.wxALL, 5 )

	UI.m_EvaluatorChoiceChoices = { "exprtk", "lua" }
	UI.m_EvaluatorChoice = wx.wxChoice( UI.MainFrame, wx.wxID_ANY, wx.wxDefaultPosition, wx.wxDefaultSize, UI.m_EvaluatorChoiceChoices, 0 )
	UI.m_EvaluatorChoice:SetSelection( 0 )
	UI.bSizer3:Add( UI.m_EvaluatorChoice, 0, wx.wxALL + wx.wxEXPAND, 2 )


	UI.m_DrawerLayout:Add( UI.bSizer3, 1, wx.wxEXPAND, 5 )

	UI.m_About = wx.wxButton( UI.MainFrame, wx.wxID_ANY, "&About", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_DrawerLayout:Add( UI.m_About, 1, wx.wxALL + wx.wxEXPAND, 2 )


	UI.m_InputLineLayout:Add( UI.m_DrawerLayout, 1, wx.wxEXPAND, 5 )


	UI.MainLayout:Add( UI.m_InputLineLayout, 1, wx.wxEXPAND, 2 )

	UI.m_Result = wx.wxTextCtrl( UI.MainFrame, wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxDefaultSize, wx.wxTE_MULTILINE )
	UI.MainLayout:Add( UI.m_Result, 3, wx.wxALL + wx.wxEXPAND, 1 )


	UI.:SetSizer( UI.MainLayout )
	UI.:Layout()

	UI.MainFrame:Centre( wx.wxBOTH )

	-- Connect Events

	UI.m_ExecuteButton:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_ExecuteButtonOnButtonClick

	event:Skip()
	end )

	UI.m_ClearResult:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_ClearResultOnButtonClick

	event:Skip()
	end )

	UI.m_ToggleDrawer:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_ToggleDrawerOnButtonClick

	event:Skip()
	end )



--wx.wxGetApp():MainLoop()
