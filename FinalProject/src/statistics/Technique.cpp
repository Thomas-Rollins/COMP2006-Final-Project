#include "Technique.h"

const std::string Technique::m_NAME = "Technique";
const char* Technique::m_ALIAS = "TEC";
const std::string Technique::m_DESCRIPTION = "Technique Description Here.";
const int Technique::m_MAX_VALUE = 65535;
const int Technique::m_MIN_VALUE = -65535;

Technique::Technique(int base_value, int current_value, float growth_value)
	:StatisticShell(m_base_value, m_current_value, m_growth_value) {}

void Technique::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}