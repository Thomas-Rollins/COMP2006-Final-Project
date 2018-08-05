#pragma once

#include <string>
#include <vector>
#include <iostream>



class Utilities
{

public:
	static void get_input(const std::string &question, std::string &input);
	static void get_input(const std::string &question, int &input);
	static void draw_message(std::string message);
	static int draw_menu(const std::vector<std::string> &options);


};

