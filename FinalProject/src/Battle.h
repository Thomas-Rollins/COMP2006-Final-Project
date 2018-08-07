#pragma once

#include <vector>

#include "Character.h"

class Battle
{
public:

	Battle(const std::vector<Character*> team_1, const std::vector<Character*> team_2);


	~Battle();

	const std::vector<Character*> get_turn_order() const { return m_turn_order; }

	void print_turn_order();



	template <typename T>
	void move_item_to_back(std::vector<T> &v, size_t itemIndex);

private:
	void update_turn_order();
	void action();
	void execute_action(const Ability* ability, Character* target);
	float get_modifiers(const Ability* ability);
	float get_elemental_dmg_modifer(const Ability* ability, Character* target);
	bool isCritAttack();
	Character* get_target();
	void give_sp(const Character* actor);
	void remove_dead();
	bool team_dead(std::vector<Character*> team);
	
	std::vector<Character*> m_team_1, m_team_2;
	std::vector<Character*> m_turn_order;
	Character* target;
	bool m_friendly;
};

