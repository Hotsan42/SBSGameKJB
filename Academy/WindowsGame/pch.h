#pragma once

//�̸������ϵ� ����� �ٸ� cpp���� ù�ٿ� #include " " ������Ѵ�

//========================================
// ## Windows Api ������ �� �ʿ��� ���##
//========================================
#include <sdkddkver.h>
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <windowsx.h>

#include <iostream>
#include <format>
#pragma comment (linker, "/entry:wWinMainCRTStartup /subsystem:console")

//==================================
// ## c++ ���� ��� ##
//==================================
#include <algorithm>
#include <string>
using namespace std;

//==================================
// ## STD ���� ��� ##
//==================================


//==================================
// ## �ڷᱸ�� ���� ��� ##
//==================================
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>


//==================================
// ## Define ���� ##
//==================================
#include "Defines.h"

//==================================
// ## Custom ���
//==================================
#include "CommonFunction.h"

