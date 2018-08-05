#include <iostream>
#include <algorithm>


#include "Battle.h"
#include "NPC.h"
#include "PlayableCharacter.h"



Battle::Battle(std::vector<Character*> team_1, std::vector<Character*> team_2)
	: m_team_1(team_1), m_team_2(team_2)
{
	
	std::cout << "Team one consists of:" << std::endl;
	for (auto&& character : m_team_1)
	{
		std::cout << character->get_name() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Team two consists of:" << std::endl;
	for (auto&& character : m_team_2)
	{
		std::cout << character->get_name() << std::endl;
	}
	std::cout << std::endl;

	//pre-allocate and combine
	m_turn_order.reserve(8);
	m_turn_order.insert(m_turn_order.end(), team_1.begin(), team_1.end());
	m_turn_order.insert(m_turn_order.end(), team_2.begin(), team_2.end());

	//sorts by highest agility value
	std::sort(m_turn_order.begin(), m_turn_order.end(), [](Character* char1, Character* char2)
	{
		return char1->get_character_stats()->get_current_value(agility_id) >
			char2->get_character_stats()->get_current_value(agility_id);
	});

	/**
	 * the characters in m_team_x and m_turn_order share the same pointer and therefore it is
	 * possible to use pointer comparison to link the two when handling actions
	 */
	/*print_turn_order();

	for (auto&& character : m_team_1)
	{
		std::cout << character->get_character_stats()->get_current_value(agility_id) << "\t" <<
			character << std::endl;
	}
	for (auto&& character : m_team_2)
	{
		std::cout << character->get_character_stats()->get_current_value(agility_id) << "\t" <<
			character << std::endl;
	}*/

}


Battle::~Battle()
{
}
// throws the item to the back of the vector without any vector re-allocation taking place
template <typename T>
void Battle::move_item_to_back(std::vector<T> &v, size_t itemIndex)
{
	auto it = v.begin() + itemIndex;
	std::rotate(it, it + 1, v.end());
}

void Battle::print_turn_order()
{

	for(auto&& character : get_turn_order() )
	{
		std::cout << character->get_character_stats()->get_current_value(agility_id) << "\t" <<
			character << std::endl;
	}
	std::cout << std::endl;
}