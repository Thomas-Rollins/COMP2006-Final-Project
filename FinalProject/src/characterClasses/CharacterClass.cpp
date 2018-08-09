#include "CharacterClass.h"
#include "Archer.h"
#include "Assassin.h"
#include "Brawler.h"
#include "Guardian.h"
#include "MagicSwordsman.h"
#include "Necromancer.h"
#include "Priest.h"
#include "Sage.h"
#include "Scout.h"
#include "Swordsman.h"
#include "Wizard.h"
#include "Warrior.h"
#include "../BalancingDefinitions.h"


CharacterClass* CharacterClass::make_character_class(const int &class_id)
{
	switch (class_id)
	{
	case archer_id:
		return new Archer(STARTING_LEVEL);
		break;
	case assassin_id:
		return new Assassin(STARTING_LEVEL);
		break;
	case brawler_id:
		return new Brawler(STARTING_LEVEL);
		break;
	case guardian_id:
		return new Guardian(STARTING_LEVEL);
		break;
	case magic_swordsman_id:
		return new MagicSwordsman(STARTING_LEVEL);
		break;
	case necromancer_id:
		return new Necromancer(STARTING_LEVEL);
		break;
	case priest_id:
		return new Priest(STARTING_LEVEL);
		break;
	case sage_id:
		return new Sage(STARTING_LEVEL);
		break;
	case scout_id:
		return new Scout(STARTING_LEVEL);
		break;
	case swordsman_id:
		return new Swordsman(STARTING_LEVEL);
		break;
	case wizard_id:
		return new Wizard(STARTING_LEVEL);
		break;
	case warrior_id:
	default:
		return new Warrior(STARTING_LEVEL);
		break;
	}
}


CharacterClass::CharacterClass(const int &level)	
{

}

CharacterClass::~CharacterClass()
{
}

const std::string CharacterClass::get_class_name() const
{
	return "Default Class container";
}