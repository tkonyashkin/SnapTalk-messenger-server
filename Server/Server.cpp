//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <Midas.hpp>
#include <Datasnap.DSIntf.hpp>
//---------------------------------------------------------------------------




USEFORM("udmServer.cpp", dmServer); /* TDataModule: File Type */
USEFORM("udssmRemoteData.cpp", dssmRemoteData); /* TDSServerModule: File Type */
USEFORM("ufMain.cpp", fMain);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		RegisterMidasLib(DllGetClassObject);
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfMain), &fMain);
		Application->CreateForm(__classid(TdmServer), &dmServer);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
