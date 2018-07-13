#pragma once

#include "StatisticShell.h"

class Wisdom : public StatisticShell
{
public:
	//Constructors
	Wisdom(int base_value, int current_value, float growth_value);
	//Accessors
	const std::string get_name() const { return m_NAME; }
	const char* get_alias() const { return m_ALIAS; }
	const std::string get_description() const { return m_DESCRIPTION; }
	const int get_max_value() const { return m_MAX_VALUE; }
	const int get_min_value() const { return m_MIN_VALUE; }

	//Mutators
	void set_base_value(const int& base_value);


private:
	//static members
	static const std::string m_NAME;
	static const char* m_ALIAS;
	static const std::string m_DESCRIPTION;
	static const int m_MAX_VALUE;
	static const int m_MIN_VALUE;
};

