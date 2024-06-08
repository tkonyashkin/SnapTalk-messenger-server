// ---------------------------------------------------------------------------

#ifndef ufMainH
#define ufMainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "udmData.h"
#include <Data.DB.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBActns.hpp>
#include <Vcl.DBClientActns.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.ToolWin.hpp>
#include "ufLogin.h"
#include "ufUser.h"
#include "ufChat.h"
#include "ufUserInfoEditor.h"
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "EhLibVCL.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"

// ---------------------------------------------------------------------------
class TfMain : public TForm {
__published: // IDE-managed Components

	TActionManager *amMain;
	TWindowClose *WindowClose1;
	TWindowCascade *WindowCascade1;
	TWindowTileHorizontal *WindowTileHorizontal1;
	TWindowTileVertical *WindowTileVertical1;
	TWindowMinimizeAll *WindowMinimizeAll1;
	TWindowArrange *WindowArrange1;
	TAction *aConnect;
	TAction *aShowMainForm;
	TAction *aClose;
	TAction *aShowUser;
	TTrayIcon *tiMain;
	TPopupMenu *pmMain;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TDataSource *dsUI;
	TToolBar *tbMain;
	TToolButton *ToolButton3;
	TToolButton *ToolButton7;
	TStatusBar *sbMain;
	TMainMenu *mmMain;
	TMenuItem *N10;
	TMenuItem *N19;
	TTimer *tMain;
	TMenuItem *miAdminPanel;
	TMenuItem *N9;
	TDBGridEh *dbgChatList;
	TAction *aChatAdd;
	TAction *aChatDelete;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TAction *aChatEdit;
	TToolButton *ToolButton6;
	TAction *aChatRefresh;
	TAction *aChatMessages;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TAction *aProfile;
	TToolButton *ToolButton11;
	TMenuItem *N1;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;

	void __fastcall aConnectExecute(TObject *Sender);
	void __fastcall aCloseExecute(TObject *Sender);
	void __fastcall aShowUserExecute(TObject *Sender);
	void __fastcall dsUIDataChange(TObject *Sender, TField *Field);
	void __fastcall aShowMainFormExecute(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall tiMainClick(TObject *Sender);
	void __fastcall tMainTimer(TObject *Sender);
	void __fastcall dbgChatListDblClick(TObject *Sender);
	void __fastcall aChatAddExecute(TObject *Sender);
	void __fastcall aChatDeleteExecute(TObject *Sender);
	void __fastcall aChatEditExecute(TObject *Sender);
	void __fastcall aChatRefreshExecute(TObject *Sender);
	void __fastcall aChatMessagesExecute(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall aProfileExecute(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TfMain(TComponent* Owner);
	void __fastcall MaxForm(TForm *Form);
	void __fastcall ActivateIterface(bool State, bool IsAdmin);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
// ---------------------------------------------------------------------------
#endif
