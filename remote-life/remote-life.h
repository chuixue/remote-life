#pragma once

#include "resource.h"
#include <string>
#include <sstream>
#include <ctime>
#include <vector>


#include "public.h"
#include "winmain.h"
#include "debug.h"



//#include <boost/algorithm/string.hpp>  
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>  

using namespace std;
using namespace boost;


int CreateCtronl(HWND hwnd, LPARAM lParam);


void btn_click();



string Print(string str, bool use_date = FALSE);
string Print(int number, bool use_date = FALSE);
void MsgBox(string txt);
void MsgBox(int number);
void MsgBox(HWND number);

#define MAX_EDIT_LENGTH 29000

//Debug dg;


