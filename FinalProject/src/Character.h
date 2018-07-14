#pragma once


#include "characterClasses/CharacterClass.h"

class Character
{
public:
	Character(CharacterClass character_class, std::string name);

private:
	CharacterClass m_character_class;
	std::string m_name;
	
	int m_level;
	double m_experience;

	void set_name(std::string name);
};
