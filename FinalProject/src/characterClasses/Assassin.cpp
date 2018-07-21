#include "Assassin.h"
#include <iostream>

const std::string Assassin::m_class_name = "Assassin";
const std::string Assassin::m_class_description = "Assassin Description Here";

Assassin::Assassin(const int &level)
	: CharacterClass(level)
{

}

Assassin::~Assassin()
{
	
}
