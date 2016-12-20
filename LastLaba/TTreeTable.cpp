#include "TTreeTable.h"

void TTreeTable::DeleteTab(TTreeNode *p)
{
	if (p != 0)
	{
		DeleteTab(p->pLeft);
		DeleteTab(p->pRight);
		delete p;
	}
}

int TTreeTable::IsFull() const
{
	TTreeNode* node = new TTreeNode();
	if (node != 0)
		return 1;
	return 0;
}

int TTreeTable::Reset()
{
	TTreeNode *node = pCurrent = pRoot;
	while (!st.empty())
		st.pop();
	Curr = 0;
	while (node != 0)
	{
		st.push(node);
		pCurrent = node;
		node = node->GetLeft();
	}
	return IsTabEnded();
}

int TTreeTable::IsTabEnded() const
{
	if (Curr >= DataCount)
		return 0;
	else
		return 1;
}

int TTreeTable::GoNext()
{
	st.pop();
	pCurrent = (pCurrent->pRight);
	while (pCurrent != 0) {
		st.push(pCurrent);
		pCurrent = (pCurrent->pLeft);
	}
	if (!st.empty()) {
		pCurrent = st.top();
	}
	Curr++;
	return 0;
}

void TTreeTable::Display(DataGridView ^ Grid)
{
	Grid->ColumnCount = 5;
	Grid->RowCount = DataCount + 1;
	Grid->Rows[0]->Cells[0]->Value = "№ Билета";
	Grid->Rows[0]->Cells[1]->Value = "Имя";
	Grid->Rows[0]->Cells[2]->Value = "Фамилия";
	Grid->Rows[0]->Cells[3]->Value = "Отчество";
	Grid->Rows[0]->Cells[4]->Value = "Адрес";
	if (DataCount != 0) {
		int k = 1;
		for (Reset(); IsTabEnded(); GoNext())
		{
			if (pCurrent != 0)
			{
				Grid->Rows[k]->Cells[0]->Value = pCurrent->Key;
				Grid->Rows[k]->Cells[1]->Value = pCurrent->pValue->GetName();
				Grid->Rows[k]->Cells[2]->Value = pCurrent->pValue->GetFaml();
				Grid->Rows[k]->Cells[3]->Value = pCurrent->pValue->GetOtch();
				Grid->Rows[k]->Cells[4]->Value = pCurrent->pValue->GetAddress();
			}
			k++;
		}
	}
}

void TTreeTable::SaveTable(StreamWriter ^ sw)
{
	sw->WriteLine("TreeTable;" + DataCount.ToString());
	sw->WriteLine("№ Билета;Имя;Фамилия;Отчество;Адрес");
	if (DataCount != 0) {
		for (Reset(); IsTabEnded(); GoNext())
		{
			sw->WriteLine(pCurrent->Key.ToString() + ";" +
				pCurrent->pValue->GetName() + ";" +
				pCurrent->pValue->GetFaml() + ";" +
				pCurrent->pValue->GetOtch() + ";" +
				pCurrent->pValue->GetAddress());
		}
	}
}

TKey TTreeTable::GetKey() const
{
	if (pCurrent != 0)
		return pCurrent->GetKey();
	else
		return 0;
}

TData * TTreeTable::GetValuePTR(void) const
{
	if (pCurrent != 0)
		return pCurrent->GetCopy();
	else
		return 0;
}

TData * TTreeTable::FindRecord(TKey k)
{
	TTreeNode* node = pRoot;
	pFind = &pRoot;
	while (node != 0)
	{
		if (node->GetKey() == k)
			break;
		if (node->GetKey() < k)
			pFind = &node->pRight;
		else
			pFind = &node->pLeft;
		node = *pFind;
	}
	if (node != 0)
		return node->pValue;
	return 0;
}

bool TTreeTable::InsRecord(TKey k, TData * pVal)
{
	if (!FindRecord(k))
	{
		DataCount++;
		*pFind = new TTreeNode(k, pVal);
		return true;
	}
	return false;
}

void TTreeTable::DelRecord(TKey k)
{
	if (!FindRecord(k))
		return;
	else
	{
		TTreeNode* node = *pFind;
		TTreeNode* temp = *pFind;
		TTreeNode* Max = *pFind;
		if (temp->pLeft == 0)
		{
			*pFind = temp->pRight;
			delete temp;
			DataCount--;
			return;
		}
		else
			if (temp->pRight == 0)
			{
				*pFind = temp->pLeft;
				delete temp;
				DataCount--;
				return;
			}
			else
			{
				Max = Max->pLeft;
				if (Max->pRight == 0)
					node = Max->pLeft;
				else
				{
					while (Max->pRight != 0)
					{
						temp = Max;
						Max = Max->pRight;
					}
					node->pValue = Max->pValue;
					temp->pRight = Max->pLeft;
				}
			}
		delete Max;
		DataCount--;
	}
}
