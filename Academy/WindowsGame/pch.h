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

#include <iostream>
#include <format>
#pragma comment (linker, "/entry:wWinMainCRTStartup /subsystem:console")
using namespace std;
//==================================
// ##c++ ���� ���
//==================================
#include <algorithm>
#include <string>

//==================================
// ## Custom ���
//==================================
#include "CommonFunction.h"

