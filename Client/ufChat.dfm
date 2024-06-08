object fChat: TfChat
  Left = 0
  Top = 0
  Caption = #1041#1077#1089#1077#1076#1072
  ClientHeight = 573
  ClientWidth = 722
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 554
    Width = 722
    Height = 19
    Panels = <>
    ExplicitTop = 625
    ExplicitWidth = 864
  end
  object PageControl1: TPageControl
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 716
    Height = 548
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 858
    ExplicitHeight = 619
    object TabSheet1: TTabSheet
      Caption = #1041#1077#1089#1077#1076#1072
      ExplicitWidth = 850
      ExplicitHeight = 591
      object Panel1: TPanel
        Left = 0
        Top = 420
        Width = 708
        Height = 100
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 0
        ExplicitTop = 491
        ExplicitWidth = 850
        DesignSize = (
          708
          100)
        object mText: TMemo
          Left = 3
          Top = 3
          Width = 621
          Height = 91
          Anchors = [akLeft, akTop, akRight, akBottom]
          Lines.Strings = (
            'mText')
          ScrollBars = ssVertical
          TabOrder = 0
          ExplicitWidth = 763
        end
        object bSend: TButton
          Left = 630
          Top = 3
          Width = 75
          Height = 38
          Action = aSendMessage
          Anchors = [akTop, akRight]
          TabOrder = 1
          ExplicitLeft = 772
        end
      end
      object DBGridEh1: TDBGridEh
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 702
        Height = 414
        Align = alClient
        AllowedOperations = []
        AutoFitColWidths = True
        DataSource = dmData.dsChatMessages
        DynProps = <>
        EditActions = [geaCopyEh, geaSelectAllEh]
        Flat = True
        IndicatorOptions = [gioShowRowIndicatorEh]
        Options = [dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
        OptionsEh = [dghFixed3D, dghHighlightFocus, dghClearSelection, dghDialogFind, dghExtendVertLines]
        ReadOnly = True
        RowLines = 2
        RowSizingAllowed = True
        SearchPanel.Enabled = True
        SearchPanel.FilterOnTyping = True
        SortLocal = True
        TabOrder = 1
        TitleParams.RowLines = 2
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
            Alignment = taCenter
            AutoFitColWidth = False
            Color = clMoneyGreen
            DynProps = <>
            EditButtons = <>
            FieldName = #1044#1072#1090#1072'_'#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080
            Footers = <>
            Layout = tlCenter
            Title.Alignment = taCenter
            Width = 125
          end
          item
            DynProps = <>
            EditButtons = <>
            FieldName = #1058#1077#1082#1089#1090
            Footers = <>
            Layout = tlCenter
            Title.Alignment = taCenter
            Width = 326
          end
          item
            Alignment = taCenter
            AutoFitColWidth = False
            Color = clMoneyGreen
            DynProps = <>
            EditButtons = <>
            FieldName = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
            Footers = <>
            Layout = tlCenter
            Title.Alignment = taCenter
            Width = 227
          end>
        object RowDetailData: TRowDetailPanelControlEh
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1059#1095#1072#1089#1090#1085#1080#1082#1080
      ImageIndex = 1
      ExplicitWidth = 850
      ExplicitHeight = 591
      object DBGridEh2: TDBGridEh
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 702
        Height = 469
        Align = alClient
        AllowedOperations = []
        AutoFitColWidths = True
        DataSource = dmData.dsChatParticipantList
        DynProps = <>
        EditActions = [geaCopyEh, geaSelectAllEh]
        Flat = True
        IndicatorOptions = [gioShowRowIndicatorEh]
        Options = [dgTitles, dgIndicator, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        OptionsEh = [dghFixed3D, dghHighlightFocus, dghClearSelection, dghDialogFind, dghExtendVertLines]
        ReadOnly = True
        RowLines = 2
        RowSizingAllowed = True
        SearchPanel.Enabled = True
        SearchPanel.FilterOnTyping = True
        SortLocal = True
        TabOrder = 0
        TitleParams.RowLines = 2
        Columns = <
          item
            DynProps = <>
            EditButtons = <>
            FieldName = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
            Footers = <>
            Layout = tlCenter
            Title.Alignment = taCenter
            Width = 470
          end
          item
            Alignment = taCenter
            DynProps = <>
            EditButtons = <>
            FieldName = #1051#1086#1075#1080#1085
            Footers = <>
            Layout = tlCenter
            Title.Alignment = taCenter
            Width = 251
          end>
        object RowDetailData: TRowDetailPanelControlEh
        end
      end
      object tbNavigator: TToolBar
        AlignWithMargins = True
        Left = 3
        Top = 478
        Width = 702
        Height = 39
        Align = alBottom
        AutoSize = True
        ButtonHeight = 39
        ButtonWidth = 39
        Caption = 'tbMain'
        DisabledImages = dmData.ilDataSet32D_2
        DrawingStyle = dsGradient
        Images = dmData.ilDataSet32E_2
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        ExplicitTop = 549
        ExplicitWidth = 844
        object ToolButton12: TToolButton
          Left = 0
          Top = 0
          Action = aChatParticipantAdd
        end
        object ToolButton13: TToolButton
          Left = 39
          Top = 0
          Action = aChatParticipantDelete
        end
        object ToolButton2: TToolButton
          Left = 78
          Top = 0
          Width = 8
          Caption = 'ToolButton2'
          ImageIndex = 10
          Style = tbsSeparator
        end
        object ToolButton14: TToolButton
          Left = 86
          Top = 0
          Action = DataSetRefresh1
        end
      end
    end
  end
  object amChat: TActionManager
    DisabledImages = dmData.ilDataSet32D_2
    Images = dmData.ilDataSet32E_2
    Left = 40
    Top = 136
    StyleName = 'Platform Default'
    object aChatParticipantAdd: TAction
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100
      ImageIndex = 4
      OnExecute = aChatParticipantAddExecute
    end
    object aChatParticipantDelete: TAction
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Hint = #1059#1076#1072#1083#1080#1090#1100
      ImageIndex = 5
      OnExecute = aChatParticipantDeleteExecute
    end
    object DataSetRefresh1: TDataSetRefresh
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      Hint = #1054#1073#1085#1086#1074#1080#1090#1100
      ImageIndex = 9
    end
    object aSendMessage: TAction
      Caption = #1054#1090#1087#1088#1072#1074#1080#1090#1100
      OnExecute = aSendMessageExecute
    end
  end
end
