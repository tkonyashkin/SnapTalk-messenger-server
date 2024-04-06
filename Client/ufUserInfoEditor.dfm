object fUserInfoEditor: TfUserInfoEditor
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1088#1086#1092#1080#1083#1100
  ClientHeight = 220
  ClientWidth = 465
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 383
    Top = 0
    Width = 82
    Height = 220
    Align = alRight
    TabOrder = 0
    ExplicitTop = -3
    ExplicitHeight = 307
    object Button1: TButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 74
      Height = 25
      Margins.Bottom = 0
      Align = alTop
      Caption = 'OK'
      Default = True
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 4
      Top = 32
      Width = 74
      Height = 25
      Align = alTop
      Caption = #1054#1090#1084#1077#1085#1072
      ModalResult = 2
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 383
    Height = 220
    Align = alClient
    TabOrder = 1
    ExplicitHeight = 307
    object lLogin: TLabel
      Left = 9
      Top = 9
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = #1051#1086#1075#1080#1085
    end
    object lPassword: TLabel
      Left = 9
      Top = 36
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = #1055#1072#1088#1086#1083#1100
    end
    object Label5: TLabel
      Left = 9
      Top = 86
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = #1060#1072#1084#1080#1083#1080#1103
    end
    object Label6: TLabel
      Left = 9
      Top = 113
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = #1048#1084#1103
    end
    object Label7: TLabel
      Left = 9
      Top = 140
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = #1054#1090#1095#1077#1089#1090#1074#1086
    end
    object Label9: TLabel
      Left = 9
      Top = 167
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = #1058#1077#1083#1077#1092#1086#1085
    end
    object lBlock: TLabel
      Left = 9
      Top = 61
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = #1041#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100
    end
    object Label14: TLabel
      Left = 9
      Top = 194
      Width = 121
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Email'
    end
    object dbeLogin: TDBEdit
      Left = 136
      Top = 6
      Width = 241
      Height = 21
      DataField = #1051#1086#1075#1080#1085
      DataSource = dmData.dsUserInfo
      TabOrder = 0
    end
    object dbePassword: TDBEdit
      Left = 136
      Top = 33
      Width = 218
      Height = 21
      DataField = #1055#1072#1088#1086#1083#1100
      DataSource = dmData.dsUserInfo
      PasswordChar = '*'
      TabOrder = 1
    end
    object DBEdit5: TDBEdit
      Left = 136
      Top = 83
      Width = 241
      Height = 21
      DataField = #1060#1072#1084#1080#1083#1080#1103
      DataSource = dmData.dsUserInfo
      TabOrder = 3
    end
    object DBEdit6: TDBEdit
      Left = 136
      Top = 110
      Width = 241
      Height = 21
      DataField = #1048#1084#1103
      DataSource = dmData.dsUserInfo
      TabOrder = 4
    end
    object DBEdit7: TDBEdit
      Left = 136
      Top = 137
      Width = 241
      Height = 21
      DataField = #1054#1090#1095#1077#1089#1090#1074#1086
      DataSource = dmData.dsUserInfo
      TabOrder = 5
    end
    object DBEdit9: TDBEdit
      Left = 136
      Top = 164
      Width = 241
      Height = 21
      DataField = #1058#1077#1083#1077#1092#1086#1085
      DataSource = dmData.dsUserInfo
      TabOrder = 6
    end
    object dbcbBlock: TDBCheckBox
      Left = 136
      Top = 60
      Width = 18
      Height = 17
      DataField = #1041#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100'_'#1076#1086#1089#1090#1091#1087
      DataSource = dmData.dsUserInfo
      TabOrder = 2
      ValueChecked = 'True'
      ValueUnchecked = 'False'
    end
    object DBEdit10: TDBEdit
      Left = 136
      Top = 191
      Width = 241
      Height = 21
      DataField = 'Email'
      DataSource = dmData.dsUserInfo
      TabOrder = 7
    end
    object cbShowPassword: TCheckBox
      Left = 360
      Top = 35
      Width = 18
      Height = 17
      TabOrder = 8
      OnClick = cbShowPasswordClick
    end
  end
end
