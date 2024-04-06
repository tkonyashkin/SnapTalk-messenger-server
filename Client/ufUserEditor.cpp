//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufUserEditor.h"
#include "udmData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfUserEditor *fUserEditor;
//---------------------------------------------------------------------------
__fastcall TfUserEditor::TfUserEditor(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfUserEditor::Button1Click(TObject *Sender)
{
	//
	if ((dmData->cdsUser->State == dsInsert) || (dmData->cdsUser->State == dsEdit))
		dmData->cdsUser->Post();
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfUserEditor::Button2Click(TObject *Sender)
{
	Close ();
}
//---------------------------------------------------------------------------
void __fastcall TfUserEditor::FormClose(TObject *Sender, TCloseAction &Action)
{
	dmData->cdsUser->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TfUserEditor::FormKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == char (27)) { Close ();

	}
}
//---------------------------------------------------------------------------
void __fastcall TfUserEditor::cbShowPasswordClick(TObject *Sender)
{
	//
	dbePassword->PasswordChar = '*';
	if (cbShowPassword->Checked)
	{
		//
		dbePassword->PasswordChar = 0;

	}
}
//---------------------------------------------------------------------------

