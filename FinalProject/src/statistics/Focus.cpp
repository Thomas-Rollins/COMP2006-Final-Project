#include "Focus.h"

const std::string Focus::m_NAME = "Focus";
const char* Focus::m_ALIAS = "FCS";
const std::string Focus::m_DESCRIPTION = "Focus Description Here.";
const int Focus::m_MAX_VALUE = 65535;
const int Focus::m_MIN_VALUE = -65535;

Focus::Focus(int base_value, int current_value, float growth_value)
	:StatisticShell(m_base_value, m_current_value, m_growth_value) {}

void Focus::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}