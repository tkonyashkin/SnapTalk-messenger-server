object dssmRemoteData: TdssmRemoteData
  OldCreateOrder = False
  OnCreate = DSServerModuleCreate
  Height = 756
  Width = 947
  object tUser: TADOTable
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    TableName = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
    Left = 96
    Top = 64
    object tUserКод: TAutoIncField
      FieldName = #1050#1086#1076
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      ReadOnly = True
    end
    object tUserФамилия: TWideStringField
      FieldName = #1060#1072#1084#1080#1083#1080#1103
      Size = 255
    end
    object tUserИмя: TWideStringField
      FieldName = #1048#1084#1103
      Size = 255
    end
    object tUserОтчество: TWideStringField
      FieldName = #1054#1090#1095#1077#1089#1090#1074#1086
      Size = 255
    end
    object tUserТелефон: TWideStringField
      FieldName = #1058#1077#1083#1077#1092#1086#1085
      Size = 255
    end
    object tUserКод_Тип_пользователя: TIntegerField
      FieldName = #1050#1086#1076'_'#1058#1080#1087'_'#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    end
    object tUserЛогин: TWideStringField
      FieldName = #1051#1086#1075#1080#1085
      Size = 255
    end
    object tUserПароль: TWideStringField
      FieldName = #1055#1072#1088#1086#1083#1100
      Size = 255
    end
    object tUserБлокировать_доступ: TBooleanField
      FieldName = #1041#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100'_'#1076#1086#1089#1090#1091#1087
    end
    object tUserДата_регистрации: TDateTimeField
      FieldName = #1044#1072#1090#1072'_'#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080
    end
    object tUserEmail: TWideStringField
      FieldName = 'Email'
      Size = 255
    end
  end
  object dspUser: TDataSetProvider
    DataSet = tUser
    ResolveToDataSet = True
    Exported = False
    UpdateMode = upWhereKeyOnly
    Left = 232
    Top = 64
  end
  object dspUserInfo: TDataSetProvider
    DataSet = qUserInfo
    ResolveToDataSet = True
    Options = [poDisableInserts, poDisableDeletes, poUseQuoteChar]
    UpdateMode = upWhereKeyOnly
    Left = 232
    Top = 16
  end
  object qUserInfo: TADOQuery
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    BeforeOpen = qUserInfoBeforeOpen
    Parameters = <>
    SQL.Strings = (
      'select * from '#1047#1072#1087#1088#1086#1089'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100)
    Left = 96
    Top = 16
    object qUserInfoКод: TAutoIncField
      FieldName = #1050#1086#1076
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      ReadOnly = True
    end
    object qUserInfoДата_регистрации: TDateTimeField
      FieldName = #1044#1072#1090#1072'_'#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080
      ReadOnly = True
    end
    object qUserInfoФамилия: TWideStringField
      FieldName = #1060#1072#1084#1080#1083#1080#1103
      Size = 255
    end
    object qUserInfoИмя: TWideStringField
      FieldName = #1048#1084#1103
      Size = 255
    end
    object qUserInfoОтчество: TWideStringField
      FieldName = #1054#1090#1095#1077#1089#1090#1074#1086
      Size = 255
    end
    object qUserInfoТелефон: TWideStringField
      FieldName = #1058#1077#1083#1077#1092#1086#1085
      Size = 255
    end
    object qUserInfoEmail: TWideStringField
      FieldName = 'Email'
      Size = 255
    end
    object qUserInfoКод_Тип_пользователя: TIntegerField
      FieldName = #1050#1086#1076'_'#1058#1080#1087'_'#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
      ReadOnly = True
    end
    object qUserInfoЛогин: TWideStringField
      FieldName = #1051#1086#1075#1080#1085
      Size = 255
    end
    object qUserInfoПароль: TWideStringField
      FieldName = #1055#1072#1088#1086#1083#1100
      Size = 255
    end
    object qUserInfoБлокировать_доступ: TBooleanField
      FieldName = #1041#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100'_'#1076#1086#1089#1090#1091#1087
    end
    object qUserInfoТип_пользователя: TWideStringField
      FieldName = #1058#1080#1087'_'#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
      ReadOnly = True
      Size = 255
    end
    object qUserInfoПользователь: TWideStringField
      FieldName = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
      ReadOnly = True
      Size = 255
    end
  end
  object tUserType: TADOTable
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    TableName = #1058#1080#1087'_'#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    Left = 96
    Top = 112
  end
  object dspUserType: TDataSetProvider
    DataSet = tUserType
    Options = [poReadOnly, poUseQuoteChar]
    Left = 232
    Top = 112
  end
  object tParams: TADOTable
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    TableName = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    Left = 96
    Top = 160
  end
  object dspParams: TDataSetProvider
    DataSet = tParams
    ResolveToDataSet = True
    Options = [poReadOnly, poUseQuoteChar]
    Left = 232
    Top = 160
  end
  object dspUserList: TDataSetProvider
    DataSet = qUserList
    Options = [poReadOnly, poUseQuoteChar]
    Left = 232
    Top = 208
  end
  object qUserList: TADOQuery
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    BeforeOpen = qUserListBeforeOpen
    Parameters = <>
    SQL.Strings = (
      'select * from '#1047#1072#1087#1088#1086#1089'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100)
    Left = 96
    Top = 208
  end
  object dspChatList: TDataSetProvider
    DataSet = qChatList
    Options = [poReadOnly, poUseQuoteChar]
    Left = 568
    Top = 16
  end
  object qChatList: TADOQuery
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    BeforeOpen = qChatListBeforeOpen
    Parameters = <
      item
        Name = 'UserID_1'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'UserID_2'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end
      item
        Name = 'UserID_3'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'SELECT'
      ''
      #1041#1077#1089#1077#1076#1072'.'#1050#1086#1076','
      #1041#1077#1089#1077#1076#1072'.'#1044#1072#1090#1072'_'#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080','
      #1041#1077#1089#1077#1076#1072'.'#1053#1072#1079#1074#1072#1085#1080#1077','
      #1041#1077#1089#1077#1076#1072'.'#1050#1086#1076'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100','
      #1047#1072#1087#1088#1086#1089'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100'.'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100','
      #1047#1072#1087#1088#1086#1089'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100'.'#1051#1086#1075#1080#1085','
      ''
      
        '(select count(*) from '#1059#1095#1072#1089#1090#1085#1080#1082'_'#1073#1077#1089#1077#1076#1099' where '#1041#1077#1089#1077#1076#1072'.'#1050#1086#1076' = '#1059#1095#1072#1089#1090#1085#1080 +
        #1082'_'#1073#1077#1089#1077#1076#1099'.'#1050#1086#1076'_'#1041#1077#1089#1077#1076#1072') AS '#1050#1086#1083#1080#1095#1077#1089#1090#1074#1086'_'#1091#1095#1072#1089#1090#1085#1080#1082#1086#1074','
      
        '(select count(*) from '#1057#1086#1086#1073#1097#1077#1085#1080#1077' where '#1041#1077#1089#1077#1076#1072'.'#1050#1086#1076' = '#1057#1086#1086#1073#1097#1077#1085#1080#1077'.'#1050#1086#1076 +
        '_'#1041#1077#1089#1077#1076#1072') AS '#1050#1086#1083#1080#1095#1077#1089#1090#1074#1086'_'#1089#1086#1086#1073#1097#1077#1085#1080#1081','
      
        '(select count(*) FROM '#1057#1086#1086#1073#1097#1077#1085#1080#1077' INNER JOIN '#1055#1088#1086#1095#1090#1077#1085#1080#1077' ON '#1057#1086#1086#1073#1097#1077#1085#1080 +
        #1077'.'#1050#1086#1076' = '#1055#1088#1086#1095#1090#1077#1085#1080#1077'.'#1050#1086#1076'_'#1057#1086#1086#1073#1097#1077#1085#1080#1077
      
        'WHERE '#1055#1088#1086#1095#1090#1077#1085#1080#1077'.'#1050#1086#1076'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100' = :UserID_1 and '#1055#1088#1086#1095#1090#1077#1085#1080#1077'.'#1055#1088#1086#1095#1080 +
        #1090#1072#1085#1086' = False) AS '#1050#1086#1083#1080#1095#1077#1089#1090#1074#1086'_'#1085#1086#1074#1099#1093'_'#1089#1086#1086#1073#1097#1077#1085#1080#1081
      ''
      
        'FROM '#1047#1072#1087#1088#1086#1089'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100' RIGHT JOIN '#1041#1077#1089#1077#1076#1072' ON '#1047#1072#1087#1088#1086#1089'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083 +
        #1100'.'#1050#1086#1076'='#1041#1077#1089#1077#1076#1072'.'#1050#1086#1076'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
      ''
      'WHERE'
      '(('#1041#1077#1089#1077#1076#1072'.'#1050#1086#1076'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100' = :UserID_2) or'
      
        'exists(select * from '#1059#1095#1072#1089#1090#1085#1080#1082'_'#1073#1077#1089#1077#1076#1099' where '#1041#1077#1089#1077#1076#1072'.'#1050#1086#1076' = '#1059#1095#1072#1089#1090#1085#1080#1082 +
        '_'#1073#1077#1089#1077#1076#1099'.'#1050#1086#1076'_'#1041#1077#1089#1077#1076#1072' and '#1059#1095#1072#1089#1090#1085#1080#1082'_'#1073#1077#1089#1077#1076#1099'.'#1050#1086#1076'_'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100' = :UserI' +
        'D_3))')
    Left = 432
    Top = 16
  end
  object dspChat: TDataSetProvider
    DataSet = qChat
    Options = [poReadOnly, poUseQuoteChar]
    Left = 568
    Top = 64
  end
  object qChat: TADOQuery
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    BeforeOpen = qChatBeforeOpen
    Parameters = <
      item
        Name = 'ChatID'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'select * '
      'from '#1041#1077#1089#1077#1076#1072
      'where '#1050#1086#1076' = :ChatID')
    Left = 432
    Top = 64
  end
  object dspChatParticipantList: TDataSetProvider
    DataSet = qChatParticipants
    Options = [poReadOnly, poUseQuoteChar]
    Left = 568
    Top = 112
  end
  object qChatParticipants: TADOQuery
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    BeforeOpen = qChatParticipantsBeforeOpen
    Parameters = <
      item
        Name = 'ChatID'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'select * '
      'from '#1047#1072#1087#1088#1086#1089'_'#1059#1095#1072#1089#1090#1085#1080#1082'_'#1073#1077#1089#1077#1076#1099
      'where '#1050#1086#1076'_'#1041#1077#1089#1077#1076#1072' = :ChatID')
    Left = 432
    Top = 112
  end
  object dspChatMessages: TDataSetProvider
    DataSet = qChatMessages
    Options = [poReadOnly, poUseQuoteChar]
    Left = 568
    Top = 160
  end
  object qChatMessages: TADOQuery
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    BeforeOpen = qChatMessagesBeforeOpen
    Parameters = <
      item
        Name = 'ChatID'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'select * '
      'from '#1047#1072#1087#1088#1086#1089'_'#1057#1086#1086#1073#1097#1077#1085#1080#1077
      'where '#1050#1086#1076'_'#1041#1077#1089#1077#1076#1072' = :ChatID')
    Left = 432
    Top = 160
  end
  object dspChatMessageReport: TDataSetProvider
    DataSet = qChatMessageReport
    Options = [poReadOnly, poUseQuoteChar]
    Left = 568
    Top = 208
  end
  object qChatMessageReport: TADOQuery
    Connection = dmServer.adoConnection
    CursorType = ctStatic
    BeforeOpen = qChatMessageReportBeforeOpen
    Parameters = <
      item
        Name = 'ChatID'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'select * '
      'from '#1047#1072#1087#1088#1086#1089'_'#1055#1088#1086#1095#1090#1077#1085#1080#1077
      'where '#1050#1086#1076'_'#1041#1077#1089#1077#1076#1072' = :ChatID')
    Left = 432
    Top = 208
  end
end
