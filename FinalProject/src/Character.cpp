#include "Character.h"
#include "characterClasses/CharacterClass.h"
#include "NPC.h"
#include "PlayableCharacter.h"

#include <iostream>


Character* Character::make_character(bool npc, const int &class_id, const std::string &name, const int &level)
{
	if (npc)
	{
		return new NPC(name, class_id, level);
	}
	else
	{
		return new PlaybleCharacter(name, class_id);
	}
}

Character::Character() 
{
	
}

Character::Character(const std::string &name, const int &class_id)
	:m_name(name)
{
	m_character_stats = new ClassStatistics();
	m_character_class = CharacterClass::make_character_class(class_id);
}

Character::Character(const std::string &name, const int &class_id, const int &level)
	:m_name(name), m_level(level)
{
	m_character_stats = new ClassStatistics();
	m_character_class = CharacterClass::make_character_class(class_id);
}

Character::~Character()
{
	delete m_character_stats;
	delete m_character_class;
	std::cout << "Character Entity Deleted" << std::endl;
}

ClassStatistics* Character::get_character_stats()
{
	return m_character_stats;
}

void Character::set_character_level(const int &level)
{
	m_level = level;
}

void Character::print_low_stats()
{
	std::cout << "AGI: " << get_character_stats()->get_base_value(agility_id) << "\tDEX: "
		<< get_character_stats()->get_base_value(dexterity_id) << "\tFCS: " <<
		get_character_stats()->get_base_value(focus_id) << std::endl << "INT: " <<
		get_character_stats()->get_base_value(intelligence_id) << "\tLUC: " <<
		get_character_stats()->get_base_value(luck_id) << "\tSTR: " <<
		get_character_stats()->get_base_value(strength_id) << std::endl << "TEC: " <<
		get_character_stats()->get_base_value(technique_id) << "\tVIT: " <<
		get_character_stats()->get_base_value(vitality_id) << "\tWIS: " <<
		get_character_stats()->get_base_value(wisdom_id) << std::endl;
}

void Character::print_high_stats()
{
	std::cout << "HP: " << get_character_stats()->get_base_value(health_id) << "\tMP: "
		<< get_character_stats()->get_base_value(mana_id) << "\tSP: "
		<< get_character_stats()->get_base_value(skill_points_id) << std::endl << "ATK: "
		<< get_character_stats()->get_base_value(atk_id) << "\tDEF: "
		<< get_character_stats()->get_base_value(def_id) << std::endl << "MGK: "
		<< get_character_stats()->get_base_value(magic_id) << "\tMND: "
		<< get_character_stats()->get_base_value(mind_id) << std::endl << "ACC: "
		<< get_character_stats()->get_base_value(accuracy_id) << "\tEVD: "
		<< get_character_stats()->get_base_value(evasion_id) << "\tCRT: "
		<< get_character_stats()->get_base_value(critical_id) << "\tLUK: "
		<< get_character_stats()->get_base_value(luck_id) << std::endl;
}
