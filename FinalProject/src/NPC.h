#pragma once
//C includes


//Intra Includes
#include "Character.h"

class NPC : public Character
{
public:
	//Constructor
	NPC(const std::string &name, const int class_id, const int &level);

	//Destructor
	virtual ~NPC();

	//Interface Methods of parent
		//Accessors	
	double get_next_level_experience();
	double get_current_experience();
	ClassStatistics* get_character_stats() { return Character::get_character_stats(); }
	std::vector<Ability*> get_abilities() {	return Character::get_abilities(); }
	
		//Mutators


	Ability* get_action();
	
	//Unimplemented
	void add_experience(const double& experience);
	
	// End of Interface Methods

	static const float STAT_MULTIPLIER;

private:
	void initialize_character_stats();

};