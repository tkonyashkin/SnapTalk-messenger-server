object fMain: TfMain
  Left = 0
  Top = 0
  Caption = #1050#1083#1080#1077#1085#1090
  ClientHeight = 544
  ClientWidth = 701
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = mmMain
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object tbMain: TToolBar
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 695
    Height = 52
    AutoSize = True
    ButtonHeight = 52
    ButtonWidth = 65
    Caption = 'tbMain'
    DisabledImages = dmData.ilMainD
    DrawingStyle = dsGradient
    Images = dmData.ilMainE
    ParentShowHint = False
    ShowCaptions = True
    ShowHint = True
    TabOrder = 0
    ExplicitWidth = 835
    object ToolButton3: TToolButton
      Left = 0
      Top = 0
      Action = aConnect
    end
    object ToolButton7: TToolButton
      Left = 65
      Top = 0
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ToolButton9: TToolButton
      Left = 73
      Top = 0
      Action = aChatMessages
    end
    object ToolButton8: TToolButton
      Left = 138
      Top = 0
      Width = 8
      Caption = 'ToolButton8'
      ImageIndex = 22
      Style = tbsSeparator
    end
    object ToolButton1: TToolButton
      Left = 146
      Top = 0
      Action = aChatAdd
    end
    object ToolButton6: TToolButton
      Left = 211
      Top = 0
      Action = aChatEdit
    end
    object ToolButton2: TToolButton
      Left = 276
      Top = 0
      Action = aChatDelete
    end
    object ToolButton4: TToolButton
      Left = 341
      Top = 0
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 18
      Style = tbsSeparator
    end
    object ToolButton5: TToolButton
      Left = 349
      Top = 0
      Action = aChatRefresh
    end
    object ToolButton10: TToolButton
      Left = 414
      Top = 0
      Width = 8
      Caption = 'ToolButton10'
      ImageIndex = 22
      Style = tbsSeparator
    end
    object ToolButton11: TToolButton
      Left = 422
      Top = 0
      Action = aProfile
    end
  end
  object sbMain: TStatusBar
    AlignWithMargins = True
    Left = 3
    Top = 522
    Width = 695
    Height = 19
    Panels = <
      item
        Width = 200
      end
      item
        Width = 300
      end>
    ExplicitWidth = 835
  end
  object dbgChatList: TDBGridEh
    AlignWithMargins = True
    Left = 3
    Top = 61
    Width = 695
    Height = 455
    Align = alClient
    AllowedOperations = []
    AutoFitColWidths = True
    DataSource = dmData.dsChatList
    DynProps = <>
    EditActions = [geaCopyEh, geaSelectAllEh]
    Flat = True
    IndicatorOptions = [gioShowRowIndicatorEh]
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
    ReadOnly = True
    RowLines = 2
    RowSizingAllowed = True
    SearchPanel.Enabled = True
    SearchPanel.FilterOnTyping = True
    SortLocal = True
    TabOrder = 2
    TitleParams.RowLines = 2
    OnDblClick = dbgChatListDblClick
    Columns = <
      item
        Alignment = taCenter
        AutoFitColWidth = False
        Color = clMoneyGreen
        DynProps = <>
        EditButtons = <>
        FieldName = #1050#1086#1076
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
        Visible = False
      end
      item
        AutoFitColWidth = False
        Color = clMoneyGreen
        DynProps = <>
        EditButtons = <>
        FieldName = #1044#1072#1090#1072'_'#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
        Width = 143
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = #1053#1072#1079#1074#1072#1085#1080#1077
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
        Width = 182
      end
      item
        AutoFitColWidth = False
        DynProps = <>
        EditButtons = <>
        FieldName = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
        Width = 144
      end
      item
        Alignment = taCenter
        AutoFitColWidth = False
        DynProps = <>
        EditButtons = <>
        FieldName = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086'_'#1085#1086#1074#1099#1093'_'#1089#1086#1086#1073#1097#1077#1085#1080#1081
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object amMain: TActionManager
    ActionBars = <
      item
        Items.CaptionOptions = coAll
        Items = <>
      end
      item
      end
      item
      end
      item
      end>
    Images = dmData.ilMainE
    Left = 80
    Top = 416
    StyleName = 'Platform Default'
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = #1047#1072#1082#1088#1099#1090#1100
      Enabled = False
      Hint = 'Close'
    end
    object WindowCascade1: TWindowCascade
      Category = 'Window'
      Caption = #1050#1072#1089#1082#1072#1076
      Enabled = False
      Hint = 'Cascade'
    end
    object WindowTileHorizontal1: TWindowTileHorizontal
      Category = 'Window'
      Caption = #1043#1086#1088#1080#1079#1086#1085#1090#1072#1083#1100#1085#1086#1077' '#1074#1099#1088#1072#1074#1085#1080#1074#1072#1085#1080#1077
      Enabled = False
      Hint = 'Tile Horizontal'
    end
    object WindowTileVertical1: TWindowTileVertical
      Category = 'Window'
      Caption = #1042#1077#1088#1090#1080#1082#1072#1083#1100#1085#1086#1077' '#1074#1099#1088#1072#1074#1085#1080#1074#1072#1085#1080#1077
      Enabled = False
      Hint = 'Tile Vertical'
    end
    object WindowMinimizeAll1: TWindowMinimizeAll
      Category = 'Window'
      Caption = #1057#1074#1077#1088#1085#1091#1090#1100' '#1074#1089#1077
      Enabled = False
      Hint = 'Minimize All'
    end
    object WindowArrange1: TWindowArrange
      Category = 'Window'
      Caption = #1059#1087#1086#1088#1103#1076#1086#1095#1080#1090#1100
      Enabled = False
    end
    object aConnect: TAction
      Caption = #1042#1093#1086#1076
      ImageIndex = 0
      OnExecute = aConnectExecute
    end
    object aShowMainForm: TAction
      Caption = #1043#1083#1072#1074#1085#1072#1103
      OnExecute = aShowMainFormExecute
    end
    object aClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 1
      OnExecute = aCloseExecute
    end
    object aShowUser: TAction
      Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
      Hint = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
      ImageIndex = 4
      OnExecute = aShowUserExecute
    end
    object aChatAdd: TAction
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1073#1077#1089#1077#1076#1091
      ImageIndex = 16
      OnExecute = aChatAddExecute
    end
    object aChatEdit: TAction
      Caption = #1056#1077#1076#1072#1082#1090'.'
      Hint = #1055#1077#1088#1077#1080#1084#1077#1085#1086#1074#1072#1090#1100' '#1073#1077#1089#1077#1076#1091
      ImageIndex = 18
      OnExecute = aChatEditExecute
    end
    object aChatDelete: TAction
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1073#1077#1089#1077#1076#1091
      ImageIndex = 17
      OnExecute = aChatDeleteExecute
    end
    object aChatRefresh: TAction
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      Hint = #1054#1073#1085#1086#1074#1080#1090#1100
      ImageIndex = 21
      OnExecute = aChatRefreshExecute
    end
    object aChatMessages: TAction
      Caption = #1057#1086#1086#1073#1097#1077#1085#1080#1103
      Hint = #1057#1086#1086#1073#1097#1077#1085#1080#1103
      ImageIndex = 6
      OnExecute = aChatMessagesExecute
    end
    object aProfile: TAction
      Caption = #1055#1088#1086#1092#1080#1083#1100
      Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1087#1088#1086#1092#1080#1083#1100
      ImageIndex = 4
      OnExecute = aProfileExecute
    end
  end
  object tiMain: TTrayIcon
    BalloonTimeout = 0
    PopupMenu = pmMain
    Visible = True
    OnClick = tiMainClick
    Left = 144
    Top = 416
  end
  object pmMain: TPopupMenu
    Left = 200
    Top = 416
    object N5: TMenuItem
      Action = aConnect
    end
    object N6: TMenuItem
      Caption = '-'
    end
    object N2: TMenuItem
      Action = aShowMainForm
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object N4: TMenuItem
      Action = aClose
    end
  end
  object dsUI: TDataSource
    DataSet = dmData.cdsUserInfo
    OnDataChange = dsUIDataChange
    Left = 256
    Top = 416
  end
  object mmMain: TMainMenu
    Left = 16
    Top = 416
    object N10: TMenuItem
      Caption = #1057#1080#1089#1090#1077#1084#1072
      object N17: TMenuItem
        Action = aProfile
      end
      object N16: TMenuItem
        Caption = '-'
      end
      object N19: TMenuItem
        Action = aConnect
      end
    end
    object N1: TMenuItem
      Caption = #1041#1077#1089#1077#1076#1072
      object N7: TMenuItem
        Action = aChatAdd
      end
      object N11: TMenuItem
        Action = aChatEdit
      end
      object N8: TMenuItem
        Action = aChatDelete
      end
      object N12: TMenuItem
        Caption = '-'
      end
      object N15: TMenuItem
        Action = aChatRefresh
      end
      object N14: TMenuItem
        Caption = '-'
      end
      object N13: TMenuItem
        Action = aChatMessages
      end
    end
    object miAdminPanel: TMenuItem
      Caption = #1055#1072#1085#1077#1083#1100' '#1072#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088#1072
      object N9: TMenuItem
        Action = aShowUser
      end
    end
  end
  object tMain: TTimer
    OnTimer = tMainTimer
    Left = 304
    Top = 416
  end
end
