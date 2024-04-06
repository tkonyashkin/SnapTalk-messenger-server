//---------------------------------------------------------------------------

#ifndef uConnectionInfoH
#define uConnectionInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
/*
	//
	Структура для хранения данных о конкретном соединении;
*/
//---------------------------------------------------------------------------
class TConnectionInfo : public TObject
{
	private:
	// Уникальный ключ;
	DWORD FKey;
	// Дата и время создания;
	TDateTime FDateTime;
	// IP адрес;
	UnicodeString FIP;
	// Код пользователя;
	int FUserKey;
	//
	int FUserTypeKey;

	public:
	// Конструктор класса;
	__fastcall TConnectionInfo (DWORD Key)
	{
		//
		FKey = Key;
		FDateTime = Now ();
		FUserKey = 0;
	}
	// Деструктор класса;
	__fastcall ~TConnectionInfo ()
	{
		//

	}
	// Свойства класса:
	__property DWORD Key = {read = FKey};
	__property TDateTime DateTime = {read = FDateTime};
	__property UnicodeString IP = {read = FIP, write = FIP};
	__property int UserKey = {read = FUserKey, write = FUserKey};
	__property int UserTypeKey = {read = FUserTypeKey, write = FUserTypeKey};

};
#endif
