#ifndef __TTABRECORD_H
#define __TTABRECORD_H

using namespace System::Windows::Forms;
#include "TData.h"
#include <string>

typedef int TKey;	//��� ����� ������

// ����� ��������-�������� ��� ������� ������� 
class TTabRecord : public TData {  
protected:        
	TKey Key;		// ���� ������
	TData* pValue;	// ��������� �� ��������
public:  
	TTabRecord(TKey k = 0, TData* pVal = 0);	// ����������� 
	void SetKey(TKey k);		// ���������� �������� �����
	TKey GetKey(void);			// �������� �������� �����
	void SetValuePtr(TData* p);	// ���������� ��������� �� ������
	TData* GetValuePTR(void);	// �������� ��������� �� ������
	TData* GetCopy();	// ���������� �����
	
	TTabRecord & operator = (TTabRecord &tr);		// ������������

	virtual bool operator == (const TTabRecord &tr); // ��������� =
	virtual bool operator < (const TTabRecord &tr);  // ��������� �<�
	virtual bool operator > (const TTabRecord &tr);  // ��������� �>�

	//������������� ������ ��� ��������� ����� ������
	friend class TTable;
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TTreeNode;
	friend class TTreeTable;	
};

#endif