#ifndef __TSCANTABLE_H
#define __TSCANTABLE_H

#include "TArrayTable.h"
class  TScanTable : public TArrayTable {
public:
	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {};	//�����������

	// �������� ������
	virtual TData* FindRecord(TKey k);				//����� ������
	virtual bool InsRecord(TKey k, TData *pVal);	//��������
	virtual void DelRecord(TKey k);					//������� ������

	virtual void SaveTable(StreamWriter^ sw);
};

#endif