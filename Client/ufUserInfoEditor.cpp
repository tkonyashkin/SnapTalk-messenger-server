// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufUserInfoEditor.h"
#include "udmData.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfUserInfoEditor *fUserInfoEditor;

// ---------------------------------------------------------------------------
__fastcall TfUserInfoEditor::TfUserInfoEditor(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfUserInfoEditor::Button1Click(TObject *Sender) {
	//
	if ((dmData->cdsUserInfo->State == dsInsert) || (dmData->cdsUserInfo->State == dsEdit))
		dmData->cdsUserInfo->Post();
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TfUserInfoEditor::Button2Click(TObject *Sender) {
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TfUserInfoEditor::FormClose(TObject *Sender, TCloseAction &Action) {
	dmData->cdsUserInfo->Cancel();
}

// ---------------------------------------------------------------------------
void __fastcall TfUserInfoEditor::FormKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == char(27)) {
		Close();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TfUserInfoEditor::cbShowPasswordClick(TObject *Sender) {
	//
	dbePassword->PasswordChar = '*';
	if (cbShowPassword->Checked) {
		//
		dbePassword->PasswordChar = 0;

	}
}
// ---------------------------------------------------------------------------
