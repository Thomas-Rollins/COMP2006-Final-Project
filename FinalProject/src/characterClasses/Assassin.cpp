#include "Assassin.h"

const std::string Assassin::m_class_name = "Assassin";
const std::string Assassin::m_class_description = "Assassin Description Here";
const Class_id Assassin::m_class_id = assassin_id;

Assassin::Assassin(const int &level)
	: CharacterClass(level) { }

Assassin::~Assassin() { }
