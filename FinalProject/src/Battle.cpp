#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <random>

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

	update_turn_order();

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
	

	do 
	{
		action();
		remove_dead();
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
	} while ((m_team_2.size() > 0) && (m_team_1.size() > 0));

	std::cout << "A team has died";
}


Battle::~Battle()
{
	// since team_1, team_2, and m_turn_order share pointers they can all be deleted at once.
	for (auto&& character : m_turn_order)
	{
		delete(character);
	}
	m_turn_order.clear();
	m_team_1.clear();
	m_team_2.clear();
}

//sorts by highest agility value
void Battle::update_turn_order()
{
	std::sort(m_turn_order.begin(), m_turn_order.end(), [](Character* char1, Character* char2)
	{
		return char1->get_character_stats()->get_current_value(agility_id) >
			char2->get_character_stats()->get_current_value(agility_id);
	});
}

/**
 * This code is kind of replicated redundantly. It's only purpose is to ensure the offsets
 * match up. This is static for simplicity.
 */
Character* Battle::get_target()
{
	std::vector<std::string> options;
	for (auto&& character : m_team_2)
	{
		std::string option = character->get_name() + "\tHP: ";
		option.append(std::to_string( (int) character->get_character_stats()->get_current_value(health_id))
			+ "/" + std::to_string( (int) character->get_character_stats()->get_base_value(health_id)));
		options.push_back(option);
	}
	for (auto&& character : m_team_1)
	{
		std::string option = character->get_name() + "\tHP: ";
		option.append(std::to_string( (int) character->get_character_stats()->get_current_value(health_id))
			+ "/" + std::to_string( (int) character->get_character_stats()->get_base_value(health_id)));
		options.push_back(option);
	}

	std::cout << "Who would you like to target?" << std::endl;

	int choice = Utilities::draw_menu(options);
	int team_1_size = m_team_1.size();
	int team_2_size = m_team_2.size();
	if (choice > team_2_size)
	{
		 //offset cause I don't care if you attack your own team.. or even yourself.
		return m_team_1.at(choice - (1 + team_2_size));
	}
	else
	{	
		return m_team_2.at(choice - 1);
	}
		
}

void Battle::action()
{
	//Character* target = get_target();
	//std::cout << m_turn_order.at(0)->get_name() << " " m_turn_order.at(0)->get_action(m_friendly)->get_name() <<
		//" used against: " << target->get_name() << std::endl;
	/*const Ability* selected_ability = m_turn_order.at(0)->get_action(m_friendly);
	if (selected_ability->isFriendly())
		execute_action(selected_ability, m_team_2.at(Utilities::random_int(0, m_team_2.size())));
	else
		execute_action(selected_ability, m_team_2.at(Utilities::random_int(0, m_team_1.size())));
	*/
	execute_action(m_turn_order.at(0)->get_action(m_friendly), get_target());

	//moves the player to the end of the turn order vector after their action.
	move_item_to_back(m_turn_order, 0);
}

void Battle::execute_action(const Ability* ability, Character* target)
{
	Character* actor = m_turn_order.at(0);

	float damage;
	float actor_atk, actor_magic, actor_acc, actor_crit;
	int debuff = -1;
	const bool friendly = ability->isFriendly();

	actor_atk = actor->get_character_stats()->get_current_value(atk_id);
	actor_magic = actor->get_character_stats()->get_current_value(magic_id);
	actor_acc = actor->get_character_stats()->get_current_value(accuracy_id);
	actor_crit = actor->get_character_stats()->get_current_value(critical_id);
	
	

	float phys_resistance = target->get_character_stats()->get_current_value(def_id);
	float mgk_resistance = target->get_character_stats()->get_current_value(mind_id);

	float power = actor_atk * ability->get_physical_damage();


	if (friendly)
	{
		damage = -1.f * ((actor_magic * 0.4f) + (actor->get_character_stats()->
			get_current_value(mind_id)) * 0.3f) * ability->get_magic_damage();
		debuff = 1;
	}
	else
	{
		damage = (
			((
			((2 * actor->get_character_level() / 5) + 2) *
				(power * actor_atk / phys_resistance)
				) / 50)
			+ 2) * get_modifiers(ability) * get_elemental_dmg_modifer(ability, target);

	}

	if (ability->get_agility_bonus() > 0)
	{
		target->get_character_stats()->set_current_value(agility_id,
			(int)floor((float)target->get_character_stats()->get_base_value(agility_id)
			* ability->get_agility_bonus()) * debuff
		);
	}
	if (ability->get_attack_bonus() > 0)
	{
		target->get_character_stats()->set_current_value(strength_id,
			(int)floor((float)target->get_character_stats()->get_base_value(strength_id)
			* ability->get_attack_bonus()) * debuff
		);
	}
	if (ability->get_magic_bonus() > 0)
	{
		target->get_character_stats()->set_current_value(intelligence_id,
			(int)floor((float)target->get_character_stats()->get_base_value(intelligence_id)
			* ability->get_magic_bonus()) * debuff
		);
	}
	if (ability->get_defense_bonus() > 0)
	{
		target->get_character_stats()->set_current_value(vitality_id,
			(int)floor((float)target->get_character_stats()->get_base_value(vitality_id)
			* ability->get_defense_bonus()) * debuff
		);
	}
	if (ability->get_mind_bonus() > 0)
	{
		target->get_character_stats()->set_current_value(wisdom_id,
			(int)floor((float)target->get_character_stats()->get_base_value(wisdom_id)
			* ability->get_mind_bonus()) * debuff
		);
	}
	

	//updates target high stats after any possible changes
	if ((target->get_character_stats()->get_current_value(health_id) - damage) 
		> target->get_character_stats()->get_base_value(health_id))
	{
		target->get_character_stats()->set_current_value(health_id, 
			target->get_character_stats()->get_base_value(health_id));
	}
	target->get_character_stats()->set_current_value(health_id,
		target->get_character_stats()->get_current_value(health_id) - damage);

	// gets the missing health/MP before a stat update to maintain it.
	float missing_health = (target->get_character_stats()->get_current_value(health_id)
		- target->get_character_stats()->get_base_value(health_id)) * -1;

	float missing_mp = (target->get_character_stats()->get_current_value(mana_id)
		- target->get_character_stats()->get_base_value(mana_id)) * -1;

	std::cout << "Missing Health: " << missing_health << "\tMissing MP: " << missing_mp << std::endl;
	if (ability->isRestore())
	{
		target->get_character_stats()->reset_current_values(false);
	}
	// updates high_stats
	target->get_character_stats()->set_high_stats();
	// removes the missing health/mp
	target->get_character_stats()->set_current_value(health_id,
		target->get_character_stats()->get_current_value(health_id) - missing_health);
	target->get_character_stats()->set_current_value(mana_id,
		target->get_character_stats()->get_current_value(mana_id) - missing_mp);

	

	std::cout << "Damage: " << damage << std::endl;
	std::cout << "actor attack: " << actor_atk << std::endl;
	std::cout << "target def: " << phys_resistance << std::endl;
	std::cout << "Difference: " << actor_atk - phys_resistance << std::endl;
	

}

float Battle::get_modifiers(const Ability* ability)
{
	Character* actor = m_turn_order.at(0);
	float modifiers = 0;
	float target_mod;
	float crit_mod;
	bool crit = isCritAttack();
	std::cout << "Crit: " << crit << std::endl;

	
	if (ability->get_num_of_targets() > 1)
		target_mod = 0.75f;
	else
		target_mod = 1.0f;

	if (crit)
		crit_mod = 1.75f;
	else
		crit_mod = 1.0f;
	

	float rand_modifier = Utilities::random_float(0.85f, 1.00f);
	
	modifiers = target_mod * crit_mod * rand_modifier;
	

	return modifiers;
}
/**
* 0 = ineffective (no damage)
* 0.25-0.5 (not very effective)
* 1 (normal effectiveness)
* 2-4 (super effective)
*/
float Battle::get_elemental_dmg_modifer(const Ability* ability, Character* target)
{
	Character* actor = m_turn_order.at(0);
	float elemental_mod = 1;
	float actor_ele_afin;
	float target_ele_afin[ClassStatistics::NUM_OF_ELEMENTAL_STATS];
	

	for (int i = 0; i < ClassStatistics::NUM_OF_ELEMENTAL_STATS; i++)
	{
		target_ele_afin[i] = target->get_character_stats()->get_current_value(static_cast<Elemental_Stats_ID> (i));
	}

	switch (ability->get_element())
	{
	case 0:
		actor_ele_afin = actor->get_character_stats()->get_current_value(fire_id);	
		elemental_mod += (0.375f * target_ele_afin[water_id]);
		elemental_mod += (0.125f * target_ele_afin[earth_id]);
		elemental_mod += (actor_ele_afin - target_ele_afin[fire_id]);
		elemental_mod -= (0.375f * target_ele_afin[wind_id]);
		elemental_mod -= (0.125f * target_ele_afin[dark_id]);
		break;
	case 1:
		actor_ele_afin = actor->get_character_stats()->get_current_value(wind_id);
		elemental_mod += (0.375f * target_ele_afin[fire_id]);
		elemental_mod += (0.125f * target_ele_afin[water_id]);
		elemental_mod += (0.125f * target_ele_afin[dark_id]);
		elemental_mod += (actor_ele_afin - target_ele_afin[wind_id]);
		elemental_mod -= (0.375f * target_ele_afin[earth_id]);
		break;
	case 2:
		actor_ele_afin = actor->get_character_stats()->get_current_value(earth_id);
		elemental_mod += (0.375f * target_ele_afin[wind_id]);
		elemental_mod += (0.375f * target_ele_afin[lightning_id]);
		elemental_mod += (0.125f * target_ele_afin[fire_id]);
		elemental_mod += (0.125f * target_ele_afin[holy_id]);
		elemental_mod += (actor_ele_afin - target_ele_afin[earth_id]);
		elemental_mod -= (0.375f * target_ele_afin[water_id]);
		elemental_mod -= (0.125f * target_ele_afin[dark_id]);
		break;
	case 3:
		actor_ele_afin = actor->get_character_stats()->get_current_value(water_id);
		elemental_mod += (0.375f * target_ele_afin[earth_id]);
		elemental_mod += (actor_ele_afin - target_ele_afin[water_id]);
		elemental_mod -= (0.375f * target_ele_afin[fire_id]);
		elemental_mod -= (0.375f * target_ele_afin[lightning_id]);
		elemental_mod -= (0.125f * target_ele_afin[wind_id]);
		elemental_mod -= (0.125f * target_ele_afin[holy_id]);
		elemental_mod -= (0.125f * target_ele_afin[dark_id]);
		break;
	case 4:
		actor_ele_afin = actor->get_character_stats()->get_current_value(lightning_id);
		elemental_mod += (0.375f * target_ele_afin[water_id]);
		elemental_mod += (0.125f * target_ele_afin[dark_id]);
		elemental_mod += (actor_ele_afin - target_ele_afin[lightning_id]);
		elemental_mod -= (0.375f * target_ele_afin[earth_id]);
		break;
	case 5:
		actor_ele_afin = actor->get_character_stats()->get_current_value(holy_id);
		elemental_mod += (0.375f * target_ele_afin[dark_id]);
		elemental_mod += (0.375f * target_ele_afin[holy_id]);
		elemental_mod += (actor_ele_afin - target_ele_afin[holy_id]);
		break;
	case 6:
		actor_ele_afin = actor->get_character_stats()->get_current_value(dark_id);
		elemental_mod += (0.375f * target_ele_afin[holy_id]);
		elemental_mod += (0.125f * target_ele_afin[water_id]);
		elemental_mod += (0.125f * target_ele_afin[earth_id]);
		elemental_mod += (actor_ele_afin - target_ele_afin[dark_id]);
		elemental_mod -= (0.125f * target_ele_afin[fire_id]);
		elemental_mod -= (0.125f * target_ele_afin[wind_id]);
		elemental_mod -= (0.125f * target_ele_afin[lightning_id]);
		break;
	case 7:
	default:
		actor_ele_afin = actor->get_character_stats()->get_current_value(void_id);
		elemental_mod += (actor_ele_afin - target_ele_afin[void_id]);
		break;
	}
	std::cout << "Elemental Mod: " << elemental_mod << std::endl;
	return elemental_mod;
}

bool Battle::isCritAttack()
{
	float chance = (1000 - m_turn_order.at(0)->get_character_stats()
		->get_current_value(critical_id)) / 10000;
	std::cout << chance << std::endl;
	return Utilities::random_float(0.f, 1.f) < chance;
}

/**
 * This method completely removes the dead making reviving not possible.
 * Not to be used with team_dead(std::vector<Character*> team)
 */
void Battle::remove_dead()
{

	std::sort(m_team_1.begin(), m_team_1.end(), [](Character* char1, Character* char2)
	{
		return char1->get_character_stats()->get_current_value(health_id) >
			char2->get_character_stats()->get_current_value(health_id);
	});

	std::sort(m_team_2.begin(), m_team_2.end(), [](Character* char1, Character* char2)
	{
		return char1->get_character_stats()->get_current_value(health_id) >
			char2->get_character_stats()->get_current_value(health_id);
	});

	for (auto&& member : m_team_1)
	{
		if (member->get_character_stats()->get_current_value(health_id) <= 0)
		{
			for (auto&& turn_member : m_turn_order)
			{
				m_turn_order.erase(std::remove(m_turn_order.begin(), m_turn_order.end(), member),
					m_turn_order.end());
				std::cout << turn_member << "member: " << member << std::endl;
			}
			std::cout << m_team_1.back()->get_name() << " has died permanently and left the team.";
			m_team_1.pop_back();
		}
	}

	for (auto&& member : m_team_2)
	{
		if (member->get_character_stats()->get_current_value(health_id) <= 0)
		{
			for (auto&& turn_member : m_turn_order)
			{
				m_turn_order.erase(std::remove(m_turn_order.begin(), m_turn_order.end(), member),
					m_turn_order.end());
				std::cout << turn_member << "member: " << member << std::endl;
			}
			std::cout << m_team_2.back()->get_name() << " has died permanently and left the team.";
			m_team_2.pop_back();
		}
	}
}

bool Battle::team_dead(std::vector<Character*> team)
{
	// This method supports reviving
	std::sort(team.begin(), team.end(), [](Character* char1, Character* char2)
	{
		return char1->get_character_stats()->get_current_value(health_id) >
			char2->get_character_stats()->get_current_value(health_id);
	});

	bool death_flag = true;
	while (death_flag && team.size() > 0)
	{
		if (team.at(0)->get_character_stats()->get_current_value(health_id) <= 0)
		{
			team.erase(team.begin());
		}
		else
			death_flag = false;
	}

	if (team.size() == 0)
		return true;
	else
		return false;
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