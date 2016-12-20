#pragma
#include <stack>
//using namespace std;
#include "TTable.h"
#include "TTreeNode.h"

class TTreeTable : public TTable
{
	TTreeNode *pRoot;		//Указатель на корень.
	TTreeNode *pCurrent;	//Указатель на текущий узел.
	int Curr;				//Позиция для итератора.
	TTreeNode** pFind;
	std::stack<TTreeNode*> st;	//Стек для итераторов.
	void DeleteTab(TTreeNode *p);
public:
	TTreeTable() : TTable() { pRoot = pCurrent = 0; pFind = &pRoot; st = std::stack<TTreeNode*>();  Curr = 0; }
	~TTreeTable() { DeleteTab(pRoot); }

	virtual int IsFull() const;						// заполнена?

														// доступ
	virtual TKey GetKey(void) const;
	virtual TData* GetValuePTR(void) const;

	// основные методы
	virtual TData* FindRecord(TKey k);				// найти запись
	virtual bool InsRecord(TKey k, TData* pVal);	// вставить
	virtual void DelRecord(TKey k);					// удалить запись

														// навигация
	virtual int Reset(void);				// установить на первую запись
	virtual int IsTabEnded(void) const;		// таблица завершена?
	virtual int GoNext(void);				// переход к следующей записи
												// (=1 после применения для последней записи таблицы)
	virtual void Display(DataGridView^ Grid);
	virtual void SaveTable(StreamWriter^ sw);
};

