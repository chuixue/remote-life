#pragma once

#include "stdafx.h"
#include <string>
#include <sstream>
#include <ctime>


using namespace std;


class Common
{
public:
	Common();
	~Common();

	static string Common::toString(int number);

	static string Common::str(HINSTANCE number);
	static string Common::str(HWND number);
	static string Common::str(string txt);
	static string Common::str(int number);
	static string Common::str(long number);

	static CHAR* Common::toLPCSTR(string txt);
	static CHAR* Common::toLPCSTR(int number);
	static CHAR* Common::toLPCSTR(HINSTANCE number);
	static CHAR* Common::toLPCSTR(HWND number);

	static CHAR* Common::GetLpcstrByStr(string txt);
	static string GetEditText(HWND hwnd);
	
	
	static tm Common::GetLocalTime();
	static string Common::GetLocalTimeS();
	static string Common::GetTimeS(tm _tm);


private:

};



