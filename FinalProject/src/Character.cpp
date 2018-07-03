#include "Character.h"

//Character Class Static initializer
int Character::last_id = 0001;




Character::Character(const char* name, const int& character_class, Low_Level_Stats& low_level_stats)
	: m_ID(Character::last_id++), m_NAME(name), m_CHARACTER_CLASS(character_class),
	m_base_low_stats(low_level_stats), m_experience(0)
{
	
}


Character::~Character()
{
	
}


#pragma region Setter_Implementations_Base_Stats
void Character::set_base_vitality(const int& base_vitality)
{
	m_base_low_stats.vitality.value = base_vitality;
}

void Character::set_base_strength(const int& base_strength)
{
	m_base_low_stats.strength.value = base_strength;
}

void Character::set_base_agility(const int& base_agility)
{
	m_base_low_stats.agility.value = base_agility;
}

void Character::set_base_dexterity(const int& base_dexterity)
{
	m_base_low_stats.dexterity.value = base_dexterity;
}

void Character::set_base_technique(const int& base_technique)
{
	m_base_low_stats.technique.value = base_technique;
}

void Character::set_base_intelligence(const int& base_intelligence)
{
	m_base_low_stats.intelligence.value = base_intelligence;
}

void Character::set_base_wisdom(const int& base_wisdom)
{
	m_base_low_stats.wisdom.value = base_wisdom;
}

void Character::set_base_focus(const int& base_focus)
{
	m_base_low_stats.focus.value = base_focus;
}

void Character::set_base_luck(const int& base_luck)
{
	m_base_low_stats.luck.value = base_luck;
}
#pragma endregion