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

#include <iostream>

//==================================
// ##c++ 관련 헤더
//==================================
#include <algorithm>
#include <string>

using namespace std;