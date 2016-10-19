// remote-life.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "remote-life.h"

#define MAX_LOADSTRING 100



// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

HWND Login_Button;          //登录按钮  
HWND Reset_Button;          //登录信息重置  
HWND Update_Button;     //发送信息重置  
HWND Send_Button;
HWND Edit_Debug;
HWND m_hwnd;



//**************************************************************
// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);




//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	HDC hdcStatic;
	HBRUSH hbrBkgnd = NULL;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDB_BUTTON_LOGIN:
			btn_click();
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// TODO:  在此添加任意绘图代码...
		EndPaint(hWnd, &ps);
		break;
	case WM_CREATE:
		CreateCtronl(hWnd, lParam);
		break;
	case WM_CTLCOLOREDIT:
		if ((HWND)lParam == Edit_Debug)
		{
			hdcStatic = (HDC)wParam;
			SetTextColor(hdcStatic, RGB(0, 255, 0));
			SetBkColor(hdcStatic, RGB(0, 0, 0));
			if (hbrBkgnd == NULL)hbrBkgnd = CreateSolidBrush(RGB(0, 0, 0));
			return (INT_PTR)hbrBkgnd;
		}
		//SetScrollPos(m_hwnd, IDE_EDIT_DEBUG, );
		//int x, int y;
		//GetScrollRange(m_hwnd, IDE_EDIT_DEBUG, &x, &y);
		
		break;
	case WM_SIZE:
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	
	return 0;
}
void btn_click()
{	
	//MsgBox(m_hwnd);
	//MsgBox(Edit_Debug);
	//MsgBox(x);

	vector<string> strs;
	string line = "12345\r\n\r\nHello\r\nOK\r\n";
	line = "sndjdbsssndfjwnsssfejnesssnn";
	boost::split(strs, line, boost::is_any_of("sss"));
	
	for (size_t i = 0; i < strs.size(); i++)
		Print(strs[i]);
		//cout << strs[i] << endl;
	//Print(line);
	Print("Finish");
	Print("Finish");
	Print("Finish");
	return;
	long l;
	for (int i = 0; i < 1000; i++)
	{
		Print("int SetScrollPos(", TRUE);
		l = GetWindowTextLength(Edit_Debug);
		Print(l);
		//32767
	}

	
}



int CreateCtronl(HWND hWnd, LPARAM lParam)
{
	Login_Button = CreateWindow(TEXT("button"),//必须为：button   
		TEXT("连接"),//按钮上显示的字符      
		WS_CHILD | WS_VISIBLE,
		550, 10, 75, 25,            //x,y,宽,高  
		hWnd, (HMENU)IDB_BUTTON_LOGIN,//添加按钮ID  
		((LPCREATESTRUCT)lParam)->hInstance, NULL);

	Reset_Button = CreateWindow(TEXT("button"),//必须为：button      
		TEXT("断开"),//按钮上显示的字符      
		WS_CHILD | WS_VISIBLE,
		550, 45, 75, 25,            //x,y,宽,高  
		hWnd, (HMENU)IDB_BUTTON_RESET,//绑定按钮ID  
		((LPCREATESTRUCT)lParam)->hInstance, NULL);
	
	Edit_Debug = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_WANTRETURN | ES_MULTILINE | ES_AUTOVSCROLL,
		10, 120, 613, 200, hWnd, (HMENU)IDE_EDIT_DEBUG, NULL, NULL);


	return 0;
}


string GetEditText(HWND hwnd)
{
	char* txt;
	long len;
	len = GetWindowTextLength(Edit_Debug);
	txt = new char[len + 1];
	txt[len] = '\0';
	GetWindowText(Edit_Debug, txt, len + 1);
	return txt;
}
tm GetLocalTime()
{
	string txt;
	stringstream sstemp;
	time_t rawtime;
	struct tm _tm;
	time(&rawtime);
	localtime_s(&_tm, &rawtime);
	return _tm;
}
string GetLocalTimeS()
{
	struct tm _tm = GetLocalTime();
	string txtD, txtT;
	stringstream sstemp;
	sstemp << _tm.tm_year + 1900 << "-" << _tm.tm_mon + 1 << "-" << _tm.tm_mday << " ";
	sstemp << _tm.tm_hour << ":" << _tm.tm_min << ":" << _tm.tm_sec;
	sstemp >> txtD;
	sstemp >> txtT;
	return txtD + " " + txtT;
}

string Print(string str, bool use_date)
{
	/*
	string txt = GetEditText(Edit_Debug);
	txt += str + (use_date ? ("\t" + GetLocalTimeS()) : "");
	txt += "\r\n";
	SetDlgItemText((HWND)m_hwnd, IDE_EDIT_DEBUG, txt.c_str());
	int x, y;
	GetScrollRange(Edit_Debug, SB_VERT, &x, &y);
	SetScrollPos(Edit_Debug, SB_VERT, y, FALSE);
	
	int len = GetWindowTextLength(Edit_Debug);
	string newLine = str + (use_date ? ("\t" + GetLocalTimeS()) : "");

	if (MAX_EDIT_LENGTH< (len + newLine.length))txt = str
*/
	//string txt = 

	string newLine = str + (use_date ? ("\t" + GetLocalTimeS()) : "");
	string txt = newLine;
	txt += "\r\n";
	int len = GetWindowTextLength(Edit_Debug);
	

	SetFocus(Edit_Debug); // set focus	
	SendMessageA(Edit_Debug, EM_SETSEL, (WPARAM)len, (LPARAM)len);
	SendMessageA(Edit_Debug, EM_REPLACESEL, 0, (LPARAM)txt.c_str());
	return str;
}
string Print(int number, bool use_date)
{
	return Print(Common::str(number), use_date);
}
void MsgBox(string txt)
{
	Win w = Win(m_hwnd);
	w.MsgBox(txt);
}
void MsgBox(int number)
{
	MsgBox(Common::str(number));
}
void MsgBox(long number)
{
	MsgBox(Common::str(number));
}
void MsgBox(HWND number)
{
	Win w = Win(m_hwnd);
	w.MsgBox(number);
}





//------------------------------------------------------------------------------------------------------------
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_REMOTELIFE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REMOTELIFE));

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_REMOTELIFE));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_REMOTELIFE);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // 将实例句柄存储在全局变量中

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 650, 400, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}
	m_hwnd = hWnd;


	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

//