#pragma once
//C includes


//Intra Includes
#include "Character.h"

class NPC : public Character
{
public:
	//Constructor
	NPC(const std::string &name);

	//Destructor
	~NPC();

	//Interface Methods of parent
	void character_action();

private:

};