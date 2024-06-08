object fMain: TfMain
  Left = 0
  Top = 0
  Caption = #1057#1077#1088#1074#1077#1088
  ClientHeight = 344
  ClientWidth = 552
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lbConnections: TListBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 546
    Height = 313
    Align = alClient
    ItemHeight = 13
    TabOrder = 0
  end
  object sbMain: TStatusBar
    AlignWithMargins = True
    Left = 3
    Top = 322
    Width = 546
    Height = 19
    Panels = <
      item
        Alignment = taCenter
        Width = 200
      end
      item
        Width = 300
      end>
  end
  object tiMain: TTrayIcon
    PopupMenu = pmMain
    Visible = True
    OnClick = tiMainClick
    Left = 32
    Top = 152
  end
  object pmMain: TPopupMenu
    Left = 32
    Top = 208
    object N1: TMenuItem
      Action = aShowMainForm
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object N3: TMenuItem
      Action = aExit
    end
  end
  object amMain: TActionManager
    ActionBars = <
      item
        AutoSize = False
      end
      item
      end
      item
      end
      item
      end
      item
      end
      item
      end
      item
      end
      item
      end
      item
      end
      item
      end
      item
      end
      item
        Items = <
          item
            Caption = '&ActionClientItem0'
          end>
      end
      item
        Items = <
          item
            Caption = '&ActionClientItem0'
          end>
      end
      item
        Items = <
          item
            Caption = 'ActionClientItem0'
          end>
      end>
    Left = 88
    Top = 152
    StyleName = 'Platform Default'
    object aShowMainForm: TAction
      Category = #1057#1077#1088#1074#1077#1088
      Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1075#1083#1072#1074#1085#1091#1102' '#1092#1086#1088#1084#1091
      OnExecute = aShowMainFormExecute
    end
    object aExit: TAction
      Category = #1057#1077#1088#1074#1077#1088
      Caption = #1047#1072#1082#1088#1099#1090#1100' '#1089#1077#1088#1074#1077#1088
      OnExecute = aExitExecute
    end
  end
end
