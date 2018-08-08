#pragma once

#define MAX_LEVEL 100
#define MAX_LEVEL_DIFFERENCE 5

#define XP_RAND_MODIFIER_LOWER_BOUND	1
#define	XP_RAND_MODIFIER_UPPER_BOUND	5
#define XP_EXPONENT						2.5
#define XP_ROUNDS_WON_BASE_MULTIPLIER	2

//HP RATIOS
#define HP_VIT_RATIO	10.000f
#define HP_STR_RATIO	3.400f
#define HP_AGI_RATIO	0.000f
#define HP_DEX_RATIO	0.000f
#define HP_TEC_RATIO	0.000f
#define HP_INT_RATIO	0.000f
#define HP_WIS_RATIO	0.000f
#define HP_FOCUS_RATIO	0.500f
#define HP_LUCK_RATIO	0.000f

//MP RATIOS
#define MP_VIT_RATIO	0.000f
#define MP_STR_RATIO	0.000f
#define MP_AGI_RATIO	0.000f
#define MP_DEX_RATIO	0.000f
#define MP_TEC_RATIO	0.000f
#define MP_INT_RATIO	10.00f
#define MP_WIS_RATIO	6.100f
#define MP_FOCUS_RATIO  0.500f
#define MP_LUCK_RATIO	0.000f

//SP RATIOS
#define SP_VIT_RATIO	0.000f
#define SP_STR_RATIO	0.000f
#define SP_AGI_RATIO	0.000f
#define SP_DEX_RATIO	0.000f
#define SP_TEC_RATIO	0.000f
#define SP_INT_RATIO	0.000f
#define SP_WIS_RATIO	0.000f
#define SP_FOCUS_RATIO  0.050f
#define SP_LUCK_RATIO	0.000f

//ATK RATIOS
#define ATK_VIT_RATIO		 0.000f
#define ATK_STR_RATIO		 2.000f
#define ATK_AGI_RATIO	 	 0.600f
#define ATK_DEX_RATIO		 0.000f
#define ATK_TEC_RATIO		 0.040f
#define ATK_INT_RATIO		-0.205f
#define ATK_WIS_RATIO		-0.300f
#define ATK_FOCUS_RATIO		-3.050f
#define ATK_LUCK_RATIO		 0.000f

//DEF RATIOS
#define DEF_VIT_RATIO		2.000f
#define DEF_STR_RATIO		0.080f
#define DEF_AGI_RATIO		0.000f
#define DEF_DEX_RATIO		0.000f
#define DEF_TEC_RATIO		0.020f
#define DEF_INT_RATIO		0.000f
#define DEF_WIS_RATIO		0.000f
#define DEF_FOCUS_RATIO		0.000f
#define DEF_LUCK_RATIO		0.000f

//MGK RATIOS
#define MGK_VIT_RATIO		 0.000f
#define MGK_STR_RATIO		-0.550f
#define MGK_AGI_RATIO		 0.000f
#define MGK_DEX_RATIO		 0.000f
#define MGK_TEC_RATIO		 0.030f
#define MGK_INT_RATIO		 2.700f
#define MGK_WIS_RATIO		 0.800f
#define MGK_FOCUS_RATIO		 0.020f
#define MGK_LUCK_RATIO		 0.000f


//MND RATIOS
#define MND_VIT_RATIO		 0.080f
#define MND_STR_RATIO		-0.050f
#define MND_AGI_RATIO		 0.000f
#define MND_DEX_RATIO		 0.000f
#define MND_TEC_RATIO		 0.020f
#define MND_INT_RATIO		 0.800f
#define MND_WIS_RATIO		 2.800f
#define MND_FOCUS_RATIO		 0.010f
#define MND_LUCK_RATIO		 0.000f

//ACC RATIOS
#define ACC_VIT_RATIO		 -0.010f
#define ACC_STR_RATIO		 -0.010f
#define ACC_AGI_RATIO		  0.080f
#define ACC_DEX_RATIO		  0.500f
#define ACC_TEC_RATIO		  0.040f
#define ACC_INT_RATIO		  0.000f
#define ACC_WIS_RATIO		  0.020f
#define ACC_FOCUS_RATIO		  0.100f
#define ACC_LUCK_RATIO		  0.800f

//EVD RATIOS
#define EVD_VIT_RATIO		 -0.300f
#define EVD_STR_RATIO		  0.000f
#define EVD_AGI_RATIO		  0.300f
#define EVD_DEX_RATIO		  0.080f
#define EVD_TEC_RATIO		  0.010f
#define EVD_INT_RATIO		 -0.010f
#define EVD_WIS_RATIO		  0.000f
#define EVD_FOCUS_RATIO		  0.040f
#define EVD_LUCK_RATIO		  0.800f

//CRT RATIOS
#define CRT_VIT_RATIO		 -0.080f
#define CRT_STR_RATIO		  0.000f
#define CRT_AGI_RATIO		  0.040f
#define CRT_DEX_RATIO		  0.050f
#define CRT_TEC_RATIO		  0.080f
#define CRT_INT_RATIO		  0.100f
#define CRT_WIS_RATIO		  0.000f
#define CRT_FOCUS_RATIO		  0.010f
#define CRT_LUCK_RATIO		  0.500f

//Balancing statics
#define BASE_LEVEL_MULTIPLIER	2
#define DMG_LEVEL_DIVISOR		5
#define DMG_LEVEL_INCREMENT		2
#define DMG_DIVISOR				50
#define DMG_INCREMENT			2

#define MGK_HEAL_RATIO			0.4f
#define MIND_HEAL_RATIO			0.3f
#define SINGLE_TARGET_MOD		1.0f
#define MULTI_TARGET_MOD		0.75f
#define CRIT_MOD				1.75f
#define NON_CRIT_MOD			1.0f
#define RAND_MOD_LOWER_BOUND	0.84f
#define RAND_MOD_UPPER_BOUND	1.01f

#define BASE_SP_GEN					5
#define TARGET_SP_GEN_RATIO			0.6f
#define SP_DIFFERENCE_MULTIPLIER	10

#define ELEMENTAL_BASE_MOD			1.f
#define ELEMENTAL_INEFFECTIVE_MOD	0.f
#define ELEMENTAL_WEAKNESS_MOD		0.125f
#define ELEMENTAL_DISADVANTAGE_MOD	0.375f
#define ELEMENTAL_NEUTRAL_MOD		1.0f
#define ELEMENTAL_ADVANTAGE_MOD		1.125f
#define ELEMENTAL_STRONG_MOD		1.375f

#define CRIT_CHANCE_UPPER_BOUND				10000.f
#define CRIT_CHANCE_RAND_MOD_LOWER_BOUND	0.f
#define CRIT_CHANCE_RAND_MOD_UPPER_BOUND	1.f
#define CRIT_CHANCE_DIVISOR					5000.f