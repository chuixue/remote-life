#pragma once

#include "resource.h"
#include <string.h>
#include <sstream>
#include <ctime>
#include <vector>


#include "public.h"
#include "winmain.h"
#include "debug.h"



//#include <boost/algorithm/string.hpp>  
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>  

#include <boost/thread/thread.hpp>  
#include <boost/lockfree/queue.hpp>  

#include <boost/atomic.hpp>  



using namespace std;
using namespace boost;
using namespace boost::lockfree;

typedef struct QueueNode
{
	tm time;
	char* data;
	QueueNode(string txt = "")
	{
		memset(this, 0x0, sizeof(QueueNode));
		this->time = Common::GetLocalTime();
		long len = txt.length();
		this->data = new char[len + 1];
		strcpy_s(this->data, len + 1, txt.c_str());
	}
}qnode;



int CreateCtronl(HWND hwnd, LPARAM lParam);


void btn_click();

void btn_click2();
void btn_click3();

string Print(string str, bool use_date = FALSE);
string Print(int number, bool use_date = FALSE);
void MsgBox(string txt);
void MsgBox(int number);
void MsgBox(HWND number);

#define MAX_EDIT_LENGTH 29000

//Debug dg;
DWORD WINAPI AcceptProc(LPVOID lpParameter);
//afx_msg void OnEditUpdate(WPARAM wParam, LPARAM lParam);//Important




