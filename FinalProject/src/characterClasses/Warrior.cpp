#include "Warrior.h"

const std::string Warrior::m_class_name = "Warrior";
const std::string Warrior::m_class_description = "Warrior Description Here";

Warrior::Warrior(const int &level)
	: CharacterClass(level)
{

}

Warrior::~Warrior()
{
}
