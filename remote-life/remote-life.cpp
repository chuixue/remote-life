// remote-life.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "remote-life.h"

#define MAX_LOADSTRING 100



// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

HWND Login_Button;          //��¼��ť  
HWND Reset_Button;          //��¼��Ϣ����  
HWND Update_Button;     //������Ϣ����  
HWND Send_Button;
HWND Edit_Debug;
HWND m_hwnd;
HWND Exit_Button;



//**************************************************************
// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);




//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
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
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDB_BUTTON_LOGIN:
			btn_click();
			break;
		case IDB_BUTTON_RESET:
			btn_click2();
			break;
		case IDB_BUTTON_EXIT:
			btn_click3();
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

		// TODO:  �ڴ���������ͼ����...
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
int CreateCtronl(HWND hWnd, LPARAM lParam)
{
	Login_Button = CreateWindow(TEXT("button"),//����Ϊ��button   
		TEXT("����"),//��ť����ʾ���ַ�      
		WS_CHILD | WS_VISIBLE,
		550, 10, 75, 25,            //x,y,��,��  
		hWnd, (HMENU)IDB_BUTTON_LOGIN,//��Ӱ�ťID  
		((LPCREATESTRUCT)lParam)->hInstance, NULL);

	Reset_Button = CreateWindow(TEXT("button"),//����Ϊ��button      
		TEXT("�Ͽ�"),//��ť����ʾ���ַ�      
		WS_CHILD | WS_VISIBLE,
		550, 45, 75, 25,            //x,y,��,��  
		hWnd, (HMENU)IDB_BUTTON_RESET,//�󶨰�ťID  
		((LPCREATESTRUCT)lParam)->hInstance, NULL);

	Exit_Button = CreateWindow(TEXT("button"),//����Ϊ��button      
		TEXT("��ֹ"),//��ť����ʾ���ַ�      
		WS_CHILD | WS_VISIBLE,
		550, 75, 75, 25,            //x,y,��,��  
		hWnd, (HMENU)IDB_BUTTON_EXIT,//�󶨰�ťID  
		((LPCREATESTRUCT)lParam)->hInstance, NULL);

	Edit_Debug = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_WANTRETURN | ES_MULTILINE | ES_AUTOVSCROLL,
		10, 120, 613, 200, hWnd, (HMENU)IDE_EDIT_DEBUG, NULL, NULL);

	
	//�ۺϵ�����
	Debug dg = Debug();

	return 0;
}


void btn_click2()
{
	for (int i = 0; i < 800; i++)
	{
		string txt = "sdjhgdhjkdjksn";

		//PushMessage(txt);
		//Print("int SetScrollPos(", TRUE);
		//l = GetWindowTextLength(Edit_Debug);
		//Print(l);
	}
	Print("Hello Every");
	MsgBox(168);
	return;
}
void btn_click3()
{
	//stopPrint = true;
	return;
}
void btn_click()
{	
	//MsgBox(m_hwnd);
	//MsgBox(Edit_Debug);
	//MsgBox(x);

	string txt = "helsdfghjkkjre";
	vector<string> lines;
	string line = "12345\r\n\r\n12345Hello\r\nO1234512345K\r\nabcde";

	//PushMessage(txt);
	//PushMessage(txt);
	
	


	//pool QueThread(3);

	//QueThread.schedule(&Thread_GetQueue);

	//QueThread.wait();
	
	//DWORD dwThreadID = 0;
	//HANDLE hThread = CreateThread(NULL, 0, AcceptProc, (LPVOID)m_hwnd, 0, NULL);
	//CloseHandle(hThread);


	//HANDLE handleFirst = CreateThread(NULL, 0, ThreadFuncEdit, 0, 0, &dwThreadID);
	
	//CreateThread();
	//CloseHandle()
	
	//DWORD dwThreadID = 0;
	//HANDLE handleFirst = CreateThread(NULL, 0, ThreadFuncFirst, 0, 0, &dwThreadID);


}
DWORD WINAPI AcceptProc(LPVOID lpParameter)
{

	HWND hwnd = (HWND)lpParameter;



	return 0;

}
void OnEditUpdate(WPARAM wParam, LPARAM lParam)
{
	string str = (char*)lParam;	int type = (int)wParam;
	switch (type)
	{
	case 0:
		str += " ��ͼ��������.";
		break;
	case 1:
		str += " ����������.";
		break;
	}

	
}



string Print(string str, bool use_date)
{
	//return "";
	string newLine = str + (use_date ? ("\t" + Common::GetLocalTimeS()) : "");
	long lLine = Debug::NeedRemovingEditText(newLine.c_str(), Edit_Debug);//����Ƿ���Ҫ�����������
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

	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_REMOTELIFE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REMOTELIFE));

	// ����Ϣѭ��: 
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
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
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
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

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


// �����ڡ������Ϣ�������
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