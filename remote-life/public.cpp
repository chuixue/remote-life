#include "public.h"


Common::Common()
{
}

Common::~Common()
{
}

string Common::toString(int number)
{
	return str(number);
}

//-------------------------------------str---------------------------------------
string Common::str(HINSTANCE number)
{
	return str((int)number);
}
string Common::str(HWND number)
{
	return str((int)number);
}
string Common::str(string txt)
{
	return txt;
}
string Common::str(int number)
{
	return str((long)number);
}
string Common::str(long number)
{
	string txt;
	stringstream ss;
	ss << number;
	ss >> txt;
	return txt;
}

//----------------------------------toLPCSTR----------------------------------
CHAR* Common::toLPCSTR(string txt)
{
	return GetLpcstrByStr(txt);
}
CHAR* Common::toLPCSTR(int number)
{
	return GetLpcstrByStr(str(number));
}
CHAR* Common::toLPCSTR(HINSTANCE number)
{
	return GetLpcstrByStr(str(number));
}
CHAR* Common::toLPCSTR(HWND number)
{
	return GetLpcstrByStr(str(number));
}

//----------------------------------------GetLpcstrByStr-----------------------------------------
CHAR* Common::GetLpcstrByStr(string txt)
{
	string st = txt;
	int length = st.size();
	char* lpstr = new char[length + 1];
	strcpy_s(lpstr, length + 1, (const char*)st.c_str());
	lpstr[length] = '\0';
	return lpstr;
}


