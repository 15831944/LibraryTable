#pragma
#include <stack>
//using namespace std;
#include "TTable.h"
#include "TTreeNode.h"

class TTreeTable : public TTable
{
	TTreeNode *pRoot;		//��������� �� ������.
	TTreeNode *pCurrent;	//��������� �� ������� ����.
	int Curr;				//������� ��� ���������.
	TTreeNode** pFind;
	std::stack<TTreeNode*> st;	//���� ��� ����������.
	void DeleteTab(TTreeNode *p);
public:
	TTreeTable() : TTable() { pRoot = pCurrent = 0; pFind = &pRoot; st = std::stack<TTreeNode*>();  Curr = 0; }
	~TTreeTable() { DeleteTab(pRoot); }

	virtual int IsFull() const;						// ���������?

														// ������
	virtual TKey GetKey(void) const;
	virtual TData* GetValuePTR(void) const;

	// �������� ������
	virtual TData* FindRecord(TKey k);				// ����� ������
	virtual bool InsRecord(TKey k, TData* pVal);	// ��������
	virtual void DelRecord(TKey k);					// ������� ������

														// ���������
	virtual int Reset(void);				// ���������� �� ������ ������
	virtual int IsTabEnded(void) const;		// ������� ���������?
	virtual int GoNext(void);				// ������� � ��������� ������
												// (=1 ����� ���������� ��� ��������� ������ �������)
	virtual void Display(DataGridView^ Grid);
	virtual void SaveTable(StreamWriter^ sw);
};

