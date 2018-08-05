#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <sstream>


	void Utilities::get_input(const std::string &question, std::string &input)
	{
		std::cout << question << std::endl;
		std::getline(std::cin, input);
	}

	void Utilities::get_input(const std::string &question, int &input)
	{
		while (true)
		{
			std::cout << question << std::endl;

			std::string tmp;
			std::getline(std::cin, tmp);
			std::stringstream stream(tmp);

			if (stream >> input)
			{
				break;
			}

			std::cout << "Please enter a correct value." << std::endl;
		}
	}

	void Utilities::draw_message(const std::string message)
	{
		std::cout << "\n" << std::endl;
		std::cout << std::setfill('=') << std::setw(30) << "\n";
		std::cout << message << "\n";
		std::cout << std::setfill('=') << std::setw(30) << "\n";
		std::cout << "\n" << std::endl;
	}

	int Utilities::draw_menu(const std::vector<std::string> &options)
	{
		int count = 1;
		for (std::string option : options)
		{
			std::cout << count << ") " << option << std::endl;
			count++;
		}

		std::cout << "\n" << std::endl;
		std::cout << std::setfill('=') << std::setw(30) << "\n";
		std::cout << std::endl;

		int choice;
		get_input("Please choose an option: ", choice);
		return choice;
	}
