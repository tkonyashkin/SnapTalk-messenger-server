//---------------------------------------------------------------------------

#ifndef udmServerH
#define udmServerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Datasnap.DSAuth.hpp>
#include <Datasnap.DSCommonServer.hpp>
#include <Datasnap.DSServer.hpp>
#include <Datasnap.DSTCPServerTransport.hpp>
#include <IndyPeerImpl.hpp>
#include <IniFiles.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "uConnectionInfo.h"
#include "uConnectionList.h"
//---------------------------------------------------------------------------
const UnicodeString c_Settings_File = "Settings.ini";
const UnicodeString c_Settings_Section_Server = "Server";
const UnicodeString c_Settings_Section_DB = "Database";
//---------------------------------------------------------------------------
/*
	Класс, организующий сервер
*/
class TdmServer : public TDataModule
{
__published:	// IDE-managed Components
	// Транспортный протокол сервера;
	TDSTCPServerTransport *DSTCPServerTransport;
	// Менеджер аутентификации сервера;
	TDSAuthenticationManager *DSAuthenticationManager;
	// Объект управления сервером;
	TDSServer *DSServer;
	// Объект, определяющий "серверный класс";
	TDSServerClass *DSServerClass;
	// ADO соединение с базой данных;
	TADOConnection *adoConnection;
	// Метод определения серверного класса;
	void __fastcall DSServerClassGetClass(TDSServerClass *DSServerClass, TPersistentClass &PersistentClass);
	// Аутентификация пользователя системы;
	void __fastcall DSAuthenticationManagerUserAuthenticate(TObject *Sender, const UnicodeString Protocol,
		  const UnicodeString Context, const UnicodeString User,
		  const UnicodeString Password, bool &valid, TStrings *UserRoles);
	// Обработчик события "Создание модуля управления сервером"
	void __fastcall DataModuleCreate(TObject *Sender);
	// Обработчик события "присоединение клиента"
	void __fastcall DSTCPServerTransportConnect(TDSTCPConnectEventObject &Event);
	// Обработчик события "отсоединение клиента"
	void __fastcall DSTCPServerTransportDisconnect(TDSTCPDisconnectEventObject Event);
	// Обработчик события "Разрушение модуля управления сервером"
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
	// Объект для работы с файлом настроек (Settings.ini)
	TIniFile *FSettings;
	// Функция вычисления полного пути к базе данных;
	UnicodeString __fastcall GetDataBaseName ();
	// Компонент, который служит для хранения списка всех соединений сервера;
	TConnectionList *FConnectionList;
	// Функция поиска пользователя по логину и паролю;
	// Возвращаемое значение "Код пользователя"
	// Возвращаемые параметры:
	// Blocked - блокировка пользователя;
	// UserType - тип пользователя;
	int __fastcall GetUserKey (UnicodeString Login, UnicodeString Password, bool &Blocked, int &UserType);
public:		// User declarations
	// Конструктор класса;
	__fastcall TdmServer(TComponent* Owner);
	// Метод выгрузки набора данных из базы данных (TableName - имя таблицы);
	TADOTable* __fastcall GetTable (UnicodeString TableName);
	// Метод выгрузки набора данных из базы данных (SQL - произвольный SQL запрос);
	TADOQuery* __fastcall GetQuery (UnicodeString SQL);
	// Метод выполнения произвольного SQL
	int __fastcall ExecQuery (UnicodeString SQL);

	// Свойства класса:
	__property TConnectionList *ConnectionList = {read=FConnectionList};
};
//---------------------------------------------------------------------------
extern PACKAGE TdmServer *dmServer;
//---------------------------------------------------------------------------
#endif
