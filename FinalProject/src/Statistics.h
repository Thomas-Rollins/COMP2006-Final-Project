#pragma once
//C++ Library Includes
#include<string>

//Intra-Includes
#include "statistics/Agility.h"
#include "statistics/Dexterity.h"
#include "statistics/Focus.h"
#include "statistics/Intelligence.h"
#include "statistics/Luck.h"
#include "statistics/Strength.h"
#include "statistics/Technique.h"
#include "statistics/Vitality.h"
#include "statistics/Wisdom.h"

struct Low_Statistics
{
	Agility agility;
	Dexterity dexterity;
	Focus focus;
	Intelligence intelligence;
	Luck luck;
	Strength strength;
	Technique technique;
	Vitality vitality;
	Wisdom wisdom;
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

struct Elemental_Stats
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
