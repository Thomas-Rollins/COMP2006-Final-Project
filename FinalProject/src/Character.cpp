#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Character.h"
#include "NPC.h"
#include "PlayableCharacter.h"


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

Character::Character(const std::string &name, const int &class_id, const bool isNPC)
	:m_name(name), m_npc(isNPC)
{
	m_character_stats = new ClassStatistics();
	m_character_class = CharacterClass::make_character_class(class_id);
}

Character::Character(const std::string &name, const int &class_id, const int &level, const bool isNPC)
	:m_name(name), m_level(level), m_npc(isNPC)
{
	m_character_stats = new ClassStatistics();
	m_character_class = CharacterClass::make_character_class(class_id);
}

Character::~Character()
{
	delete m_character_stats;
	delete m_character_class;

	//deletes the pointers contained in the array
	for (auto&& ability : m_abilities)
	{
		if(ability != nullptr)
			delete(ability);
	}
	m_abilities.clear();
}

// overloaded operators ...added cause friends aren't happening.
void Character::operator+(const float &health)
{
	float current = m_character_stats->get_current_value(health_id);
	m_character_stats->set_current_value(health_id, current + health);
}

void Character::operator-(const float &health)
{
	float current = m_character_stats->get_current_value(health_id);
	m_character_stats->set_current_value(health_id, current - health);
}

ClassStatistics* Character::get_character_stats()
{
	return m_character_stats;
}

void Character::set_character_level(const int &level)
{
	if (level < STARTING_LEVEL)
		m_level = STARTING_LEVEL;
	else
	{
		if (level > MAX_LEVEL)
			m_level = MAX_LEVEL;
		else
			m_level = level;
	}
}

void Character::addAbility(Ability* newAbility)
{
	m_abilities.push_back(newAbility);
}

void Character::updateAbility_State()
{
	for (auto&& ability : get_abilities())
	{
		if (this->get_character_level() < ability->get_level_requirement() ||
			this->get_character_stats()->get_current_value(mana_id) < ability->get_mp_cost() ||
			this->get_character_stats()->get_current_value(skill_points_id) <
			ability->get_sp_cost())
		{
			ability->setUsable(false);
		}
		else
			ability->setUsable(true);
	}	
}

void Character::print_low_stats()
{
	std::cout << std::setfill(' ') << std::right << std::setw(12)
		<< this->get_name() << "'s basic parameters." << std::endl;
	std::cout << std::setfill(' ') << std::left << "AGI: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(agility_id);
	std::cout << std::setfill(' ') << std::left << "DEX: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(dexterity_id);
	std::cout << std::setfill(' ') << std::left << "FCS: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(focus_id) << std::endl;
	std::cout << std::setfill(' ') << std::left << "INT: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(intelligence_id);
	std::cout << std::setfill(' ') << std::left << "LUK: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(luck_id);
	std::cout << std::setfill(' ') << std::left << "STR: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(strength_id) << std::endl;
	std::cout << std::setfill(' ') << std::left << "TEC: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(technique_id);
	std::cout << std::setfill(' ') << std::left << "VIT: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(vitality_id);
	std::cout << std::setfill(' ') << std::left << "WIS: " << std::left << std::setw(8)
		<< get_character_stats()->get_base_value(wisdom_id) << std::endl << std::endl;
}

void Character::print_high_stats()
{
	std::cout << std::setfill(' ') << std::right << std::setw(12)
		<< this->get_name() << "'s calculated parameters." << std::endl;
	std::cout << std::setw(10) << "HP: " << std::internal
		<< floor(get_character_stats()->get_base_value(health_id));
	std::cout << std::setw(10) << "MP: " << std::internal
		<< floor(get_character_stats()->get_base_value(mana_id));
	std::cout << std::setw(10) << "SP: " << std::internal
		<< floor(get_character_stats()->get_base_value(skill_points_id)) << std::endl;
	std::cout << std::left << "ATK: " << std::setw(8)
		<< floor(get_character_stats()->get_base_value(atk_id));
	std::cout << std::left << "DEF: " << std::setw(8)
		<< floor(get_character_stats()->get_base_value(def_id));
	std::cout << std::left << "MGK: " << std::setw(8)
		<< floor(get_character_stats()->get_base_value(magic_id));
	std::cout << std::left << "MND: " << std::setw(8)
		<< floor(get_character_stats()->get_base_value(mind_id)) << std::endl;
	std::cout << std::right << std::setw(10) << "ACC: " << std::internal
		<< floor(get_character_stats()->get_base_value(accuracy_id));
	std::cout << std::setw(10) << "EVD: " << std::internal
		<< floor(get_character_stats()->get_base_value(evasion_id));
	std::cout << std::setw(10) << "CRT: " << std::internal
		<< floor(get_character_stats()->get_base_value(critical_id)) << "\n"
		<< std::endl;
}

void Character::print_elemental_affinities()
{
	std::cout << "Fire: " << floor(get_character_stats()->get_base_value(fire_id)) <<
		"\tWind: " << floor(get_character_stats()->get_base_value(wind_id)) <<
		"\tEarth: " << floor(get_character_stats()->get_base_value(earth_id)) << std::endl <<
		"Water: " << floor(get_character_stats()->get_base_value(water_id)) <<
		"\tLghtn: " << floor(get_character_stats()->get_base_value(lightning_id)) <<
		"\tHoly: " << floor(get_character_stats()->get_base_value(holy_id)) << std::endl <<
		"Dark: " << floor(get_character_stats()->get_base_value(dark_id)) <<
		"\tVoid: " << floor(get_character_stats()->get_base_value(void_id)) << std::endl
		<< std::endl;

}

void Character::print_abiities()
{
	std::cout << "Abilities:" << std::endl;
	
	// auto&& retains const-ness and the rvalue-ness of the result of the itererator dereference
	for (auto&& ability : get_abilities())
	{
		std::cout << ability->get_name() << std::endl << ability->get_description() << std::endl
			<< "phys damage: " << ability->get_physical_damage() << "\tMagic dmg: " <<
			ability->get_magic_damage() << "\tAtt Bonus: " << ability->get_attack_bonus() <<
			"\tMagic Bonus: " << ability->get_magic_bonus() << "\tDef Bonus: " <<
			ability->get_defense_bonus() << "\tMind Bonus: " << ability->get_mind_bonus() <<
			"\tMagic Bonus: " << ability->get_magic_bonus() << "\tDef Bonus: " <<
			ability->get_defense_bonus() << "\tMind Bonus: " << ability->get_mind_bonus() <<
			"\tAgility Bonus: " << ability->get_agility_bonus() << "\tAcc Bonus: " <<
			ability->get_accuracy_bonus() << "\tElement: " << ability->get_element() <<
			"\tMP cost: " << ability->get_mp_cost() << "\tSP Cost: " <<
			ability->get_sp_cost() << "\tTargets: " << ability->get_num_of_targets() <<
			"\tLevel Req: " << ability->get_level_requirement() << "\tFriendly: " <<
			ability->isFriendly() << "\tStuns : " << ability->isStun() <<
			"\tExecute: " << ability->isExecute() << "\tRestore: " << ability->isRestore() <<
			"\tUsable: " << ability->isUsable() << std::endl;
	}
}
