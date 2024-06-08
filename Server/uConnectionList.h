//---------------------------------------------------------------------------

#ifndef uConnectionListH
#define uConnectionListH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "uConnectionInfo.h"
#include <System.SysUtils.hpp>
#include "ufMain.h"
//---------------------------------------------------------------------------
const int c_NotFind = -1;
//---------------------------------------------------------------------------
/*
	����� ��� �������� ���������� �������
*/
//---------------------------------------------------------------------------
class TConnectionList : public TObject
{
	private:
	// ������, � ������� �������� ���������� � �����������;
	TStringList *FList;
	// ���������, ���������� ��� ��������� ��������� ������ ����������;
	void Change ()
	{
		//
        TThread::Queue (NULL, ConnectionListOnChange);
	}

	protected:

	public:
	// � OnChange ������������ ���������, ������� ����� ���������� ��� ��������� ������;
	TNotifyEvent OnChange;

	// ����������� ������;
	__fastcall TConnectionList()
	{
		//
		FList = new TStringList ();
	}
	// ���������� ������;
	__fastcall ~TConnectionList()
	{
		//
        FList->Free ();
	}
	// ������� ������ ������ �� ����� (���������� ������);
	int __fastcall Find (DWORD Key)
	{
		//
		TConnectionInfo* CI;
		// ���������� ������;
		for (int I = 0; I < FList->Count; I ++)
		{
			//
			CI = (TConnectionInfo *) FList->Objects[I];
			// ���� ���� ������;
			if (CI->Key == Key)
			{
				// ����������� �� �������;
				return I;
			}
		}
		return c_NotFind;
	}
	// ������� ���������� � ������ ������;
	TConnectionInfo* __fastcall AddConnection (DWORD Key)
	{
		//
        //
		TConnectionInfo* CI = NULL;
		// ���� ������ ����� ��� � ������, �� ������ ����� ��������� � ���� ������;
		if (Find (Key) == c_NotFind)
		{

			CI = new TConnectionInfo (Key);
			FList->AddObject("", CI);
			Change ();
		}
		return CI;
	}
	// ������� ��������� ������ �� �����;
	TConnectionInfo* __fastcall GetConnectionKey (DWORD Key)
	{
		// ���� ��������� � ��������� ������;
		int I = Find(Key);
		if (I != c_NotFind)
		{
			// ���������� ��������� ���������;
			return (TConnectionInfo *) FList->Objects[I];
		}
		return NULL;
	}
	// ������� ��������� ������ �� �������;
	TConnectionInfo* __fastcall GetConnectionIndex (int Index)
	{
		// ���� ������ �� ������� �� ������� �������� ������, �� ���������� ���������;
		if ((Index >= 0) && (Index < FList->Count))
		{
			return (TConnectionInfo *)FList->Objects[Index];
		}
		return NULL;
	}
	// ������� ��������� ����� ������ ����������;
	TStrings* __fastcall GetList ()
	{
		//
		TStrings *Result = new TStringList ();
		Result->AddStrings(FList);
		return Result;
	}

	// ������� ��������� ���������� ��������� � ������;
	int __fastcall GetCount()
	{
		//
		return FList->Count;
    }
	// �������� �������� �� ������;
	void __fastcall DelConnection (DWORD Key)
	{
		//
		// ���� ������� � ��������� ������;
		int I = Find(Key);
		// ���������, ����� �� ������� ��������� � �������� ������;
		if (I != c_NotFind)
		{
			// ���������� ���������;
			TConnectionInfo *CI = (TConnectionInfo *) FList->Objects[I];
			// ��������� ���;
			CI->Free();
			// ������� ������ �� ������;
			FList->Delete(I);
			// ��������� ��������� � OnChange;
			Change ();
		}
	}
	//
	void __fastcall ConnectionListOnChange ()
	{
		//
		try
		{
			fMain->sbMain->Panels->operator [](1)->Text = "���������� �������� ���������� = " + IntToStr (FList->Count);
			fMain->lbConnections->Items->Clear ();
			for (int I = 0; I < FList->Count ; I ++)
			{
				TConnectionInfo *CI = (TConnectionInfo *)FList->Objects[I];
				fMain->lbConnections->Items->Add ("����� [" + FloatToStr (CI->Key) + "], ����� ����� [" + DateTimeToStr (CI->DateTime) + "], IP-����� [" + CI->IP + "]");
			}
		}
		catch (...)
		{

		}
	}
	__published:

};




#endif
