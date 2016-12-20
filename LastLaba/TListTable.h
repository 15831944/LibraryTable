#ifndef __TLISTTABLE_H
#define __TLISTTABLE_H

#include "TListItem.h"
#include "TTable.h"
#define ListMaxSize 1000

class TListTable : public TTable {
	TListItem* pFirst;
	TListItem* pCurrent;
	int nCurrent;
	void DelItem(TListItem* del);
	void DeleteTable();
	TListItem* pFind;
public:
	//конструктор
	TListTable() : TTable()	{
		pFirst = 0; pCurrent = 0; nCurrent = 0; pFind = 0;
	}
	~TListTable() { DeleteTable(); }

	virtual int IsFull() const;		// заполнена?

	// доступ
	virtual TKey GetKey(void) const;
	virtual TData* GetValuePTR(void) const;

	// основные методы
	virtual TData* FindRecord(TKey k);			// найти запись
	virtual bool InsRecord(TKey k, TData* pVal); // вставить
	virtual void DelRecord(TKey k);				// удалить запись

	//навигация
	virtual int Reset(void);			// установить на первую запись
	virtual int IsTabEnded(void) const; // таблица завершена?
	virtual int GoNext(void);			// переход к следующей записи
										//(=1 после применения для последней записи таблицы)
	virtual int SetCurrentPos(int pos);	// установить текущую запись
	int GetCurrentPos(void) const;		//получить номер текущей записи

	virtual void Display(DataGridView^ Grid);
	virtual void SaveTable(StreamWriter^ sw);
};

#endif