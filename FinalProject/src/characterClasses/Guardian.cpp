#include "Guardian.h"

const std::string Guardian::m_class_name = "Guardian";
const std::string Guardian::m_class_description = "Guardian Description Here";

Guardian::Guardian(const int &level)
	: CharacterClass(level)
{

}



Guardian::~Guardian()
{
}
