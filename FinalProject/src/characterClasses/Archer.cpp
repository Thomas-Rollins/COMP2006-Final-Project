#include <iostream>

#include "Archer.h"
#include "../PlayableCharacter.h"
#include "../NPC.h"


const std::string Archer::m_class_name = "Archer";
const std::string Archer::m_class_description = "Archer Description Here";
const Class_id Archer::m_class_id = archer_id;

Archer::Archer(const int &level)
	:CharacterClass(level) { }

Archer::~Archer() { }

