#pragma once
//C includes


//Intra Includes
#include "Character.h"

class PlaybleCharacter : public Character
{
public:
	//Constructor
	PlaybleCharacter(const std::string &name, const int class_id);

	//Destructor
	virtual ~PlaybleCharacter();
	
	//Flag checks
	bool experience_req_met();

	//Accessors
	double get_next_level_experience() { return m_exp_required_for_next_level; }
	double get_current_experience() { return m_experience; }
	ClassStatistics* get_character_stats() { return Character::get_character_stats(); }

	//Mutators
	void set_next_level_experience();
	void level_up();
	void initialize_character_stats();
	void set_base_stats();
	void level_base_stats();
	void add_experience(const double& experience);
	void character_action();

private:
	double m_experience;
	double m_exp_required_for_next_level;
};
