object fUserList: TfUserList
  Left = 0
  Top = 0
  Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
  ClientHeight = 564
  ClientWidth = 784
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object DBGridEh1: TDBGridEh
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 778
    Height = 494
    Align = alClient
    AllowedOperations = []
    AutoFitColWidths = True
    DataSource = dmData.dsUserList
    DynProps = <>
    EditActions = [geaCopyEh, geaSelectAllEh]
    Flat = True
    IndicatorOptions = [gioShowRowIndicatorEh]
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
    ReadOnly = True
    RowLines = 2
    RowSizingAllowed = True
    SearchPanel.Enabled = True
    SearchPanel.FilterOnTyping = True
    SortLocal = True
    TabOrder = 0
    TitleParams.RowLines = 2
    OnDblClick = DBGridEh1DblClick
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
        AutoFitColWidth = False
        DynProps = <>
        EditButtons = <>
        FieldName = #1051#1086#1075#1080#1085
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
        Width = 97
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
        Width = 250
      end
      item
        AutoFitColWidth = False
        DynProps = <>
        EditButtons = <>
        FieldName = #1041#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100'_'#1076#1086#1089#1090#1091#1087
        Footers = <>
        Layout = tlCenter
        Title.Alignment = taCenter
        Width = 82
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 545
    Width = 784
    Height = 19
    Panels = <>
  end
  object Panel1: TPanel
    Left = 0
    Top = 500
    Width = 784
    Height = 45
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    DesignSize = (
      784
      45)
    object bSelect: TButton
      Left = 706
      Top = 3
      Width = 75
      Height = 38
      Anchors = [akTop, akRight]
      Caption = #1042#1099#1073#1088#1072#1090#1100
      Default = True
      TabOrder = 0
      OnClick = bSelectClick
    end
  end
end
