#include "TScanTable.h"
enum TSortMethod { INSERT_SORT, MERGE_SORT, QUIQ_SORT };
class  TSortTable : public TScanTable {
protected:
	TSortMethod SortMethod; // метод сортировки
	void SortData(void);   // сортировка данных
	void InsertSort(TTabRecord *pMem, int DataCount); // метод вставок
	void MergeSort(TTabRecord *pMem, int DataCount);  // метод слияния
	TTabRecord* merge_sort(TTabRecord *_pRecs, TTabRecord *pBuff, unsigned int left, unsigned int right);
	void QuiqSort(TTabRecord *pMem, int DataCount); // быстрая сортировка
	void QuiqSplit(TTabRecord *pData, int Size, int &Prior);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) {};// конструктор
	TSortTable(const TScanTable &tab); // из просматриваемой таблицы
	TSortTable & operator=(const TScanTable &tab); // присваивание
	TSortMethod GetSortMethod(void);    // получить метод сортировки
	void SetSortMethod(TSortMethod sm);// установить метод сортировки
									   // основные методы
	virtual TData* FindRecord(TKey k); // найти запись
	virtual bool InsRecord(TKey k, TData *pVal); // вставить
	virtual void DelRecord(TKey k);        // удалить запись

	virtual void SaveTable(StreamWriter^ sw);
};

