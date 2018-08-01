#include "ClassStatistics.h"

const std::string* ClassStatistics::LOW_STAT_DESCRIPTIONS[] =
{
	LOW_STAT_DESCRIPTIONS[agility_id]		= (std::string*)	"Agility Description Here",
	LOW_STAT_DESCRIPTIONS[dexterity_id]		= (std::string*)	"Dexterity Description Here",
	LOW_STAT_DESCRIPTIONS[focus_id]			= (std::string*)	"Focus Description Here",
	LOW_STAT_DESCRIPTIONS[intelligence_id]	= (std::string*)	"Intelligence Description Here",
	LOW_STAT_DESCRIPTIONS[luck_id]			= (std::string*)	"Luck Description Here",
	LOW_STAT_DESCRIPTIONS[strength_id]		= (std::string*)	"Strength Description Here" ,
	LOW_STAT_DESCRIPTIONS[technique_id]		= (std::string*)	"Technique Description Here",
	LOW_STAT_DESCRIPTIONS[vitality_id]		= (std::string*)	"Vitality Description Here",
	LOW_STAT_DESCRIPTIONS[wisdom_id]		= (std::string*)	"Wisdom Description Here"
};
	//max value for any high_level stat: 9 999 999 999
const double ClassStatistics::HIGH_STAT_MAX_VALUE = 9999999999;

const std::string* ClassStatistics::HIGH_STAT_DESCRIPTIONS[] =
{
	HIGH_STAT_DESCRIPTIONS[health_id]		= (std::string*)	"Represents the life force. When this hits 0 you die.",
	HIGH_STAT_DESCRIPTIONS[mana_id]			= (std::string*)	"Represents the ability to use magic. Without it you cannot use any magic based abilities.",
	HIGH_STAT_DESCRIPTIONS[skill_points_id] = (std::string*)	"Represents the ability to activate skills. Most skills require skill points to activate. Skill points increase during battle when you take or deal damage.",
	HIGH_STAT_DESCRIPTIONS[physical_atk_id] = (std::string*)	"Represents the ability to deal physical damage.",
	HIGH_STAT_DESCRIPTIONS[def_id]			= (std::string*)	"Represents the ability to resist physical damage.",
	HIGH_STAT_DESCRIPTIONS[magic_atk_id]	= (std::string*)	"Represents the ability to deal magic damage.",
	HIGH_STAT_DESCRIPTIONS[mind_id]			= (std::string*)	"Represents the ability to resist magic damage.",
	HIGH_STAT_DESCRIPTIONS[accuracy_id]		= (std::string*)	"Represents the likeliness of your attacks landing. This effects both Physical and Magical attacks.",
	HIGH_STAT_DESCRIPTIONS[evasion_id]		= (std::string*)	"Represents the ability to dodge both physical and magical attacks.",
	HIGH_STAT_DESCRIPTIONS[critical_id]		= (std::string*)	"Represents the ability exploit the target's weak points dealing massive damage."
};

const float ClassStatistics::ELEMENTAL_STAT_MAX_VALUE = 500.00f;
const std::string* ClassStatistics::ELEMENTAL_STAT_DESCRIPTIONS[] =
{
	ELEMENTAL_STAT_DESCRIPTIONS[fire_id]		= (std::string*) "Represents your ability to utilize and resist the element of fire.",
	ELEMENTAL_STAT_DESCRIPTIONS[wind_id]		= (std::string*) "Represents your ability to utilize and resist the element of wind.",
	ELEMENTAL_STAT_DESCRIPTIONS[earth_id]		= (std::string*) "Represents your ability to utilize and resist the element of earth.",
	ELEMENTAL_STAT_DESCRIPTIONS[water_id]		= (std::string*) "Represents your ability to utilize and resist the element of water.",
	ELEMENTAL_STAT_DESCRIPTIONS[lightning_id]	= (std::string*) "Represents your ability to utilize and resist the element of lightning.",
	ELEMENTAL_STAT_DESCRIPTIONS[holy_id]		= (std::string*) "Represents your ability to utilize and resist the holy element.",
	ELEMENTAL_STAT_DESCRIPTIONS[dark_id]		= (std::string*) "Represents your ability to utilize and resist the dark elemen.t",
	ELEMENTAL_STAT_DESCRIPTIONS[void_id]		= (std::string*) "Represents your ability to utilize and resist element-less magic."
};

ClassStatistics::ClassStatistics() 
{
	
}

ClassStatistics::~ClassStatistics() {}


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