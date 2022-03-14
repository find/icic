----------------------------------------------------------------------------
-- Lua code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
-- http://www.wxformbuilder.org/
----------------------------------------------------------------------------

-- Load the wxLua module, does nothing if running from wxLua, wxLuaFreeze, or wxLuaEdit
package.cpath = package.cpath..";./?.dll;./?.so;../lib/?.so;../lib/vc_dll/?.dll;../lib/bcc_dll/?.dll;../lib/mingw_dll/?.dll;"
require("wx")

UI = {}


-- create MainFrame
UI.MainFrame = wx.wxFrame (wx.NULL, wx.wxID_ANY, "Caculator", wx.wxDefaultPosition, wx.wxSize( 622,301 ), wx.wxDEFAULT_FRAME_STYLE + wx.wxSYSTEM_MENU+wx.wxTAB_TRAVERSAL, "Calculator" )
	UI.MainFrame:SetSizeHints( wx.wxSize( 400,200 ), wx.wxDefaultSize )

	UI.m_MainLayout = wx.wxFlexGridSizer( 3, 1, 0, 0 )
	UI.m_MainLayout:AddGrowableRow( 1 )
	UI.m_MainLayout:SetFlexibleDirection( wx.wxBOTH )
	UI.m_MainLayout:SetNonFlexibleGrowMode( wx.wxFLEX_GROWMODE_SPECIFIED )

	UI.m_InputLineLayout = wx.wxBoxSizer( wx.wxHORIZONTAL )

	UI.m_ExprInput = wx.wxTextCtrl( UI.MainFrame, wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxSize( -1,100 ), wx.wxTE_MULTILINE )
	UI.m_InputLineLayout:Add( UI.m_ExprInput, 20, wx.wxALL + wx.wxEXPAND, 0 )

	UI.m_ExecuteButton = wx.wxButton( UI.MainFrame, wx.wxID_ANY, "=", wx.wxDefaultPosition, wx.wxSize( 40,-1 ), 0 )

	UI.m_ExecuteButton:SetDefault()
	UI.m_InputLineLayout:Add( UI.m_ExecuteButton, 1, wx.wxALL + wx.wxEXPAND, 1 )

	UI.m_ClearResult = wx.wxButton( UI.MainFrame, wx.wxID_ANY, "&Clear", wx.wxDefaultPosition, wx.wxSize( 40,-1 ), 0 )
	UI.m_InputLineLayout:Add( UI.m_ClearResult, 1, wx.wxALL + wx.wxEXPAND, 1 )


	UI.m_MainLayout:Add( UI.m_InputLineLayout, 1, wx.wxEXPAND, 0 )

	UI.m_ResultSizer = wx.wxBoxSizer( wx.wxHORIZONTAL )

	UI.m_Result = wx.wxTextCtrl( UI.MainFrame, wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxDefaultSize, wx.wxTE_MULTILINE )
	UI.m_ResultSizer:Add( UI.m_Result, 3, wx.wxALL + wx.wxEXPAND, 0 )

	UI.m_ToggleHistory = wx.wxButton( UI.MainFrame, wx.wxID_ANY, ">", wx.wxDefaultPosition, wx.wxSize( 16,-1 ), 0 )
	UI.m_ToggleHistory:SetFont( wx.wxFont( 12, wx.wxFONTFAMILY_DEFAULT, wx.wxFONTSTYLE_NORMAL, wx.wxFONTWEIGHT_NORMAL, False, "" ) )
	UI.m_ToggleHistory:SetToolTip( "Toggle History Window" )

	UI.m_ResultSizer:Add( UI.m_ToggleHistory, 0, wx.wxALL + wx.wxEXPAND, 0 )

	UI.m_HistoryListChoices = {}
	UI.m_HistoryList = wx.wxListBox( UI.MainFrame, wx.wxID_ANY, wx.wxDefaultPosition, wx.wxDefaultSize, UI.m_HistoryListChoices, wx.wxLB_HSCROLL + wx.wxLB_NEEDED_SB )
	UI.m_ResultSizer:Add( UI.m_HistoryList, 4, wx.wxALL + wx.wxEXPAND, 0 )


	UI.m_MainLayout:Add( UI.m_ResultSizer, 1, wx.wxEXPAND, 0 )


	UI.:SetSizer( UI.m_MainLayout )
	UI.:Layout()
	UI.m_MainMenuBar = wx.wxMenuBar( wx.wxMB_DOCKABLE )
	UI.m_Window = wx.wxMenu()
	UI.m_StayOnTop = wx.wxMenuItem( UI.m_Window, wx.wxID_ANY, "Stay On &Top".."\t" .. "Ctrl+T", "", wx.wxITEM_CHECK )
	UI.m_Window:Append( UI.m_StayOnTop )

	UI.m_MenuToggleHistory = wx.wxMenuItem( UI.m_Window, wx.wxID_ANY, "Toggle &History Window".."\t" .. "Ctrl+H", "", wx.wxITEM_NORMAL )
	UI.m_Window:Append( UI.m_MenuToggleHistory )

	UI.m_NewWindow = wx.wxMenuItem( UI.m_Window, wx.wxID_ANY, "&New Window".."\t" .. "Ctrl+N", "", wx.wxITEM_NORMAL )
	UI.m_Window:Append( UI.m_NewWindow )

	UI.m_CloseWindow = wx.wxMenuItem( UI.m_Window, wx.wxID_ANY, "Close Window".."\t" .. "Ctrl+Q", "", wx.wxITEM_NORMAL )
	UI.m_Window:Append( UI.m_CloseWindow )

	UI.m_MainMenuBar:Append( UI.m_Window, "&Window" )

	UI.m_EditMenu = wx.wxMenu()
	UI.m_EvalEngine = wx.wxMenu()
	UI.m_EngineExprtk = wx.wxMenuItem( UI.m_EvalEngine, wx.wxID_ANY, "&exprtk".."\t" .. "Alt+Shift+E", "", wx.wxITEM_RADIO )
	UI.m_EvalEngine:Append( UI.m_EngineExprtk )
	UI.m_EngineExprtk:Check( True )

	UI.m_EngineLua = wx.wxMenuItem( UI.m_EvalEngine, wx.wxID_ANY, "&Lua".."\t" .. "Alt+Shift+L", "", wx.wxITEM_RADIO )
	UI.m_EvalEngine:Append( UI.m_EngineLua )

	UI.m_EditMenu:Append(wx.wxID_ANY, "En&gine", UI.m_EvalEngine)

	UI.m_MenuEval = wx.wxMenuItem( UI.m_EditMenu, wx.wxID_ANY, "&Evaluate".."\t" .. "Ctrl+Enter", "", wx.wxITEM_NORMAL )
	UI.m_EditMenu:Append( UI.m_MenuEval )

	UI.m_Clear = wx.wxMenuItem( UI.m_EditMenu, wx.wxID_ANY, "&Clear".."\t" .. "Ctrl+L", "", wx.wxITEM_NORMAL )
	UI.m_EditMenu:Append( UI.m_Clear )

	UI.m_ClearHistory = wx.wxMenuItem( UI.m_EditMenu, wx.wxID_ANY, "Clear &History".."\t" .. "Ctrl+D", "", wx.wxITEM_NORMAL )
	UI.m_EditMenu:Append( UI.m_ClearHistory )

	UI.m_MainMenuBar:Append( UI.m_EditMenu, "&Edit" )

	UI.m_HelpMenu = wx.wxMenu()
	UI.m_About = wx.wxMenuItem( UI.m_HelpMenu, wx.wxID_ANY, "&About", "", wx.wxITEM_NORMAL )
	UI.m_HelpMenu:Append( UI.m_About )

	UI.m_MainMenuBar:Append( UI.m_HelpMenu, "&Help" )

	UI.MainFrame:SetMenuBar( UI.m_MainMenuBar )


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

	UI.m_ToggleHistory:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_ToggleHistoryOnButtonClick

	event:Skip()
	end )

	UI.m_HistoryList:Connect( wx.wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, function(event)
	--implements m_HistoryListOnListBoxDClick

	event:Skip()
	end )

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_MenuToggleHistoryOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_NewWindowOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_CloseWindowOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_EngineExprtkOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_EngineLuaOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_MenuEvalOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_ClearOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_ClearHistoryOnMenuSelection

	event:Skip()
	end)

	UI.MainFrame:Connect( wx.wxID_ANY ,wx.wxEVT_COMMAND_MENU_SELECTED , function(event)
	--implements m_AboutOnMenuSelection

	event:Skip()
	end)


-- create AboutDialog
UI.AboutDialog = wx.wxDialog (wx.NULL, wx.wxID_ANY, "About", wx.wxDefaultPosition, wx.wxSize( 354,191 ), wx.wxDEFAULT_DIALOG_STYLE )
	UI.AboutDialog:SetSizeHints( wx.wxDefaultSize, wx.wxDefaultSize )

	UI.bSizer6 = wx.wxBoxSizer( wx.wxVERTICAL )


	UI.bSizer6:Add( 0, 0, 1, wx.wxEXPAND, 5 )

	UI.m_staticText3 = wx.wxStaticText( UI.AboutDialog, wx.wxID_ANY, "Just A Calculator", wx.wxDefaultPosition, wx.wxSize( -1,-1 ), wx.wxALIGN_CENTER_HORIZONTAL )
	UI.m_staticText3:Wrap( -1 )

	UI.bSizer6:Add( UI.m_staticText3, 0, wx.wxALL + wx.wxEXPAND, 5 )


	UI.bSizer6:Add( 0, 0, 1, wx.wxEXPAND, 5 )

	UI.m_staticText2 = wx.wxStaticText( UI.AboutDialog, wx.wxID_ANY, "Copyright (C) 2022 yuguo", wx.wxDefaultPosition, wx.wxDefaultSize, wx.wxALIGN_CENTER_HORIZONTAL )
	UI.m_staticText2:Wrap( -1 )

	UI.bSizer6:Add( UI.m_staticText2, 0, wx.wxALL + wx.wxEXPAND, 5 )


	UI.:SetSizer( UI.bSizer6 )
	UI.:Layout()

	UI.AboutDialog:Centre( wx.wxBOTH )


--wx.wxGetApp():MainLoop()
