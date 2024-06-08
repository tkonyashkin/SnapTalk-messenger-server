// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "udssmRemoteData.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"

// ---------------------------------------------------------------------------
__fastcall TdssmRemoteData::TdssmRemoteData(TComponent* Owner) : TDSServerModule(Owner) {
}

// ----------------------------------------------------------------------------
// Функция перевода типа DateTime в MS Access DateTime
UnicodeString __fastcall DateToAccessDate(TDateTime Value) {
	//
	UnicodeString Date = "";
	Date = "#" + FormatDateTime("MM", Value) + "/" + FormatDateTime("DD", Value) + "/" + FormatDateTime("YYYY",
		Value) + " #";
	return Date;
}

// ---------------------------------------------------------------------------
double ffabs(double X) {
	//
	if ((X < 0))
		X = X * (-1);
	return X;
}

// ---------------------------------------------------------------------------
UnicodeString QtoP(UnicodeString S) {
	//
	UnicodeString Result = S;
	for (int I = 1; I <= Result.Length(); I++) {
		if (Result[I] == ',')
			Result[I] = '.';
	}
	return Result;
}

// ---------------------------------------------------------------------------
TADOQuery * __fastcall TdssmRemoteData::UserGet(int ID) {
	//
	UnicodeString F = "";

	if ((F != ""))
		F = F + " and ";
	F = F + "Код = " + IntToStr(ID);

	if ((F != ""))
		F = " where " + F;
	return dmServer->GetQuery("select * from Пользователь" + F);
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::GetAccess(int UserTypeID) {
	//
	if (UserTypeID == c_User_type_Admin_user) {
		//
		dspUser->Exported = true;
		// dspServise->Options = dspServise->Options >> poReadOnly;
		// dspServiceType->Options = dspServiceType->Options >> poReadOnly;
		// dspRequestState->Options = dspRequestState->Options >> poReadOnly;
		// dspClient->Options = dspClient->Options >> poReadOnly;
		dspParams->Options = dspParams->Options >> poReadOnly;
	}

	if (UserTypeID == c_User_type_Dispatcher_user) {
		//
		// dspClient->Options = dspClient->Options >> poReadOnly;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TdssmRemoteData::qRequestBeforeOpen(TDataSet * DataSet) {
	//
	/*
	 UnicodeString F = RequestAccessSQLFilter();

	 TADOQuery *Q = UserGet(FUserID);
	 try
	 {
	 //
	 if (Q->FieldByName("Фильтр_Дата_1")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Дата >= " + DateToAccessDate(Q->FieldByName("Фильтр_Дата_1")->AsDateTime);

	 }
	 if (Q->FieldByName("Фильтр_Дата_2")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Дата < " + DateToAccessDate(Q->FieldByName("Фильтр_Дата_2")->AsDateTime + 1);

	 }

	 if (Q->FieldByName("Фильтр_Код_Статус")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Код_Статус = " + IntToStr(Q->FieldByName("Фильтр_Код_Статус")->AsInteger);
	 }

	 if (Q->FieldByName("Фильтр_Код_Клиент")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Код_Клиент = " + IntToStr(Q->FieldByName("Фильтр_Код_Клиент")->AsInteger);
	 }

	 if (Q->FieldByName("Фильтр_Код_Услуга")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Код_Услуга = " + IntToStr(Q->FieldByName("Фильтр_Код_Услуга")->AsInteger);
	 }

	 if (Q->FieldByName("Фильтр_Код_Диспетчер")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Код_Пользователь = " + IntToStr(Q->FieldByName("Фильтр_Код_Диспетчер")->AsInteger);
	 }

	 if (Q->FieldByName("Фильтр_Код_Исполнитель")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Код_Исполнитель = " + IntToStr(Q->FieldByName("Фильтр_Код_Исполнитель")->AsInteger);
	 }

	 if (Q->FieldByName("Фильтр_Код_Клиент")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "Код_Клиент = " + IntToStr(Q->FieldByName("Фильтр_Код_Клиент")->AsInteger);
	 }

	 Q->Free();
	 }
	 catch (...)
	 {
	 //
	 Q->Free();
	 }


	 if ((F != ""))
	 {
	 F = "(" + F + ") or ";
	 F = F + "(Код = " + IntToStr (FRequestID) + ")";
	 }

	 if ( (F != "") )
	 {
	 F = " where (" + F + ") ";
	 }

	 ((TADOQuery*)DataSet)->SQL->Clear();
	 ((TADOQuery*)DataSet)->SQL->Add ("select * from Заявка" + F);
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::AccessForAdminOnly() {
	//
	if (FUserTypeID != c_User_type_Admin_user)
		throw new Exception("Доступно только администратору");
}

// ---------------------------------------------------------------------------
int __fastcall TdssmRemoteData::GetUserID() {
	return FUserID;
}

// ---------------------------------------------------------------------------
int __fastcall TdssmRemoteData::GetUserTypeID() {
	//
	return FUserTypeID;
}

// ---------------------------------------------------------------------------
TDateTime __fastcall TdssmRemoteData::GetDateTime() {
	//
	return Now();
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::DSServerModuleCreate(TObject *Sender) {
	//
	FUserID = dmServer->ConnectionList->GetConnectionKey(GetCurrentThreadId())->UserKey;
	FUserTypeID = dmServer->ConnectionList->GetConnectionKey(GetCurrentThreadId())->UserTypeKey;
	GetAccess(FUserTypeID);
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::qUserInfoBeforeOpen(TDataSet *DataSet) {
	((TADOQuery*)DataSet)->SQL->Clear();
	((TADOQuery*)DataSet)->SQL->Add("select * from Запрос_Пользователь where Код = " + IntToStr(FUserID));
}
// ---------------------------------------------------------------------------

void __fastcall TdssmRemoteData::qUserListBeforeOpen(TDataSet *DataSet) {
	((TADOQuery*)DataSet)->SQL->Clear();
	((TADOQuery*)DataSet)->SQL->Add("select * from Запрос_Пользователь");
}

// ---------------------------------------------------------------------------

TADOQuery * __fastcall TdssmRemoteData::ChatGet(int ID) {
	TADOQuery *Q = dmServer->GetQuery("select * from Беседа where Код = " + IntToStr(ID));
	try {
		if (Q->RecordCount == 0) {
			throw new Exception(c_Msg_Record_not_find);
		}
		return Q;
	}
	catch (...) {
		Q->Free();
		throw;
	}
}

// ---------------------------------------------------------------------------
int __fastcall TdssmRemoteData::ChatAdd(UnicodeString title) {
	TADOQuery *Q = dmServer->GetQuery("select * from Беседа where Код = 0");
	try {
		Q->Insert();
		Q->FieldByName("Дата_регистрации")->AsDateTime = GetDateTime();
		Q->FieldByName("Код_Пользователь")->AsInteger = FUserID;
		Q->FieldByName("Название")->AsString = title;
		Q->Post();
		ChatParticipantAdd(Q->FieldByName("Код")->AsInteger, FUserID);
		return Q->FieldByName("Код")->AsInteger;
	}
	catch (...) {
		Q->Free();
		throw;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::ChatEdit(UnicodeString title) {
	AccessForChatAdminOnly();
	TADOQuery *Q = ChatGet(FChatID);
	try {
		Q->Edit();
		Q->FieldByName("Название")->AsString = title;
		Q->Post();
	}
	__finally {
		Q->Free();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::ChatDelete() {
	AccessForChatAdminOnly();
	TADOQuery *Q = ChatGet(FChatID);
	try {
		Q->Delete();
	}
	__finally {
		Q->Free();
	}
}

// ---------------------------------------------------------------------------
int __fastcall TdssmRemoteData::ChatIDGet() {
	return FChatID;
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::ChatIDSet(int ID) {
	FChatID = ID;
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::ChatParticipantAdd(int ChatID, int UserID) {
	TADOQuery *Q = ChatGet(ChatID);
	try {
		TADOQuery *P = dmServer->GetQuery("select * from Участник_беседы where Код_Беседа = " + IntToStr(ChatID) +
			" and Код_Пользователь = " + IntToStr(UserID));
		try {
			if (P->RecordCount == 0) {
				P->Insert();
				P->FieldByName("Код_Беседа")->AsInteger = ChatID;
				P->FieldByName("Код_Пользователь")->AsInteger = UserID;
				P->Post();
			}
		}
		__finally {
			P->Free();
		}
	}
	__finally {
		Q->Free();
	}
}

// ---------------------------------------------------------------------------
bool __fastcall TdssmRemoteData::ChatParticipantAdd(int UserID) {
	AccessForChatAdminOnly();
	ChatParticipantAdd (FChatID, UserID);
}

// ---------------------------------------------------------------------------
bool __fastcall TdssmRemoteData::ChatParticipantDelete(int UserID) {
	AccessForChatAdminOnly();

	TADOQuery *Q = ChatGet(FChatID);
	try {
		if (UserID == Q->FieldByName("Код_Пользователь")->AsInteger) {
			throw new Exception("Нельзя удалить создателя беседы");
		}

		TADOQuery *P = dmServer->GetQuery("select * from Участник_беседы where Код_Беседа = " + IntToStr(FChatID) +
			" and Код_Пользователь = " + IntToStr(UserID));
		try {
			if (P->RecordCount > 0) {
				P->Delete();
			}
		}
		__finally {
			P->Free();
		}
	}
	__finally {
		Q->Free();
	}
}

// ---------------------------------------------------------------------------
TADOQuery * __fastcall TdssmRemoteData::ChatParticipants(int ChatID) {
	return dmServer->GetQuery("select * from Участник_беседы where Код_Беседа = " + IntToStr(ChatID));
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::qChatListBeforeOpen(TDataSet *DataSet) {
	//
	TADOQuery *Q = (TADOQuery*)DataSet;
	Q->Parameters->ParamByName("UserID_1")->Value = FUserID;
	Q->Parameters->ParamByName("UserID_2")->Value = FUserID;
	Q->Parameters->ParamByName("UserID_3")->Value = FUserID;
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::qChatBeforeOpen(TDataSet *DataSet) {
	TADOQuery *Q = (TADOQuery*)DataSet;
	Q->Parameters->ParamByName("ChatID")->Value = FChatID;
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::qChatParticipantsBeforeOpen(TDataSet *DataSet) {
	TADOQuery *Q = (TADOQuery*)DataSet;
	Q->Parameters->ParamByName("ChatID")->Value = FChatID;
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::qChatMessagesBeforeOpen(TDataSet *DataSet) {
	TADOQuery *Q = (TADOQuery*)DataSet;
	Q->Parameters->ParamByName("ChatID")->Value = FChatID;
}
// ---------------------------------------------------------------------------

void __fastcall TdssmRemoteData::qChatMessageReportBeforeOpen(TDataSet *DataSet) {
	TADOQuery *Q = (TADOQuery*)DataSet;
	Q->Parameters->ParamByName("ChatID")->Value = FChatID;
}
// ---------------------------------------------------------------------------

int __fastcall TdssmRemoteData::ChatSendMessage(UnicodeString Msg) {
	//
	int MessageID = -1;
	TADOQuery *Q = ChatGet(FChatID);
	try {
		TADOQuery *M = dmServer->GetQuery("select * from Сообщение where Код = 0");
		try {
			M->Insert();
			M->FieldByName("Код_Беседа")->AsInteger = FChatID;
			M->FieldByName("Код_Пользователь")->AsInteger = FUserID;
			M->FieldByName("Дата_регистрации")->AsDateTime = GetDateTime();
			M->FieldByName("Текст")->AsString = Msg;
			M->Post();
			MessageID = M->FieldByName("Код")->AsInteger;

			TADOQuery *chatParticipants = ChatParticipants(FChatID);
			for (int i = 1; i <= chatParticipants->RecordCount; i++) {
				chatParticipants->RecNo = i;
				TADOQuery *ReadReport = dmServer->GetQuery("select * from Прочтение where Код_Сообщение = 0");
				try {
					ReadReport->Insert();
					ReadReport->FieldByName("Код_Сообщение")->AsInteger = MessageID;
					ReadReport->FieldByName("Код_Пользователь")->AsInteger =
						chatParticipants->FieldByName("Код_Пользователь")->AsInteger;
					ReadReport->FieldByName("Прочитано")->AsBoolean = false;

					if (FUserID == ReadReport->FieldByName("Код_Пользователь")->AsInteger) {
						ReadReport->FieldByName("Прочитано")->AsBoolean = true;
						ReadReport->FieldByName("Дата")->AsDateTime = GetDateTime();
					}
					ReadReport->Post();
				}
				__finally {
					ReadReport->Free();
				}
			}
			return MessageID;
		}
		__finally {
			M->Free();
		}
	}
	__finally {
		Q->Free();
	}

}

// ---------------------------------------------------------------------------
int __fastcall TdssmRemoteData::GetNewMessageCount() {
	int Count = 0;
	try {
		TADOQuery *Q =
			dmServer->GetQuery("select * from Запрос_Пользователь_Новые_сообщения where Код_Пользователь = " +
			IntToStr(FUserID));
		try {
			if (Q->RecordCount > 0) {
				Count = Q->FieldByName("Количество")->AsInteger;
			}
		}
		__finally {
			Q->Free();
		}
	}
	catch (...) {
	}
	return Count;
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::ChatReadAll() {
	TADOQuery *Q = ChatGet(FChatID);
	try {

		TADOQuery *ReadReport =
			dmServer->GetQuery
			("SELECT * FROM Сообщение INNER JOIN Прочтение ON Сообщение.Код = Прочтение.Код_Сообщение where Код_Беседа = " +
			IntToStr(FChatID) + " and Прочтение.Код_Пользователь = " + IntToStr(FUserID));
		try {
			for (int i = 1; i <= ReadReport->RecordCount; i++) {
				ReadReport->RecNo = i;
				if (ReadReport->FieldByName("Прочитано")->AsBoolean == false) {
					ReadReport->Edit();
					ReadReport->FieldByName("Прочитано")->AsBoolean = true;
					ReadReport->FieldByName("Дата")->AsDateTime = GetDateTime();
					ReadReport->Post();
				}
			}
		}
		__finally {
			ReadReport->Free();
		}
	}
	__finally {
		Q->Free();
	}
}

// ---------------------------------------------------------------------------
bool __fastcall TdssmRemoteData::UserIsAdmin() {
	return FUserTypeID == 1;
}

// ---------------------------------------------------------------------------
bool __fastcall TdssmRemoteData::UserIsChatAdmin() {
	TADOQuery *Q = ChatGet(FChatID);
	try {
		return Q->FieldByName("Код_Пользователь")->AsInteger == FUserID;
	}
	__finally {
		Q->Free();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::AccessForChatAdminOnly() {
	if (UserIsChatAdmin() != true)
		throw new Exception("Доступно только автору беседы");
}
// ---------------------------------------------------------------------------
