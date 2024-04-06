//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <Midas.hpp>
#include <Datasnap.DSIntf.hpp>
//---------------------------------------------------------------------------
























USEFORM("ufMain.cpp", fMain);
USEFORM("ufLogin.cpp", fLogin);
USEFORM("ufUserList.cpp", fUserList);
USEFORM("ufUserInfoEditor.cpp", fUserInfoEditor);
USEFORM("ufUser.cpp", fUser);
USEFORM("ufChat.cpp", fChat);
USEFORM("udmData.cpp", dmData); /* TDataModule: File Type */
USEFORM("ufUserEditor.cpp", fUserEditor);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		RegisterMidasLib(DllGetClassObject);
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfMain), &fMain);
		Application->CreateForm(__classid(TdmData), &dmData);
		Application->CreateForm(__classid(TfLogin), &fLogin);
		Application->CreateForm(__classid(TfUser), &fUser);
		Application->CreateForm(__classid(TfUserInfoEditor), &fUserInfoEditor);
		Application->CreateForm(__classid(TfChat), &fChat);
		Application->CreateForm(__classid(TfUserList), &fUserList);
		Application->CreateForm(__classid(TfUserEditor), &fUserEditor);
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
