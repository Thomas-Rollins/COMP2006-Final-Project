#pragma once

#include "../../ClassStatistics.h"

class Ability
{
public:
	Ability() = delete;

	Ability(const std::string& name, const std::string& desc, const float& phys_damage, const float& mgk_damage, const float& atk_bonus, const float& mgk_bonus, const float& def_bonus, const float& mnd_bonus, const float& agi_bonus, const float& acc_bonus, const Elemental_Stats_ID& element, int mp_cost, const int sp_cost, const int num_of_targets, const int level_req, const bool isFriendly, const bool isStun, const bool isExecute, const bool isRestore);

	~Ability();

	//accessors
	std::string get_name() const { return m_name; }
	std::string get_description() const { return m_description; }
	const float get_physical_damage() const { return m_physical_damage; }
	const float get_magic_damage() const { return m_magic_damage; }
	const float get_attack_bonus() const { return m_attack_bonus; }
	const float get_magic_bonus() const { return m_magic_damage; }
	const float get_defense_bonus() const { return m_defense_bonus; }
	const float get_mind_bonus() const { return m_mind_bonus; }
	const float get_agility_bonus() const { return m_agility_bonus; }
	const float get_accuracy_bonus() const { return m_accuracy_bonus; }
	const int get_mp_cost() const { return m_mp_cost; }
	const int get_sp_cost() const { return m_sp_cost; }
	const int get_num_of_targets() const { return m_num_of_targets; }
	const int get_level_requirement() const { return m_level_requirement; }
	const Elemental_Stats_ID get_element() const { return m_element; }
	const bool isFriendly() const { return m_friendly; }
	const bool isStun() const { return m_stun; }
	const bool isExecute() const { return m_execute; }
	const bool isRestore() const { return m_restore; }
	bool isUsable() const { return m_usable; }

	//mutators
	void setUsable(bool usable);

private:
	const std::string m_name;
	const std::string m_description;
	const float m_physical_damage;
	const float m_magic_damage;
	const float m_attack_bonus;
	const float m_magic_bonus;
	const float m_defense_bonus;
	const float m_mind_bonus;
	const float m_agility_bonus;
	const float m_accuracy_bonus;
	const int m_mp_cost;
	const int m_sp_cost;
	const int m_num_of_targets;
	const int m_level_requirement;
	const Elemental_Stats_ID m_element;
	const bool m_friendly;
	const bool m_stun;
	const bool m_execute;
	const bool m_restore;
	
	bool m_usable;


};
