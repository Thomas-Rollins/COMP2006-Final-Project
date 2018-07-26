#pragma once
//C includes
#include <string>

//Intra Includes
#include "../ClassStatistics.h"


enum Class_id : int
{
	null_class_id, archer_id, assassin_id, brawler_id, guardian_id,
	magic_swordsman_id, necromancer_id, priest_id, sage_id,
	scout_id, swordsman_id, warrior_id, wizard_id
};

class CharacterClass
{
public:
	static CharacterClass* make_character_class(const int &class_id);
	
	CharacterClass(const int &level);

	virtual ~CharacterClass();

	virtual const std::string get_class_name() const = 0;
	
	virtual const Class_id get_class_id() const = 0;

private:
	
	

};

