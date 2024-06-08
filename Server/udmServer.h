//---------------------------------------------------------------------------

#ifndef udmServerH
#define udmServerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Datasnap.DSAuth.hpp>
#include <Datasnap.DSCommonServer.hpp>
#include <Datasnap.DSServer.hpp>
#include <Datasnap.DSTCPServerTransport.hpp>
#include <IndyPeerImpl.hpp>
#include <IniFiles.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "uConnectionInfo.h"
#include "uConnectionList.h"
#include <DbxSocketChannelNative.hpp>
//---------------------------------------------------------------------------
const UnicodeString c_Settings_File = "Settings.ini";
const UnicodeString c_Settings_Section_Server = "Server";
const UnicodeString c_Settings_Section_DB = "Database";
//---------------------------------------------------------------------------
/*
	�����, ������������ ������
*/
class TdmServer : public TDataModule
{
__published:	// IDE-managed Components
	// ������������ �������� �������;
	TDSTCPServerTransport *DSTCPServerTransport;
	// �������� �������������� �������;
	TDSAuthenticationManager *DSAuthenticationManager;
	// ������ ���������� ��������;
	TDSServer *DSServer;
	// ������, ������������ "��������� �����";
	TDSServerClass *DSServerClass;
	// ADO ���������� � ����� ������;
	TADOConnection *adoConnection;
	// ����� ����������� ���������� ������;
	void __fastcall DSServerClassGetClass(TDSServerClass *DSServerClass, TPersistentClass &PersistentClass);
	// �������������� ������������ �������;
	void __fastcall DSAuthenticationManagerUserAuthenticate(TObject *Sender, const UnicodeString Protocol,
		  const UnicodeString Context, const UnicodeString User,
		  const UnicodeString Password, bool &valid, TStrings *UserRoles);
	// ���������� ������� "�������� ������ ���������� ��������"
	void __fastcall DataModuleCreate(TObject *Sender);
	// ���������� ������� "������������� �������"
	void __fastcall DSTCPServerTransportConnect(TDSTCPConnectEventObject &Event);
	// ���������� ������� "������������ �������"
	void __fastcall DSTCPServerTransportDisconnect(TDSTCPDisconnectEventObject Event);
	// ���������� ������� "���������� ������ ���������� ��������"
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
	// ������ ��� ������ � ������ �������� (Settings.ini)
	TIniFile *FSettings;
	// ������� ���������� ������� ���� � ���� ������;
	UnicodeString __fastcall GetDataBaseName ();
	// ���������, ������� ������ ��� �������� ������ ���� ���������� �������;
	TConnectionList *FConnectionList;
	// ������� ������ ������������ �� ������ � ������;
	// ������������ �������� "��� ������������"
	// ������������ ���������:
	// Blocked - ���������� ������������;
	// UserType - ��� ������������;
	int __fastcall GetUserKey (UnicodeString Login, UnicodeString Password, bool &Blocked, int &UserType);
public:		// User declarations
	// ����������� ������;
	__fastcall TdmServer(TComponent* Owner);
	// ����� �������� ������ ������ �� ���� ������ (TableName - ��� �������);
	TADOTable* __fastcall GetTable (UnicodeString TableName);
	// ����� �������� ������ ������ �� ���� ������ (SQL - ������������ SQL ������);
	TADOQuery* __fastcall GetQuery (UnicodeString SQL);
	// ����� ���������� ������������� SQL
	int __fastcall ExecQuery (UnicodeString SQL);

	// �������� ������:
	__property TConnectionList *ConnectionList = {read=FConnectionList};
};
//---------------------------------------------------------------------------
extern PACKAGE TdmServer *dmServer;
//---------------------------------------------------------------------------
#endif
