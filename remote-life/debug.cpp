#include "debug.h"


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

	string newLine = str + (use_date ? ("\t" + Common::GetLocalTimeS()) : "");
	long lLine = NeedRemovingEditText(newLine.c_str(), Edit_Debug);//检测是否需要清除部分内容
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
	return;
}

//---------------------------------------子类1-------------------------------------
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
HWND Debug::m_hwnd = (HWND)0;
HWND Debug::m_hwnd_edit = (HWND)0;
boost::atomic<bool> Debug::stopPrint = boost::atomic<bool>(false);
queue<QueueNode, fixed_sized<false> > Debug::QueueMsg;

Debug::Debug()
{
	this->Init();
}
Debug::Debug(HWND hwnd_win, HWND hwnd_edit)
{
	Debug::m_hwnd = hwnd_win;
	Debug::m_hwnd_edit = hwnd_edit;
	Init();
}
Debug::~Debug()
{

}
void Debug::Init()
{
	this->ThreadMsg.create_thread(Debug::MsgProcess);
}


void Debug::MsgProcess()
{
	Debug::stopPrint = false;
	QueueNode node;
	while (!stopPrint)
	{
		int p = QueueMsg.pop(node);
		if (p)Print(node.data, true);
	};
}

//static
void Debug::Print(string txt, bool use_date, HWND Edit_Debug)
{
	if (!Edit_Debug) Edit_Debug = Debug::m_hwnd_edit;
	if (!Edit_Debug)return;
	QueueNode node(txt);
	Debug::QueueMsg.push(node);
}
