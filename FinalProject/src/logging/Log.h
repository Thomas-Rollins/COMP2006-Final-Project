#pragma once
#include <iostream>

template<typename T>
void Log(T input)
{
	std::clog << input << std::endl;
}