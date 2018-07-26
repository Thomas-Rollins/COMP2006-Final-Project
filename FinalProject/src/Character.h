#pragma once
//C includes
#include <string>

//Intra Includes
#include "characterClasses/CharacterClass.h"
#include "ClassStatistics.h"



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
	virtual void set_base_stats() = 0;
	virtual void add_experience(const double& experience) = 0;


	//Accessors
	CharacterClass* get_character_class() { return m_character_class; }
	int get_character_level() { return m_level; }

	//mutators
	void set_character_level(const int &level);
	
	virtual void print_stats();

private:
	const std::string m_name;
	int m_level;

	CharacterClass* m_character_class;
	ClassStatistics* m_character_stats;

};
