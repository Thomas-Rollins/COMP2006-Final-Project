#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <random>

#include "Battle.h"
#include "NPC.h"
#include "PlayableCharacter.h"
#include "Custom_Exception.cpp"


Battle::Battle(std::vector<Character*> team_1, std::vector<Character*> team_2)
	: m_team_1(team_1), m_team_2(team_2)
{
	main_control();
}

Battle::~Battle()
{
	// since team_1, team_2, and m_turn_order share pointers they can all be deleted at once.
	for (auto&& character : m_turn_order)
	{
		if(character)
			delete(character);
	}
	m_turn_order.clear();
	m_team_1.clear();
	m_team_2.clear();
}

void Battle::main_control()
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
	m_turn_order.reserve(m_team_1.size() + m_team_2.size());
	m_turn_order.insert(m_turn_order.end(), m_team_1.begin(), m_team_1.end());
	m_turn_order.insert(m_turn_order.end(), m_team_2.begin(), m_team_2.end());

	update_turn_order();

	/**
	* the characters in m_team_x and m_turn_order share the same pointer and therefore it is
	* possible to use pointer comparison to link the two when handling actions
	*/
	do
	{
		action();
			
		execute_action(m_turn_order.at(0)->get_action(m_friendly_target), get_target());
		/*std::cout << "Team one consists of:" << std::endl;
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

		std::cout << std::endl;*/
	} while (!check_battle_over());
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
	// adds the available targets to the options vector
	for (auto&& character : m_team_2)
	{
		std::string option = character->get_name() + "\tHP: ";
		option.append(std::to_string( (int) character->get_character_stats()->get_current_value(health_id))
			+ "/" + std::to_string( (int) character->get_character_stats()->get_base_value(health_id)));

		option.append("\tMP: ");
		option.append(std::to_string((int)character->get_character_stats()->get_current_value(mana_id))
			+ "/" + std::to_string((int)character->get_character_stats()->get_base_value(mana_id)));

		option.append("\tSP: ");
		option.append(std::to_string((int)character->get_character_stats()->get_current_value(skill_points_id))
			+ "/" + std::to_string((int)character->get_character_stats()->get_base_value(skill_points_id)));

		options.push_back(option);
	}
	for (auto&& character : m_team_1)
	{
		std::string option = character->get_name() + "\tHP: ";
		option.append(std::to_string( (int) character->get_character_stats()->get_current_value(health_id))
			+ "/" + std::to_string( (int) character->get_character_stats()->get_base_value(health_id)));

		option.append("\tMP: ");
		option.append(std::to_string((int)character->get_character_stats()->get_current_value(mana_id))
			+ "/" + std::to_string((int)character->get_character_stats()->get_base_value(mana_id)));

		option.append("\tSP: ");
		option.append(std::to_string((int)character->get_character_stats()->get_current_value(skill_points_id))
			+ "/" + std::to_string((int)character->get_character_stats()->get_base_value(skill_points_id)));

		options.push_back(option);
	}

	std::cout << m_turn_order.at(0)->get_name() << " who would you like to target?" << std::endl;

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

Character* Battle::get_target(std::vector<Character*> team, std::vector<Character*> original_targets)
{
	std::vector<std::string> options;
	for (Character* target : original_targets)
	{
		int index = NULL_INDEX;
		try
		{
			index = find_vector_index(team, target);
			if (index != NULL_INDEX)
			{
				move_item_to_back(team, index);
				team.pop_back();
			}
		}
		catch (MemberDoesNotExist* e)
		{
			std::cerr << e->what();
		}	
	}
	if (!team.empty())
	{
		// adds the available targets to the options vector
		for (auto&& character : team)
		{
			std::string option = character->get_name() + "\tHP: ";
			option.append(std::to_string((int)character->get_character_stats()->get_current_value(health_id))
				+ "/" + std::to_string((int)character->get_character_stats()->get_base_value(health_id)));

			option.append("\tMP: ");
			option.append(std::to_string((int)character->get_character_stats()->get_current_value(mana_id))
				+ "/" + std::to_string((int)character->get_character_stats()->get_base_value(mana_id)));

			option.append("\tSP: ");
			option.append(std::to_string((int)character->get_character_stats()->get_current_value(skill_points_id))
				+ "/" + std::to_string((int)character->get_character_stats()->get_base_value(skill_points_id)));

			options.push_back(option);
		}

		std::cout << m_turn_order.at(0)->get_name() << " who else would you like to target?" << std::endl;

		int choice = Utilities::draw_menu(options);
		return team.at(choice - 1);
	}
	else
		return nullptr;
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

	

	//moves the player to the end of the turn order vector after their action.
	move_item_to_back(m_turn_order, 0);
}

void Battle::execute_action(const Ability* ability, Character* oringinal_target)
{
	Character* actor = m_turn_order.at(0);
	const bool friendly = ability->isFriendly();
	int num_of_targets = ability->get_num_of_targets();
	int sp_gen = 5;
	float damage;

	float actor_atk = actor->get_character_stats()->get_current_value(atk_id);
	float actor_magic = actor->get_character_stats()->get_current_value(magic_id);
	float power = actor_atk * ability->get_physical_damage() + (actor_magic * ability->get_magic_damage());
	
	std::vector<Character*> targets;
	if (num_of_targets == 1)
	{
		targets.push_back(oringinal_target);
		num_of_targets = 0;
	}
	// adds more targets to the vector while the number of targets hasn't been met.
	while (num_of_targets > 1)
	{
		int index = NULL_INDEX;
		try {
			 index = find_vector_index(m_team_1, oringinal_target);
			 if (index != NULL_INDEX)
			 {
				 if (num_of_targets >= m_team_1.size())
				 {
					 targets = m_team_1;
					 num_of_targets = 0;
				 }
				 else
				 {
					 targets.push_back(get_target(m_team_1, targets));
					 num_of_targets--;
				 }
			 }
			 else
			 {
				 index = find_vector_index(m_team_2, oringinal_target);
				 if (index != NULL_INDEX)
				 {
					 if (num_of_targets >= m_team_1.size())
					 {
						 targets = m_team_2;
						 num_of_targets = 0;
					 }
					 else
					 {
						 targets.push_back(get_target(m_team_2, targets));
						 num_of_targets--;
					 }
				 }
				 break;
			 }		
		}
		catch (MemberDoesNotExist* e) 
		{
			std::cerr << e->what();
		}
	}

	for (Character* target : targets)
	{
		float phys_resistance = target->get_character_stats()->get_current_value(def_id);
		float mgk_resistance = target->get_character_stats()->get_current_value(mind_id);

		if (friendly)
		{
			damage = ((actor_magic * MGK_HEAL_RATIO) + (actor->get_character_stats()->
				get_current_value(mind_id)) * MIND_HEAL_RATIO) * ability->get_magic_damage()
				* get_elemental_dmg_modifer(ability, target);

			*target + damage;

			std::string message = actor->get_name() + " used " + ability->get_name() + " on " +
				target->get_name() + " and healed " + std::to_string((int)damage) + " health.";

			m_message_queue.push_back(message);

			apply_buffs_debuffs(target, ability, true);
		}
		else
		{
			damage = (
				((
				((BASE_LEVEL_MULTIPLIER * actor->get_character_level() / DMG_LEVEL_DIVISOR) + DMG_LEVEL_INCREMENT) *
					(power * actor_atk / phys_resistance)
					) / DMG_DIVISOR)
				+ DMG_INCREMENT) * get_modifiers(ability) * get_elemental_dmg_modifer(ability, target);

			*target - damage;

			std::string message = actor->get_name() + " used " + ability->get_name() + " on " +
				target->get_name() + " and dealt " + std::to_string((int)damage) + " damage.";
			m_message_queue.push_back(message);
			/*std::cout << actor->get_name() << " used " << ability->get_name() << " on " <<
			target->get_name() << " and dealt " << (int)damage << " damage." << std::endl;*/

			apply_buffs_debuffs(target, ability, false);
		}

		//sp generation
		float percent_difference = abs(target->get_character_stats()->get_base_value(health_id) - damage)
			/ abs(target->get_character_stats()->get_base_value(health_id));
		sp_gen += (int)(percent_difference * SP_DIFFERENCE_MULTIPLIER);
		/*std::cout << "SP Gen: " << sp_gen << std::endl;*/

		actor->get_character_stats()->set_current_value(mana_id,
			actor->get_character_stats()->get_current_value(mana_id) - ability->get_mp_cost()
		);
		actor->get_character_stats()->set_current_value(skill_points_id,
			actor->get_character_stats()->get_current_value(skill_points_id) - ability->get_sp_cost() + sp_gen
		);
		target->get_character_stats()->set_current_value(skill_points_id,
			target->get_character_stats()->get_current_value(skill_points_id) + floor(sp_gen * TARGET_SP_GEN_RATIO)
		); 
	}
}

void Battle::apply_buffs_debuffs(Character* target, const Ability* ability, bool friendly)
{
	bool buffs_applied = false;
	int buff = -1;
	int buff_amount;
	std::string message;
	std::string message_verb = "lost ";
	if (friendly)
	{
		buff = 1;
		message_verb = "gained ";
	}
		
	if (ability->get_agility_bonus() > 0.0)
	{
		buff_amount = (int)floor((float)target->get_character_stats()->get_base_value(agility_id)
			* ability->get_agility_bonus()) * buff;
		target->get_character_stats()->set_current_value(agility_id, buff_amount);

		 message = target->get_name() + " has " + message_verb + " " 
			+ std::to_string(abs(buff_amount)) + " agility.";
		 m_message_queue.push_back(message);
		buffs_applied = true;
	}
	if (ability->get_attack_bonus() > 0.0)
	{
		buff_amount = (int)floor((float)target->get_character_stats()->get_base_value(strength_id)
			* ability->get_attack_bonus()) * buff;
		target->get_character_stats()->set_current_value(strength_id, buff_amount);

		message = target->get_name() + " has " + message_verb + " "
			+ std::to_string(abs(buff_amount)) + " strength.";
		m_message_queue.push_back(message);
		buffs_applied = true;
	}
	if (ability->get_magic_bonus() > 0.0)
	{
		buff_amount = (int)floor((float)target->get_character_stats()->get_base_value(intelligence_id)
			* ability->get_magic_bonus()) * buff;
		target->get_character_stats()->set_current_value(intelligence_id, buff_amount);

		message = target->get_name() + " has " + message_verb + " "
			+ std::to_string(abs(buff_amount)) + " intelligence.";
		m_message_queue.push_back(message);
		buffs_applied = true;
	}
	if (ability->get_defense_bonus() > 0.0)
	{
		buff_amount = (int)floor((float)target->get_character_stats()->get_base_value(vitality_id)
			* ability->get_defense_bonus()) * buff;
		target->get_character_stats()->set_current_value(vitality_id, buff_amount);

		message = target->get_name() + " has " + message_verb + " "
			+ std::to_string(abs(buff_amount)) + " vitality.";
		m_message_queue.push_back(message);
		buffs_applied = true;
	}
	if (ability->get_mind_bonus() > 0.0)
	{
		buff_amount = (int)floor((float)target->get_character_stats()->get_base_value(wisdom_id)
			* ability->get_mind_bonus()) * buff;
		target->get_character_stats()->set_current_value(wisdom_id,  buff_amount);

		message = target->get_name() + " has " + message_verb + " "
			+ std::to_string(abs(buff_amount)) + " wisdom.";
		m_message_queue.push_back(message);
		buffs_applied = true;
	}

	if (ability->isRestore())
	{
		message = target->get_name() + " has had all buffs and debuffs removed.\n";
		m_message_queue.push_back(message);
		buffs_applied = true;
	}

	// finds the index of the target and moves them to the back of the turn_order.
	if (ability->isStun())
	{
		int index = find_vector_index(m_turn_order, target);
		if (index == NULL_INDEX)
		{
			std::cerr << "Could not find " + target->get_name() << std::endl;
		}
		move_item_to_back(m_turn_order, index);
		m_message_queue.push_back(target->get_name() + " was stunned!\n");
		/*std::vector<Character*>::iterator it = std::find(m_turn_order.begin(), m_turn_order.end(), target);

		if (it != m_turn_order.end())
		{
			int index = std::distance(m_turn_order.begin(), it);
			move_item_to_back(m_turn_order, index);
			m_message_queue.push_back(target->get_name() + " was stunned!\n");
		}*/
	}

	if (buffs_applied)
	{
		// gets the missing health/MP before a stat update to maintain it.
		float missing_health = (target->get_character_stats()->get_base_value(health_id)
			- target->get_character_stats()->get_current_value(health_id));

		float missing_mp = (target->get_character_stats()->get_base_value(mana_id)
			- target->get_character_stats()->get_current_value(mana_id));

		float current_sp = (target->get_character_stats()->get_current_value(skill_points_id)
			- target->get_character_stats()->get_base_value(skill_points_id));
		// removes all debuffs/buffs
		if(ability->isRestore())
			target->get_character_stats()->reset_current_values(false);

		// updates high_stats
		target->get_character_stats()->set_high_stats();
		// removes the missing health/mp
		*target - missing_health;
		target->get_character_stats()->set_current_value(mana_id,
			target->get_character_stats()->get_current_value(mana_id) - missing_mp);
		// adds the original sp back
		target->get_character_stats()->set_current_value(skill_points_id,
			target->get_character_stats()->get_current_value(skill_points_id) + current_sp);
	}
}

float Battle::get_modifiers(const Ability* ability)
{
	Character* actor = m_turn_order.at(0);
	float modifiers = 0;
	float target_mod;
	float crit_mod;
	bool crit = isCritAttack();

	if (ability->get_num_of_targets() > 1)
		target_mod = MULTI_TARGET_MOD;
	else
		target_mod = SINGLE_TARGET_MOD;

	if (crit)
		crit_mod = CRIT_MOD;
	else
		crit_mod = NON_CRIT_MOD;
	
	float rand_modifier = Utilities::random_float(RAND_MOD_LOWER_BOUND, RAND_MOD_UPPER_BOUND);
	
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
	float elemental_mod = ELEMENTAL_BASE_MOD;
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
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[water_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[earth_id]);
		elemental_mod += (ELEMENTAL_NEUTRAL_MOD * (actor_ele_afin - target_ele_afin[fire_id]));
		elemental_mod -= (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[wind_id]);
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[dark_id]);
		break;
	case 1:
		actor_ele_afin = actor->get_character_stats()->get_current_value(wind_id);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[fire_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[water_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[dark_id]);
		elemental_mod += (ELEMENTAL_NEUTRAL_MOD * (actor_ele_afin - target_ele_afin[wind_id]));
		elemental_mod -= (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[earth_id]);
		break;
	case 2:
		actor_ele_afin = actor->get_character_stats()->get_current_value(earth_id);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[wind_id]);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[lightning_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[fire_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[holy_id]);
		elemental_mod += (ELEMENTAL_NEUTRAL_MOD * (actor_ele_afin - target_ele_afin[earth_id]));
		elemental_mod -= (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[water_id]);
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[dark_id]);
		break;
	case 3:
		actor_ele_afin = actor->get_character_stats()->get_current_value(water_id);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD	* target_ele_afin[earth_id]);
		elemental_mod += (ELEMENTAL_NEUTRAL_MOD			* (actor_ele_afin - target_ele_afin[water_id]));
		elemental_mod -= (ELEMENTAL_DISADVANTAGE_MOD	* target_ele_afin[fire_id]);
		elemental_mod -= (ELEMENTAL_DISADVANTAGE_MOD	* target_ele_afin[lightning_id]);
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD		* target_ele_afin[wind_id]);
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD		* target_ele_afin[holy_id]);
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD		* target_ele_afin[dark_id]);
		break;
	case 4:
		actor_ele_afin = actor->get_character_stats()->get_current_value(lightning_id);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[water_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[dark_id]);
		elemental_mod += (ELEMENTAL_NEUTRAL_MOD * (actor_ele_afin - target_ele_afin[lightning_id]));
		elemental_mod -= (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[earth_id]);
		break;
	case 5:
		actor_ele_afin = actor->get_character_stats()->get_current_value(holy_id);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[dark_id]);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[holy_id]);
		elemental_mod += (ELEMENTAL_NEUTRAL_MOD * (actor_ele_afin - target_ele_afin[holy_id]));
		break;
	case 6:
		actor_ele_afin = actor->get_character_stats()->get_current_value(dark_id);
		elemental_mod += (ELEMENTAL_DISADVANTAGE_MOD * target_ele_afin[holy_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[water_id]);
		elemental_mod += (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[earth_id]);
		elemental_mod += (ELEMENTAL_NEUTRAL_MOD * (actor_ele_afin - target_ele_afin[dark_id]));
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[fire_id]);
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[wind_id]);
		elemental_mod -= (ELEMENTAL_WEAKNESS_MOD * target_ele_afin[lightning_id]);
		break;
	case 7:
	default:
		actor_ele_afin = actor->get_character_stats()->get_current_value(void_id);
		elemental_mod += ELEMENTAL_NEUTRAL_MOD * (actor_ele_afin - target_ele_afin[void_id]);
		break;
	}
	std::cout << "Elemental Mod: " << elemental_mod << std::endl;
	return elemental_mod;
}

bool Battle::isCritAttack()
{
	float chance = abs((CRIT_CHANCE_UPPER_BOUND - m_turn_order.at(0)->get_character_stats()
		->get_current_value(critical_id)) - CRIT_CHANCE_UPPER_BOUND) / CRIT_CHANCE_DIVISOR;
	/*std::cout << "CRT value: " << m_turn_order.at(0)->get_character_stats()->get_current_value(critical_id) << std::endl;
	std::cout << "crit chance: " << chance  << "%" << std::endl;*/
	bool crit = Utilities::random_float(CRIT_CHANCE_RAND_MOD_LOWER_BOUND, CRIT_CHANCE_RAND_MOD_UPPER_BOUND) < chance;
	if (crit)
		m_message_queue.push_back("Critical strike! ");
	return crit;
}


/**
 * This method completely removes the dead making reviving not possible.
 * Not to be used with team_dead(std::vector<Character*> &team)
 */
void Battle::remove_dead(std::vector<Character*> &team, bool broadcast)
{
	// iterates through the vector and find if a a character has <= 0 Health
	std::vector<Character*>::iterator it = std::find_if(team.begin(), team.end(),
		[](Character* charater) {
		if (charater->get_character_stats()->get_current_value(health_id) <= 0)
			return true;
		return false;
	});
	// if a character has zero health this iterates over the vector once more to find the index of the character
	if (it != team.end())
	{
		int index = find_vector_index(team, *it);
		if (index == NULL_INDEX)
			throw (MemberDoesNotExist());
		else
		{
			move_item_to_back(team, index);
			if (broadcast)  //broadcasts death if true
				m_message_queue.push_back(team.back()->get_name() + " has died and permanently left the team."); 
			team.pop_back();
		}
	}
}

bool Battle::team_dead(std::vector<Character*> &team)
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

/**
 * removes dead characters and prints message queue before checking if the battle is over.
 */
bool Battle::check_battle_over()
{
	for (int i = 0; i < 4; i++)
	{
		remove_dead(m_team_1, true);
		remove_dead(m_team_2, true);
	}
	for (int i = 0; i < 7; i++)
		remove_dead(m_turn_order, false);

	print_messages();
	m_message_queue.clear();

	if (m_team_1.size() == 0)
	{
		std::cout << std::endl << std::endl << std::endl << "Your entire party has died...." << std::endl <<
			"\tGame Over." << std::endl;
		return true;
	}
	if (m_team_2.size() == 0)
	{
		std::cout << std::endl << std::endl << std::endl << "Congratulations! You have won the match." << std::endl;
		return true;
	}
	return false;
}

/**
 * returns the index of the element passed
 */
template <typename T>
int Battle::find_vector_index(std::vector<T> &vector, T element)
{
	typename std::vector<T>::iterator it = std::find(vector.begin(), vector.end(), element);

	if (it != vector.end())
	{
		return std::distance(vector.begin(), it);
	}
	else
		return NULL_INDEX;
}

/**
 * /throws the item to the back of the vector without any vector re-allocation taking place
 */
template <typename T>
void Battle::move_item_to_back(std::vector<T> &vector, size_t index)
{
	auto it = vector.begin() + index;
	std::rotate(it, it + 1, vector.end());
}

/**
 * Displays the agility and current turn order 
 * #TODO: update print-out to make it display better
 */
void Battle::print_turn_order()
{
	for(auto&& character : get_turn_order() )
	{
		std::cout << character->get_character_stats()->get_current_value(agility_id) << "\t" <<
			character->get_name() << std::endl;
	}
	std::cout << std::endl;
}

void Battle::print_messages()
{
	for (auto&& message : m_message_queue)
	{
		std::cout << message << "...";
		std::cin.get();
	}
}