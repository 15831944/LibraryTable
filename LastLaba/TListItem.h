#ifndef __TLISTITEM_H
#define __TLISTITEM_H

#include "TTabRecord.h"
class TListItem: public TTabRecord {
protected:
	TListItem *pNext;
public:
	TListItem(TKey k = 0, TData* d = 0, TListItem*p = 0) :TTabRecord(k, d)	{
		pNext = p;
	}

	TListItem* GetNext() { return pNext; }

	TData* GetCopy() { 
		TData* temp = new TData(*this);
		return temp;
	}

	friend class TListTable;
};

#endif