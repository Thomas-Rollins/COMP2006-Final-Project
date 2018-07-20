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
#include "Warrior.h"
#include "Wizard.h"

CharacterClass* CharacterClass::make_character(const int &class_id, const std::string &name)
{
	switch (class_id)
	{
	case archer_id:
		return new Archer(name);
		break;
	case assassin_id:
		return new Assassin(name);
		break;
	case brawler_id:
		return new Brawler(name);
		break;
	case guardian_id:
		return new Guardian(name);
		break;
	case magic_swordsman_id:
		return new MagicSwordsman(name);
		break;
	case necromancer_id:
		return new Necromancer(name);
		break;
	case priest_id:
		return new Priest(name);
		break;
	case sage_id:
		return new Sage(name);
		break;
	case scout_id:
		return new Scout(name);
		break;
	case swordsman_id:
		return new Swordsman(name);
		break;
	case wizard_id:
		return new Wizard(name);
		break;
	case warrior_id:
	default:
		return new Warrior(name);
		break;
	}
}

CharacterClass::CharacterClass(const std::string &name)
	:Character(name)
{

}


CharacterClass::~CharacterClass()
{
}
