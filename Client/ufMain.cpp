// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufMain.h"

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
TfMain *fMain;

// ---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::aConnectExecute(TObject *Sender) {
	if (dmData->SQLConnection->Connected == true) {
		//
		dmData->SQLConnection->Connected = false;
		aConnect->Caption = "Вход";
		aConnect->Hint = aConnect->Caption;
		aConnect->ImageIndex = 0;
		ActivateIterface(false, false);

	}
	else {
		//
		if (fLogin->ShowModal() == mrOk) {
			//
			aConnect->Caption = "Выход";
			aConnect->Hint = aConnect->Caption;
			aConnect->ImageIndex = 1;
			ActivateIterface(true, dmData->RemoteMethods->UserIsAdmin());
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::aCloseExecute(TObject *Sender) {
	Application->Terminate();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::aShowUserExecute(TObject *Sender) {
	dmData->TestActiveConnection();
	fUser->ShowModal();
	dmData->cdsChatList->Refresh();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::dsUIDataChange(TObject *Sender, TField *Field) {
	UnicodeString S = "";

	sbMain->Panels->operator[](0)->Text = dmData->cdsUserInfoТип_пользователя->Value;
	sbMain->Panels->operator[](1)->Text = dmData->cdsUserInfoПользователь->Value;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::aShowMainFormExecute(TObject *Sender) {
	//
	Show();
	SetForegroundWindow(this->Handle);
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::FormCloseQuery(TObject *Sender, bool &CanClose) {
	//
	CanClose = false;
	Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::FormKeyPress(TObject *Sender, System::WideChar &Key) {
	if (Key == char(27))
		Hide();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::FormShow(TObject *Sender) {
	//

}
// ---------------------------------------------------------------------------

void __fastcall TfMain::tiMainClick(TObject *Sender) {
	aShowMainForm->Execute();
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::MaxForm(TForm *Form) {
	//
	// WindowMinimizeAll1->Execute();
	Form->WindowState = wsMaximized;
	Form->Show();
}

// ---------------------------------------------------------------------------

void __fastcall TfMain::tMainTimer(TObject *Sender) {
	try {
		if (dmData->SQLConnection->Connected) {
			int NewMessageCount = dmData->RemoteMethods->GetNewMessageCount();
			if (dmData->NewMessageCount != NewMessageCount) {
				dmData->NewMessageCount = NewMessageCount;
				if (dmData->NewMessageCount > 0) {
					tiMain->BalloonHint = "Новые сообщения: " + IntToStr(NewMessageCount) + " шт.";
					tiMain->ShowBalloonHint();
					FlashWindow(fMain->Handle, true);
				}
				dmData->cdsChatList->Refresh();
				if (fChat->Visible) {
					dmData->cdsChatMessages->Refresh();
					dmData->cdsChatMessages->Last();
					dmData->RemoteMethods->ChatReadAll();
				}
			}
		}
	}
	catch (Exception &E) {
		// ShowMessage(E.Message);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::dbgChatListDblClick(TObject *Sender) {
	aChatMessages->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::aChatAddExecute(TObject *Sender) {
	//
	dmData->TestActiveConnection();
	UnicodeString Title = "";
	if (InputQuery("Введите название для беседы", "Название беседы", Title) == true) {
		dmData->RemoteMethods->ChatAdd(Title);
		dmData->cdsChatList->Refresh();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::aChatDeleteExecute(TObject *Sender) {
	//
	dmData->TestActiveConnection();
	if (dmData->cdsChatList->RecordCount > 0) {
		dmData->RemoteMethods->ChatIDSet(dmData->cdsChatList->FieldByName("Код")->AsInteger);
		if (MessageDlg("Подтвердите удаление?", mtConfirmation, TMsgDlgButtons(0) << mbOK << mbCancel, 0) == mrOk) {
			//
			dmData->RemoteMethods->ChatDelete();
			dmData->cdsChatList->Refresh();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::aChatEditExecute(TObject *Sender) {
	dmData->TestActiveConnection();
	if (dmData->cdsChatList->RecordCount > 0) {
		dmData->RemoteMethods->ChatIDSet(dmData->cdsChatList->FieldByName("Код")->AsInteger);
		UnicodeString Title = dmData->cdsChatListНазвание->AsString;
		if (InputQuery("Введите название для беседы", "Название беседы", Title) == true) {
			dmData->RemoteMethods->ChatEdit(Title);
			dmData->cdsChatList->Refresh();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::aChatRefreshExecute(TObject *Sender) {
	dmData->TestActiveConnection();
	dmData->cdsChatList->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::ActivateIterface(bool State, bool IsAdmin) {
	aChatAdd->Enabled = State;
	aChatEdit->Enabled = State;
	aChatDelete->Enabled = State;
	aChatRefresh->Enabled = State;
	aChatMessages->Enabled = State;
	aProfile->Enabled = State;
	miAdminPanel->Visible = State && IsAdmin;
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::aChatMessagesExecute(TObject *Sender) {
	//
	dmData->TestActiveConnection();
	if (dmData->cdsChatList->RecordCount > 0) {
		dmData->RemoteMethods->ChatIDSet(dmData->cdsChatList->FieldByName("Код")->AsInteger);
		dmData->cdsChat->Refresh();
		dmData->cdsChatParticipantList->Refresh();
		dmData->RemoteMethods->ChatReadAll();
		dmData->cdsChatMessages->Refresh();
		dmData->cdsChatMessages->Last();
		fChat->Caption = dmData->cdsChatНазвание->AsString;
		fChat->ShowModal();
		dmData->cdsChatList->Refresh();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::FormCreate(TObject *Sender) {
	ActivateIterface(false, false);
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::aProfileExecute(TObject *Sender) {
	//
	dmData->TestActiveConnection();
	if (fUserInfoEditor->ShowModal() == mrOk) {
		dmData->cdsChatList->Refresh();
	}
}
// ---------------------------------------------------------------------------
