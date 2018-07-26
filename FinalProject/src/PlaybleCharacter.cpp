#include <iostream>
#include <cmath>
#include <fstream>

#include "PlayableCharacter.h"
#include "../include/jsoncpp/json/json.h"
#include "logging/Log.h"


//Constructor
PlaybleCharacter::PlaybleCharacter(const std::string &name, const int class_id)
	: Character(name, class_id) 
{
	initialize_character_stats();
}

//Destructor
PlaybleCharacter::~PlaybleCharacter()
{
	std::cout << "PlayableCharacter entity Deleted" << std::endl;
}

void PlaybleCharacter::set_next_level_experience()
{
	m_exp_required_for_next_level = round((4 * (pow (get_character_level() + 1, 3))) / 5);
}

bool PlaybleCharacter::experience_req_met()
{
	return (get_next_level_experience() - get_current_experience()) <= 0;
}

void PlaybleCharacter::add_experience(const double& experience)
{
	m_experience += experience;
	level_up();
}


void PlaybleCharacter::level_up()
{
	while (experience_req_met())
	{
		set_character_level(get_character_level() + 1);
		level_base_stats();
		set_next_level_experience();
	}
	
}

void PlaybleCharacter::character_action()
{
	//#TODO: add Action code
}

void PlaybleCharacter::initialize_character_stats()
{
	std::string class_name;

	switch (get_character_class()->get_class_id())
	{
	case archer_id:
		class_name = "Archer";
		break;
	case assassin_id:
		class_name = "Assassin";
		break;
	case brawler_id:
		class_name = "Brawler";
		break;
	case guardian_id:
		class_name = "Guardian";
		break;
	case magic_swordsman_id:
		class_name = "Magic_Swordsman";
		break;
	case necromancer_id:
		class_name = "Necromancer";
		break;
	case priest_id:
		class_name = "Priest";
		break;
	case sage_id:
		class_name = "Sage";
		break;
	case scout_id:
		class_name = "Scout";
		break;
	case swordsman_id:
		class_name = "Swordsman";
		break;
	case warrior_id:
		class_name = "Warrior";
		break;
	case wizard_id:
		class_name = "Wizard";
		break;
	default:
		class_name = "NullClass";
		break;
	}

	Json::Value obj;
	std::ifstream character_class_file("data/classes/" + class_name + ".json", std::ifstream::binary);
	if (character_class_file.fail())
	{
		std::cout << "File not Found:" << std::endl;
	}
	else
	{
		character_class_file >> obj;
		const Json::Value& base_stats = obj["stats"];

		for (int i = 0; i < get_character_stats()->NUM_OF_LOW_STATS; i++)
		{
			Low_Stats_ID i_ref = static_cast<Low_Stats_ID> (i); //cast to an Low_Stats_ID Enum type
																// Growth Values -> MUST BE FIRST
			this->get_character_stats()->set_growth_value(
				i_ref, base_stats[i_ref]["growth_rate"].asFloat()
			);
			// Base Values
			this->get_character_stats()->set_base_value(
				i_ref, (int)floor(base_stats[i_ref]["base"].asUInt())
			);
		}
		this->get_character_stats()->reset_current_values();
	}
}

void PlaybleCharacter::set_base_stats()
{
	//#TODO: add base_stat initalization

}

/**
* This method will break if the Low_Stats_ID enum is not sequential
This method is to increase base stats after a level up.
*/
void PlaybleCharacter::level_base_stats()
{
	for (int i = 0; i < this->get_character_stats()->NUM_OF_LOW_STATS; i++)
	{
		Low_Stats_ID i_ref = static_cast<Low_Stats_ID> (i); //cast to an Low_Stats_ID Enum type

		this->get_character_stats()->set_base_value(i_ref,
			this->get_character_stats()->get_base_value(i_ref) + 
			(int)floor(
			(this->get_character_stats()->get_growth_value(i_ref) * 
				this->get_character_stats()->BASE_STAT_INCREASE_PER_LEVEL)
			)
		);

		this->get_character_stats()->reset_current_values();
	}
}