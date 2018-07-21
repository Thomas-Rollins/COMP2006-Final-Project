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

CharacterClass* CharacterClass::make_character_class(const int &class_id)
{
	switch (class_id)
	{
	case archer_id:
		return new Archer(1);
		break;
	case assassin_id:
		return new Assassin(1);
		break;
	case brawler_id:
		return new Brawler(1);
		break;
	case guardian_id:
		return new Guardian(1);
		break;
	case magic_swordsman_id:
		return new MagicSwordsman(1);
		break;
	case necromancer_id:
		return new Necromancer(1);
		break;
	case priest_id:
		return new Priest(1);
		break;
	case sage_id:
		return new Sage(1);
		break;
	case scout_id:
		return new Scout(1);
		break;
	case swordsman_id:
		return new Swordsman(1);
		break;
	case wizard_id:
		return new Wizard(1);
		break;
	case warrior_id:
	default:
		return new Warrior(1);
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
	return "Default Class";
}