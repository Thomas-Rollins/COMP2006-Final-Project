#include "Character.h"


Character::Character(CharacterClass character_class, std::string name)
	: m_character_class(character_class)
{
	set_name(m_name);
	m_experience = 0.0;
	m_level = 0;
}


void Character::set_name(std::string name)
{
	//#TODO: Validation
	m_name = name;

}