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

	/*for (int i = 0; i < 256; i++)
	{
		std::cout << "Level " << i << ": ";
		std::cout << round((4 * (pow(i + 1, 3))) / 5) << std::endl;
	}*/

	for (int i = 0; i < 12; i++)
	{
		int rand_class = (int)(random_int(1, 12));
		bool rand_type = (bool)(random_int(1, 10) % 2);
		Character* new_character = Character::make_character(true, i+1, "Name", 100);

		characters.push_back(new_character);
	}

	for (auto character : characters)
	{
		double rand_exp = (double)random_int(1000, 800000000);
		try {
			character->add_experience(rand_exp);
		}
		catch (NotImplemented e) {}		
		
		std::cout << character->get_character_class()->get_class_name() << std::endl;
		std::cout << "Level: " << character->get_character_level() << std::endl;
		std::cout << "Current xp: " << character->get_current_experience() << std::endl;
		std::cout << "Exp for next Level: " << character->get_next_level_experience() << std::endl;
		character->print_low_stats();
		character->print_high_stats();

		delete (character);
		std::cout << std::endl;
	}

	characters.clear();
	std::cin.get();
	return(0);
}


