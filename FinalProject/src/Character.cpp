#include "Character.h"

#include <iostream>

Character::Character(const std::string &name)
{

}

Character::~Character()
{
	delete m_character_stats;
	std::cout << "Character Entity Deleted" << std::endl;
}

