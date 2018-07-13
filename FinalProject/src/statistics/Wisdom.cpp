#include "Wisdom.h"

const std::string Wisdom::m_NAME = "Wisdom";
const char* Wisdom::m_ALIAS = "WIS";
const std::string Wisdom::m_DESCRIPTION = "Wisdom Description Here.";
const int Wisdom::m_MAX_VALUE = 65535;
const int Wisdom::m_MIN_VALUE = -65535;


Wisdom::Wisdom(int base_value, int current_value, float growth_value)
	:StatisticShell(m_base_value, m_current_value, m_growth_value) {}

void Wisdom::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}