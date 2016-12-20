#include "TArrayTable.h"

TArrayTable::TArrayTable(int Size)
{
	TabSize = Size;
	CurrPos = 0;
	pRecs = new TTabRecord[TabSize];
	for (int i = 0; i < Size; i++)
		pRecs[i] = *new TTabRecord(0,0);
}

int TArrayTable::IsFull() const
{
	if (DataCount == TabSize)
		return 1;
	return 0;
}

int TArrayTable::GetTabSize() const
{
	return TabSize;
}

TKey TArrayTable::GetKey(void) const
{
	return pRecs[CurrPos].GetKey();
}

TData * TArrayTable::GetValuePTR(void) const
{
	return pRecs[CurrPos].GetValuePTR();
}

TKey TArrayTable::GetKey(TDataPos mode) const
{
	switch (mode)
	{
	case FIRST_POS: return pRecs[0].GetKey();
		break;
	case CURRENT_POS: return pRecs[CurrPos].GetKey();
		break;
	case LAST_POS: return pRecs[DataCount-1].GetKey();
		break;	
	}
	return 0;
}

TData * TArrayTable::GetValuePTR(TDataPos mode) const
{
	switch (mode)
	{
	case FIRST_POS: return pRecs[0].GetValuePTR();
		break;
	case CURRENT_POS: return pRecs[CurrPos].GetValuePTR();
		break;
	case LAST_POS: return pRecs[DataCount-1].GetValuePTR();
		break;
	}
	return 0;
}

int TArrayTable::Reset(void)
{
	CurrPos = 0;
	return 0;
}

int TArrayTable::IsTabEnded(void) const
{	
	if (CurrPos == DataCount-1)
		return 1;
	return 0;
}

int TArrayTable::GoNext(void)
{
	if (CurrPos < DataCount)
	{
		CurrPos++;
		return 0;
	}
	else
	{
		return 1;
	}
}

int TArrayTable::SetCurrentPos(int pos)
{
	if (pos > TabSize)
		return 0;
	CurrPos = pos;
	return 1;
}

int TArrayTable::GetCurrentPos(void) const
{
	return CurrPos;
}

void TArrayTable::Display(DataGridView ^ Grid)
{
	Grid->ColumnCount = 5;
	Grid->RowCount = DataCount + 1;
	Grid->Rows[0]->Cells[0]->Value = "№ Билета";
	Grid->Rows[0]->Cells[1]->Value = "Имя";
	Grid->Rows[0]->Cells[2]->Value = "Фамилия";
	Grid->Rows[0]->Cells[3]->Value = "Отчество";
	Grid->Rows[0]->Cells[4]->Value = "Адрес";
	if (DataCount != 0) {
		for (int i = 1; i < DataCount+1; i++)
		{
			Grid->Rows[i]->Cells[0]->Value = pRecs[i-1].Key;
			Grid->Rows[i]->Cells[1]->Value = pRecs[i-1].pValue->GetName();
			Grid->Rows[i]->Cells[2]->Value = pRecs[i-1].pValue->GetFaml();
			Grid->Rows[i]->Cells[3]->Value = pRecs[i-1].pValue->GetOtch();
			Grid->Rows[i]->Cells[4]->Value = pRecs[i-1].pValue->GetAddress();

		}
	}
}
