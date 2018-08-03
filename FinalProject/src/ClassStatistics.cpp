#include "ClassStatistics.h"

#include <iostream>

// Assigning Statics
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
const float ClassStatistics::SP_MAX_VALUE = 100.00f;

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
	{ (std::string*) "Represents your ability to utilize and resist the element of earth.",		(std::string*) "ERTH"	},
	{ (std::string*) "Represents your ability to utilize and resist the element of water.",		(std::string*) "WTER"	},
	{ (std::string*) "Represents your ability to utilize and resist the element of lightning.", (std::string*) "LTNG"	},
	{ (std::string*) "Represents your ability to utilize and resist the holy element.",			(std::string*) "HOLY"	},
	{ (std::string*) "Represents your ability to utilize and resist the dark elemen.t",			(std::string*) "DARK"	},
	{ (std::string*) "Represents your ability to utilize and resist element-less magic.",		(std::string*) "VOID"	}
};


// Static ratios
const High_Level_Calculation_Ratios* ClassStatistics::HP_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	10.00f,
	// STR
	3.400f,
	// AGI
	0.000f,
	// DEX
	0.000f,
	// TEC
	0.000f,
	// INT
	0.000f,
	// WIS
	0.000f,
	// FCS
	0.500f,
	// LUK
	0.000f
};
const High_Level_Calculation_Ratios* ClassStatistics::MP_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	0.000f,
	// STR
	0.000f,
	// AGI
	0.000f,
	// DEX
	0.000f,
	// TEC
	0.000f,
	// INT
	10.000f,
	// WIS
	6.100f,
	// FCS
	0.500f,
	// LUK
	0.000f,

};
// the SP_RATIO is used differently. It effects the generation of SP per turn/action not the max which is 
// always 100.
const High_Level_Calculation_Ratios* ClassStatistics::SP_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	0.000f,
	// STR
	0.000f,
	// AGI
	0.000f,
	// DEX
	0.000f,
	// TEC
	0.000f,
	// INT
	0.000f,
	// WIS
	0.000f,
	// FCS
	0.500f,
	// LUK
	0.000f,
};
const High_Level_Calculation_Ratios* ClassStatistics::ATK_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	0.000f,
	// STR
	2.000f,
	// AGI
	0.600f,
	// DEX
	0.000f,
	// TEC
	0.040f,
	// INT
	-0.205f,
	// WIS
	-0.300f,
	// FCS
	-0.300f,
	// LUK
	0.000f,
};
const High_Level_Calculation_Ratios* ClassStatistics::DEF_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	2.000f,
	// STR
	0.080f,
	// AGI
	0.000f,
	// DEX
	0.000f,
	// TEC
	0.020f,
	// INT
	0.000f,
	// WIS
	0.000f,
	// FCS
	0.000f,
	// LUK
	0.000f,
};
const High_Level_Calculation_Ratios* ClassStatistics::MGK_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	0.000f,
	// STR
	-0.550f,
	// AGI
	0.000f,
	// DEX
	0.000f,
	// TEC
	0.030f,
	// INT
	2.700f,
	// WIS
	0.800f,
	// FCS
	0.020f,
	// LUK
	0.000f,
};
const High_Level_Calculation_Ratios* ClassStatistics::MND_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	0.080f,
	// STR
	-0.050f,
	// AGI
	0.000f,
	// DEX
	0.000f,
	// TEC
	0.020f,
	// INT
	0.800f,
	// WIS
	2.800f,
	// FCS
	0.010f,
	// LUK
	0.000f,
};
const High_Level_Calculation_Ratios* ClassStatistics::ACC_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	-0.010f,
	// STR
	-0.030f,
	// AGI
	0.080f,
	// DEX
	0.500f,
	// TEC
	0.040f,
	// INT
	0.000f,
	// WIS
	0.020f,
	// FCS
	0.050f,
	// LUK
	0.800f,
};
const High_Level_Calculation_Ratios* ClassStatistics::EVD_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	-0.300f,
	// STR
	0.000f,
	// AGI
	0.300f,
	// DEX
	0.080f,
	// TEC
	0.010f,
	// INT
	-0.010f,
	// WIS
	0.000f,
	// FCS
	0.040f,
	// LUK
	0.800f,
};
const High_Level_Calculation_Ratios* ClassStatistics::CRT_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	-0.080f,
	// STR
	0.000f,
	// AGI
	0.040f,
	// DEX
	0.500f,
	// TEC
	0.080f,
	// INT
	0.200f,
	// WIS
	0.000f,
	// FCS
	0.010f,
	// LUK
	0.500f,
};
// Trated differently as it is actually a low stat.
const High_Level_Calculation_Ratios* ClassStatistics::LUK_RATIO = new High_Level_Calculation_Ratios
{
	// VIT
	0.000f,
	// STR
	0.000f,
	// AGI
	0.000f,
	// DEX
	0.000f,
	// TEC
	0.000f,
	// INT
	0.000f,
	// WIS
	0.000f,
	// FCS
	0.000f,
	// LUK
	0.000f,
};

// End of Static Assignment

ClassStatistics::ClassStatistics() 
{
	
}

ClassStatistics::~ClassStatistics() {}
// Accessors
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

	// Elemental
const float ClassStatistics::get_base_value(Elemental_Stats_ID const &stat_id) const
{
	return m_elemental_stats[stat_id][base_value_id];
}

const float ClassStatistics::get_current_value(Elemental_Stats_ID const &stat_id) const
{
	return m_elemental_stats[stat_id][current_value_id];
}
// End of Accessors

// Mutators
	// Low Level
void ClassStatistics::set_base_value(Low_Stats_ID const &stat_id, const int &base_value)
{
	if (base_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][base_value_id] = (float)base_value;
	else
		m_low_level_stats[stat_id][base_value_id] = LOW_STAT_MAX_VALUE;
}

void ClassStatistics::set_current_value(Low_Stats_ID const &stat_id, const int &current_value)
{
	if (current_value <= LOW_STAT_MAX_VALUE)
		m_low_level_stats[stat_id][current_value_id] = (float)current_value;
	else
		m_low_level_stats[stat_id][current_value_id] = LOW_STAT_MAX_VALUE;
}

void ClassStatistics::set_growth_value(Low_Stats_ID const &stat_id, const float &growth_value)
{
		m_low_level_stats[stat_id][growth_value_id] = growth_value;
}

	// High Level
void ClassStatistics::set_base_value(High_Stats_ID const &stat_id, const float &base_value)
{
	if (stat_id == skill_points_id)
		m_high_level_stats[skill_points_id][base_value_id] = 0.f;
	else if (base_value <= HIGH_STAT_MAX_VALUE)
		m_high_level_stats[stat_id][base_value_id] = base_value;
	else
		m_high_level_stats[stat_id][base_value_id] = HIGH_STAT_MAX_VALUE;
}
void ClassStatistics::set_current_value(High_Stats_ID const&stat_id, const float &current_value)
{
	if (stat_id == skill_points_id)
	{
		if(current_value <= SP_MAX_VALUE)
			m_high_level_stats[skill_points_id][current_value_id] = current_value;
		else
			m_high_level_stats[skill_points_id][current_value_id] = SP_MAX_VALUE;
	}
	else if (current_value <= HIGH_STAT_MAX_VALUE)
		m_high_level_stats[stat_id][current_value_id] = current_value;
	else 
		m_high_level_stats[stat_id][current_value_id] = HIGH_STAT_MAX_VALUE;
}
	// Elemental
void ClassStatistics::set_base_value(Elemental_Stats_ID const &stat_id, const float &base_value)
{
	if (base_value <= ELEMENTAL_STAT_MAX_VALUE)
		m_elemental_stats[stat_id][base_value_id] = (float)base_value;
	else
		m_elemental_stats[stat_id][base_value_id] = ELEMENTAL_STAT_MAX_VALUE;
}
void ClassStatistics::set_current_value(Elemental_Stats_ID const&stat_id, const float &current_value)
{
	if (current_value <= ELEMENTAL_STAT_MAX_VALUE)
		m_elemental_stats[stat_id][current_value_id] = (float)current_value;
	else
		m_elemental_stats[stat_id][current_value_id] = ELEMENTAL_STAT_MAX_VALUE;
}

// Old Incrementors
//void ClassStatistics::increment_base_value(Low_Stats_ID const &stat_id, const int &value)
//{
//	if (value <= LOW_STAT_MAX_VALUE)
//		m_low_level_stats[stat_id][base_value_id] += value;
//}
//
//void ClassStatistics::increment_current_value(Low_Stats_ID const &stat_id, const int &value)
//{
//	if (value <= LOW_STAT_MAX_VALUE)
//		m_low_level_stats[stat_id][current_value_id] += value;
//}
//
//void ClassStatistics::increment_growth_value(Low_Stats_ID const &stat_id, const float &value)
//{
//	if (value <= LOW_STAT_MAX_VALUE)
//		m_low_level_stats[stat_id][growth_value_id] += value;
//}


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

	for (int i = 0; i < NUM_OF_HIGH_LEVEL_STATS; i++)
	{
		High_Stats_ID i_ref = static_cast<High_Stats_ID> (i);
		float value = this->get_base_value(i_ref);
		this->set_current_value(i_ref, value);
	}
}

void ClassStatistics::set_high_stats()
{
	this->set_base_value(health_id, floor(calculate_high_stat(HP_RATIO)));
	this->set_base_value(mana_id, floor(calculate_high_stat(MP_RATIO)));
	this->set_base_value(magic_id, calculate_high_stat(MGK_RATIO));
	this->set_base_value(skill_points_id, 0);
	this->set_base_value(atk_id, calculate_high_stat(ATK_RATIO));
	this->set_base_value(def_id, calculate_high_stat(DEF_RATIO));
	this->set_base_value(magic_id, calculate_high_stat(MGK_RATIO));
	this->set_base_value(mind_id, calculate_high_stat(MND_RATIO));
	this->set_base_value(accuracy_id, calculate_high_stat(ACC_RATIO));
	this->set_base_value(evasion_id, calculate_high_stat(EVD_RATIO));
	this->set_base_value(critical_id, calculate_high_stat(CRT_RATIO));
}

float ClassStatistics::calculate_high_stat(const High_Level_Calculation_Ratios* stat_ratio)
{
	return float(get_base_value(vitality_id)) * stat_ratio->VIT_RATIO
		+ get_base_value(strength_id) * stat_ratio->STR_RATIO
		+ get_base_value(agility_id) * stat_ratio->AGI_RATIO
		+ get_base_value(dexterity_id) * stat_ratio->DEX_RATIO
		+ get_base_value(technique_id) * stat_ratio->TEC_RATIO
		+ get_base_value(intelligence_id) * stat_ratio->INT_RATIO
		+ get_base_value(wisdom_id) * stat_ratio->WIS_RATIO
		+ get_base_value(focus_id) * stat_ratio->FCS_RATIO
		+ get_base_value(luck_id) * stat_ratio->LUK_RATIO;
}
