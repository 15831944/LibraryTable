#include "TScanTable.h"
enum TSortMethod { INSERT_SORT, MERGE_SORT, QUIQ_SORT };
class  TSortTable : public TScanTable {
protected:
	TSortMethod SortMethod; // ����� ����������
	void SortData(void);   // ���������� ������
	void InsertSort(TTabRecord *pMem, int DataCount); // ����� �������
	void MergeSort(TTabRecord *pMem, int DataCount);  // ����� �������
	TTabRecord* merge_sort(TTabRecord *_pRecs, TTabRecord *pBuff, unsigned int left, unsigned int right);
	void QuiqSort(TTabRecord *pMem, int DataCount); // ������� ����������
	void QuiqSplit(TTabRecord *pData, int Size, int &Prior);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) {};// �����������
	TSortTable(const TScanTable &tab); // �� ��������������� �������
	TSortTable & operator=(const TScanTable &tab); // ������������
	TSortMethod GetSortMethod(void);    // �������� ����� ����������
	void SetSortMethod(TSortMethod sm);// ���������� ����� ����������
									   // �������� ������
	virtual TData* FindRecord(TKey k); // ����� ������
	virtual bool InsRecord(TKey k, TData *pVal); // ��������
	virtual void DelRecord(TKey k);        // ������� ������

	virtual void SaveTable(StreamWriter^ sw);
};

