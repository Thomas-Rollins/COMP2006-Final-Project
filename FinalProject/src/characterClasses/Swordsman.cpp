#include "Swordsman.h"

const std::string Swordsman::m_class_name = "Swordsman";
const std::string Swordsman::m_class_description = "Swordsman Description Here";

Swordsman::Swordsman(const int &level)
	: CharacterClass(level)
{

}

Swordsman::~Swordsman()
{
}
