// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufUserList.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAxisGridsEh"
#pragma link "DBGridEh"
#pragma link "DBGridEhGrouping"
#pragma link "DBGridEhToolCtrls"
#pragma link "DynVarsEh"
#pragma link "EhLibVCL"
#pragma link "GridsEh"
#pragma link "ToolCtrlsEh"
#pragma resource "*.dfm"
TfUserList *fUserList;

// ---------------------------------------------------------------------------
__fastcall TfUserList::TfUserList(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfUserList::FormShow(TObject *Sender) {
	dmData->cdsUserList->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TfUserList::bSelectClick(TObject *Sender) {
	//
	if (dmData->cdsUserList->RecordCount == 0) {
        throw new Exception("Ïîëüçîâàòåëü íå âûáðàí");
	}
	FUserID = dmData->cdsUserListÊîä->AsInteger;
	ModalResult = mrOk;
}

// ---------------------------------------------------------------------------
int __fastcall TfUserList::GetUserID() {
	return FUserID;
}
// ---------------------------------------------------------------------------
void __fastcall TfUserList::DBGridEh1DblClick(TObject *Sender)
{
	bSelect->Click();
}
//---------------------------------------------------------------------------

