#include "debug.h"



HANDLE hMutex;


//若多线程单独调用此函数最好加互斥
LONG DBG::NeedRemovingEditText(LPCTSTR txt, HWND Edit_Debug)
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

void DBG::Print(string str, bool use_date, HWND Edit_Debug)
{
	if (!Edit_Debug)return;
	WaitForSingleObject(hMutex, INFINITE);//*********Lock***********

	string newLine = str + (use_date ? ("\t" + Common::GetLocalTimeS()) : "");
	long lLine = NeedRemovingEditText(newLine.c_str(), Edit_Debug);//检测是否需要清除部分内容
	string ttt = Common::GetEditText(Edit_Debug);
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

	ReleaseMutex(hMutex);//*********unLock***********
	return;
}

//---------------------------------------子类1-------------------------------------
_Debug::_Debug()
{}
_Debug::~_Debug()
{}
_Debug::_Debug(HWND hwnd_win, HWND hwnd_edit)
{
	this->m_hwnd = hwnd_win;
	this->m_hwnd_edit = hwnd_edit;
}
void _Debug::Print(string str, bool use_date)
{
	return DBG::Print(str, use_date, this->m_hwnd_edit);
}

//-----------------------------------子类2------------------------------------------
boost::lockfree::queue<QueueNode, fixed_sized<false> > Debug::QueueMsg(0);
boost::atomic<bool> Debug::stopPrint(false);
HWND Debug::m_hwnd_edit = 0;

Debug::Debug()
{
}
Debug::Debug(HWND hwnd_win, HWND hwnd_edit)
{
	this->m_hwnd = hwnd_win;
	Debug::m_hwnd_edit = hwnd_edit;
	this->Init();
}
Debug::~Debug()
{
}
void Debug::Init()
{
	Debug::stopPrint = false;
	HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Debug::MsgProcess, this, 0, NULL);
	CloseHandle(hThread);
}
void* Debug::MsgProcess(void *args)//void* args
{
	//Debug *pThis = ((Debug *)args);	//Debug *pThis = static_cast<Debug *>(args);
	QueueNode node;
	while (!Debug::stopPrint)
	{
		int p = Debug::QueueMsg.pop(node);
		if (p)DBG::Print(node.data, node.useDate, Debug::m_hwnd_edit);
	};
	return 0;
}
void Debug::Print(string txt, bool use_date)
{
	if (!this->m_hwnd_edit)return;
	QueueNode node(txt, use_date);
	int a = Debug::QueueMsg.push(node);
	int b = a;
}
