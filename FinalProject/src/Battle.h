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
	Character* get_target();
	
	std::vector<Character*> m_team_1, m_team_2;
	std::vector<Character*> m_turn_order;
	Character* target;
	bool m_friendly;
};

