#include <iostream>
#include "Archer.h"
#include "../PlayableCharacter.h"
#include "../NPC.h"

const std::string Archer::m_class_name = "Archer";
const std::string Archer::m_class_description = "Archer Description Here";

Archer::Archer(const int &level)
	:CharacterClass(level)
{

}

Archer::~Archer()
{
	std::cout << "Archer Entity Deleted" << std::endl;
}
