#pragma once
#include <string>


#include "Statistics.h"

//{
//	{ "Guardian", 1 },
//	{ "Warrior", 2 },
//	{ "Swordsman", 3 },
//	{ "Brawler", 4 },
//	{ "Assassin", 5 },
//	{ "Scout", 6 },
//	{ "Archer", 7 },
//	{ "Sorcerer", 8 },
//	{ "Wizard", 9 },
//	{ "Sage", 10 },
//	{ "Priest", 11 },
//	{ "Necromancer", 12 },
//}


static const std::string CHARACTER_CLASSES[13]{ "NullClass", "Guardian", "Warrior", "Swordsman", "Brawler", "Assassin", "Scout", "Archer", "Sorcerer", "Wizard", "Sage", "Priest", "Necromancer" };


class Character
{
public:
	// Constructors
	Character() = delete;
	Character(const char* name, const int& character_class, Low_Level_Stats& low_level_stats);
	
	// Destructors
	~Character();

private:
	//Statics
	static int last_id;
	
	// Constants
	const int m_ID;
	const std::string m_NAME;
	const int m_CHARACTER_CLASS;
	// End of Constants

	// Statistics
	Low_Level_Stats m_base_low_stats;
	Low_Level_Stats m_current_low_stats;
	High_Level_Stats m_high_level_stats;
	High_Level_Elemental_Stats m_elemental_attack;
	High_Level_Elemental_Stats m_elemental_defense;
	int m_experience;
	// End of Statistics
	
public:
	// Getters
	const int get_character_id() const { return m_ID; }
	const std::string get_character_name() const { return m_NAME; }
	const int get_current_experience() const { return m_experience; }
	const int get_character_class() const { return m_CHARACTER_CLASS; }
	const std::string get_character_class_string() const { return CHARACTER_CLASSES[m_CHARACTER_CLASS]; }

	// Getters For Base Low-Level Statistics
	const int get_base_vitality() const { return m_base_low_stats.vitality.value; }
	const int get_base_strength() const { return m_base_low_stats.strength.value; }
	const int get_base_agility() const { return m_base_low_stats.agility.value; }
	const int get_base_dexterity() const { return m_base_low_stats.dexterity.value; }
	const int get_base_technique() const { return m_base_low_stats.technique.value; }
	const int get_base_intelligence() const { return m_base_low_stats.intelligence.value; }
	const int get_base_wisdom() const { return m_base_low_stats.wisdom.value; }
	const int get_base_focus() const { return m_base_low_stats.focus.value; }
	const int get_base_luck() const { return m_base_low_stats.luck.value; }
	

	
	// Setters For Base Low-Level Statistics
	void set_base_vitality(const int& base_vitality);
	void set_base_strength(const int& base_strength);
	void set_base_agility(const int& base_agility);
	void set_base_dexterity(const int& base_dexterity);
	void set_base_technique(const int& base_technique);
	void set_base_intelligence(const int& base_intelligence);
	void set_base_wisdom(const int& base_wisdom);
	void set_base_focus(const int& base_mentality);
	void set_base_luck(const int& base_luck);
};
