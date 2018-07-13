#include "StatisticShell.h"


StatisticShell::StatisticShell(int base_value, int current_value, float growth_value)
	: m_base_value(base_value), m_current_value(current_value), m_growth_value(growth_value) {}

StatisticShell::~StatisticShell() {}

void StatisticShell::set_base_value(const int& base_value)
{
	m_base_value = base_value;
}

void StatisticShell::set_current_value(const int& current_value)
{
	m_current_value = current_value;
}
void StatisticShell::set_growth_value(const float& growth_value)
{
	m_growth_value = growth_value;
}
