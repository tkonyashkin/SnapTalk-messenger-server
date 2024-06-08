// ---------------------------------------------------------------------------

#pragma hdrstop

#include "udmData.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
// #pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
TdmData *dmData;

// ---------------------------------------------------------------------------
__fastcall TdmData::TdmData(TComponent* Owner) : TDataModule(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::ExecOpForm(TForm *F) {
	//
	if (FShowOpForm == true)
		F->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::TestActiveConnection() {
	//
	if (SQLConnection->Connected == false) {
		//
		throw new Exception("Необходимо выполнить вход!");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::DataModuleCreate(TObject *Sender) {
	//
	FShowOpForm = true;
	FSettings = new TIniFile(ExtractFilePath(Application->ExeName) + "\\" + c_Settings_File);
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::aeMainException(TObject *Sender, Exception * E) {
	//
	MessageDlg(E->Message, mtInformation, TMsgDlgButtons(0) << mbOK, 0);
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::ActiveCDS(bool Value) {
	//
	UnicodeString S = "";
	for (int I = 0; I <= this->ComponentCount - 1; I++) {
		//
		if (this->Components[I]->ClassName() == "TClientDataSet") {
			//
			TClientDataSet *cds = (TClientDataSet*)(this->Components[I]);
			try {
				//
				cds->Active = Value;
			}
			catch (Exception &E) {
				if (S != "")
					S = S + WideChar(13);
				S = S + cds->Name + " (" + E.Message + ")";
			}
		}
	}
	if ((Value == true) && (S != "")) {
		S = "У Вас нет доступа к следующим наборам данных: " + WideChar(13) + S;
		// MessageDlg(S, mtInformation, TMsgDlgButtons(0) << mbYes, 0);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsCommonAfterCancel(TDataSet *DataSet) {
	//
	TClientDataSet *cds = (TClientDataSet*)DataSet;
	cds->CancelUpdates();
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::cdsCommonAfterDelete(TDataSet *DataSet) {
	TClientDataSet *cds = (TClientDataSet*)DataSet;
	if (cds->ApplyUpdates(0) == 0) {
		cds->Refresh();
	}
	else {
		cds->CancelUpdates();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsCommonAfterPost(TDataSet *DataSet) {
	TClientDataSet *cds = (TClientDataSet*)DataSet;
	try {
		if (cds->ApplyUpdates(0) == 0) {
			cds->Refresh();
		}
		else {
			//
			try {
				cds->Edit();
			}
			catch (...) {
			}
			Abort;
		}
	}
	catch (...) {
		try {
			cds->Edit();
		}
		catch (...) {
		}
		throw;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::cdsCommonReconcileError(TCustomClientDataSet *DataSet, EReconcileError *E,
	TUpdateKind UpdateKind, TReconcileAction &Action) {
	//
	throw new Exception(E->Message);
}

// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsCommonBeforeDelete(TDataSet *DataSet) {
	//
	if (MessageDlg("Подтвердите удаление?", mtConfirmation, TMsgDlgButtons(0) << mbOK << mbCancel, 0) != mrOk) {
		//
		Abort();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsUserAfterEdit(TDataSet *DataSet) {
	ExecOpForm(fUserEditor);
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::cdsUserAfterInsert(TDataSet *DataSet) {
	ExecOpForm(fUserEditor);
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::SQLConnectionAfterConnect(TObject *Sender) {
	FNewMessageCount = 0;
	FRemoteMethods = new TdssmRemoteDataClient(SQLConnection->DBXConnection);
	ActiveCDS(true);
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::SQLConnectionBeforeDisconnect(TObject *Sender) {
	//
	try {
		ActiveCDS(false);
		FRemoteMethods->Free();

	}
	catch (...) {

	}
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::DataModuleDestroy(TObject *Sender) {
	SQLConnection->Connected = false;
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsUserListCalcFields(TDataSet *DataSet) {
	//
	// cdsUserListПользователь->Value = cdsUserListФамилия->Value + " " + cdsUserListИмя->Value + " " + cdsUserListОтчество->Value;
}
// ---------------------------------------------------------------------------

/*
 void __fastcall TdmData::cdsProtocolAfterInsert(TDataSet *DataSet) {


 int Key = RemoteMethods->ProtocolAdd();
 cdsProtocol->Refresh();
 if (cdsProtocol->Locate("Код", Key, TLocateOptions(0)) == false)
 throw new Exception("Запись не найдена");
 cdsProtocol->Edit();
 Abort();


 }
 */

// ---------------------------------------------------------------------------
void __fastcall TdmData::cdsRentListBeforeInsert(TDataSet *DataSet) {
	/*
	 try {
	 int ID = RemoteMethods->RentAdd();
	 RemoteMethods->RentSetID(ID);
	 fRentEditor->ShowModal();
	 cdsRentList->Refresh();
	 if (cdsRentList->Locate("Код", ID, TLocateOptions(0)) == false)
	 throw new Exception("Запись не найдена");
	 }
	 __finally {
	 Abort();
	 }
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsRentListBeforeEdit(TDataSet *DataSet) {
	/*
	 try {
	 RemoteMethods->RentSetID(cdsRentList->FieldByName("Код")->AsInteger);
	 fRentEditor->ShowModal();
	 cdsRentList->Refresh();
	 }
	 __finally {
	 Abort();
	 }
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::cdsRentListBeforeDelete(TDataSet *DataSet) {
	/*
	 try {
	 if (MessageDlg("Подтвердите удаление?", mtConfirmation, TMsgDlgButtons(0) << mbOK << mbCancel, 0) == mrOk) {
	 RemoteMethods->RentSetID(cdsRentList->FieldByName("Код")->AsInteger);
	 RemoteMethods->RentDelete();
	 cdsRentList->Refresh();
	 }
	 }
	 __finally {
	 Abort();
	 }
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsClientListBeforeInsert(TDataSet *DataSet) {
	/*
	 try {
	 int ID = RemoteMethods->ClientAdd();
	 RemoteMethods->ClientSetID(ID);
	 fClientEditor->ShowModal();
	 cdsClientList->Refresh();
	 if (cdsClientList->Locate("Код", ID, TLocateOptions(0)) == false)
	 throw new Exception("Запись не найдена");
	 }
	 __finally {
	 Abort();
	 }
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TdmData::cdsClientListBeforeEdit(TDataSet *DataSet) {
	/*
	 try {
	 RemoteMethods->ClientSetID(cdsClientList->FieldByName("Код")->AsInteger);
	 fClientEditor->ShowModal();
	 cdsClientList->Refresh();
	 }
	 __finally {
	 Abort();
	 }
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsClientListBeforeDelete(TDataSet *DataSet) {
	/*
	 try {
	 if (MessageDlg("Подтвердите удаление?", mtConfirmation,
	 TMsgDlgButtons(0) << mbOK << mbCancel, 0) == mrOk) {
	 RemoteMethods->ClientSetID
	 (cdsClientList->FieldByName("Код")->AsInteger);
	 RemoteMethods->ClientDelete();
	 cdsClientList->Refresh();
	 }
	 }
	 __finally {
	 Abort();
	 }
	 */
}

// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsApartmentListBeforeDelete(TDataSet *DataSet) {
	/*
	 try {
	 if (MessageDlg("Подтвердите удаление?", mtConfirmation,
	 TMsgDlgButtons(0) << mbOK << mbCancel, 0) == mrOk) {
	 RemoteMethods->ApartmentSetID
	 (cdsApartmentList->FieldByName("Код")->AsInteger);
	 RemoteMethods->ApartmentDelete();
	 cdsApartmentList->Refresh();
	 }
	 }
	 __finally {
	 Abort();
	 }
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsApartmentListBeforeEdit(TDataSet *DataSet) {
	/*
	 try {
	 RemoteMethods->ApartmentSetID(cdsApartmentList->FieldByName("Код")
	 ->AsInteger);
	 fApartmentEditor->ShowModal();
	 cdsApartmentList->Refresh();
	 }
	 __finally {
	 Abort();
	 }
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TdmData::cdsApartmentListBeforeInsert(TDataSet *DataSet) {
	/*
	 try {
	 int ID = RemoteMethods->ApartmentAdd();
	 RemoteMethods->ApartmentSetID(ID);
	 fApartmentEditor->ShowModal();
	 cdsApartmentList->Refresh();
	 if (cdsApartmentList->Locate("Код", ID, TLocateOptions(0)) == false)
	 throw new Exception("Запись не найдена");
	 }
	 __finally {
	 Abort();
	 }
	 */
}
// ---------------------------------------------------------------------------
