#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>


#include "Character.h"
#include "Custom_Exception.cpp"
#include "Battle.h"
#include "BalancingDefinitions.h"

static int rounds_won = 0;

std::string get_npc_name(const int class_id)
{
	switch (class_id)
	{
	case archer_id:
		return "NPC Archer";
		break;
	case assassin_id:
		return "NPC Assassin";
		break;
	case brawler_id:
		return "NPC Brawler";
		break;
	case guardian_id:
		return "NPC Guardian";
		break;
	case magic_swordsman_id:
		return "NPC Magic-Swordsman";
		break;
	case necromancer_id:
		return "NPC Necromancer";
		break;
	case priest_id:
		return "NPC Priest";
		break;
	case sage_id:
		return "NPC Sage";
		break;
	case scout_id:
		return "NPC Scout";
		break;
	case swordsman_id:
		return "NPC Swordsman";
		break;
	case warrior_id:
		return  "NPC Warrior";
		break;
	case wizard_id:
		return "NPC Wizard";
		break;
	default:
		return "NPC NullClass";
		break;
	}
}

int get_average_level(std::vector<Character*> &team)
{
	float average = 0;
	for (auto&& member : team)
	{
		average += member->get_character_level();
	}
	return (int)floor(average / team.size());
}

std::vector<Character*> generate_NPC_team(const int avg_level)
{
	std::vector<Character*> team_2;
	team_2.reserve(4);

	int npc_class_id_1, npc_class_id_2, npc_class_id_3, npc_class_id_4;
	npc_class_id_1 = Utilities::random_int(1, 12);
	npc_class_id_2 = Utilities::random_int(1, 12);
	npc_class_id_3 = Utilities::random_int(1, 12);
	npc_class_id_4 = Utilities::random_int(1, 12);

	int min_level = avg_level - MAX_LEVEL_DIFFERENCE;
	if (min_level < 1)
		min_level = 1;

	int max_level = avg_level + MAX_LEVEL_DIFFERENCE;
	if (max_level > MAX_LEVEL)
		max_level = MAX_LEVEL;
	if (rounds_won < 2)
	{
		min_level = rounds_won + 1;
		max_level = rounds_won + 2;
	}

	//prevents 2 NPCs from having the same class
	while (npc_class_id_2 == npc_class_id_1)
	{
		npc_class_id_2 = Utilities::random_int(1, 12);
	}
	while (npc_class_id_3 == npc_class_id_2 || npc_class_id_3 == npc_class_id_1)
	{
		npc_class_id_3 = Utilities::random_int(1, 12);
	}
	while (npc_class_id_4 == npc_class_id_1 || npc_class_id_4 == npc_class_id_2 || npc_class_id_4 == npc_class_id_3)
	{
		npc_class_id_4 = Utilities::random_int(1, 12);
	}
	team_2.push_back(Character::make_character(
		true, npc_class_id_1, get_npc_name(npc_class_id_1), Utilities::random_int(min_level, max_level))
	);
	team_2.push_back(Character::make_character(
		true, npc_class_id_2, get_npc_name(npc_class_id_2), Utilities::random_int(min_level, max_level))
	);
	team_2.push_back(Character::make_character(
		true, npc_class_id_3, get_npc_name(npc_class_id_3), Utilities::random_int(min_level, max_level))
	);
	team_2.push_back(Character::make_character(
		true, npc_class_id_4, get_npc_name(npc_class_id_4), Utilities::random_int(min_level, max_level))
	);
	return team_2;
}

void give_exp(std::vector<Character*> team)
{
	for (auto&& member : team)
	{
		double experience =
			pow(1 + rounds_won * XP_ROUNDS_WON_BASE_MULTIPLIER, XP_EXPONENT) *
			Utilities::random_float(XP_RAND_MODIFIER_LOWER_BOUND, XP_RAND_MODIFIER_UPPER_BOUND);
		member->add_experience(experience);
		member->get_character_stats()->reset_current_values(true);
	}
}

int main()
{
	srand(static_cast <unsigned> (time(nullptr)));

	std::cout << "Welcome to the ForeverLost's Balancing Not Required Arena RPG\n\t- This is a typically a 4v4 battle\n\t- NPCs will always have 4 per team, however, the player team could potentially have less.\n\t- The player team persists each round.\n\t- Death is Permanent.\n\t- At the end of each round all stats will be restored.\n\t- You can attack/heal/buff/debuff anyone, although you may not want to heal/buff your enemies.\n\t- You earn experience points at the end of each round.\n\t- EXP earned scales heavily by your current streak of rounds.\n Please follow the below prompts to play...\n" << std::endl;

	std::vector<Character*> team_1, team_2;
	
	/**
	 * Primary start location
	 */
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Player " << i + 1 << " out of 4 creation." << std::endl;
		std::string name;
		Class_id class_id;
		Utilities::get_input("Please enter your name:\t", name);
		std::cout << "Please select your class" << std::endl;
		std::vector<std::string> options = {
			"Archer", "Assassin", "Brawler", "Guardian", "Magic Swordsman", "Necromancer", "Priest", "Sage", "Scout", "Swordsman", "Warrior", "Wizard"
		};
		class_id = static_cast<Class_id>(Utilities::draw_menu(options));
		std::cout << std::endl;
		team_1.push_back(Character::make_character(false, class_id, name, STARTING_LEVEL));
		team_1.back()->print_low_stats();
		team_1.back()->print_high_stats();
	}
	
	bool again = false;
	bool can_continue = true;
	
	do 
	{	
		if (rounds_won > 0)
		{
			give_exp(team_1);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
		Battle battle{ team_1, generate_NPC_team(get_average_level(team_1)) };
		can_continue = battle.main_control();
		if (can_continue)
			rounds_won++;
					
		again = Utilities::get_input("\nYou have won " + std::to_string(rounds_won) +
				" rounds. Would you like to play another round? (y/n)" +
				"\nNote: Your team member's will not be replenished.");

	} while (again);

	for (auto&& memeber : team_1)
	{
		if (memeber != nullptr)
			delete memeber;
	}
	for (auto&& memeber : team_2)
	{
		if (memeber != nullptr)
			delete memeber;
	}
	team_1.clear();
	team_2.clear();
		
	Utilities::draw_message("\tThanks for Playing!");
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return(0);
}


