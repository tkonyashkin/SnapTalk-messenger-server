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
// ������� �������� ���� DateTime � MS Access DateTime
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
	F = F + "��� = " + IntToStr(ID);

	if ((F != ""))
		F = " where " + F;
	return dmServer->GetQuery("select * from ������������" + F);
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
	 if (Q->FieldByName("������_����_1")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���� >= " + DateToAccessDate(Q->FieldByName("������_����_1")->AsDateTime);

	 }
	 if (Q->FieldByName("������_����_2")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���� < " + DateToAccessDate(Q->FieldByName("������_����_2")->AsDateTime + 1);

	 }

	 if (Q->FieldByName("������_���_������")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���_������ = " + IntToStr(Q->FieldByName("������_���_������")->AsInteger);
	 }

	 if (Q->FieldByName("������_���_������")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���_������ = " + IntToStr(Q->FieldByName("������_���_������")->AsInteger);
	 }

	 if (Q->FieldByName("������_���_������")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���_������ = " + IntToStr(Q->FieldByName("������_���_������")->AsInteger);
	 }

	 if (Q->FieldByName("������_���_���������")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���_������������ = " + IntToStr(Q->FieldByName("������_���_���������")->AsInteger);
	 }

	 if (Q->FieldByName("������_���_�����������")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���_����������� = " + IntToStr(Q->FieldByName("������_���_�����������")->AsInteger);
	 }

	 if (Q->FieldByName("������_���_������")->IsNull == false)
	 {
	 //
	 if ((F != "")) F = F + " and ";
	 F = F + "���_������ = " + IntToStr(Q->FieldByName("������_���_������")->AsInteger);
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
	 F = F + "(��� = " + IntToStr (FRequestID) + ")";
	 }

	 if ( (F != "") )
	 {
	 F = " where (" + F + ") ";
	 }

	 ((TADOQuery*)DataSet)->SQL->Clear();
	 ((TADOQuery*)DataSet)->SQL->Add ("select * from ������" + F);
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::AccessForAdminOnly() {
	//
	if (FUserTypeID != c_User_type_Admin_user)
		throw new Exception("�������� ������ ��������������");
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
	((TADOQuery*)DataSet)->SQL->Add("select * from ������_������������ where ��� = " + IntToStr(FUserID));
}
// ---------------------------------------------------------------------------

void __fastcall TdssmRemoteData::qUserListBeforeOpen(TDataSet *DataSet) {
	((TADOQuery*)DataSet)->SQL->Clear();
	((TADOQuery*)DataSet)->SQL->Add("select * from ������_������������");
}

// ---------------------------------------------------------------------------

TADOQuery * __fastcall TdssmRemoteData::ChatGet(int ID) {
	TADOQuery *Q = dmServer->GetQuery("select * from ������ where ��� = " + IntToStr(ID));
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
	TADOQuery *Q = dmServer->GetQuery("select * from ������ where ��� = 0");
	try {
		Q->Insert();
		Q->FieldByName("����_�����������")->AsDateTime = GetDateTime();
		Q->FieldByName("���_������������")->AsInteger = FUserID;
		Q->FieldByName("��������")->AsString = title;
		Q->Post();
		ChatParticipantAdd(Q->FieldByName("���")->AsInteger, FUserID);
		return Q->FieldByName("���")->AsInteger;
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
		Q->FieldByName("��������")->AsString = title;
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
		TADOQuery *P = dmServer->GetQuery("select * from ��������_������ where ���_������ = " + IntToStr(ChatID) +
			" and ���_������������ = " + IntToStr(UserID));
		try {
			if (P->RecordCount == 0) {
				P->Insert();
				P->FieldByName("���_������")->AsInteger = ChatID;
				P->FieldByName("���_������������")->AsInteger = UserID;
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
		if (UserID == Q->FieldByName("���_������������")->AsInteger) {
			throw new Exception("������ ������� ��������� ������");
		}

		TADOQuery *P = dmServer->GetQuery("select * from ��������_������ where ���_������ = " + IntToStr(FChatID) +
			" and ���_������������ = " + IntToStr(UserID));
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
	return dmServer->GetQuery("select * from ��������_������ where ���_������ = " + IntToStr(ChatID));
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
		TADOQuery *M = dmServer->GetQuery("select * from ��������� where ��� = 0");
		try {
			M->Insert();
			M->FieldByName("���_������")->AsInteger = FChatID;
			M->FieldByName("���_������������")->AsInteger = FUserID;
			M->FieldByName("����_�����������")->AsDateTime = GetDateTime();
			M->FieldByName("�����")->AsString = Msg;
			M->Post();
			MessageID = M->FieldByName("���")->AsInteger;

			TADOQuery *chatParticipants = ChatParticipants(FChatID);
			for (int i = 1; i <= chatParticipants->RecordCount; i++) {
				chatParticipants->RecNo = i;
				TADOQuery *ReadReport = dmServer->GetQuery("select * from ��������� where ���_��������� = 0");
				try {
					ReadReport->Insert();
					ReadReport->FieldByName("���_���������")->AsInteger = MessageID;
					ReadReport->FieldByName("���_������������")->AsInteger =
						chatParticipants->FieldByName("���_������������")->AsInteger;
					ReadReport->FieldByName("���������")->AsBoolean = false;

					if (FUserID == ReadReport->FieldByName("���_������������")->AsInteger) {
						ReadReport->FieldByName("���������")->AsBoolean = true;
						ReadReport->FieldByName("����")->AsDateTime = GetDateTime();
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
			dmServer->GetQuery("select * from ������_������������_�����_��������� where ���_������������ = " +
			IntToStr(FUserID));
		try {
			if (Q->RecordCount > 0) {
				Count = Q->FieldByName("����������")->AsInteger;
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
			("SELECT * FROM ��������� INNER JOIN ��������� ON ���������.��� = ���������.���_��������� where ���_������ = " +
			IntToStr(FChatID) + " and ���������.���_������������ = " + IntToStr(FUserID));
		try {
			for (int i = 1; i <= ReadReport->RecordCount; i++) {
				ReadReport->RecNo = i;
				if (ReadReport->FieldByName("���������")->AsBoolean == false) {
					ReadReport->Edit();
					ReadReport->FieldByName("���������")->AsBoolean = true;
					ReadReport->FieldByName("����")->AsDateTime = GetDateTime();
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
		return Q->FieldByName("���_������������")->AsInteger == FUserID;
	}
	__finally {
		Q->Free();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TdssmRemoteData::AccessForChatAdminOnly() {
	if (UserIsChatAdmin() != true)
		throw new Exception("�������� ������ ������ ������");
}
// ---------------------------------------------------------------------------
