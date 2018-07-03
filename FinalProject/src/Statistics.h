#pragma once
#include <string>


#include "logging/Log.h"

static int low_stat_default_const_count = 0;

struct Low_Stat_Shell
{
	Low_Stat_Shell(const std::string description, const char* alias, const int max_value,
		const int& min_value)
		: DESCRIPTION(description), ALIAS(alias), MAX_VALUE(max_value), MIN_VALUE(min_value)
	{

	}

	const std::string DESCRIPTION;
	const char* ALIAS;
	const int MAX_VALUE; //	65536;
	const int MIN_VALUE; //	-65536;
};

struct Low_Statistics
{
public:
	Low_Statistics()
	{
		Log("Low_Statistics Default Constructor Used");
		low_stat_default_const_count++;
		Log(low_stat_default_const_count);
		
	}
	Low_Statistics(Low_Stat_Shell* statistic, float growth, int start_value)
		: statistic(statistic), growth_value(growth), value(start_value)
	{

	}
	Low_Stat_Shell* statistic;
	float growth_value;
	int value;
};

struct Low_Level_Stats
{
public:

	Low_Statistics vitality;
	Low_Statistics strength;
	Low_Statistics agility;
	Low_Statistics dexterity;
	Low_Statistics technique;
	Low_Statistics intelligence;
	Low_Statistics wisdom;
	Low_Statistics focus;
	Low_Statistics luck;

	//// Base Elemental Affinities
	Low_Statistics affinity_fire;
	Low_Statistics affinity_wind;
	Low_Statistics affinity_earth;
	Low_Statistics affinity_water;
	Low_Statistics affinity_lightning;
	Low_Statistics affinity_holy;
	Low_Statistics affinity_dark;

};

struct High_Level_Stats
{
public:
	float health;
	float mana;
	float stamina;
	float physical_attack;
	float physical_defense;
	float magic_attack;
	float magic_defense;
	float accuracy;
	float evasion;
	float critical_rate;
};

struct High_Level_Elemental_Stats
{
public:
	float fire;
	float wind;
	float earth;
	float water;
	float lightning;
	float holy;
	float dark;
	float typeless;
};
