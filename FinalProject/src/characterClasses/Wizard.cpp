#include "Wizard.h"

const std::string Wizard::m_class_name = "Wizard";
const std::string Wizard::m_class_description = "Wizard Description Here";

Wizard::Wizard(const int &level)
	:  CharacterClass(level)
{
	
}

Wizard::~Wizard()
{
}
