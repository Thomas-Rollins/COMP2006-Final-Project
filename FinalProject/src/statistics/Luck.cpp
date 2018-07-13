#include "Luck.h"

const std::string Luck::m_NAME = "Luck";
const char* Luck::m_ALIAS = "LUK";
const std::string Luck::m_DESCRIPTION = "Luck Description Here.";
const int Luck::m_MAX_VALUE = 100;
const int Luck::m_MIN_VALUE = -100;

Luck::Luck(int base_value, int current_value, float growth_value)
	:StatisticShell(m_base_value, m_current_value, m_growth_value) {}

void Luck::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}