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
	//�����������
	TListTable() : TTable()	{
		pFirst = 0; pCurrent = 0; nCurrent = 0; pFind = 0;
	}
	~TListTable() { DeleteTable(); }

	virtual int IsFull() const;		// ���������?

	// ������
	virtual TKey GetKey(void) const;
	virtual TData* GetValuePTR(void) const;

	// �������� ������
	virtual TData* FindRecord(TKey k);			// ����� ������
	virtual bool InsRecord(TKey k, TData* pVal); // ��������
	virtual void DelRecord(TKey k);				// ������� ������

	//���������
	virtual int Reset(void);			// ���������� �� ������ ������
	virtual int IsTabEnded(void) const; // ������� ���������?
	virtual int GoNext(void);			// ������� � ��������� ������
										//(=1 ����� ���������� ��� ��������� ������ �������)
	virtual int SetCurrentPos(int pos);	// ���������� ������� ������
	int GetCurrentPos(void) const;		//�������� ����� ������� ������

	virtual void Display(DataGridView^ Grid);
	virtual void SaveTable(StreamWriter^ sw);
};

#endif