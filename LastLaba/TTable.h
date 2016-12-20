#ifndef __TTABLE_H
#define __TTABLE_H

#include "TTabRecord.h"

using namespace System::IO;

class  TTable {
protected:
	int DataCount;  // количество записей в таблице
	int Efficiency; // показатель эффективности выполнения операции
public:
	TTable() { DataCount = 0; Efficiency = 0; } //конструктор
	virtual ~TTable() {};						//деструктор

	// информационные методы
	int GetDataCount() const { return DataCount; }		// к-во записей
	int GetEfficiency() const { return Efficiency; }	// эффективность
	int IsEmpty() const { return DataCount == 0; }		//пуста?
	virtual int IsFull() const = 0;						// заполнена?

	// доступ
	virtual TKey GetKey(void) const = 0;
	virtual TData* GetValuePTR(void) const = 0;

	// основные методы
	virtual TData* FindRecord(TKey k) = 0;				// найти запись
	virtual bool InsRecord(TKey k, TData* pVal) = 0;	// вставить
	virtual void DelRecord(TKey k) = 0;					// удалить запись

	// навигация
	virtual int Reset(void) = 0;				// установить на первую запись
	virtual int IsTabEnded(void) const = 0;		// таблица завершена?
	virtual int GoNext(void) = 0;				// переход к следующей записи
												// (=1 после применения для последней записи таблицы)
	virtual void Display(DataGridView^ Grid) = 0;
	virtual void SaveTable(StreamWriter^ sw) = 0;
	friend class TListTable;
};

#endif