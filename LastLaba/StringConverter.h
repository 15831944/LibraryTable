#include <string>

typedef std::string string;
using namespace System;

string ToSTDstring(String^ s)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	string res = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return res;
}
