// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufChat.h"
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
TfChat *fChat;

// ---------------------------------------------------------------------------
__fastcall TfChat::TfChat(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfChat::FormCreate(TObject *Sender) {
	mText->Lines->Clear();
}

// ---------------------------------------------------------------------------
void __fastcall TfChat::aChatParticipantAddExecute(TObject *Sender) {
	//
	if (fUserList->ShowModal() == mrOk) {
		dmData->RemoteMethods->ChatParticipantAdd(fUserList->GetUserID());
		dmData->cdsChatParticipantList->Refresh();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfChat::aChatParticipantDeleteExecute(TObject *Sender) {
	//
	if (dmData->cdsChatParticipantList->RecordCount > 0) {
		if (MessageDlg("Подтвердите удаление?", mtConfirmation, TMsgDlgButtons(0) << mbOK << mbCancel, 0) == mrOk) {
			//
			dmData->RemoteMethods->ChatParticipantDelete(dmData->cdsChatParticipantListКод_Пользователь->AsInteger);
			dmData->cdsChatParticipantList->Refresh();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfChat::aSendMessageExecute(TObject *Sender) {
	//
	UnicodeString Message = Trim(mText->Lines->Text);
	if (Message.Length() > 0) {
		dmData->RemoteMethods->ChatSendMessage(mText->Lines->Text);
		dmData->cdsChatMessages->Refresh();
		dmData->cdsChatMessages->Last();
		mText->Lines->Clear();
	}
}
// ---------------------------------------------------------------------------
