#include "stdafx.h"
#include <string>
#include "public.h"

using namespace std;


class Win{
public:
	HWND m_hwnd;


public:
	Win();
	Win(HWND hwnd);
	~Win();

	void Win::MsgBox(string txt);
	void Win::MsgBox(int number);
	void Win::MsgBox(HWND number);
	void Win::MsgBox(HWND hwnd, string txt);
	static void Win::MsgBoxS(string txt);
	static void Win::MsgBoxS(HWND hwnd, string txt);
	

	string Print(string str);



private:


};