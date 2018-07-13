#include "CharacterClass.h"



CharacterClass::CharacterClass(std::string name, Low_Statistics inital_stats)
	: m_low_stats(inital_stats)
{
	//#TODO: entry validation
	m_name = name;
}

CharacterClass::~CharacterClass() {}