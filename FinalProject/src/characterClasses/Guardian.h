#pragma once
#include <vector>


#include "CharacterClass.h"
#include "abilities/Abilities.h"


class Guardian : public CharacterClass
{
public:
	virtual ~Guardian();

	Guardian(std::string name, Low_Statistics inital_stats);


private:
	std::vector<Abilities> m_abilities;
};

