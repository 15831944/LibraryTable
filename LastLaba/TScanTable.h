#ifndef __TSCANTABLE_H
#define __TSCANTABLE_H

#include "TArrayTable.h"
class  TScanTable : public TArrayTable {
public:
	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {};	//конструктор

	// основные методы
	virtual TData* FindRecord(TKey k);				//найти запись
	virtual bool InsRecord(TKey k, TData *pVal);	//вставить
	virtual void DelRecord(TKey k);					//удалить запись

	virtual void SaveTable(StreamWriter^ sw);
};

#endif