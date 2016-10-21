#include "stdafx.h"
#include <string>
#include "public.h"
#include <vector>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>  

using namespace std;
using namespace boost;

class Debug{
public:
	HWND m_hwnd;
	HWND m_hwnd_edit;

public:
	Debug();
	Debug(HWND hwnd_win, HWND hwnd_edit);
	~Debug();
	
	string Print(string str, bool use_date = FALSE);


	string Debug::GetEditText(HWND hwnd=NULL);
	LONG Debug::NeedRemovingEditText(LPCTSTR txt, HWND hWndEdit = NULL);
	static LONG Debug::NeedRemovingEditCtrlText(LPCTSTR txt, HWND hWndEdit);

	
	static DWORD WINAPI ThreadFuncFirst(LPVOID param);

private:


};






DWORD WINAPI ThreadFuncFirst(LPVOID param);