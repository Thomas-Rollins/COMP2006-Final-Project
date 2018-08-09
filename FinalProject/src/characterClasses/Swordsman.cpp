#include "Swordsman.h"

const std::string Swordsman::m_class_name = "Swordsman";
const std::string Swordsman::m_class_description = "Swordsman Description Here";
const Class_id Swordsman::m_class_id = swordsman_id;

Swordsman::Swordsman(const int &level)
	: CharacterClass(level) { }


Swordsman::~Swordsman() { }

