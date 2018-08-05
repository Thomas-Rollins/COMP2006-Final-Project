#include "Character.h"
#include "NPC.h"
#include "PlayableCharacter.h"


#include <iostream>
#include <algorithm>


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

	//deletes the pointers contained in the array
	for (auto&& ability : m_abilities)
	{
		delete(ability);
	}
	m_abilities.clear();

	std::cout << "Character Entity Deleted" << std::endl;
}

// overloaded operators ...added cause friends aren't happening.
void Character::operator+(const int health)
{
	float current = (float) m_character_stats->get_current_value(health_id);
	m_character_stats->set_current_value(health_id, current + health);
}

void Character::operator-(const int health)
{
	float current = (float) m_character_stats->get_current_value(health_id);
	m_character_stats->set_current_value(health_id, current - health);
}

ClassStatistics* Character::get_character_stats()
{
	return m_character_stats;
}

void Character::set_character_level(const int &level)
{
	m_level = level;
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
			this->get_character_stats()->get_current_value(mana_id) < ability->get_mp_cost() || this->get_character_stats()->get_current_value(skill_points_id) <
			ability->get_sp_cost())
		{
			ability->setUsable(false);
		}
		else
			ability->setUsable(true);
	}
	
}

const Ability* Character::get_action(const bool friendly)
{
	std::vector<Ability*> usable_abilities = m_abilities;

	//sorts the abilities by m_usable (usable ones first)
	std::sort(usable_abilities.begin(), usable_abilities.end(), [](Ability* ability_1, Ability* ability_2)
	{
		return ability_1->isUsable() > ability_2->isUsable();
	});

	// removes all unusable abilities
	for (auto&& ability : usable_abilities)
	{
		if (!ability->isUsable())
		{
			usable_abilities.pop_back();
		}
	}

	std::vector<std::string> options;
	for (auto&& ability : usable_abilities)
	{
		// populates the vector of options with the ability name and MP/SP costs
		if (ability->isUsable())
		{
			std::cout << std::endl << ability->get_mp_cost() << "\t" << ability->get_sp_cost() << std::endl;
			std::string option = ability->get_name() + "\tMP: ";
			option.append(std::to_string(ability->get_mp_cost()) + "\tSP: ");
			option.append(std::to_string(ability->get_sp_cost()));

			options.push_back(option);
		}
	}
	std::cout << "Which ability would you like to use?" << std::endl;
	return usable_abilities.at(Utilities::draw_menu(options) - 1);
}

void Character::print_low_stats()
{
	std::cout << "AGI: " << get_character_stats()->get_base_value(agility_id) << "\t\tDEX: "
		<< get_character_stats()->get_base_value(dexterity_id) << "\t\tFCS: " <<
		get_character_stats()->get_base_value(focus_id) << std::endl << "INT: " <<
		get_character_stats()->get_base_value(intelligence_id) << "\t\tLUC: " <<
		get_character_stats()->get_base_value(luck_id) << "\t\tSTR: " <<
		get_character_stats()->get_base_value(strength_id) << std::endl << "TEC: " <<
		get_character_stats()->get_base_value(technique_id) << "\t\tVIT: " <<
		get_character_stats()->get_base_value(vitality_id) << "\t\tWIS: " <<
		get_character_stats()->get_base_value(wisdom_id) << std::endl;
}

void Character::print_high_stats()
{
	std::cout << "HP: " << get_character_stats()->get_base_value(health_id) << "\t\tMP: "
		<< get_character_stats()->get_base_value(mana_id) << "\t\tSP: "
		<< get_character_stats()->get_base_value(skill_points_id) << std::endl << "ATK: "
		<< get_character_stats()->get_base_value(atk_id) << "\t\tDEF: "
		<< get_character_stats()->get_base_value(def_id) << std::endl << "MGK: "
		<< get_character_stats()->get_base_value(magic_id) << "\t\tMND: "
		<< get_character_stats()->get_base_value(mind_id) << std::endl << "ACC: "
		<< get_character_stats()->get_base_value(accuracy_id) << "\t\tEVD: "
		<< get_character_stats()->get_base_value(evasion_id) << "\t\tCRT: "
		<< get_character_stats()->get_base_value(critical_id) << std::endl;
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
