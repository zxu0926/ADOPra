#pragma once
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <xfunctional>
#include <iostream>
#include <xlocbuf>
#include <codecvt>
using namespace std;

#ifdef _UNICODE
#define string_t wstring
#else
#define string_t string
#endif

#define CODE_CONVERT_USE_WIN32

class string_util
{
public:
	string_util();
	~string_util();

public:
	static std::string& trim_l(std::string& str);
	static std::string& trim_r(std::string &str);
};

