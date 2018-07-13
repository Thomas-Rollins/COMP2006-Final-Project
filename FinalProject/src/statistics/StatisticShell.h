#pragma once
#include <string>

//Intra-Includes
//#include "Agility.h"
//#include "Dexterity.h"
//#include "Focus.h"
//#include "Intelligence.h"
//#include "Luck.h"
//#include "Strength.h"
//#include "Technique.h"
//#include "Vitality.h"
//#include "Wisdom.h"

class StatisticShell
{
public:
	//Constructors
	
	StatisticShell(int base_value, int current_value, float growth_value);
	
	//Deconstructors
	virtual ~StatisticShell();

	//Accessors
	const int get_base_value() { return m_base_value; }
	const int get_current_value() { return m_current_value; }
	const float get_growth_value() { return m_growth_value; }

	//Pure Virtual Accessors
	virtual const std::string get_name() const = 0;
	virtual const char* get_alias() const = 0;
	virtual const std::string get_description() const = 0;
	virtual const int get_max_value() const = 0;
	virtual const int get_min_value() const = 0;

	//Mutators
	void set_current_value(const int& current_value);
	void set_growth_value(const float& growth_value);

	//Pure Virtual Mutators
	virtual void set_base_value(const int& base_value) = 0;

protected:
	int m_base_value;
	int m_current_value;
	float m_growth_value;
};

