#pragma once
#include "TTabRecord.h"
class  TTreeNode : public TTabRecord {
protected:
	TTreeNode *pLeft, *pRight; // указатели на поддеревья
public:
	TTreeNode(TKey k = 0, TData *pVal = 0, TTreeNode *pL = 0,
		TTreeNode *pR = 0) : TTabRecord(k, pVal), pLeft(pL), pRight(pR) {};
	TTreeNode* GetLeft(void)  { return pLeft;	} // указатель на левое поддерево
	TTreeNode* GetRight(void) { return pRight; }  // указатель на правое поддерево
	TData *GetCopy() {
		TData* temp = new TData(*this);
		return temp;
	}  // изготовить копию

	friend class TTreeTable;
};
