#pragma once

//미리컴파일된 헤더는 다른 cpp파일 첫줄에 #include " " 해줘야한다

//========================================
// ## Windows Api 구성에 꼭 필요한 헤더##
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
// ## c++ 관련 헤더 ##
//==================================
#include <algorithm>
#include <string>
using namespace std;

//==================================
// ## STD 관련 헤더 ##
//==================================


//==================================
// ## 자료구조 관련 헤더 ##
//==================================
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>


//==================================
// ## Define 설정 ##
//==================================
#include "Defines.h"

//==================================
// ## Custom 헤더
//==================================
#include "CommonFunction.h"

