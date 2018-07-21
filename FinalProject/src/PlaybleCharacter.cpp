#include "PlayableCharacter.h"

#include <iostream>

//Constructor
PlaybleCharacter::PlaybleCharacter(const std::string &name, const int class_id)
	: Character(name, class_id)
{

}

//Destructor
PlaybleCharacter::~PlaybleCharacter()
{
	std::cout << "PlayableCharacter entity Deleted" << std::endl;
}


bool PlaybleCharacter::experience_req_met()
{
	return (get_next_level_experience() - get_current_experience()) <= 0;
}

void PlaybleCharacter::add_experience(const int& experience)
{
	m_experience += experience;
}


void PlaybleCharacter::level_up(bool experience_req_met)
{
	if (!experience_req_met)
	{
		return;
	}
	else
	{
		//#TODO: add level up code
	}
}

void PlaybleCharacter::character_action()
{
	//TODO: add Action code
}