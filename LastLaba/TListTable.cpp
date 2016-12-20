#include "TListTable.h"

void TListTable::DelItem(TListItem * del)
{
	if (del == pFirst)
		pFirst = pFirst->pNext;
	else
	{
		TListItem* i;
		for (i = pFirst; i->pNext != del; i = i->pNext) {}
		i->pNext = del->pNext;
	}
	delete del;
}

void TListTable::DeleteTable()
{
	TListItem *i, *del;
	i = pFirst;
	while (i != 0)
	{
		del = i;
		i = i->pNext;
		DelItem(del);
	}
	pFirst = 0;
}

int TListTable::IsFull() const
{
	TListItem* item = new TListItem();
	if (item != 0)
		return 1;
	return 0;
}

TKey TListTable::GetKey(void) const
{
	return pCurrent->Key;
}

TData * TListTable::GetValuePTR(void) const
{
	return pCurrent->pValue;
}

TData * TListTable::FindRecord(TKey k)
{
	for (TListItem* i = pFirst; i != 0; i = i->pNext)
		if (i->Key == k)
		{
			return i->pValue;
			pFind = i;
		}
	return 0;
}

bool TListTable::InsRecord(TKey k, TData * pVal)
{
	if (!FindRecord(k))	{}
	else return false;
	if (DataCount < ListMaxSize)
	{
		DataCount++;
		TListItem* p = new TListItem(k, pVal);
		if (pFirst == 0)
		{
			pFirst = p;
		}
		else
		{
			if (k < pFirst->Key)
			{
				p->pNext = pFirst;
				pFirst = p;
			}
			else
			{
				TListItem* prev = pFirst;
				if (prev->pNext == 0)
				{
					prev->pNext = p;
					return true;
				}
				TListItem* curr = pFirst->pNext;
				while ((prev->pNext != 0) && (k > curr->Key))
				{
					prev = prev->pNext;
					curr = curr->pNext;
				}
				if (curr == 0)
					prev->pNext = p;
				else
				{
					prev->pNext = p;
					p->pNext = curr;
				}
			}
		}
	}
	return true;
}

void TListTable::DelRecord(TKey k)
{
	for (TListItem* i = pFirst; i != 0; i = i->pNext)
		if (i->Key == k)
		{
			DelItem(i);
			DataCount--;
			break;
		}
}

int TListTable::Reset(void)
{
	pCurrent = pFirst;
	nCurrent = 0;
	return 0;
}

int TListTable::IsTabEnded(void) const
{
	if (pCurrent->pNext == 0)
		return 1;
	return 0;
}

int TListTable::GoNext(void)
{
	if (pCurrent->pNext != 0)
	{
		pCurrent = pCurrent->pNext;
		return 0;
	}
	else
	{
		return 1;
	}
}

int TListTable::SetCurrentPos(int pos)
{
	int k = 0;
	for (TListItem* i = pFirst; i != 0; i = i->pNext)
	{
		if (k == pos)
		{
			pCurrent = i;
			break;
		}
		k++;
	}
	nCurrent = pos;
	return 1;
}

int TListTable::GetCurrentPos(void) const
{
	return nCurrent;
}

void TListTable::Display(DataGridView ^ Grid)
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
		for (TListItem* i = pFirst; i != 0; i = i->pNext)
		{
			Grid->Rows[k]->Cells[0]->Value = i->Key;
			Grid->Rows[k]->Cells[1]->Value = i->pValue->GetName();
			Grid->Rows[k]->Cells[2]->Value = i->pValue->GetFaml();
			Grid->Rows[k]->Cells[3]->Value = i->pValue->GetOtch();
			Grid->Rows[k]->Cells[4]->Value = i->pValue->GetAddress();
			k++;
		}
	}
}

void TListTable::SaveTable(StreamWriter ^ sw)
{
	sw->WriteLine("ListTable;" + DataCount.ToString());
	sw->WriteLine("№ Билета;Имя;Фамилия;Отчество;Адрес");
	if (DataCount != 0) {
		for (TListItem* i = pFirst; i != 0; i = i->pNext)
		{
			sw->WriteLine(i->Key.ToString() + ";" +
				i->pValue->GetName() + ";" +
				i->pValue->GetFaml() + ";" +
				i->pValue->GetOtch() + ";" +
				i->pValue->GetAddress());
		}
	}
}
