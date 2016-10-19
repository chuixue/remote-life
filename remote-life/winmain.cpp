#include "winmain.h"

Win::Win()
{

}
Win::Win(HWND hwnd)
{

}
Win::~Win()
{

}

void Win::MsgBox(string txt)
{
	MessageBox(this->m_hwnd, Common::toLPCSTR(txt), "Warning", MB_APPLMODAL);
}
void Win::MsgBox(int number)
{
	MsgBox(Common::str(number));
}
void Win::MsgBox(HWND number)
{
	MsgBox(Common::str(number));
}
//ststic function
void Win::MsgBoxS(string txt)
{
	MessageBox(NULL, Common::toLPCSTR(txt), "Warning", MB_APPLMODAL);
}
void Win::MsgBox(HWND hwnd, string txt)
{
	MessageBox(hwnd, Common::toLPCSTR(txt), "Warning", MB_APPLMODAL);
}
void Win::MsgBoxS(HWND hwnd, string txt)
{
	Win w(NULL);
	w.MsgBox(hwnd, txt);
}


string Win::Print(string str)
{
	//SetDlgItemText((HWND)hInst, (int)Debug_Text, str.c_str());
	return str;
}

