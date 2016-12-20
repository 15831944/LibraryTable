#include "TTabRecord.h"

TTabRecord::TTabRecord(TKey k, TData * pVal)
{
	Key = k;
	if (pVal != 0)
		pValue = new TData(*pVal);
	else
		pValue = new TData();
}


void TTabRecord::SetKey(TKey k)
{
	Key = k;
}

TKey TTabRecord::GetKey(void)
{
	return Key;
}

void TTabRecord::SetValuePtr(TData * p)
{
	pValue = new TData(*p);
}

TData * TTabRecord::GetValuePTR(void)
{
	return pValue;
}

TData * TTabRecord::GetCopy()
{
	TData *temp = new TData(*pValue);
	return temp;
}

TTabRecord & TTabRecord::operator=(TTabRecord & tr)
{
	Key = tr.Key;
	pValue = tr.pValue;
	return *this;
}

bool TTabRecord::operator==(const TTabRecord & tr)
{
	return Key == tr.Key;
}

bool TTabRecord::operator<(const TTabRecord & tr)
{
	return Key < tr.Key;
}

bool TTabRecord::operator>(const TTabRecord & tr)
{
	return Key > tr.Key;
}

