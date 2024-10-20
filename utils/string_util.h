
#pragma once
#include <string>
#include <numeric>
#include <algorithm>
#include <xfunctional>
#include <iostream>
#include <xlocbuf>
#include <codecvt>

class string_util
{
public:
	string_util();
	~string_util();

public:
	static std::string& trim_l(std::string& str);
};

