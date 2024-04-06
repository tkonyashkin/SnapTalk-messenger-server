//---------------------------------------------------------------------------

#ifndef ufMainH
#define ufMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
//---------------------------------------------------------------------------
/*
	Главная форма сервера;
*/
class TfMain : public TForm
{
__published:	// IDE-managed Components
	TListBox *lbConnections;
	TStatusBar *sbMain;
	TTrayIcon *tiMain;
	TPopupMenu *pmMain;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TActionManager *amMain;
	TAction *aShowMainForm;
	TAction *aExit;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall aShowMainFormExecute(TObject *Sender);
	void __fastcall aExitExecute(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall tiMainClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
