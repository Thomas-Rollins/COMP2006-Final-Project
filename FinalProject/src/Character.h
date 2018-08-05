#pragma once
//C includes
#include <string>
#include <vector>

//Intra Includes
#include "characterClasses/CharacterClass.h"
#include "ClassStatistics.h"
#include "characterClasses/abilities/Ability.h"



class Character
{
public:
	//Constructor
	Character();
	Character(const std::string &name, const int &class_id);
	Character(const std::string &name, const int &class_id, const int &level);
	//Virtual Destructor
	virtual ~Character();

	//Statics
	static Character* make_character(bool npc, const int &class_id, const std::string &name, const int &level);

	// Pure Virtuals
		//Accessors
	virtual double get_next_level_experience() = 0;
	virtual double get_current_experience() = 0;
	virtual ClassStatistics* get_character_stats() = 0;
	
		//Mutators
	virtual void add_experience(const double& experience) = 0;
	virtual void print_low_stats();
	virtual void print_high_stats();
	virtual void print_abiities();

	//Accessors
	const std::vector<Ability*> get_abilities() const { return m_abilities; }
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

};
