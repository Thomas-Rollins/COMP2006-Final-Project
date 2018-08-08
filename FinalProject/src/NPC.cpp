#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

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
					base_stats[i_ref]["base"].asInt() +
					(floor((get_character_stats()->get_growth_value(i_ref) *
						this->get_character_stats()->BASE_STAT_INCREASE_PER_LEVEL) *
						(this->get_character_level() - 1)))
					* STAT_MULTIPLIER)
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
		this->get_abilities().reserve(5);
		const Json::Value& abilities = obj["abilities"];
		for (int i = 0; i < obj["abilities"].size(); i++)
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
			this->addAbility(newAbility);
		}
		//updates the isUsable state.
		this->updateAbility_State();
		
	}
	this->print_elemental_affinities();
}


const Ability* NPC::get_action(const bool friendly)
{
	//updates ability states (if unusable/etc)
	this->updateAbility_State();
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

	//std::vector<std::string> options;
	//for (auto&& ability : usable_abilities)
	//{
	//	// populates the vector of options with the ability name and MP/SP costs
	//	if (ability->isUsable())
	//	{
	//		std::string option = ability->get_name() + "\tMP: ";
	//		option.append(std::to_string(ability->get_mp_cost()) + "\tSP: ");
	//		option.append(std::to_string(ability->get_sp_cost()));

	//		options.push_back(option);
	//	}
	//}

	/*std::cout << "Which ability would you like to use?" << std::endl;
	return usable_abilities.at(Utilities::draw_menu(options) - 1);*/

	// Very simple NPC control for them to select an ability.
	return usable_abilities.at(Utilities::random_int(0, usable_abilities.size()));
}


void NPC::add_experience(const double& experience)
{
	throw NotImplemented();
}

