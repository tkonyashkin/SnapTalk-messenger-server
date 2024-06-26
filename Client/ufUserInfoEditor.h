//---------------------------------------------------------------------------

#ifndef ufUserInfoEditorH
#define ufUserInfoEditorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TfUserInfoEditor : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TButton *Button1;
	TButton *Button2;
	TPanel *Panel1;
	TLabel *lLogin;
	TLabel *lPassword;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label9;
	TLabel *lBlock;
	TLabel *Label14;
	TDBEdit *dbeLogin;
	TDBEdit *dbePassword;
	TDBEdit *DBEdit5;
	TDBEdit *DBEdit6;
	TDBEdit *DBEdit7;
	TDBEdit *DBEdit9;
	TDBCheckBox *dbcbBlock;
	TDBEdit *DBEdit10;
	TCheckBox *cbShowPassword;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall cbShowPasswordClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfUserInfoEditor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfUserInfoEditor *fUserInfoEditor;
//---------------------------------------------------------------------------
#endif
