#include <iostream>

#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "characterClasses/CharacterClass.h"

// random number generator that returns a random float
float random_float(const float &from, const float &to)
{
	return from + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (to - from)));
};

int main()
{
	srand(static_cast <unsigned> (time(nullptr)));

	std::vector<CharacterClass*> characters;

	for (int i = 0; i < 10; i++)
	{
		int rand_class = (int)(random_float(1, 12));

		characters.push_back(CharacterClass::make_character(i, (std::string)"Char name"));
		
		
	}

	for (auto character : characters)
	{
		std::cout << typeid(*(character)).name() << std::endl;
		delete (character);
		std::cout << std::endl;
	}
	characters.clear();
	
	std::cin.get();
	return(0);
}