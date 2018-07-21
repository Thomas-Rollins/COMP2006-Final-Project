#include "NPC.h"

#include <iostream>

//Constructor
NPC::NPC(const std::string &name, const int &level, const int class_id)
	: Character(name, class_id)
{

}

//Destructor
NPC::~NPC()
{
	std::cout << "NPC entity Deleted" << std::endl;
}

void NPC::character_action()
{
	//TODO: add Action code
}