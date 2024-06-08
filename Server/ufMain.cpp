//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufMain.h"
#include "udmServer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TfMain::FormShow(TObject *Sender)
{
	//
	fMain->sbMain->Panels->operator [](0)->Text = "Порт сервера = " + IntToStr (dmServer->DSTCPServerTransport->Port);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::aShowMainFormExecute(TObject *Sender)
{
	fMain->Show();
	SetForegroundWindow(fMain->Handle);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::aExitExecute(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	CanClose = false;
	Hide();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::tiMainClick(TObject *Sender)
{
	aShowMainForm->Execute();
}
//---------------------------------------------------------------------------

