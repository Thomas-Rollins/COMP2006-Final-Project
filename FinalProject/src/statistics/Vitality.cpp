#include "Vitality.h"


const std::string Vitality::m_NAME = "Vitality";
const char* Vitality::m_ALIAS = "VIT";
const std::string Vitality::m_DESCRIPTION = "Vitality Description Here.";
const int Vitality::m_MAX_VALUE = 65535;
const int Vitality::m_MIN_VALUE = -65535;


Vitality::Vitality(int base_value, int current_value, float growth_value)
	: StatisticShell(base_value, current_value, growth_value) {}


void Vitality::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}