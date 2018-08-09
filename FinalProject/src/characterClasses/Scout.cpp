#include "Scout.h"

const std::string Scout::m_class_name = "Scout";
const std::string Scout::m_class_description = "Scout Description Here";
const Class_id Scout::m_class_id = scout_id;

Scout::Scout(const int &level)
	: CharacterClass(level) { }


Scout::~Scout() { }

