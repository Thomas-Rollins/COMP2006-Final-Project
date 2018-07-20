#pragma once
//C includes


//Intra Includes
#include "Character.h"

class PlaybleCharacter : public Character
{
public:
	//Constructor
	PlaybleCharacter(const std::string &name);

	//Destructor
	 ~PlaybleCharacter();

	//Interface methods of parent
	void character_action();
	
	bool experience_req_met();
	void level_up(bool);
	void add_experience(const int& experience);

	
	//Accessors
	double get_next_level_experience() { return m_exp_required_for_next_level; }
	double get_current_experience() { return m_experience; }

private:
	double m_experience;
	double m_exp_required_for_next_level;
};
