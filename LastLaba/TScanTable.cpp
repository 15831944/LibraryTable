#include "TScanTable.h"

TData * TScanTable::FindRecord(TKey k)
{
	for (int i = 0; i < DataCount; i++)
	{
		if (k == pRecs[i].GetKey())
		{
			return pRecs[i].GetValuePTR();
		}
	}
	return 0;
}

bool TScanTable::InsRecord(TKey k, TData *pVal)
{
	if (!FindRecord(k)) {}
	else return false;
	if (IsFull())
		return false;
	else
	{
		pRecs[DataCount] = TTabRecord(k, pVal);
		DataCount++;
		return true;
	}
}

void TScanTable::DelRecord(TKey k)
{
	for (int i = 0; i < DataCount; i++)
	{
		if (k == pRecs[i].GetKey())
		{
			for (int j = i; j < DataCount - 1; j++)
				pRecs[j] = pRecs[j + 1];
			pRecs[DataCount] = TTabRecord();
			DataCount--;
		}
	}
}

void TScanTable::SaveTable(StreamWriter ^ sw)
{
	sw->WriteLine("ScanTable;" + DataCount.ToString() + ";" + TabSize.ToString());
	sw->WriteLine("№ Билета;Имя;Фамилия;Отчество;Адрес");
	if (DataCount != 0) {
		for (int i = 0; i < DataCount; i++)
		{
			sw->WriteLine(pRecs[i].Key.ToString() + ";" +
				pRecs[i].pValue->GetName() + ";" +
				pRecs[i].pValue->GetFaml() + ";" +
				pRecs[i].pValue->GetOtch() + ";" +
				pRecs[i].pValue->GetAddress());
		}
	}
}
