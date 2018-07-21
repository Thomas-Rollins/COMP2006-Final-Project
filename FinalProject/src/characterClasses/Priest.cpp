#include "Priest.h"

const std::string Priest::m_class_name = "Priest";
const std::string Priest::m_class_description = "Priest Description Here";

Priest::Priest(const int &level)
	: CharacterClass(level)
{

}


Priest::~Priest()
{
}
