#ifndef __TTABLE_H
#define __TTABLE_H

#include "TTabRecord.h"

using namespace System::IO;

class  TTable {
protected:
	int DataCount;  // ���������� ������� � �������
	int Efficiency; // ���������� ������������� ���������� ��������
public:
	TTable() { DataCount = 0; Efficiency = 0; } //�����������
	virtual ~TTable() {};						//����������

	// �������������� ������
	int GetDataCount() const { return DataCount; }		// �-�� �������
	int GetEfficiency() const { return Efficiency; }	// �������������
	int IsEmpty() const { return DataCount == 0; }		//�����?
	virtual int IsFull() const = 0;						// ���������?

	// ������
	virtual TKey GetKey(void) const = 0;
	virtual TData* GetValuePTR(void) const = 0;

	// �������� ������
	virtual TData* FindRecord(TKey k) = 0;				// ����� ������
	virtual bool InsRecord(TKey k, TData* pVal) = 0;	// ��������
	virtual void DelRecord(TKey k) = 0;					// ������� ������

	// ���������
	virtual int Reset(void) = 0;				// ���������� �� ������ ������
	virtual int IsTabEnded(void) const = 0;		// ������� ���������?
	virtual int GoNext(void) = 0;				// ������� � ��������� ������
												// (=1 ����� ���������� ��� ��������� ������ �������)
	virtual void Display(DataGridView^ Grid) = 0;
	virtual void SaveTable(StreamWriter^ sw) = 0;
	friend class TListTable;
};

#endif