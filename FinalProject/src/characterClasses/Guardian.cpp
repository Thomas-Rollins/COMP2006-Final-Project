#include "Guardian.h"

const std::string Guardian::m_class_name = "Guardian";
const std::string Guardian::m_class_description = "Guardian Description Here";
const Class_id Guardian::m_class_id = guardian_id;

Guardian::Guardian(const int &level)
	: CharacterClass(level) { }



Guardian::~Guardian() { }
