//---------------------------------------------------------------------------

#ifndef uConnectionInfoH
#define uConnectionInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
/*
	//
	��������� ��� �������� ������ � ���������� ����������;
*/
//---------------------------------------------------------------------------
class TConnectionInfo : public TObject
{
	private:
	// ���������� ����;
	DWORD FKey;
	// ���� � ����� ��������;
	TDateTime FDateTime;
	// IP �����;
	UnicodeString FIP;
	// ��� ������������;
	int FUserKey;
	//
	int FUserTypeKey;

	public:
	// ����������� ������;
	__fastcall TConnectionInfo (DWORD Key)
	{
		//
		FKey = Key;
		FDateTime = Now ();
		FUserKey = 0;
	}
	// ���������� ������;
	__fastcall ~TConnectionInfo ()
	{
		//

	}
	// �������� ������:
	__property DWORD Key = {read = FKey};
	__property TDateTime DateTime = {read = FDateTime};
	__property UnicodeString IP = {read = FIP, write = FIP};
	__property int UserKey = {read = FUserKey, write = FUserKey};
	__property int UserTypeKey = {read = FUserTypeKey, write = FUserTypeKey};

};
#endif
