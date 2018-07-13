#include "Intelligence.h"

const std::string Intelligence::m_NAME = "Intelligence";
const char* Intelligence::m_ALIAS = "INT";
const std::string Intelligence::m_DESCRIPTION = "Intelligence Description Here.";
const int Intelligence::m_MAX_VALUE = 65535;
const int Intelligence::m_MIN_VALUE = -65535;

Intelligence::Intelligence(int base_value, int current_value, float growth_value)
	:StatisticShell(m_base_value, m_current_value, m_growth_value) {}

void Intelligence::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}