#pragma once
//C++ Library Includes
#include<string>

//Intra-Includes
#include "../Statistics.h"

struct class_temp_template
{
	int base_agility;
	int base_dexterity;
	int base_focus;
	int base_intelligence;
	int base_luck;
	int base_strength;
	int base_technique;
	int base_vitality;
	int base_wisdom;

	float growth_agility;
	float growth_dexterity;
	float growth_focus;
	float growth_intelligence;
	float growth_luck;
	float growth_strength;
	float growth_technique;
	float growth_vitality;
	float growth_wisdom;
};

enum class_id : int
{
	archer_id = 1, assassin_id = 2, brawler_id = 3, guardian_id = 4,
	magic_swordsman_id = 5, necromancer_id = 6, preist_id = 7, sage_id = 8, 
	scout_id = 9, swordsman_id = 10, warrior_id = 11, wizard_id = 12
};

class CharacterClass
{
public:
	//Constructors
	CharacterClass() = delete;
	CharacterClass(std::string name, Low_Statistics inital_stats);

	//Destructors
	~CharacterClass();

	//Accessors
	Low_Statistics get_low_stats() const { return m_low_stats; }

	//Mutators

private:
	//members
	std::string m_name;

	Low_Statistics m_low_stats;
	High_Level_Stats m_high_stats;
	Elemental_Stats m_elemental_stats;
	
};


