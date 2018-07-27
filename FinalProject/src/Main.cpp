#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "Character.h"
#include "Custom_Exception.cpp"

// random number generator that returns a random float
int random_int(const int &from, const int &to)
{
	return rand() % to + from;
};

int main()
{
	srand(static_cast <unsigned> (time(nullptr)));

	std::vector<Character*> characters;

	for (int i = 0; i < 1000; i++)
	{
		std::cout << round((4 * (pow(i + 1, 3))) / 5) << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		int rand_class = (int)(random_int(1, 12));
		bool rand_type = (bool)(random_int(1, 10) % 2);
		Character* new_character = Character::make_character(rand_type, rand_class, "Name", i+1);

		characters.push_back(new_character);
	}

	for (auto character : characters)
	{
		double rand_exp = (double)random_int(100000000, 800000000);
		try {
			character->add_experience(rand_exp);
		}
		catch (NotImplemented e)
		{
			std::cerr << "Non-implemented method call.";
		}
		
		std::cout << character->get_character_class()->get_class_name() << std::endl;
		std::cout << "Level: " << character->get_character_level() << std::endl;
		std::cout << "Current xp: " << character->get_current_experience() << std::endl;
		std::cout << "Exp for next Level: " << character->get_next_level_experience() << std::endl;
		character->print_stats();

		delete (character);
		std::cout << std::endl;
	}
	characters.clear();
	std::cin.get();
	return(0);
}