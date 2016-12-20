#include "TData.h"

TData::TData(string _n, string _f, string _o, string _a)
{
	name = _n;
	faml = _f;
	otch = _o;
	address = _a;
}

TData::TData(TData & d)
{

	name = d.name;
	faml = d.faml;
	otch = d.otch;
	address = d.address;
}

TData & TData::operator=(TData & d)
{
	name = d.name;
	faml = d.faml;
	otch = d.otch;
	address = d.address;
	return *this;
}

String ^ TData::GetName()
{
	String^ s = gcnew String(name.c_str());
	return s;
}

String ^ TData::GetFaml()
{
	String^ s = gcnew String(faml.c_str());
	return s;
}

String ^ TData::GetOtch()
{
	String^ s = gcnew String(otch.c_str());
	return s;
}

String ^ TData::GetAddress()
{
	String^ s = gcnew String(address.c_str());
	return s;
}
