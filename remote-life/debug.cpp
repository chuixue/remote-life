#include "debug.h"

Debug::Debug()
{

}
Debug::Debug(HWND hwnd_win, HWND hwnd_edit)
{
	this->m_hwnd = hwnd_win;
	this->m_hwnd_edit = hwnd_edit;

}
Debug::~Debug()
{

}

string Debug::Print(string str, bool use_date)
{
	HWND Edit_Debug = this->m_hwnd_edit;
	string newLine = str + (use_date ? ("\t" + Common::GetLocalTimeS()) : "");
	long lLine = NeedRemovingEditText(newLine.c_str());//检测是否需要清除部分内容
	if (lLine > 0)
	{
		SendMessage(Edit_Debug, EM_SETSEL, (WPARAM)0, (LPARAM)(lLine));
		SendMessage(Edit_Debug, EM_REPLACESEL, (WPARAM)FALSE, NULL);
	}
	string txt = newLine;
	txt += "\r\n";
	int len = GetWindowTextLength(Edit_Debug);
	SetFocus(Edit_Debug); // set focus	
	SendMessageA(Edit_Debug, EM_SETSEL, (WPARAM)len, (LPARAM)len);
	SendMessageA(Edit_Debug, EM_REPLACESEL, 0, (LPARAM)txt.c_str());
	return str;
}

DWORD WINAPI ThreadFuncFirst(LPVOID param)
{
	Debug dg = Debug();
	int iCount = 50;
	while (iCount--){
		string s = "ThreadFuncFirst:" + Common::str(iCount);
		dg.Print(s);
	}
	return 0;
}




LONG Debug::NeedRemovingEditCtrlText(LPCTSTR txt, HWND Edit_Debug)
{
	long nMaxLength = (long)SendMessage(Edit_Debug, EM_GETLIMITTEXT, 0, 0);
	string text_old = Common::GetEditText(Edit_Debug);
	vector<string> lines;
	split_regex(lines, text_old, regex("\r\n"));
	int lCount = lines.size(), lineL = 0;
	long len = GetWindowTextLength(Edit_Debug) + _tcslen(txt) + 2, lLine = 0;
	while (1)
	{
		if (len<nMaxLength)break;
		if (lineL >= lCount)break;
		long _len = _tcslen(lines[lineL].c_str()) + 2;
		len -= _len;
		lLine += _len;
		lineL++;
	}
	return lLine;
}
LONG Debug::NeedRemovingEditText(LPCTSTR txt, HWND Edit_Debug)
{
	if (!Edit_Debug)Edit_Debug = this->m_hwnd_edit;
	return this->NeedRemovingEditCtrlText(txt, Edit_Debug);
}

string Debug::GetEditText(HWND hwnd)
{
	if (!hwnd)hwnd = this->m_hwnd_edit;
	return Common::GetEditText(hwnd);
}

