// ---------------------------------------------------------------------------

#ifndef udssmRemoteDataH
#define udssmRemoteDataH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <DSServer.hpp>
#include "uConnectionList.h"
#include <Data.DB.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Data.Win.ADODB.hpp>
#include "udmServer.h"
#include <Math.hpp>
// ---------------------------------------------------------------------------
const int c_User_type_Admin_user = 1;
const int c_User_type_Dispatcher_user = 2;
const int c_User_type_Master_user = 3;

const UnicodeString c_Msg_Record_not_find = "Запись не найдена";
const UnicodeString c_Msg_Error_request_status = "Текущий статус заявки не позволяет выполнить смену статуса";

// ---------------------------------------------------------------------------
/*
 Серверный класс;
 Его проекцией могут пользоваться все подключаемые клиенты;
 От предоставляет клиентам данные и функции;
 */
// ---------------------------------------------------------------------------
class TdssmRemoteData : public TDSServerModule {
__published: // IDE-managed Components

	TADOTable *tUser;
	TDataSetProvider *dspUser;
	TDataSetProvider *dspUserInfo;
	TADOQuery *qUserInfo;
	TADOTable *tUserType;
	TDataSetProvider *dspUserType;
	TADOTable *tParams;
	TDataSetProvider *dspParams;
	TAutoIncField *tUserКод;
	TWideStringField *tUserФамилия;
	TWideStringField *tUserИмя;
	TWideStringField *tUserОтчество;
	TWideStringField *tUserТелефон;
	TIntegerField *tUserКод_Тип_пользователя;
	TWideStringField *tUserЛогин;
	TWideStringField *tUserПароль;
	TBooleanField *tUserБлокировать_доступ;
	TDateTimeField *tUserДата_регистрации;
	TWideStringField *tUserEmail;
	TDataSetProvider *dspUserList;
	TADOQuery *qUserList;
	TDataSetProvider *dspChatList;
	TADOQuery *qChatList;
	TDataSetProvider *dspChat;
	TADOQuery *qChat;
	TDataSetProvider *dspChatParticipantList;
	TADOQuery *qChatParticipants;
	TDataSetProvider *dspChatMessages;
	TADOQuery *qChatMessages;
	TDataSetProvider *dspChatMessageReport;
	TADOQuery *qChatMessageReport;
	TAutoIncField *qUserInfoКод;
	TDateTimeField *qUserInfoДата_регистрации;
	TWideStringField *qUserInfoФамилия;
	TWideStringField *qUserInfoИмя;
	TWideStringField *qUserInfoОтчество;
	TWideStringField *qUserInfoТелефон;
	TWideStringField *qUserInfoEmail;
	TIntegerField *qUserInfoКод_Тип_пользователя;
	TWideStringField *qUserInfoЛогин;
	TWideStringField *qUserInfoПароль;
	TBooleanField *qUserInfoБлокировать_доступ;
	TWideStringField *qUserInfoТип_пользователя;
	TWideStringField *qUserInfoПользователь;

	void __fastcall DSServerModuleCreate(TObject *Sender);
	void __fastcall qRequestBeforeOpen(TDataSet * DataSet);
	void __fastcall qUserInfoBeforeOpen(TDataSet *DataSet);
	void __fastcall qUserListBeforeOpen(TDataSet *DataSet);
	void __fastcall qChatListBeforeOpen(TDataSet *DataSet);
	void __fastcall qChatBeforeOpen(TDataSet *DataSet);
	void __fastcall qChatParticipantsBeforeOpen(TDataSet *DataSet);
	void __fastcall qChatMessagesBeforeOpen(TDataSet *DataSet);
	void __fastcall qChatMessageReportBeforeOpen(TDataSet *DataSet);

private: // User declarations

	int FUserID;
	int FUserTypeID;
	int FChatID;

	void __fastcall GetAccess(int UserTypeID);
	TADOQuery * __fastcall UserGet(int ID);
	TADOQuery * __fastcall ChatGet(int ID);
	TADOQuery * __fastcall ChatParticipants(int ChatID);
	void __fastcall AccessForChatAdminOnly();
	void __fastcall AccessForAdminOnly();

	void __fastcall ChatParticipantAdd(int ChatID, int UserID);

public: // User declarations

	__fastcall TdssmRemoteData(TComponent* Owner);
	/// <summary>
	///   Получить текущее время сервера
	/// </summary>
	TDateTime __fastcall GetDateTime();
	/// <summary>
	///   Получить тип пользователя
	/// </summary>
	int __fastcall GetUserTypeID();
	/// <summary>
	///   Получить идентификатор пользователя
	/// </summary>
	int __fastcall GetUserID();

	int __fastcall ChatIDGet();
	void __fastcall ChatIDSet(int ID);
	int __fastcall ChatAdd(UnicodeString title);
	void __fastcall ChatEdit(UnicodeString title);
	bool __fastcall ChatParticipantAdd(int UserID);
	bool __fastcall ChatParticipantDelete(int UserID);
	int __fastcall ChatSendMessage(UnicodeString Msg);
	void __fastcall ChatDelete();
	void __fastcall ChatReadAll();

	bool __fastcall UserIsAdmin();
	bool __fastcall UserIsChatAdmin();

	int __fastcall GetNewMessageCount();
};

// ---------------------------------------------------------------------------
extern PACKAGE TdssmRemoteData *dssmRemoteData;
// ---------------------------------------------------------------------------
#endif
