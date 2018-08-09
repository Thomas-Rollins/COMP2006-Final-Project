#include <iostream>

#include "Ability.h"

Ability::Ability(const std::string& name, const std::string& desc, const float& phys_damage,
	const float& mgk_damage, const float& atk_bonus, const float& mgk_bonus, const float& def_bonus,
	const float& mnd_bonus, const float& agi_bonus, const float& acc_bonus, const Elemental_Stats_ID& element,
	int mp_cost, const int sp_cost, const int num_of_targets, const int level_req, const bool isFriendly,
	const bool isStun, const bool isExecute, const bool isRestore)
	: m_name(name), m_description(desc), m_physical_damage(phys_damage), m_magic_damage(mgk_damage),
	m_attack_bonus(atk_bonus), m_magic_bonus(mgk_bonus), m_defense_bonus(def_bonus),
	m_mind_bonus(mnd_bonus), m_agility_bonus(agi_bonus), m_accuracy_bonus(acc_bonus), m_element(element),
	m_mp_cost(mp_cost), m_sp_cost(sp_cost), m_num_of_targets(num_of_targets), m_level_requirement(level_req),
	m_friendly(isFriendly), m_stun(isStun), m_execute(isExecute), m_restore(isRestore) { }

Ability::~Ability() { }


void Ability::setUsable(bool usable)
{
	m_usable = usable;
}