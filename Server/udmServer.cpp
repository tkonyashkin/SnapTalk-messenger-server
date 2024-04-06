//---------------------------------------------------------------------------


#pragma hdrstop

#include "udmServer.h"
#include "udssmRemoteData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmServer *dmServer;
//---------------------------------------------------------------------------
__fastcall TdmServer::TdmServer(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TdmServer::DSServerClassGetClass(TDSServerClass *DSServerClass, TPersistentClass &PersistentClass)
{
	// ���������� ��������� �����
	PersistentClass = __classid(TdssmRemoteData);
}
//---------------------------------------------------------------------------
void __fastcall TdmServer::DSAuthenticationManagerUserAuthenticate(TObject *Sender,
		  const UnicodeString Protocol, const UnicodeString Context, const UnicodeString User,
		  const UnicodeString Password, bool &valid, TStrings *UserRoles)
{
	// valid - ����, ������������, ��������� ������������ ���� �� ������ ��� ���������;
	// � ����� ������ �� ������������ ������ �� ����, ������ �� ������������ � ��
	// �� ������ � ������ ��� ���.
	valid = false;
	// ���������� ������������;
	bool Blocked = false;
	// ��� ������������;
	int UserTypeKey;
	// ��� ������������;
	int UserKey = GetUserKey (User, Password, Blocked, UserTypeKey);
	// ����������, "�������� �� ������������ � �������, ��� ���"
	valid = UserKey > 0;
	// ���� ���������� �����������, �� ����������� ����������;
	if (Blocked == true) throw new Exception ("���� � ������� ����������. ��� ������� ������������.");
	// ���� ��������� �� �����������, �� ����������� ����������;
	if (valid == false) throw new Exception ("�������� ���� �����/������.");

	// ���� ��� �������� ��������, ���� ��������������� ������� ������,
	// ������� ������ ��������������� �������� ������ (ThreadId);
	TConnectionInfo *CI = ConnectionList->GetConnectionKey (GetCurrentThreadId());
	// ���������� "��� ������������";
	CI->UserKey = UserKey;
	// ���������� "��� ������������";
	CI->UserTypeKey = UserTypeKey;
}
//---------------------------------------------------------------------------
TADOTable* __fastcall TdmServer::GetTable (UnicodeString TableName)
{
	// ������� ������;
	TADOTable* Result = new TADOTable (NULL);
	try
	{
		// ��� ���������� ������� ���������� ���������� � ����� ������;
		Result->Connection = adoConnection;
		// ��������� ��� �������;
		Result->TableName = TableName;
		// ��������� �����;
		Result->Open ();
		// ���������� ���������;
		return Result;
	}
	catch (...)
	{
		//
		// � ������ ������:
		// ��������� ������
		Result->Free ();
		// �������� ������ � ������� ����������;
		throw;
	}
}
//---------------------------------------------------------------------------
TADOQuery* __fastcall TdmServer::GetQuery (UnicodeString SQL)
{
	// ������� ������;
	TADOQuery* Result = new TADOQuery (NULL);
	try
	{
		// ��� ���������� ������� ���������� ���������� � ����� ������;
		Result->Connection = adoConnection;
		// ���������� ������ SQL;
		Result->SQL->Text = SQL;

		// ��������� �����;
		Result->Open ();

		return Result;
	}
	catch (...)
	{
		// � ������ ������:
		// ��������� ������
		Result->Free ();
		// �������� ������ � ������� ����������;
		throw;
	}
}
//---------------------------------------------------------------------------
int __fastcall TdmServer::ExecQuery (UnicodeString SQL)
{
	// ������� ������;
	TADOQuery* Result = new TADOQuery (NULL);
	try
	{
		// ��� ���������� ������� ���������� ���������� � ����� ������;
		Result->Connection = adoConnection;
		// ���������� ������ SQL;
		Result->SQL->Text = SQL;
		// ���������� ��������� ���������� �������;
		int Value = Result->ExecSQL();
		// ����������� ������;
		Result->Free ();
		//
		return Value;
	}
	catch (...)
	{
		// � ������ ������:
		// ��������� ������
		Result->Free ();
		// �������� ������ � ������� ����������;
		throw;
	}
}
//---------------------------------------------------------------------------
int __fastcall TdmServer::GetUserKey (UnicodeString Login, UnicodeString Password, bool &Blocked, int &UserType)
{
	// ������� ������;
	// ���������� ���� �� ������ ��� ����� �������� ��������;
	TADOQuery *T = GetQuery ("select * from ������������ where ����� = " + QuotedStr (Login));
	try
	{
		// ���������, ������� �� ������, ��������������� �������;
		if (T->RecordCount > 0)
		{
			// ��������� ������ (��� � ������ �������� ��������)
			if (T->FieldByName("������")->AsString == Password)
			{
				// ������� ������ � ������ ������ �������;
				// ���������� ��� ������������
				UserType = T->FieldByName("���_���_������������")->AsInteger;
				// ���������� �������� ���������� ������������;
				Blocked = T->FieldByName("�����������_������")->AsBoolean;
				// ���������� ��� ������������;
				int UserKey = T->FieldByName("���")->AsInteger;
				// ����������� ������ ("����� ��� �� memory")
				T->Free ();
				// ���������� ��� ������������
				return UserKey;
			}
		}
	}
	catch (...)
	{
		//
		// � ������ ������:
		// ��������� ������
		T->Free ();
		// �������� ������ � ������� ����������;
		throw;
	}
	return 0;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TdmServer::GetDataBaseName ()
{
	// �������� ����� ����� ���� ������ �� �������� (Settings.ini)
	UnicodeString Result = FSettings->ReadString(c_Settings_Section_DB, "DB", "Base.mdb");
	// ��������� �� ����� ����� Path.
	// � ���� Path �����, �� ��������� � ����� ����� ���� ����������;
	if (ExtractFilePath(Result) == "")
	{
		Result = ExtractFilePath(Application->ExeName) + Result;
	}
	return Result;
}
//---------------------------------------------------------------------------
void __fastcall TdmServer::DataModuleCreate(TObject *Sender)
{
	// ������� ������;
	FConnectionList = new TConnectionList ();
	// ������� ������;
	FSettings = new TIniFile (ExtractFilePath (Application->ExeName) + "\\" + c_Settings_File);
	// ��������� ������������ � ���, ���, ���� �� ����� ������� ����������,
	// ���� IDE ���������� ����������������;
	if (adoConnection->Connected == true)
	{
		ShowMessage ("adoConnection.Connected = true. ���������� ����� �������.");
		Application->Terminate ();
	}
	// ����������� ������ ���������� � ����� ������;
	adoConnection->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + GetDataBaseName () + ";Persist Security Info=False";
	try
	{
		//
		// ��������� �� �������� (Settings.ini) ���� �������;
		DSTCPServerTransport->Port = FSettings->ReadInteger(c_Settings_Section_Server, "Port", 6000);
		// ��������� ������;
		DSServer->Start ();
		// ��������� ���������� � ����� ������;
		adoConnection->Connected = true;
	}
	catch (Exception &E)
	{
		// � ������ ������:
		Application->MainForm->Show ();
		// ���������� ��������� (�� �������);
		MessageDlg (E.Message, mtError, TMsgDlgButtons () << mbOK, 0);
		MessageDlg ("���������� ����� �������.", mtInformation, TMsgDlgButtons () << mbOK, 0);
		// ��������� ����������;
		Application->Terminate ();
	}
}
//---------------------------------------------------------------------------

void __fastcall TdmServer::DSTCPServerTransportConnect(TDSTCPConnectEventObject &Event)

{
	// ������� ������ � ������ CurrentThreadId;
	TConnectionInfo *CI = ConnectionList->AddConnection(GetCurrentThreadId ());
	// ����� ��� IP
	CI->IP = Event.Channel->ChannelInfo->ClientInfo.IpAddress;
}
//---------------------------------------------------------------------------

void __fastcall TdmServer::DSTCPServerTransportDisconnect(TDSTCPDisconnectEventObject Event)
{
	// ������� ����������;
	ConnectionList->DelConnection(GetCurrentThreadId ());
}
//---------------------------------------------------------------------------

void __fastcall TdmServer::DataModuleDestroy(TObject *Sender)
{
	// ������������� ������ �������;
	DSServer->Stop();
}
//---------------------------------------------------------------------------



