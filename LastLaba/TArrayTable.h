#ifndef __TARRAYTABLE_H
#define __TARRAYTABLE_H

using namespace System::Windows::Forms;
#include "TTable.h"
#define TabMaxSize 50

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class  TArrayTable : public TTable {
protected:
	TTabRecord *pRecs;	// память для записей таблицы
	int TabSize;        // макс. возм.количество записей в таблице
	int CurrPos;        // номер текущей записи (нумерация с 0)
public:
	TArrayTable(int Size = TabMaxSize);			// конструктор
	~TArrayTable() { delete[] pRecs; };			// деструктор

	// информационные методы
	virtual int IsFull() const;		// заполнена?
	int GetTabSize() const;			// к-во записей

	// доступ
	virtual TKey GetKey(void) const;
	virtual TData* GetValuePTR(void) const;
	virtual TKey GetKey(TDataPos mode) const;
	virtual TData* GetValuePTR(TDataPos mode) const;

	// основные методы
	virtual TData* FindRecord(TKey k) = 0;			// найти запись
	virtual bool InsRecord(TKey k, TData* pVal) = 0; // вставить
	virtual void DelRecord(TKey k) = 0;				// удалить запись
													//навигация
	virtual int Reset(void);			// установить на первую запись
	virtual int IsTabEnded(void) const; // таблица завершена?
	virtual int GoNext(void);			// переход к следующей записи
										//(=1 после применения для последней записи таблицы)
	virtual int SetCurrentPos(int pos);	// установить текущую запись
	int GetCurrentPos(void) const;		//получить номер текущей записи

	virtual void Display(DataGridView^ Grid);
	virtual void SaveTable(StreamWriter^ sw) = 0;
	friend TSortTable;
};

#endif