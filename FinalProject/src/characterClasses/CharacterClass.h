#pragma once
//C includes
#include <string>

//Intra Includes
#include "../ClassStatistics.h"


enum Class_id : int
{
	null_class_id = 0, archer_id = 1, assassin_id = 2, brawler_id = 3, guardian_id = 4,
	magic_swordsman_id = 5, necromancer_id = 6, priest_id = 7, sage_id = 8,
	scout_id = 9, swordsman_id = 10, warrior_id = 11, wizard_id = 12
};

class CharacterClass
{
public:
	static CharacterClass* make_character_class(const int &class_id);
	
	CharacterClass(const int &level);

	virtual ~CharacterClass();

	virtual const std::string get_class_name() const;
	

private:
	
	

};

