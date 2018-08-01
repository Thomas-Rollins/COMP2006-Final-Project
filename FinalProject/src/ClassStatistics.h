#pragma once
#include <string>

/**
 * This enum MUST be sequential
 */
enum Low_Stats_ID : const int 
{
	agility_id, dexterity_id, focus_id, intelligence_id, luck_id,
	strength_id, technique_id, vitality_id, wisdom_id
};

enum Low_Stats_Attribute : const int 
{
	base_value_id, current_value_id, growth_value_id
};

enum High_Stats_ID : const int
{
	health_id, mana_id, skill_points_id, physical_atk_id, def_id, magic_atk_id, mind_id,
	accuracy_id, evasion_id, critical_id
};

// Used for Elemental Attack, Resist, and Affinity
enum Elemental_Stats_ID : const int
{
	fire_id, wind_id, earth_id, water_id, lightning_id, holy_id, dark_id, void_id
};

class ClassStatistics
{
public:
	//Constructors
	ClassStatistics();

	//Destructors
	~ClassStatistics();

	//Accessors
	const int get_base_value(Low_Stats_ID const &stat_id) const;
	const int get_current_value(Low_Stats_ID const &stat_id) const;
	const float get_growth_value(Low_Stats_ID const &stat_id) const;
	
	//Incrementors
	void increment_base_value(Low_Stats_ID const &stat_id, const int &value);
	void increment_current_value(Low_Stats_ID const &stat_id, const int &value);
	void increment_growth_value(Low_Stats_ID const &stat_id, const float &value);

	//Mutators
	void set_base_value(Low_Stats_ID const &stat_id, const int &base_value);
	void set_current_value(Low_Stats_ID const&stat_id, const int &current_value);
	void set_growth_value(Low_Stats_ID const &stat_id, const float &growth_value);

	//Static consts
		//Low stats
	static const int NUM_OF_LOW_STATS = 9;
	static const int NUM_OF_LOW_STAT_ATTRIBUTES = 3;
		//High Stats
	static const int NUM_OF_HIGH_LEVEL_STATS = 10;
	static const int NUM_OF_HIGH_STAT_ATTRIBUTES = 2;
		// Elemental Stats
	static const int NUM_OF_ELEMENTAL_STATS = 8;
	static const int NUM_OF_ELEMENTAL_STAT_ATTRIBUTES = 3;
	//Balancing Static
	static const int BASE_STAT_INCREASE_PER_LEVEL = 5;

	//Mutators
	void reset_current_values();

private:
	//static consts
	// Low Level
	static const int LOW_STAT_MAX_VALUE = 65535;
	static const std::string* LOW_STAT_DESCRIPTIONS[NUM_OF_LOW_STATS];
	float m_low_level_stats[NUM_OF_LOW_STATS][NUM_OF_LOW_STAT_ATTRIBUTES];

	//High Level
	static const double HIGH_STAT_MAX_VALUE;
	static const std::string* HIGH_STAT_DESCRIPTIONS[NUM_OF_HIGH_LEVEL_STATS];
	float m_high_level_stats[NUM_OF_HIGH_LEVEL_STATS][NUM_OF_HIGH_STAT_ATTRIBUTES];

	//Elemental
	static const float ELEMENTAL_STAT_MAX_VALUE;
	static const std::string* ELEMENTAL_STAT_DESCRIPTIONS[NUM_OF_ELEMENTAL_STATS];
	float m_elemental_stats[NUM_OF_ELEMENTAL_STATS][NUM_OF_ELEMENTAL_STAT_ATTRIBUTES];


	
};

