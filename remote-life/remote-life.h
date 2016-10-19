#pragma once

#include "resource.h"
#include "public.h"

#include "winmain.h"

#include <string>

#include <sstream>
#include <ctime>
#include <vector>

#include <boost/algorithm/string.hpp>  

using namespace std;
using namespace boost;


int CreateCtronl(HWND hwnd, LPARAM lParam);


void btn_click();

string GetEditText(HWND hwnd);
tm GetLocalTime();
string GetLocalTimeS();


string Print(string str, bool use_date = FALSE);
string Print(int number, bool use_date = FALSE);
void MsgBox(string txt);
void MsgBox(int number);
void MsgBox(HWND number);

#define MAX_EDIT_LENGTH 29800


