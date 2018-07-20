#pragma once
#include <string>

enum Low_Stats_ID : int 
{
	agility_id = 0, dexterity_id = 1, focus_id = 2, intelligence_id = 3, luck_id = 4, strength_id = 5, technique_id = 6, vitality_id = 7, wisdom_id = 8
};

enum Low_Stats_Attribute : int 
{
	base_value_id = 0, current_value_id = 1, growth_value_id = 2
};

class ClassStatistics
{
public:
	//Constructors
	ClassStatistics();

	//Destructors
	~ClassStatistics();

	//Accessors
	const int get_base_value(Low_Stats_ID &stat_id) const;
	const int get_current_value(Low_Stats_ID &stat_id) const;
	const float get_growth_value(Low_Stats_ID &stat_id) const;
	
	//Incrementors
	void increment_base_value(Low_Stats_ID &stat_id, int &base_value);
	void increment_current_value(Low_Stats_ID &stat_id, int &current_value);
	void increment_growth_value(Low_Stats_ID &stat_id, float &growth_value);

	

private:
	//static consts
	static const int NUM_OF_LOW_STATS = 9;
	static const int NUM_OF_LOW_STAT_ATTRIBUTES = 3;
	static const int LOW_STAT_MAX_VALUE = 65535;
	static const std::string* LOW_STAT_DESCRIPTIONS[NUM_OF_LOW_STATS];
	
	float m_low_level_stats[NUM_OF_LOW_STATS][NUM_OF_LOW_STAT_ATTRIBUTES];

	//Mutators
	void set_base_value(Low_Stats_ID &stat_id, int &base_value);
	void set_current_value(Low_Stats_ID &stat_id, int &current_value);
	void set_growth_value(Low_Stats_ID &stat_id, float &growth_value);
};

