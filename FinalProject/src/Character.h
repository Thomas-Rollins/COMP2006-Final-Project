#pragma once
//C includes
#include <string>

//Intra Includes
#include "ClassStatistics.h"


class Character
{
public:
	//Constructor
	Character(const std::string &name);
	//Virtual Destructor
	virtual ~Character();
	//Pure virtual Functions
	

	

private:
	const std::string m_name;
	int m_level;
	
	ClassStatistics* m_character_stats;

};
