#ifndef __TTABRECORD_H
#define __TTABRECORD_H

using namespace System::Windows::Forms;
#include "TData.h"
#include <string>

typedef int TKey;	//тип ключа записи

// Класс объектов-значений для записей таблицы 
class TTabRecord : public TData {  
protected:        
	TKey Key;		// ключ записи
	TData* pValue;	// указатель на значение
public:  
	TTabRecord(TKey k = 0, TData* pVal = 0);	// конструктор 
	void SetKey(TKey k);		// установить значение ключа
	TKey GetKey(void);			// получить значение ключа
	void SetValuePtr(TData* p);	// установить указатель на данные
	TData* GetValuePTR(void);	// получить указатель на данные
	TData* GetCopy();	// изготовить копию
	
	TTabRecord & operator = (TTabRecord &tr);		// присваивание

	virtual bool operator == (const TTabRecord &tr); // сравнение =
	virtual bool operator < (const TTabRecord &tr);  // сравнение «<»
	virtual bool operator > (const TTabRecord &tr);  // сравнение «>»

	//дружественные классы для различных типов таблиц
	friend class TTable;
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TTreeNode;
	friend class TTreeTable;	
};

#endif