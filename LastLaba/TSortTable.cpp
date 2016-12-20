#include "TSortTable.h"

void TSortTable::SortData(void)
{
	switch (SortMethod)
	{
		case INSERT_SORT: InsertSort(pRecs, DataCount); break;
		case MERGE_SORT: MergeSort(pRecs, DataCount); break;
		case QUIQ_SORT: QuiqSort(pRecs, DataCount); break;
	}
}

void TSortTable::InsertSort(TTabRecord * pMem, int DataCount)
{
	for (int i = 0; i < DataCount; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (pMem[j] < pMem[j - 1])
			{
				TTabRecord temp = pMem[j];
				pMem[j] = pMem[j - 1];
				pMem[j - 1] = temp;
			}
			else
				break;
		}
	}
}

TTabRecord * TSortTable::merge_sort(TTabRecord *_pRecs, TTabRecord *pBuff, unsigned int left, unsigned int right)
{
	if (left == right)
	{
		pBuff[left] = _pRecs[left];
	}

	unsigned int middle = (unsigned int)((left + right) * 0.5);

	// раздел€й и сортируй
	TTabRecord *l_buff = merge_sort(_pRecs, pBuff, left, middle);
	TTabRecord *r_buff = merge_sort(_pRecs, pBuff, middle + 1, right);

	// сли€ние двух отсортированных половин
	TTabRecord *target = l_buff == _pRecs ? pBuff : _pRecs;

	unsigned int width = right - left, l_cur = left, r_cur = middle + 1;
	for (unsigned int i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right)
		{
			if (l_buff[l_cur].GetKey() < r_buff[r_cur].GetKey())
			{
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle)
		{
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	return target;
}

void TSortTable::MergeSort(TTabRecord * _pRecs, int DataCount)
{
	TTabRecord *pData = _pRecs;
	TTabRecord *pBuff = new TTabRecord[DataCount];
	TTabRecord *pTemp = pBuff;
	pTemp = merge_sort(pData, pBuff, 0, DataCount -1);
	for (int i = 0; i < DataCount; i++) pBuff[i] = pData[i];
	delete pTemp;
}

void TSortTable::QuiqSort(TTabRecord * pMem, int DataCount)
{
	int prior;
	int n1, n2;
	if (DataCount > 1)
	{
		QuiqSplit(pRecs, DataCount, prior);
		n1 = prior + 1;
		n2 = DataCount - n1;
		QuiqSort(pRecs, n1 - 1);
		QuiqSort(pRecs + n1, n2);
	}
}

void TSortTable::QuiqSplit(TTabRecord * pData, int Size, int & Prior)
{
	TTabRecord pPrior = pData[0];
	TTabRecord temp;
	int i1 = 1;
	int i2 = Size - 1;
	while (i1 <= i2)
	{
		while ((i1<Size) && (pData[i1].GetKey() > pPrior.GetKey()))
			i1++;
		while (pData[i2].GetKey() > pPrior.GetKey())
			i2--;
		if (i1 < i2)
		{
			temp = pData[i1];
			pData[i1] = pData[i2];
			pData[i2] = temp;
		}
	}
	pData[0] = pData[i2];
	pData[i2] = pPrior;
	Prior = i2;
	Efficiency += Size;
}

TSortTable::TSortTable(const TScanTable & tab)
{
	*this = tab;
	SortMethod = INSERT_SORT;
	SortData();
}

TSortTable & TSortTable::operator=(const TScanTable &tab)
{
	if (pRecs != 0)
	{
		delete[] pRecs;
		pRecs = 0;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	pRecs = new TTabRecord[TabSize];
	for (int i = 0; i < DataCount; i++)
	{
		pRecs[i] = tab.pRecs[i];

	}
	CurrPos = 0;
	SortMethod = INSERT_SORT;
	SortData();
	return *this;

}

TSortMethod TSortTable::GetSortMethod(void)
{
	return SortMethod;
}

void TSortTable::SetSortMethod(TSortMethod sm)
{
	SortMethod = sm;
}

TData * TSortTable::FindRecord(TKey k)
{
	int low, high, mid;
	//бинарный поиск в отсортированном массиве
	low = 0;
	high = DataCount;
	while (low <= high) {
		mid = (low + high) / 2;
		if (k < pRecs[mid].Key)
			high = mid - 1;
		else if (k > pRecs[mid].Key)
			low = mid + 1;
		else
			return pRecs[mid].pValue;
	}
	return 0;
}

bool TSortTable::InsRecord(TKey k, TData *pVal)
{
	if (!FindRecord(k)) {}
	else return false;
	if (!IsFull())
	{
		int InsPos;
		//поиск места дл€ вставки
		for (int i = 0; i < DataCount; i++)
			if (pRecs[i].Key <= k)
				InsPos = i+1;
		//втавка в нужное место со сдвигом остального
		for (int i = DataCount; i > InsPos; i--)
		{
			pRecs[i] = pRecs[i-1] ;
		}
		pRecs[InsPos] = TTabRecord(k, pVal);
		DataCount++;
		return true;
	}
	return false;
}

void TSortTable::DelRecord(TKey k)
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

void TSortTable::SaveTable(StreamWriter ^ sw)
{
	sw->WriteLine("SortTable;" + DataCount.ToString() + ";" + TabSize.ToString());
	sw->WriteLine("є Ѕилета;»м€;‘амили€;ќтчество;јдрес");
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
