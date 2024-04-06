//---------------------------------------------------------------------------

#ifndef ufLoginH
#define ufLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "udmData.h"
//---------------------------------------------------------------------------
/*
	Форма входа в систему.
*/
class TfLogin : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabeledEdit *leName;
	TLabeledEdit *lePassword;
	TButton *bOk;
	TButton *bCancel;
	TTabSheet *TabSheet2;
	TLabeledEdit *leAdress;
	TLabeledEdit *lePort;
	void __fastcall bOkClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall leNameEnter(TObject *Sender);
	void __fastcall leAdressEnter(TObject *Sender);
	void __fastcall lePasswordEnter(TObject *Sender);
	void __fastcall lePortEnter(TObject *Sender);
	void __fastcall bCancelClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TfLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfLogin *fLogin;
//---------------------------------------------------------------------------
#endif
