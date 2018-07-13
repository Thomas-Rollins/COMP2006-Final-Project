#include "Strength.h"

const std::string Strength::m_NAME = "Strength";
const char* Strength::m_ALIAS = "STR";
const std::string Strength::m_DESCRIPTION = "Strength Description Here.";
const int Strength::m_MAX_VALUE = 65535;
const int Strength::m_MIN_VALUE = -65535;

Strength::Strength(int base_value, int current_value, float growth_value)
	:StatisticShell(m_base_value, m_current_value, m_growth_value) {}

void Strength::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}