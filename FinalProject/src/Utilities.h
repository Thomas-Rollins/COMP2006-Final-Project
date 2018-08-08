#pragma once

#include <string>
#include <vector>
#include <iostream>

#ifndef NULL_INDEX
#define NULL_INDEX -1
#endif

#define FILL_WIDTH 30
#define FILL_CHAR '='


class Utilities
{

public:
	static void get_input(const std::string &question, std::string &input);
	static void get_input(const std::string &question, int &input);
	static void draw_message(std::string message);
	static int draw_menu(const std::vector<std::string> &options);

	static int random_int(const int &from, const int &to);
	static float random_float(const float &from, const float &to);

};

