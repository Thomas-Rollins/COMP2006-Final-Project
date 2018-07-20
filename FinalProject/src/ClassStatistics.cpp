#include "ClassStatistics.h"

const std::string* LOW_STAT_DESCRIPTIONS[] =
{
	LOW_STAT_DESCRIPTIONS[agility_id]		= (std::string*)"Agility Description Here",
	LOW_STAT_DESCRIPTIONS[dexterity_id]		= (std::string*)"Dexterity Description Here",
	LOW_STAT_DESCRIPTIONS[focus_id]			= (std::string*)"Focus Description Here",
	LOW_STAT_DESCRIPTIONS[intelligence_id]	= (std::string*)"Intelligence Description Here",
	LOW_STAT_DESCRIPTIONS[luck_id]			= (std::string*)"Luck Description Here",
	LOW_STAT_DESCRIPTIONS[strength_id]		= (std::string*)"Strength Description Here" ,
	LOW_STAT_DESCRIPTIONS[technique_id]		= (std::string*)"Technique Description Here",
	LOW_STAT_DESCRIPTIONS[vitality_id]		= (std::string*)"Vitality Description Here",
	LOW_STAT_DESCRIPTIONS[wisdom_id]		= (std::string*)"Wisdom Description Here"
};

ClassStatistics::ClassStatistics()
{
}


ClassStatistics::~ClassStatistics()
{
}


const int ClassStatistics::get_base_value(Low_Stats_ID &stat_id) const
{
	return (int)m_low_level_stats[stat_id][base_value_id];
}

const int ClassStatistics::get_current_value(Low_Stats_ID &stat_id) const
{
	return (int)m_low_level_stats[stat_id][current_value_id];
}

const float ClassStatistics::get_growth_value(Low_Stats_ID &stat_id) const 
{
	return m_low_level_stats[stat_id][growth_value_id]; 
}


void ClassStatistics::set_base_value(Low_Stats_ID &stat_id, int &base_value)
{
	if (base_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][base_value_id] = (float)base_value;
}

void ClassStatistics::set_current_value(Low_Stats_ID &stat_id, int &current_value)
{
	if (current_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][current_value_id] = (float)current_value;
}

void ClassStatistics::set_growth_value(Low_Stats_ID &stat_id, float &growth_value)
{
	if (growth_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][growth_value_id] = growth_value;
}

void ClassStatistics::increment_base_value(Low_Stats_ID &stat_id, int &base_value)
{
	if (base_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][base_value_id] += base_value;
}

void ClassStatistics::increment_current_value(Low_Stats_ID &stat_id, int &current_value)
{
	if (current_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][current_value_id] += current_value;
}

void ClassStatistics::increment_growth_value(Low_Stats_ID &stat_id, float &growth_value)
{
	if (growth_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][growth_value_id] += growth_value;
}