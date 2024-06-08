//---------------------------------------------------------------------------

#ifndef ufUserH
#define ufUserH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "udmData.h"
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "EhLibVCL.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBActns.hpp>
#include <Vcl.DBClientActns.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TfUser : public TForm
{
__published:	// IDE-managed Components
	TDBGridEh *DBGridEh1;
	TToolBar *tbNavigator;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TToolButton *ToolButton15;
	TToolButton *ToolButton2;
	TToolButton *ToolButton17;
	TToolButton *ToolButton18;
	TToolButton *ToolButton19;
	TToolButton *ToolButton1;
	TToolButton *ToolButton20;
	TToolButton *ToolButton21;
	TToolButton *ToolButton4;
	TToolButton *ToolButton22;
	TActionManager *amNavigator;
	TDataSetFirst *DataSetFirst1;
	TDataSetPrior *DataSetPrior1;
	TDataSetNext *DataSetNext1;
	TDataSetLast *DataSetLast1;
	TDataSetInsert *DataSetInsert1;
	TDataSetDelete *DataSetDelete1;
	TDataSetEdit *DataSetEdit1;
	TDataSetPost *DataSetPost1;
	TDataSetCancel *DataSetCancel1;
	TDataSetRefresh *DataSetRefresh1;
	TClientDataSetApply *ClientDataSetApply1;
	TStatusBar *StatusBar1;
private:	// User declarations
public:		// User declarations
	__fastcall TfUser(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfUser *fUser;
//---------------------------------------------------------------------------
#endif
