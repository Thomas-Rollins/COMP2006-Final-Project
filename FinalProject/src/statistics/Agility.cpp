#include "Agility.h"
Agility::~Agility() 
{
	
};

const std::string Agility::m_NAME = "Agility";
const char* Agility::m_ALIAS = "AGI";
const std::string Agility::m_DESCRIPTION = "Agility Description Here.";
const int Agility::m_MAX_VALUE = 65535;
const int Agility::m_MIN_VALUE = -65535;

Agility::Agility(int base_value, int current_value, float growth_value)
	: StatisticShell(base_value, current_value, growth_value) {}

void Agility::set_base_value(const int& base_value)
{
	m_base_value = base_value;

	//Run Update High level stat methods

}