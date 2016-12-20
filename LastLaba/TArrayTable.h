#ifndef __TARRAYTABLE_H
#define __TARRAYTABLE_H

using namespace System::Windows::Forms;
#include "TTable.h"
#define TabMaxSize 50

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class  TArrayTable : public TTable {
protected:
	TTabRecord *pRecs;	// ������ ��� ������� �������
	int TabSize;        // ����. ����.���������� ������� � �������
	int CurrPos;        // ����� ������� ������ (��������� � 0)
public:
	TArrayTable(int Size = TabMaxSize);			// �����������
	~TArrayTable() { delete[] pRecs; };			// ����������

	// �������������� ������
	virtual int IsFull() const;		// ���������?
	int GetTabSize() const;			// �-�� �������

	// ������
	virtual TKey GetKey(void) const;
	virtual TData* GetValuePTR(void) const;
	virtual TKey GetKey(TDataPos mode) const;
	virtual TData* GetValuePTR(TDataPos mode) const;

	// �������� ������
	virtual TData* FindRecord(TKey k) = 0;			// ����� ������
	virtual bool InsRecord(TKey k, TData* pVal) = 0; // ��������
	virtual void DelRecord(TKey k) = 0;				// ������� ������
													//���������
	virtual int Reset(void);			// ���������� �� ������ ������
	virtual int IsTabEnded(void) const; // ������� ���������?
	virtual int GoNext(void);			// ������� � ��������� ������
										//(=1 ����� ���������� ��� ��������� ������ �������)
	virtual int SetCurrentPos(int pos);	// ���������� ������� ������
	int GetCurrentPos(void) const;		//�������� ����� ������� ������

	virtual void Display(DataGridView^ Grid);
	virtual void SaveTable(StreamWriter^ sw) = 0;
	friend TSortTable;
};

#endif