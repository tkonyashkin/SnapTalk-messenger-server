#ifndef udssmRemoteDataClientH
#define udssmRemoteDataClientH

#include "DBXCommon.hpp"
#include "Classes.hpp"
#include "SysUtils.hpp"
#include "DB.hpp"
#include "SqlExpr.hpp"
#include "DBXDBReaders.hpp"

  class TdssmRemoteDataClient : public TObject
  {
  private:
    TDBXConnection *FDBXConnection;
    bool FInstanceOwner;
    TDBXCommand *FDSServerModuleCreateCommand;
    TDBXCommand *FqRequestBeforeOpenCommand;
    TDBXCommand *FqUserInfoBeforeOpenCommand;
    TDBXCommand *FqUserListBeforeOpenCommand;
    TDBXCommand *FqChatListBeforeOpenCommand;
    TDBXCommand *FqChatBeforeOpenCommand;
    TDBXCommand *FqChatParticipantsBeforeOpenCommand;
    TDBXCommand *FqChatMessagesBeforeOpenCommand;
    TDBXCommand *FqChatMessageReportBeforeOpenCommand;
    TDBXCommand *FGetDateTimeCommand;
    TDBXCommand *FGetUserTypeIDCommand;
    TDBXCommand *FGetUserIDCommand;
    TDBXCommand *FChatIDGetCommand;
    TDBXCommand *FChatIDSetCommand;
    TDBXCommand *FChatAddCommand;
    TDBXCommand *FChatEditCommand;
    TDBXCommand *FChatParticipantAddCommand;
    TDBXCommand *FChatParticipantDeleteCommand;
    TDBXCommand *FChatSendMessageCommand;
    TDBXCommand *FChatDeleteCommand;
    TDBXCommand *FChatReadAllCommand;
    TDBXCommand *FUserIsAdminCommand;
    TDBXCommand *FUserIsChatAdminCommand;
    TDBXCommand *FGetNewMessageCountCommand;
  public:
    __fastcall TdssmRemoteDataClient::TdssmRemoteDataClient(TDBXConnection *ADBXConnection);
    __fastcall TdssmRemoteDataClient::TdssmRemoteDataClient(TDBXConnection *ADBXConnection, bool AInstanceOwner);
    __fastcall TdssmRemoteDataClient::~TdssmRemoteDataClient();
    void __fastcall DSServerModuleCreate(TJSONObject* Sender);
    void __fastcall qRequestBeforeOpen(TDataSet* DataSet);
    void __fastcall qUserInfoBeforeOpen(TDataSet* DataSet);
    void __fastcall qUserListBeforeOpen(TDataSet* DataSet);
    void __fastcall qChatListBeforeOpen(TDataSet* DataSet);
    void __fastcall qChatBeforeOpen(TDataSet* DataSet);
    void __fastcall qChatParticipantsBeforeOpen(TDataSet* DataSet);
    void __fastcall qChatMessagesBeforeOpen(TDataSet* DataSet);
    void __fastcall qChatMessageReportBeforeOpen(TDataSet* DataSet);
    System::TDateTime __fastcall GetDateTime();
    int __fastcall GetUserTypeID();
    int __fastcall GetUserID();
    int __fastcall ChatIDGet();
    void __fastcall ChatIDSet(int ID);
    int __fastcall ChatAdd(System::UnicodeString title);
    void __fastcall ChatEdit(System::UnicodeString title);
    bool __fastcall ChatParticipantAdd(int UserID);
    bool __fastcall ChatParticipantDelete(int UserID);
    int __fastcall ChatSendMessage(System::UnicodeString Msg);
    void __fastcall ChatDelete();
    void __fastcall ChatReadAll();
    bool __fastcall UserIsAdmin();
    bool __fastcall UserIsChatAdmin();
    int __fastcall GetNewMessageCount();
  };

#endif

