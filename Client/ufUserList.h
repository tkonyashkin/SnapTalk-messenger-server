//---------------------------------------------------------------------------

#ifndef ufUserListH
#define ufUserListH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "udmData.h"
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "EhLibVCL.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfUserList : public TForm
{
__published:	// IDE-managed Components
	TDBGridEh *DBGridEh1;
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TButton *bSelect;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall bSelectClick(TObject *Sender);
	void __fastcall DBGridEh1DblClick(TObject *Sender);
private:	// User declarations
	int FUserID;
public:		// User declarations
	__fastcall TfUserList(TComponent* Owner);

	int  __fastcall GetUserID ();

};
//---------------------------------------------------------------------------
extern PACKAGE TfUserList *fUserList;
//---------------------------------------------------------------------------
#endif
