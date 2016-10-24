#include "stdafx.h"
#include <string>
#include "public.h"
#include <vector>
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
	bool useDate;
	QueueNode(string txt = "", bool _useDate=false)
	{
		memset(this, 0x0, sizeof(QueueNode));
		this->time = Common::GetLocalTime();
		long len = txt.length();
		this->data = new char[len + 1];
		strcpy_s(this->data, len + 1, txt.c_str());
	}
}qnode;


class DBG{
public:
	static void DBG::Print(string str, bool use_date, HWND hwnd_edit);
	static LONG DBG::NeedRemovingEditText(LPCTSTR txt, HWND hWndEdit);
};

class _Debug:public DBG
{
public:
	HWND m_hwnd;
	HWND m_hwnd_edit;

public:
	_Debug();
	~_Debug();
	_Debug(HWND hwnd_win, HWND hwnd_edit);
	void _Debug::Print(string str, bool use_date = FALSE);
};


//static
class Debug:public DBG
{
public:
	HWND m_hwnd;
	HWND m_hwnd_edit;
	
	boost::lockfree::queue<QueueNode, fixed_sized<false> > QueueMsg;
	
	//MessageQueue QueueMsg;

	boost::atomic<bool> stopPrint;

public:
	Debug();
	Debug(HWND hwnd_win, HWND hwnd_edit);
	~Debug();
	
	
	void Debug::Init();
	void Debug::Print(string str, bool use_date = FALSE);

	static void* Debug::MsgProcess(void *args);

};


