object dmServer: TdmServer
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 295
  Width = 160
  object DSTCPServerTransport: TDSTCPServerTransport
    Port = 5000
    Server = DSServer
    BufferKBSize = 32
    Filters = <>
    AuthenticationManager = DSAuthenticationManager
    OnConnect = DSTCPServerTransportConnect
    OnDisconnect = DSTCPServerTransportDisconnect
    KeepAliveEnablement = kaDefault
    Left = 64
    Top = 168
  end
  object DSAuthenticationManager: TDSAuthenticationManager
    OnUserAuthenticate = DSAuthenticationManagerUserAuthenticate
    Roles = <>
    Left = 64
    Top = 216
  end
  object DSServer: TDSServer
    AutoStart = False
    HideDSAdmin = False
    Left = 64
    Top = 72
  end
  object DSServerClass: TDSServerClass
    OnGetClass = DSServerClassGetClass
    Server = DSServer
    LifeCycle = 'Session'
    Left = 64
    Top = 120
  end
  object adoConnection: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Projects\3781\'#1055#1088 +
      #1086#1077#1082#1090'\'#1057#1077#1088#1074#1077#1088'\Win32\Release\Base.mdb;Persist Security Info=False'
    KeepConnection = False
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 64
    Top = 24
  end
end
