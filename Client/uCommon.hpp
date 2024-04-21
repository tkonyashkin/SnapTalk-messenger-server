// CodeGear C++Builder
// Copyright (c) 1995, 2011 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uCommon.pas' rev: 23.00 (Win32)

#ifndef UcommonHPP
#define UcommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Data.Win.ADODB.hpp>	// Pascal unit
#include <Vcl.DBGrids.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.ShellAPI.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Datasnap.DBClient.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ucommon
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall DateTimeSubToStr(double Value);
extern PACKAGE void __fastcall ClearMemory(System::TObject* Obj);
extern PACKAGE void __fastcall DataSetLocateKey(Data::Db::TDataSet* DS, const System::Variant &KeyName, const System::Variant &KeyValue);
extern PACKAGE void __fastcall DataSetReload(Data::Db::TDataSet* DS);
extern PACKAGE void __fastcall dbgTitleClick(Vcl::Dbgrids::TColumn* Column);
extern PACKAGE System::WideString __stdcall GetTempDir(void);
extern PACKAGE unsigned __fastcall ExecuteFile(const System::UnicodeString FileName, const System::UnicodeString Params, const System::UnicodeString DefaultDir, int ShowCmd);

}	/* namespace Ucommon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UCOMMON)
using namespace Ucommon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// UcommonHPP
