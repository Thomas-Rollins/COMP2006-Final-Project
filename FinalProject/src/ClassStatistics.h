#pragma once
#include <string>

enum Description_Attribute_ID : const int 
{
	desc_id, short_form_id
};

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

/**
* This enum MUST be sequential
*/
enum High_Stats_ID : const int
{
	health_id, mana_id, skill_points_id, atk_id, def_id, magic_id, mind_id,
	accuracy_id, evasion_id, critical_id
};

/**
* This enum MUST be sequential
* Used for Elemental Attack, Resist, and Affinity
*/ 
enum Elemental_Stats_ID : const int
{
	fire_id, wind_id, earth_id, water_id, lightning_id, holy_id, dark_id, void_id
};

struct High_Level_Calculation_Ratios
{
	const float VIT_RATIO;
	const float STR_RATIO;
	const float AGI_RATIO;
	const float DEX_RATIO;
	const float TEC_RATIO;
	const float INT_RATIO;
	const float WIS_RATIO;
	const float FCS_RATIO;
	const float LUK_RATIO;

	High_Level_Calculation_Ratios(float vit_ratio, const float str_ratio,
		const float agi_ratio, const float dex_ratio, const float tec_ratio,
		const float int_ratio, const float wis_ratio, const float fcs_ratio,
		const float luk_ratio)
		: VIT_RATIO(vit_ratio), STR_RATIO(str_ratio), AGI_RATIO(agi_ratio), DEX_RATIO(dex_ratio),
		TEC_RATIO(tec_ratio), INT_RATIO(int_ratio), WIS_RATIO(wis_ratio), FCS_RATIO(fcs_ratio),
		LUK_RATIO(luk_ratio) {}
};

class ClassStatistics
{
public:
	//Constructors
	ClassStatistics();

	//Destructors
	~ClassStatistics();

	//Accessors
		// Low Level
	const int get_base_value(Low_Stats_ID const &stat_id) const;
	const int get_current_value(Low_Stats_ID const &stat_id) const;
	const float get_growth_value(Low_Stats_ID const &stat_id) const;
		// High Level
	const float get_base_value(High_Stats_ID const &stat_id) const;
	const float get_current_value(High_Stats_ID const &stat_id) const;
		// Elemental
	const float get_base_value(Elemental_Stats_ID const &stat_id) const;
	const float get_current_value(Elemental_Stats_ID const &stat_id) const;

	//Mutators
		// Low Level
	void set_base_value(Low_Stats_ID const &stat_id, const int &base_value);

	void set_current_value(Low_Stats_ID const &stat_id);
	void set_current_value(Low_Stats_ID const&stat_id, const int &current_value);
	void set_growth_value(Low_Stats_ID const &stat_id, const float &growth_value);
		// High Level
	void set_base_value(High_Stats_ID const &stat_id, const float &base_value);
	void set_current_value(High_Stats_ID const &stat_id);
	void set_current_value(High_Stats_ID const&stat_id, const float &current_value);
		// Elemental
	void set_base_value(Elemental_Stats_ID const &stat_id, const float &base_value);
	void set_current_value(Elemental_Stats_ID const&stat_id, const float &current_value);

	//Static consts
	static const int STAT_DESC_ATTRIBUTES = 2;
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
	void set_high_stats();
	float calculate_high_stat(const High_Level_Calculation_Ratios* stat_ratio);
private:
	//static consts
	// Low Level
	static const int LOW_STAT_MAX_VALUE = 65535;
	static const std::string* LOW_STAT_DESCRIPTIONS[NUM_OF_LOW_STATS][STAT_DESC_ATTRIBUTES];
	float m_low_level_stats[NUM_OF_LOW_STATS][NUM_OF_LOW_STAT_ATTRIBUTES];

	//High Level
	static const float HIGH_STAT_MAX_VALUE;
	static const float SP_MAX_VALUE;
	static const std::string* HIGH_STAT_DESCRIPTIONS[NUM_OF_HIGH_LEVEL_STATS][STAT_DESC_ATTRIBUTES];
	float m_high_level_stats[NUM_OF_HIGH_LEVEL_STATS][NUM_OF_HIGH_STAT_ATTRIBUTES];

	//Elemental
	static const float ELEMENTAL_STAT_MAX_VALUE;
	static const std::string* ELEMENTAL_STAT_DESCRIPTIONS[NUM_OF_ELEMENTAL_STATS][STAT_DESC_ATTRIBUTES];
	float m_elemental_stats[NUM_OF_ELEMENTAL_STATS][NUM_OF_ELEMENTAL_STAT_ATTRIBUTES];

	// Balancing Ratios for High Level Stat Calculations
	static const High_Level_Calculation_Ratios* HP_RATIO;
	static const High_Level_Calculation_Ratios* MP_RATIO;
	static const High_Level_Calculation_Ratios* SP_RATIO;
	static const High_Level_Calculation_Ratios* ATK_RATIO;
	static const High_Level_Calculation_Ratios* DEF_RATIO;
	static const High_Level_Calculation_Ratios* MGK_RATIO;
	static const High_Level_Calculation_Ratios* MND_RATIO;
	static const High_Level_Calculation_Ratios* ACC_RATIO;
	static const High_Level_Calculation_Ratios* EVD_RATIO;
	static const High_Level_Calculation_Ratios* CRT_RATIO;
	static const High_Level_Calculation_Ratios* LUK_RATIO;

};

