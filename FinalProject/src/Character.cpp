#include "Character.h"
#include "characterClasses/CharacterClass.h"
#include "NPC.h"
#include "PlayableCharacter.h"

#include <iostream>


Character* Character::make_character(bool npc, const int &class_id, const std::string &name, const int &level)
{
	if (npc)
	{
		return new NPC(name, level, class_id);
	}
	else
	{
		return new PlaybleCharacter(name, class_id);
	}
}

Character::Character()
{

}

Character::Character(const std::string &name, const int &class_id)
	:m_name(name)
{
	m_character_class = CharacterClass::make_character_class(class_id);
}

Character::~Character()
{
	delete m_character_stats;
	delete m_character_class;
	std::cout << "Character Entity Deleted" << std::endl;
}

