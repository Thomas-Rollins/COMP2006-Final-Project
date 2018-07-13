#include "Dexterity.h"

const std::string Dexterity::m_NAME = "Dexterity";
const char* Dexterity::m_ALIAS = "DEX";
const std::string Dexterity::m_DESCRIPTION = "Dexterity Description Here.";
const int Dexterity::m_MAX_VALUE = 65535;
const int Dexterity::m_MIN_VALUE = -65535;

Dexterity::Dexterity(int base_value, int current_value, float growth_value)
	: StatisticShell(base_value, current_value, growth_value) {}

void Dexterity::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}