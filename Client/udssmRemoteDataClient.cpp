//
// Created by the DataSnap proxy generator.
// 05.04.2024 23:37:51
//

#include "udssmRemoteDataClient.h"

void __fastcall TdssmRemoteDataClient::DSServerModuleCreate(TJSONObject* Sender)
{
  if (FDSServerModuleCreateCommand == NULL)
  {
    FDSServerModuleCreateCommand = FDBXConnection->CreateCommand();
    FDSServerModuleCreateCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FDSServerModuleCreateCommand->Text = "TdssmRemoteData.DSServerModuleCreate";
    FDSServerModuleCreateCommand->Prepare();
  }
  FDSServerModuleCreateCommand->Parameters->Parameter[0]->Value->SetJSONValue(Sender, FInstanceOwner);
  FDSServerModuleCreateCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qRequestBeforeOpen(TDataSet* DataSet)
{
  if (FqRequestBeforeOpenCommand == NULL)
  {
    FqRequestBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqRequestBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqRequestBeforeOpenCommand->Text = "TdssmRemoteData.qRequestBeforeOpen";
    FqRequestBeforeOpenCommand->Prepare();
  }
  FqRequestBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqRequestBeforeOpenCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qUserInfoBeforeOpen(TDataSet* DataSet)
{
  if (FqUserInfoBeforeOpenCommand == NULL)
  {
    FqUserInfoBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqUserInfoBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqUserInfoBeforeOpenCommand->Text = "TdssmRemoteData.qUserInfoBeforeOpen";
    FqUserInfoBeforeOpenCommand->Prepare();
  }
  FqUserInfoBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqUserInfoBeforeOpenCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qUserListBeforeOpen(TDataSet* DataSet)
{
  if (FqUserListBeforeOpenCommand == NULL)
  {
    FqUserListBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqUserListBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqUserListBeforeOpenCommand->Text = "TdssmRemoteData.qUserListBeforeOpen";
    FqUserListBeforeOpenCommand->Prepare();
  }
  FqUserListBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqUserListBeforeOpenCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qChatListBeforeOpen(TDataSet* DataSet)
{
  if (FqChatListBeforeOpenCommand == NULL)
  {
    FqChatListBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqChatListBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqChatListBeforeOpenCommand->Text = "TdssmRemoteData.qChatListBeforeOpen";
    FqChatListBeforeOpenCommand->Prepare();
  }
  FqChatListBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqChatListBeforeOpenCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qChatBeforeOpen(TDataSet* DataSet)
{
  if (FqChatBeforeOpenCommand == NULL)
  {
    FqChatBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqChatBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqChatBeforeOpenCommand->Text = "TdssmRemoteData.qChatBeforeOpen";
    FqChatBeforeOpenCommand->Prepare();
  }
  FqChatBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqChatBeforeOpenCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qChatParticipantsBeforeOpen(TDataSet* DataSet)
{
  if (FqChatParticipantsBeforeOpenCommand == NULL)
  {
    FqChatParticipantsBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqChatParticipantsBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqChatParticipantsBeforeOpenCommand->Text = "TdssmRemoteData.qChatParticipantsBeforeOpen";
    FqChatParticipantsBeforeOpenCommand->Prepare();
  }
  FqChatParticipantsBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqChatParticipantsBeforeOpenCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qChatMessagesBeforeOpen(TDataSet* DataSet)
{
  if (FqChatMessagesBeforeOpenCommand == NULL)
  {
    FqChatMessagesBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqChatMessagesBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqChatMessagesBeforeOpenCommand->Text = "TdssmRemoteData.qChatMessagesBeforeOpen";
    FqChatMessagesBeforeOpenCommand->Prepare();
  }
  FqChatMessagesBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqChatMessagesBeforeOpenCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::qChatMessageReportBeforeOpen(TDataSet* DataSet)
{
  if (FqChatMessageReportBeforeOpenCommand == NULL)
  {
    FqChatMessageReportBeforeOpenCommand = FDBXConnection->CreateCommand();
    FqChatMessageReportBeforeOpenCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FqChatMessageReportBeforeOpenCommand->Text = "TdssmRemoteData.qChatMessageReportBeforeOpen";
    FqChatMessageReportBeforeOpenCommand->Prepare();
  }
  FqChatMessageReportBeforeOpenCommand->Parameters->Parameter[0]->Value->SetDBXReader(new TDBXDataSetReader(DataSet, FInstanceOwner), True);
  FqChatMessageReportBeforeOpenCommand->ExecuteUpdate();
}

System::TDateTime __fastcall TdssmRemoteDataClient::GetDateTime()
{
  if (FGetDateTimeCommand == NULL)
  {
    FGetDateTimeCommand = FDBXConnection->CreateCommand();
    FGetDateTimeCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FGetDateTimeCommand->Text = "TdssmRemoteData.GetDateTime";
    FGetDateTimeCommand->Prepare();
  }
  FGetDateTimeCommand->ExecuteUpdate();
  System::TDateTime result = FGetDateTimeCommand->Parameters->Parameter[0]->Value->AsDateTime;
  return result;
}

int __fastcall TdssmRemoteDataClient::GetUserTypeID()
{
  if (FGetUserTypeIDCommand == NULL)
  {
    FGetUserTypeIDCommand = FDBXConnection->CreateCommand();
    FGetUserTypeIDCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FGetUserTypeIDCommand->Text = "TdssmRemoteData.GetUserTypeID";
    FGetUserTypeIDCommand->Prepare();
  }
  FGetUserTypeIDCommand->ExecuteUpdate();
  int result = FGetUserTypeIDCommand->Parameters->Parameter[0]->Value->GetInt32();
  return result;
}

int __fastcall TdssmRemoteDataClient::GetUserID()
{
  if (FGetUserIDCommand == NULL)
  {
    FGetUserIDCommand = FDBXConnection->CreateCommand();
    FGetUserIDCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FGetUserIDCommand->Text = "TdssmRemoteData.GetUserID";
    FGetUserIDCommand->Prepare();
  }
  FGetUserIDCommand->ExecuteUpdate();
  int result = FGetUserIDCommand->Parameters->Parameter[0]->Value->GetInt32();
  return result;
}

int __fastcall TdssmRemoteDataClient::ChatIDGet()
{
  if (FChatIDGetCommand == NULL)
  {
    FChatIDGetCommand = FDBXConnection->CreateCommand();
    FChatIDGetCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatIDGetCommand->Text = "TdssmRemoteData.ChatIDGet";
    FChatIDGetCommand->Prepare();
  }
  FChatIDGetCommand->ExecuteUpdate();
  int result = FChatIDGetCommand->Parameters->Parameter[0]->Value->GetInt32();
  return result;
}

void __fastcall TdssmRemoteDataClient::ChatIDSet(int ID)
{
  if (FChatIDSetCommand == NULL)
  {
    FChatIDSetCommand = FDBXConnection->CreateCommand();
    FChatIDSetCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatIDSetCommand->Text = "TdssmRemoteData.ChatIDSet";
    FChatIDSetCommand->Prepare();
  }
  FChatIDSetCommand->Parameters->Parameter[0]->Value->SetInt32(ID);
  FChatIDSetCommand->ExecuteUpdate();
}

int __fastcall TdssmRemoteDataClient::ChatAdd(System::UnicodeString title)
{
  if (FChatAddCommand == NULL)
  {
    FChatAddCommand = FDBXConnection->CreateCommand();
    FChatAddCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatAddCommand->Text = "TdssmRemoteData.ChatAdd";
    FChatAddCommand->Prepare();
  }
  FChatAddCommand->Parameters->Parameter[0]->Value->SetWideString(title);
  FChatAddCommand->ExecuteUpdate();
  int result = FChatAddCommand->Parameters->Parameter[1]->Value->GetInt32();
  return result;
}

void __fastcall TdssmRemoteDataClient::ChatEdit(System::UnicodeString title)
{
  if (FChatEditCommand == NULL)
  {
    FChatEditCommand = FDBXConnection->CreateCommand();
    FChatEditCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatEditCommand->Text = "TdssmRemoteData.ChatEdit";
    FChatEditCommand->Prepare();
  }
  FChatEditCommand->Parameters->Parameter[0]->Value->SetWideString(title);
  FChatEditCommand->ExecuteUpdate();
}

bool __fastcall TdssmRemoteDataClient::ChatParticipantAdd(int UserID)
{
  if (FChatParticipantAddCommand == NULL)
  {
    FChatParticipantAddCommand = FDBXConnection->CreateCommand();
    FChatParticipantAddCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatParticipantAddCommand->Text = "TdssmRemoteData.ChatParticipantAdd";
    FChatParticipantAddCommand->Prepare();
  }
  FChatParticipantAddCommand->Parameters->Parameter[0]->Value->SetInt32(UserID);
  FChatParticipantAddCommand->ExecuteUpdate();
  bool result = FChatParticipantAddCommand->Parameters->Parameter[1]->Value->GetBoolean();
  return result;
}

bool __fastcall TdssmRemoteDataClient::ChatParticipantDelete(int UserID)
{
  if (FChatParticipantDeleteCommand == NULL)
  {
    FChatParticipantDeleteCommand = FDBXConnection->CreateCommand();
    FChatParticipantDeleteCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatParticipantDeleteCommand->Text = "TdssmRemoteData.ChatParticipantDelete";
    FChatParticipantDeleteCommand->Prepare();
  }
  FChatParticipantDeleteCommand->Parameters->Parameter[0]->Value->SetInt32(UserID);
  FChatParticipantDeleteCommand->ExecuteUpdate();
  bool result = FChatParticipantDeleteCommand->Parameters->Parameter[1]->Value->GetBoolean();
  return result;
}

int __fastcall TdssmRemoteDataClient::ChatSendMessage(System::UnicodeString Msg)
{
  if (FChatSendMessageCommand == NULL)
  {
    FChatSendMessageCommand = FDBXConnection->CreateCommand();
    FChatSendMessageCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatSendMessageCommand->Text = "TdssmRemoteData.ChatSendMessage";
    FChatSendMessageCommand->Prepare();
  }
  FChatSendMessageCommand->Parameters->Parameter[0]->Value->SetWideString(Msg);
  FChatSendMessageCommand->ExecuteUpdate();
  int result = FChatSendMessageCommand->Parameters->Parameter[1]->Value->GetInt32();
  return result;
}

void __fastcall TdssmRemoteDataClient::ChatDelete()
{
  if (FChatDeleteCommand == NULL)
  {
    FChatDeleteCommand = FDBXConnection->CreateCommand();
    FChatDeleteCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatDeleteCommand->Text = "TdssmRemoteData.ChatDelete";
    FChatDeleteCommand->Prepare();
  }
  FChatDeleteCommand->ExecuteUpdate();
}

void __fastcall TdssmRemoteDataClient::ChatReadAll()
{
  if (FChatReadAllCommand == NULL)
  {
    FChatReadAllCommand = FDBXConnection->CreateCommand();
    FChatReadAllCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FChatReadAllCommand->Text = "TdssmRemoteData.ChatReadAll";
    FChatReadAllCommand->Prepare();
  }
  FChatReadAllCommand->ExecuteUpdate();
}

bool __fastcall TdssmRemoteDataClient::UserIsAdmin()
{
  if (FUserIsAdminCommand == NULL)
  {
    FUserIsAdminCommand = FDBXConnection->CreateCommand();
    FUserIsAdminCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FUserIsAdminCommand->Text = "TdssmRemoteData.UserIsAdmin";
    FUserIsAdminCommand->Prepare();
  }
  FUserIsAdminCommand->ExecuteUpdate();
  bool result = FUserIsAdminCommand->Parameters->Parameter[0]->Value->GetBoolean();
  return result;
}

bool __fastcall TdssmRemoteDataClient::UserIsChatAdmin()
{
  if (FUserIsChatAdminCommand == NULL)
  {
    FUserIsChatAdminCommand = FDBXConnection->CreateCommand();
    FUserIsChatAdminCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FUserIsChatAdminCommand->Text = "TdssmRemoteData.UserIsChatAdmin";
    FUserIsChatAdminCommand->Prepare();
  }
  FUserIsChatAdminCommand->ExecuteUpdate();
  bool result = FUserIsChatAdminCommand->Parameters->Parameter[0]->Value->GetBoolean();
  return result;
}

int __fastcall TdssmRemoteDataClient::GetNewMessageCount()
{
  if (FGetNewMessageCountCommand == NULL)
  {
    FGetNewMessageCountCommand = FDBXConnection->CreateCommand();
    FGetNewMessageCountCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FGetNewMessageCountCommand->Text = "TdssmRemoteData.GetNewMessageCount";
    FGetNewMessageCountCommand->Prepare();
  }
  FGetNewMessageCountCommand->ExecuteUpdate();
  int result = FGetNewMessageCountCommand->Parameters->Parameter[0]->Value->GetInt32();
  return result;
}


__fastcall  TdssmRemoteDataClient::TdssmRemoteDataClient(TDBXConnection *ADBXConnection)
{
  if (ADBXConnection == NULL)
    throw EInvalidOperation("Connection cannot be nil.  Make sure the connection has been opened.");
  FDBXConnection = ADBXConnection;
  FInstanceOwner = True;
}


__fastcall  TdssmRemoteDataClient::TdssmRemoteDataClient(TDBXConnection *ADBXConnection, bool AInstanceOwner)
{
  if (ADBXConnection == NULL)
    throw EInvalidOperation("Connection cannot be nil.  Make sure the connection has been opened.");
  FDBXConnection = ADBXConnection;
  FInstanceOwner = AInstanceOwner;
}


__fastcall  TdssmRemoteDataClient::~TdssmRemoteDataClient()
{
  delete FDSServerModuleCreateCommand;
  delete FqRequestBeforeOpenCommand;
  delete FqUserInfoBeforeOpenCommand;
  delete FqUserListBeforeOpenCommand;
  delete FqChatListBeforeOpenCommand;
  delete FqChatBeforeOpenCommand;
  delete FqChatParticipantsBeforeOpenCommand;
  delete FqChatMessagesBeforeOpenCommand;
  delete FqChatMessageReportBeforeOpenCommand;
  delete FGetDateTimeCommand;
  delete FGetUserTypeIDCommand;
  delete FGetUserIDCommand;
  delete FChatIDGetCommand;
  delete FChatIDSetCommand;
  delete FChatAddCommand;
  delete FChatEditCommand;
  delete FChatParticipantAddCommand;
  delete FChatParticipantDeleteCommand;
  delete FChatSendMessageCommand;
  delete FChatDeleteCommand;
  delete FChatReadAllCommand;
  delete FUserIsAdminCommand;
  delete FUserIsChatAdminCommand;
  delete FGetNewMessageCountCommand;
}


