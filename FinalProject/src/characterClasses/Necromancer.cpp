#include "Necromancer.h"

const std::string Necromancer::m_class_name = "Necromancer";
const std::string Necromancer::m_class_description = "Necromancer Description Here";
const Class_id Necromancer::m_class_id = necromancer_id;

Necromancer::Necromancer(const int &level)
	: CharacterClass(level) { }

Necromancer::~Necromancer() { }
