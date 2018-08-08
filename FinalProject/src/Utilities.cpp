#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <sstream>


	void Utilities::get_input(const std::string &question, std::string &input)
	{
		std::cout << question << std::endl;
		std::getline(std::cin, input);
	}

	bool Utilities::get_input(const std::string &question)
	{
		std::cout << question << std::endl;
		char choice = 'z';
		do {
			char choice = std::cin.get();
			if (choice == 'Y' || choice == 'y')
				return true;
			if (choice == 'N' || choice == 'n')
				return false;
			else
				std::cout << std::endl << "Please enter only 'y' or 'n'" << std::endl;
		} while (choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');
		
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

			std::cout << "Please enter an integer." << std::endl;
		}
	}

	void Utilities::draw_message(const std::string message)
	{
		std::cout << "\n" << std::endl;
		std::cout << std::setfill(FILL_CHAR) << std::setw(FILL_WIDTH) << "\n";
		std::cout << message << "\n";
		std::cout << std::setfill(FILL_CHAR) << std::setw(FILL_WIDTH) << "\n";
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
		std::cout << std::setfill(FILL_CHAR) << std::setw(FILL_WIDTH) << "\n";
		std::cout << std::endl;

		int choice;
		std::string error_msg = "Your choice must be between 1 and " + std::to_string(options.size())
			+ ".\n";
		get_input("Please choose an option: ", choice);
		while (choice > options.size() || choice == 0)
		{
			get_input(error_msg, choice);
		}
		return choice;
	}

	int Utilities::random_int(const int &from, const int &to)
	{
		return rand() % to + from;
	};

	float  Utilities::random_float(const float &from, const float &to)
	{
		return from + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (to - from)));
	}
