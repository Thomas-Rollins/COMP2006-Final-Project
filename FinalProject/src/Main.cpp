#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>


#include "Character.h"
#include "Custom_Exception.cpp"
#include "Battle.h"


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
		return "NPC Magic_Swordsman";
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

int main()
{
	srand(static_cast <unsigned> (time(nullptr)));
	
	std::vector<Character*> characters;

	//for (int i = 0; i < 256; i++)
	//{
	//	std::cout << "Level " << i << ": ";
	//	std::cout << round((4 * (pow(i + 1, 3))) / 5) << std::endl;
	//}

	/*for (int i = 0; i < 12; i++)
	{
		int rand_class = (int)(Utilities::random_int(1, 12));
		bool rand_type = (bool)(Utilities::random_int(1, 10) % 2);
		Character* new_character = Character::make_character(true, i+1, "Name", 100);

		characters.push_back(new_character);
	}*/

	//for (auto&& character : characters)
	//{
	//	character->print_abiities();
	//}

	std::vector<Character*> team_1, team_2;
	team_1.reserve(4);
	team_2.reserve(4);

	/**
	 * Primary start location
	 */
/*
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Player " << i+1 << " out of 4 creation." << std::endl;
		std::string name;
		Class_id class_id;
		Utilities::get_input("Please enter your name:\t", name);
		std::cout << "Please select your class" << std::endl;
		std::vector<std::string> options = {
			"Archer", "Assassin", "Brawler", "Guardian", "Magic Swordsman", "Necromancer", "Priest", "Sage", "Scout", "Swordsman", "Warrior", "Wizard"
		};
		class_id = static_cast<Class_id>(Utilities::draw_menu(options));
		std::cout << std::endl;
		team_1.push_back(Character::make_character(false, class_id, name, 5));
	}

	int npc_class_id_1, npc_class_id_2, npc_class_id_3, npc_class_id_4;
	npc_class_id_1 = Utilities::random_int(1, 12);
	npc_class_id_2 = Utilities::random_int(1, 12);
	npc_class_id_3 = Utilities::random_int(1, 12);
	npc_class_id_4 = Utilities::random_int(1, 12);

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
	team_2.push_back(Character::make_character(true, npc_class_id_1, get_npc_name(npc_class_id_1), 5));
	team_2.push_back(Character::make_character(true, npc_class_id_2, get_npc_name(npc_class_id_2), 5));
	team_2.push_back(Character::make_character(true, npc_class_id_3, get_npc_name(npc_class_id_3), 5));
	team_2.push_back(Character::make_character(true, npc_class_id_4, get_npc_name(npc_class_id_4), 5));
	
		


	// All npcs
	Character* new_character1 = Character::make_character(true, archer_id, "Player 1", 10);
	Character* new_character2 = Character::make_character(true, warrior_id, "Player 2", 12);
	Character* new_character3 = Character::make_character(true, magic_swordsman_id, "Player 3", 15);
	Character* new_character4 = Character::make_character(true, priest_id, "Player 4", 13);
	team_1.push_back(new_character1);
	team_1.push_back(new_character2);
	team_1.push_back(new_character3);
	team_1.push_back(new_character4);


	// All npcs
	Character* new_character5 = Character::make_character(true, assassin_id, "Player 5", 50);
	Character* new_character6 = Character::make_character(true, guardian_id, "Player 6", 54);
	Character* new_character7 = Character::make_character(true, wizard_id, "Player 7", 56);
	Character* new_character8 = Character::make_character(true, brawler_id, "Player 8", 49);
	team_2.push_back(new_character5);
	team_2.push_back(new_character6);
	team_2.push_back(new_character7);
	team_2.push_back(new_character8);
*/



	Battle battle{ team_1, team_2 };

	for (auto character : characters)
	{
		/*double rand_exp = (double)random_int(1000, 800000000);
		try {
			character->add_experience(rand_exp);
		}
		catch (NotImplemented e) {}		*/
		//
		//std::cout << character->get_character_class()->get_class_name() << std::endl;
		//std::cout << "Level: " << character->get_character_level() << std::endl;
		//std::cout << "Current xp: " << character->get_current_experience() << std::endl;
		//std::cout << "Exp for next Level: " << character->get_next_level_experience() << std::endl;
		//character->print_low_stats();
		//character->print_high_stats();
		////character->print_abiities();

		delete (character);
		/*std::cout << std::endl;*/
	}

	characters.clear();
	std::cin.get();
	return(0);
}


