#pragma once
//C includes
#include <string>
#include <vector>

//Intra Includes
#include "characterClasses/CharacterClass.h"
#include "ClassStatistics.h"
#include "characterClasses/abilities/Ability.h"
#include "Utilities.h"



class Character
{
public:
	//Constructor
	Character() = delete;
	Character(const std::string &name, const int &class_id, const bool isNPC);
	Character(const std::string &name, const int &class_id, const int &level, const bool isNPC);
	//Virtual Destructor
	virtual ~Character();

	//Statics
	static Character* make_character(bool npc, const int &class_id, const std::string &name, const int &level);

	void operator+(const float &health);
	void operator-(const float &health);

	// Pure Virtuals
		//Accessors
	virtual double get_next_level_experience() = 0;
	virtual double get_current_experience() = 0;
	virtual ClassStatistics* get_character_stats() = 0;
	//actions
	virtual Ability* get_action() = 0;
	
		//Mutators
	virtual void add_experience(const double& experience) = 0;
	virtual void print_low_stats();
	virtual void print_high_stats();
	virtual void print_abiities();
	virtual void print_elemental_affinities();
		

	//Accessors
	const bool isNPC() const { return m_npc; }
	std::vector<Ability*> get_abilities() const { return m_abilities; }
	const CharacterClass* get_character_class() const { return m_character_class; }
	const std::string get_name() const { return m_name; }
	const int get_character_level() const { return m_level; }

	//mutators
	void set_character_level(const int &level);
	void addAbility(Ability* newAbility);
	void updateAbility_State();

private:
	const std::string m_name;
	int m_level;
	std::vector<Ability*> m_abilities;
	CharacterClass* m_character_class;
	ClassStatistics* m_character_stats;
	const bool m_npc;

};
