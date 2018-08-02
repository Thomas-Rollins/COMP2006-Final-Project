#include <iostream>
#include <cmath>
#include <fstream>

#include "NPC.h"
#include "../include/jsoncpp/json/json.h"

#include "logging/Log.h"
#include "Custom_Exception.cpp"

//Balancing Variable
const float NPC::STAT_MULTIPLIER = 1.3f;

//Constructor
NPC::NPC(const std::string &name, const int class_id, const int &level)
	: Character(name, class_id, level)
{
	
	initialize_character_stats();
}

//Destructor
NPC::~NPC()
{
	std::cout << "NPC entity Deleted" << std::endl;
}

void NPC::character_action()
{
	//#TODO: add Action code
}

double NPC::get_next_level_experience() { return 0; }


double NPC::get_current_experience()
{
	return round((4 * (pow(get_character_level() + 1, 3))) / 5);
}

ClassStatistics* NPC::get_character_stats() 
{
	return Character::get_character_stats();
}

void NPC::initialize_character_stats()
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
	std::ifstream character_class_file("data/classes/"+ class_name +".json", std::ifstream::binary);
	if (character_class_file.fail())
	{
		std::cerr << "File not Found: " << "data/classes/" << class_name << ".json" << std::endl;
		exit(1);
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
				i_ref, (int)floor(
					base_stats[i_ref]["base"].asUInt() +
					(floor((get_character_stats()->get_growth_value(i_ref) *
						this->get_character_stats()->BASE_STAT_INCREASE_PER_LEVEL) *
						(this->get_character_level() - 1)))
					* STAT_MULTIPLIER)
			);
		}
		this->get_character_stats()->set_high_stats();
		this->get_character_stats()->reset_current_values();
	}
}

void NPC::set_base_stats()
{
	//#TODO: add method to change base-stats based on actions within the game
}

void NPC::add_experience(const double& experience)
{
	//throw NotImplemented();
}