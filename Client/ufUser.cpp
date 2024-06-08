//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufUser.h"
//---------------------------------------------------------------------------
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
TfUser *fUser;
//---------------------------------------------------------------------------
__fastcall TfUser::TfUser(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
