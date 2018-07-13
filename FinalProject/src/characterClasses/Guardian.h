#pragma once
#include <vector>


#include "CharacterClass.h"
#include "abilities/Abilities.h"


class Guardian : protected CharacterClass
{
public:
	Guardian(std::string name, Low_Statistics* inital_stats);


private:
	std::vector<Abilities> abilities;
};

