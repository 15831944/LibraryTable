#pragma once
#include <string>
typedef std::string string;
using namespace System;

class TData
{
protected:
	string name;
	string faml;
	string otch;
	string address;
public:
	TData(string _n = "", string _f = "", string _o = "", string _a = "");
	TData(TData& d);
	TData &operator=(TData& d);
	String^ GetName();
	String^ GetFaml();
	String^ GetOtch();
	String^ GetAddress();
};

