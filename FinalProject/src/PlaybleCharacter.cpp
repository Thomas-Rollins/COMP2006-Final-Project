#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

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
	std::cout << this->get_name() << " has gained " << std::to_string(floor(experience)) << ".";
	level_up();
}


void PlaybleCharacter::level_up()
{
	bool show_stats = false;
	while (experience_req_met())
	{
		if (get_character_level() + 1 < MAX_LEVEL)
		{
			set_character_level(get_character_level() + 1);
			level_base_stats();
			set_next_level_experience();
			show_stats = Utilities::get_input(this->get_name() + " has leveled up!" 
				+ "Would you like to view your stats?");
			if (show_stats)
			{
				this->print_low_stats();
				this->print_high_stats();
			}	
		}
		else
			set_character_level(MAX_LEVEL);
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
		this->get_character_stats()->set_high_stats();
		
		//Initializes the affinities
		const Json::Value& affinity = obj["affinities"];
		for (int i = 0; i < obj["affinities"].size(); i++)
		{
			this->get_character_stats()->set_base_value(
				static_cast<Elemental_Stats_ID>(affinity[i]["id"].asInt()),
				affinity[i]["value"].asFloat()
			);
		}
		this->get_character_stats()->reset_current_values(true);

		// #TODO: deal with signed/unsigned mismatch case
		const Json::Value& abilities = obj["abilities"];
		for (int i = 0; i < obj.size(); i++)
		{
			Ability* newAbility = new Ability(
				abilities[i]["name"].asString(),
				abilities[i]["description"].asString(),
				abilities[i]["physical_damage"].asFloat(),
				abilities[i]["magic_damage"].asFloat(),
				abilities[i]["attack_bonus"].asFloat(),
				abilities[i]["magic_bonus"].asFloat(),
				abilities[i]["defense_bonus"].asFloat(),
				abilities[i]["mind_bonus"].asFloat(),
				abilities[i]["agility_bonus"].asFloat(),
				abilities[i]["accuracy_bonus"].asFloat(),
				static_cast<Elemental_Stats_ID>(abilities[i]["element"].asInt()),
				static_cast<int>(abilities[i]["mp_cost"].asInt()),
				static_cast<int>(abilities[i]["sp_cost"].asInt()),
				static_cast<int>(abilities[i]["targets"].asInt()),
				static_cast<int>(abilities[i]["level_req"].asInt()),
				abilities[i]["friendly"].asBool(),
				abilities[i]["stun"].asBool(),
				abilities[i]["execute"].asBool(),
				abilities[i]["restore"].asBool()
			);
			this->get_abilities().push_back(newAbility);
		}
	}
	
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
		this->get_character_stats()->set_high_stats();
		this->get_character_stats()->reset_current_values(true);
	}
}

const Ability* PlaybleCharacter::get_action(const bool friendly)
{
	std::vector<Ability*> usable_abilities = this->get_abilities();

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
			std::string option = ability->get_name() + "\tMP: ";
			option.append(std::to_string(ability->get_mp_cost()) + "\tSP: ");
			option.append(std::to_string(ability->get_sp_cost()));

			options.push_back(option);
		}
	}

	std::cout << "Which ability would you like to use?" << std::endl;
	return usable_abilities.at(Utilities::draw_menu(options) - 1);
}