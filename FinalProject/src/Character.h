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
	//Virtual Destructor
	virtual ~Character();
	
	Character* make_character(bool npc, const int &class_id, const std::string &name, const int &level);

	CharacterClass* get_character_class() { return m_character_class; }



private:
	const std::string m_name;
	int m_level;

	CharacterClass* m_character_class;

	ClassStatistics* m_character_stats;


};
