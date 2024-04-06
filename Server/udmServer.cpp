//---------------------------------------------------------------------------


#pragma hdrstop

#include "udmServer.h"
#include "udssmRemoteData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmServer *dmServer;
//---------------------------------------------------------------------------
__fastcall TdmServer::TdmServer(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TdmServer::DSServerClassGetClass(TDSServerClass *DSServerClass, TPersistentClass &PersistentClass)
{
	// Определяем серверный класс
	PersistentClass = __classid(TdssmRemoteData);
}
//---------------------------------------------------------------------------
void __fastcall TdmServer::DSAuthenticationManagerUserAuthenticate(TObject *Sender,
		  const UnicodeString Protocol, const UnicodeString Context, const UnicodeString User,
		  const UnicodeString Password, bool &valid, TStrings *UserRoles)
{
	// valid - флаг, определяющий, разрешить пользователю вход на сервер или запретить;
	// в нашем случае он определяется исходя из того, найден ли пользователь в БД
	// по логину и паролю или нет.
	valid = false;
	// Блокировка пользователя;
	bool Blocked = false;
	// Тип пользователя;
	int UserTypeKey;
	// Код пользователя;
	int UserKey = GetUserKey (User, Password, Blocked, UserTypeKey);
	// Определяем, "впускать ли пользователя в систему, или нет"
	valid = UserKey > 0;
	// Если блокировка установлена, то выбрасываем исключение;
	if (Blocked == true) throw new Exception ("Вход в систему невозможен. Ваш аккаунт заблокирован.");
	// Если валидация не установлена, то выбрасываем исключение;
	if (valid == false) throw new Exception ("Неверная пара логин/пароль.");

	// Если все проверки пройдены, ищем соответствующий элемент списка,
	// который связан идентификатором текущего потока (ThreadId);
	TConnectionInfo *CI = ConnectionList->GetConnectionKey (GetCurrentThreadId());
	// Записываем "код пользователя";
	CI->UserKey = UserKey;
	// Записываем "тип пользователя";
	CI->UserTypeKey = UserTypeKey;
}
//---------------------------------------------------------------------------
TADOTable* __fastcall TdmServer::GetTable (UnicodeString TableName)
{
	// Создаем объект;
	TADOTable* Result = new TADOTable (NULL);
	try
	{
		// Для созданного объекта определяем соединение с базой данных;
		Result->Connection = adoConnection;
		// Указываем имя таблицы;
		Result->TableName = TableName;
		// Открываем набор;
		Result->Open ();
		// Возвращаем результат;
		return Result;
	}
	catch (...)
	{
		//
		// В случае ошибки:
		// Разрушаем объект
		Result->Free ();
		// Передаем ошибку в главный обработчик;
		throw;
	}
}
//---------------------------------------------------------------------------
TADOQuery* __fastcall TdmServer::GetQuery (UnicodeString SQL)
{
	// Создаем объект;
	TADOQuery* Result = new TADOQuery (NULL);
	try
	{
		// Для созданного объекта определяем соединение с базой данных;
		Result->Connection = adoConnection;
		// Определяем запрос SQL;
		Result->SQL->Text = SQL;

		// Открываем набор;
		Result->Open ();

		return Result;
	}
	catch (...)
	{
		// В случае ошибки:
		// Разрушаем объект
		Result->Free ();
		// Передаем ошибку в главный обработчик;
		throw;
	}
}
//---------------------------------------------------------------------------
int __fastcall TdmServer::ExecQuery (UnicodeString SQL)
{
	// Создаем объект;
	TADOQuery* Result = new TADOQuery (NULL);
	try
	{
		// Для созданного объекта определяем соединение с базой данных;
		Result->Connection = adoConnection;
		// Определяем запрос SQL;
		Result->SQL->Text = SQL;
		// Возвращаем результат выполнения запроса;
		int Value = Result->ExecSQL();
		// Освобождаем память;
		Result->Free ();
		//
		return Value;
	}
	catch (...)
	{
		// В случае ошибки:
		// Разрушаем объект
		Result->Free ();
		// Передаем ошибку в главный обработчик;
		throw;
	}
}
//---------------------------------------------------------------------------
int __fastcall TdmServer::GetUserKey (UnicodeString Login, UnicodeString Password, bool &Blocked, int &UserType)
{
	// Создаем объект;
	// Производим поис по логину без учета регистра символов;
	TADOQuery *T = GetQuery ("select * from Пользователь where Логин = " + QuotedStr (Login));
	try
	{
		// проверяем, найдена ли строка, удовлетворяющая условию;
		if (T->RecordCount > 0)
		{
			// Проверяем пароль (уже с учетом регистра символов)
			if (T->FieldByName("Пароль")->AsString == Password)
			{
				// Провера логина и пароля прошла успешно;
				// Возвращаем тип пользователя
				UserType = T->FieldByName("Код_Тип_пользователя")->AsInteger;
				// Возвращаем значение блокировки пользователя;
				Blocked = T->FieldByName("Блокировать_доступ")->AsBoolean;
				// Возвращаем код пользователя;
				int UserKey = T->FieldByName("Код")->AsInteger;
				// Освобождаем память ("Сотри его из memory")
				T->Free ();
				// Возвращаем код пользователя
				return UserKey;
			}
		}
	}
	catch (...)
	{
		//
		// В случае ошибки:
		// Разрушаем объект
		T->Free ();
		// Передаем ошибку в главный обработчик;
		throw;
	}
	return 0;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TdmServer::GetDataBaseName ()
{
	// Загрузка имени файла базы данных из настроек (Settings.ini)
	UnicodeString Result = FSettings->ReadString(c_Settings_Section_DB, "DB", "Base.mdb");
	// Извлекаем из этого имени Path.
	// И если Path пусто, то добавляем к этому имени путь приложения;
	if (ExtractFilePath(Result) == "")
	{
		Result = ExtractFilePath(Application->ExeName) + Result;
	}
	return Result;
}
//---------------------------------------------------------------------------
void __fastcall TdmServer::DataModuleCreate(TObject *Sender)
{
	// Создаем объект;
	FConnectionList = new TConnectionList ();
	// Создаем объект;
	FSettings = new TIniFile (ExtractFilePath (Application->ExeName) + "\\" + c_Settings_File);
	// Уведомить разработчика о том, что, либо он забыл закрыть соединения,
	// либо IDE устраивает самодеятельность;
	if (adoConnection->Connected == true)
	{
		ShowMessage ("adoConnection.Connected = true. Приложение будет закрыто.");
		Application->Terminate ();
	}
	// Определение строки соединения с базой данных;
	adoConnection->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + GetDataBaseName () + ";Persist Security Info=False";
	try
	{
		//
		// Загружаем из настроек (Settings.ini) порт сервера;
		DSTCPServerTransport->Port = FSettings->ReadInteger(c_Settings_Section_Server, "Port", 6000);
		// Запускаем сервер;
		DSServer->Start ();
		// Открываем соединение с базой данных;
		adoConnection->Connected = true;
	}
	catch (Exception &E)
	{
		// В случае ошибки:
		Application->MainForm->Show ();
		// Показываем сообщения (об ошибках);
		MessageDlg (E.Message, mtError, TMsgDlgButtons () << mbOK, 0);
		MessageDlg ("Приложение будет закрыто.", mtInformation, TMsgDlgButtons () << mbOK, 0);
		// Закрываем приложение;
		Application->Terminate ();
	}
}
//---------------------------------------------------------------------------

void __fastcall TdmServer::DSTCPServerTransportConnect(TDSTCPConnectEventObject &Event)

{
	// Создаем объект с ключем CurrentThreadId;
	TConnectionInfo *CI = ConnectionList->AddConnection(GetCurrentThreadId ());
	// Пишем его IP
	CI->IP = Event.Channel->ChannelInfo->ClientInfo.IpAddress;
}
//---------------------------------------------------------------------------

void __fastcall TdmServer::DSTCPServerTransportDisconnect(TDSTCPDisconnectEventObject Event)
{
	// Удаляем соединение;
	ConnectionList->DelConnection(GetCurrentThreadId ());
}
//---------------------------------------------------------------------------

void __fastcall TdmServer::DataModuleDestroy(TObject *Sender)
{
	// Останавливаем работу сервера;
	DSServer->Stop();
}
//---------------------------------------------------------------------------



