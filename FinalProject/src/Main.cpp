#include <iostream>

#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "Character.h"

// random number generator that returns a random float
float random_float(const float &from, const float &to)
{
	return from + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (to - from)));
};

int main()
{
	srand(static_cast <unsigned> (time(nullptr)));

	std::vector<Character*> characters;

	for (int i = 0; i < 100; i++)
	{
		int rand_class = (int)(random_float(1, 12));
		Character* new_character = new Character("Test Name", rand_class);

		characters.push_back(new_character);

	}

	for (auto character : characters)
	{
		std::cout << character->get_character_class()->get_class_name() << std::endl;
		delete (character);
		std::cout << std::endl;
	}
	characters.clear();
	std::cin.get();
	return(0);
}