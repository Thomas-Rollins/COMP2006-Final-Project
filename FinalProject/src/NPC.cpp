#include "NPC.h"

#include <iostream>

//Constructor
NPC::NPC(const std::string &name)
	: Character(name)
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