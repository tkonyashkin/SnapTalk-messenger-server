//---------------------------------------------------------------------------

#ifndef uConnectionListH
#define uConnectionListH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "uConnectionInfo.h"
#include <System.SysUtils.hpp>
#include "ufMain.h"
//---------------------------------------------------------------------------
const int c_NotFind = -1;
//---------------------------------------------------------------------------
/*
	Класс для хранения соединений сервера
*/
//---------------------------------------------------------------------------
class TConnectionList : public TObject
{
	private:
	// Список, в котором хранятся информация о соединениях;
	TStringList *FList;
	// Процедура, вызываемая при изменении состояния списка соединений;
	void Change ()
	{
		//
        TThread::Queue (NULL, ConnectionListOnChange);
	}

	protected:

	public:
	// В OnChange записывается процедура, которая будет вызываться при изменении списка;
	TNotifyEvent OnChange;

	// Конструктор класса;
	__fastcall TConnectionList()
	{
		//
		FList = new TStringList ();
	}
	// Деструктор класса;
	__fastcall ~TConnectionList()
	{
		//
        FList->Free ();
	}
	// Функция поиска записи по ключу (возвращает индекс);
	int __fastcall Find (DWORD Key)
	{
		//
		TConnectionInfo* CI;
		// Перебираем список;
		for (int I = 0; I < FList->Count; I ++)
		{
			//
			CI = (TConnectionInfo *) FList->Objects[I];
			// Если ключ найден;
			if (CI->Key == Key)
			{
				// Выскакиваем из функции;
				return I;
			}
		}
		return c_NotFind;
	}
	// Функция добавления в список записи;
	TConnectionInfo* __fastcall AddConnection (DWORD Key)
	{
		//
        //
		TConnectionInfo* CI = NULL;
		// Если такого ключа нет в списке, то создаём новый описатель с этим ключем;
		if (Find (Key) == c_NotFind)
		{

			CI = new TConnectionInfo (Key);
			FList->AddObject("", CI);
			Change ();
		}
		return CI;
	}
	// Функция получения записи по ключу;
	TConnectionInfo* __fastcall GetConnectionKey (DWORD Key)
	{
		// Ищем описатель с указанным ключем;
		int I = Find(Key);
		if (I != c_NotFind)
		{
			// Возвращаем найденный описатель;
			return (TConnectionInfo *) FList->Objects[I];
		}
		return NULL;
	}
	// Функция получения записи по индексу;
	TConnectionInfo* __fastcall GetConnectionIndex (int Index)
	{
		// Если индекс не выходит за пределы индексов списка, то возвращаем описатель;
		if ((Index >= 0) && (Index < FList->Count))
		{
			return (TConnectionInfo *)FList->Objects[Index];
		}
		return NULL;
	}
	// Функция получения копии списка соединения;
	TStrings* __fastcall GetList ()
	{
		//
		TStrings *Result = new TStringList ();
		Result->AddStrings(FList);
		return Result;
	}

	// Функция получения количества элементов в списке;
	int __fastcall GetCount()
	{
		//
		return FList->Count;
    }
	// Удаление элемента из списка;
	void __fastcall DelConnection (DWORD Key)
	{
		//
		// Ищем элемент с указанным ключем;
		int I = Find(Key);
		// Проверяем, нашла ли функция описатель с заданным ключем;
		if (I != c_NotFind)
		{
			// Возвращаем описатель;
			TConnectionInfo *CI = (TConnectionInfo *) FList->Objects[I];
			// Разрушаем его;
			CI->Free();
			// Удаляем запись из списка;
			FList->Delete(I);
			// Выполняем процедуру в OnChange;
			Change ();
		}
	}
	//
	void __fastcall ConnectionListOnChange ()
	{
		//
		try
		{
			fMain->sbMain->Panels->operator [](1)->Text = "Количество активных соединений = " + IntToStr (FList->Count);
			fMain->lbConnections->Items->Clear ();
			for (int I = 0; I < FList->Count ; I ++)
			{
				TConnectionInfo *CI = (TConnectionInfo *)FList->Objects[I];
				fMain->lbConnections->Items->Add ("Поток [" + FloatToStr (CI->Key) + "], Время входа [" + DateTimeToStr (CI->DateTime) + "], IP-адрес [" + CI->IP + "]");
			}
		}
		catch (...)
		{

		}
	}
	__published:

};




#endif
