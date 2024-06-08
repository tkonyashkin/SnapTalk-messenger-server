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
	// Читаем
	int Port = StrToInt (lePort->Text);
	// Сбрасываем соединение
	dmData->SQLConnection->Connected = false;
	// Чистим параметры соединения
	dmData->SQLConnection->Params->Clear ();
	// Задаем протокол
	dmData->SQLConnection->Params->Add("CommunicationProtocol=tcp/ip");
	// Порт
	dmData->SQLConnection->Params->Add("Port=" + IntToStr(Port));
	// Хост
	dmData->SQLConnection->Params->Add("HostName=" + leAdress->Text);
	// Имя пользователя
	dmData->SQLConnection->Params->Add("DSAuthenticationUser=" + leName->Text);
	// Пароль
	dmData->SQLConnection->Params->Add("DSAuthenticationPassword=" + lePassword->Text);
	// Пробуем соединиться
	dmData->SQLConnection->Connected = true;
	// В случае успешного соединения сохраненяем в Settings.ini:
	// Адрес сервера
	dmData->Settings->WriteString(c_Settings_Section_Connection, "Host", leAdress->Text);
	// Порт
	dmData->Settings->WriteInteger(c_Settings_Section_Connection, "Port", Port);
	// Имя пользователя;
	dmData->Settings->WriteString(c_Settings_Section_Connection, "UserName", leName->Text);
	// Возвращаем mrOk
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::FormClose(TObject *Sender, TCloseAction &Action)
{
	//
	// Удаляем введенный пароль из поля (безопасность :))
	lePassword->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TfLogin::FormShow(TObject *Sender)
{
	//
	// Загрузка Settings.ini
	// Адрес
	leAdress->Text = dmData->Settings->ReadString(c_Settings_Section_Connection, "Host", "localhost");
	// Порт
	lePort->Text = IntToStr(dmData->Settings->ReadInteger(c_Settings_Section_Connection, "Port", 5000));
	// Имя пользователя
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

