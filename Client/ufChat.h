//---------------------------------------------------------------------------

#ifndef ufChatH
#define ufChatH
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
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.DBActns.hpp>
#include "ufUserList.h"
//---------------------------------------------------------------------------
class TfChat : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TPanel *Panel1;
	TMemo *mText;
	TButton *bSend;
	TDBGridEh *DBGridEh1;
	TDBGridEh *DBGridEh2;
	TActionManager *amChat;
	TAction *aChatParticipantAdd;
	TAction *aChatParticipantDelete;
	TDataSetRefresh *DataSetRefresh1;
	TToolBar *tbNavigator;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton2;
	TToolButton *ToolButton14;
	TAction *aSendMessage;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall aChatParticipantAddExecute(TObject *Sender);
	void __fastcall aChatParticipantDeleteExecute(TObject *Sender);
	void __fastcall aSendMessageExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfChat(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfChat *fChat;
//---------------------------------------------------------------------------
#endif
