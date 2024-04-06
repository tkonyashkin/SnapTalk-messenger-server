//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufLogin.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfLogin *fLogin;
//---------------------------------------------------------------------------
__fastcall TfLogin::TfLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::bOkClick(TObject *Sender)
{
	// ������
	int Port = StrToInt (lePort->Text);
	// ���������� ����������
	dmData->SQLConnection->Connected = false;
	// ������ ��������� ����������
	dmData->SQLConnection->Params->Clear ();
	// ������ ��������
	dmData->SQLConnection->Params->Add("CommunicationProtocol=tcp/ip");
	// ����
	dmData->SQLConnection->Params->Add("Port=" + IntToStr(Port));
	// ����
	dmData->SQLConnection->Params->Add("HostName=" + leAdress->Text);
	// ��� ������������
	dmData->SQLConnection->Params->Add("DSAuthenticationUser=" + leName->Text);
	// ������
	dmData->SQLConnection->Params->Add("DSAuthenticationPassword=" + lePassword->Text);
	// ������� �����������
	dmData->SQLConnection->Connected = true;
	// � ������ ��������� ���������� ����������� � Settings.ini:
	// ����� �������
	dmData->Settings->WriteString(c_Settings_Section_Connection, "Host", leAdress->Text);
	// ����
	dmData->Settings->WriteInteger(c_Settings_Section_Connection, "Port", Port);
	// ��� ������������;
	dmData->Settings->WriteString(c_Settings_Section_Connection, "UserName", leName->Text);
	// ���������� mrOk
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::FormClose(TObject *Sender, TCloseAction &Action)
{
	//
	// ������� ��������� ������ �� ���� (������������ :))
	lePassword->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::FormShow(TObject *Sender)
{
	//
	// �������� Settings.ini
	// �����
	leAdress->Text = dmData->Settings->ReadString(c_Settings_Section_Connection, "Host", "localhost");
	// ����
	lePort->Text = IntToStr(dmData->Settings->ReadInteger(c_Settings_Section_Connection, "Port", 5000));
	// ��� ������������
	leName->Text = dmData->Settings->ReadString(c_Settings_Section_Connection, "UserName", "");

}
//---------------------------------------------------------------------------
void __fastcall TfLogin::leNameEnter(TObject *Sender)
{
	//
	leName->SetFocus ();
	leName->SelectAll ();
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::leAdressEnter(TObject *Sender)
{
	leAdress->SetFocus ();
	leAdress->SelectAll ();
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::lePasswordEnter(TObject *Sender)
{
	//
	lePassword->SetFocus ();
	lePassword->SelectAll ();
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::lePortEnter(TObject *Sender)
{
	//
	lePort->SetFocus ();
	lePort->SelectAll ();
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::bCancelClick(TObject *Sender)
{
	Close ();
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == Char (27)) {
		Close ();
	}
}
//---------------------------------------------------------------------------

