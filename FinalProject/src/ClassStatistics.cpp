#include "ClassStatistics.h"

const std::string* ClassStatistics::LOW_STAT_DESCRIPTIONS[NUM_OF_LOW_STATS][STAT_DESC_ATTRIBUTES] =
{
	{ (std::string*)	"Agility Description Here",			(std::string*) "AGI" },
	{ (std::string*)	"Dexterity Description Here",		(std::string*) "DEX" },
	{ (std::string*)	"Focus Description Here",			(std::string*) "FCS" },
	{ (std::string*)	"Intelligence Description Here",	(std::string*) "INT" },
	{ (std::string*)	"Luck Description Here",			(std::string*) "LUK" },
	{ (std::string*)	"Strength Description Here" ,		(std::string*) "STR" },
	{ (std::string*)	"Technique Description Here",		(std::string*) "TEC" },
	{ (std::string*)	"Vitality Description Here",		(std::string*) "VIT" },
	{ (std::string*)	"Wisdom Description Here",			(std::string*) "WIS" }
};
	//max value for any high_level stat: 9 999 999 999
const float ClassStatistics::HIGH_STAT_MAX_VALUE = 9999999999.000f;

const std::string* ClassStatistics::HIGH_STAT_DESCRIPTIONS[NUM_OF_HIGH_LEVEL_STATS][STAT_DESC_ATTRIBUTES] =
{
	{ 
		(std::string*)	"Represents the life force. When this hits 0 you die.",
		(std::string*)	"HP" 
	},
	{
		(std::string*)	"Represents the ability to use magic. Without it you cannot use any magic based abilities.",
		(std::string*)	"MP" 
	},
	{
		(std::string*)	"Represents the ability to activate skills. Most skills require skill points to activate. Skill points increase during battle when you take or deal damage.",
		(std::string*)	"SP"
	},
	{
		(std::string*)	"Represents the ability to deal physical damage.",
		(std::string*)	"ATK"
	},
	{
		(std::string*)	"Represents the ability to resist physical damage.",
		(std::string*)	"DEF"
	},
	{
		(std::string*)	"Represents the ability to deal magic damage.",
		(std::string*)	"MGK"
	},
	{
		(std::string*)	"Represents the ability to resist magic damage.",
		(std::string*)	"MND"
	},
	{
		(std::string*)	"Represents the likeliness of your attacks landing. This effects both Physical and Magical attacks.",
		(std::string*)  "ACC"
	},
	{
		(std::string*)	"Represents the ability to dodge both physical and magical attacks.",
		(std::string*)	"EVD"
	},
	{	(std::string*)	"Represents the ability exploit the target's weak points dealing massive damage.",
		(std::string*)	"CRT"
	}
};

const float ClassStatistics::ELEMENTAL_STAT_MAX_VALUE = 500.00f;
const std::string* ClassStatistics::ELEMENTAL_STAT_DESCRIPTIONS[NUM_OF_ELEMENTAL_STATS][STAT_DESC_ATTRIBUTES] =
{
	{ (std::string*) "Represents your ability to utilize and resist the element of fire.",		(std::string*) "FIRE"	},
	{ (std::string*) "Represents your ability to utilize and resist the element of wind.",		(std::string*) "WIND"	},
	{ (std::string*) "Represents your ability to utilize and resist the element of earth.",		(std::string*) "EARTH"	},
	{ (std::string*) "Represents your ability to utilize and resist the element of water.",		(std::string*) "WATER"	},
	{ (std::string*) "Represents your ability to utilize and resist the element of lightning.", (std::string*) "LTNG"	},
	{ (std::string*) "Represents your ability to utilize and resist the holy element.",			(std::string*) "HOLY"	},
	{ (std::string*) "Represents your ability to utilize and resist the dark elemen.t",			(std::string*) "DARK"	},
	{ (std::string*) "Represents your ability to utilize and resist element-less magic.",		(std::string*) "VOID"	}
};

ClassStatistics::ClassStatistics() 
{
	
}

ClassStatistics::~ClassStatistics() {}

// Low Level
const int ClassStatistics::get_base_value(Low_Stats_ID const &stat_id) const
{
	return (int)m_low_level_stats[stat_id][base_value_id];
}

const int ClassStatistics::get_current_value(Low_Stats_ID const &stat_id) const
{
	return (int)m_low_level_stats[stat_id][current_value_id];
}

const float ClassStatistics::get_growth_value(Low_Stats_ID const &stat_id) const
{
	return m_low_level_stats[stat_id][growth_value_id]; 
}

//High Level
const float ClassStatistics::get_base_value(High_Stats_ID const &stat_id) const
{
	return m_high_level_stats[stat_id][base_value_id];
}

const float ClassStatistics::get_current_value(High_Stats_ID const &stat_id) const
{
	return m_high_level_stats[stat_id][current_value_id];
}

void ClassStatistics::set_base_value(Low_Stats_ID const &stat_id, const int &base_value)
{
	if (base_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][base_value_id] = (float)base_value;
}

void ClassStatistics::set_current_value(Low_Stats_ID const &stat_id, const int &current_value)
{
	if (current_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][current_value_id] = (float)current_value;
}

void ClassStatistics::set_growth_value(Low_Stats_ID const &stat_id, const float &growth_value)
{
	if (growth_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][growth_value_id] = growth_value;
}

void ClassStatistics::increment_base_value(Low_Stats_ID const &stat_id, const int &value)
{
	if (value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][base_value_id] += value;
}

void ClassStatistics::increment_current_value(Low_Stats_ID const &stat_id, const int &value)
{
	if (value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][current_value_id] += value;
}

void ClassStatistics::increment_growth_value(Low_Stats_ID const &stat_id, const float &value)
{
	if (value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][growth_value_id] += value;
}

/**
 * This method will break if the Low_Stats_ID enum is not sequential
 */
void ClassStatistics::reset_current_values()
{
	for (int i = 0; i < NUM_OF_LOW_STATS; i++)
	{
		Low_Stats_ID i_ref = static_cast<Low_Stats_ID> (i);
		int value = this->get_base_value(i_ref);
		this->set_current_value(i_ref, value);
	}
}