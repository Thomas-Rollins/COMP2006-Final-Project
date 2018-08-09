#include "Wizard.h"

const std::string Wizard::m_class_name = "Wizard";
const std::string Wizard::m_class_description = "Wizard Description Here";
const Class_id Wizard::m_class_id = wizard_id;

Wizard::Wizard(const int &level)
	:  CharacterClass(level) { }


Wizard::~Wizard() { }