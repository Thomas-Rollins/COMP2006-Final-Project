#include <iostream>
#include <string>
#include <fstream>


#include "../include/jsoncpp/json/json.h"


#include "Character.h"
#include "logging/Log.h"





int main()
{
	{
	/*{
		Json::Value obj;

		std::ifstream alice("data/alice.json", std::ifstream::binary);
		alice >> obj;
		std::cout << "Book: " << obj["book"].asString() << std::endl;
		std::cout << "Year: " << obj["year"].asUInt() << std::endl;
		const Json::Value& characters = obj["characters"];
		for (unsigned int i = 0; i < characters.size(); i++)
		{
			std::cout << "    name: " << characters[i]["name"].asString();
			std::cout << " chapter: " << characters[i]["chapter"].asUInt();
			std::cout << std::endl;
		}

	}*/

	Low_Stat_Shell vitality{ "Vitality Description Here", "VIT", 65535, -65535 };
	Low_Stat_Shell strength{ "Strength Description Here", "STR", 65535, -65535 };
	Low_Stat_Shell agility{ "Agility Description Here", "AGI", 65535, -65535 };
	Low_Stat_Shell dexterity{ "Dexterity Description Here", "DEX", 65535, -65535 };
	Low_Stat_Shell technique{ "Tech Description Here", "TEC", 65535, -65535 };
	Low_Stat_Shell intelligence{ "Int Description Here", "INT", 65535, -65535 };
	Low_Stat_Shell wisdom{ "Wisdom Description Here", "WIS", 65535, -65535 };
	Low_Stat_Shell focus{ "Focus Description Here", "FCS", 65535, -65535 };
	Low_Stat_Shell luck{ "luck Description Here", "LUC", 65535, -65535 };


	Low_Statistics character_vitality{ &vitality, 0.90f, 9 };
	Low_Statistics character_strength{ &strength, 0.91f, 8 };
	Low_Statistics character_agility{ &agility, 0.92f, 7 };
	Low_Statistics character_dexterity{ &dexterity, 0.93f, 6 };
	Low_Statistics character_technique{ &technique, 0.94f, 5 };
	Low_Statistics character_intelligence{ &intelligence, 0.95f, 4 };
	Low_Statistics character_wisdom{ &wisdom, 0.96f, 3 };
	Low_Statistics character_focus{ &focus, 0.97f, 2 };
	Low_Statistics character_luck{ &luck, 0.98f, 1 };

	Low_Statistics* stats_ary[9]{ &character_vitality, &character_strength, &character_agility,
	&character_dexterity, &character_technique, &character_intelligence, &character_wisdom,
	&character_luck };

	Low_Level_Stats character_stats{ character_vitality, character_strength, character_agility, character_dexterity, character_technique, character_intelligence, character_wisdom, character_focus, character_luck };


	Character newCharacter{ "Thomas", 5, character_stats };

	for (int i = 0; i < 8; i++)
	{
		Log("******************************");
		Log(stats_ary[i]->statistic->DESCRIPTION);
		Log(stats_ary[i]->statistic->ALIAS);
		Log(stats_ary[i]->statistic->MAX_VALUE);
		Log(stats_ary[i]->statistic->MIN_VALUE);
		Log(stats_ary[i]->growth_value);
		Log(stats_ary[i]->value);
		Log("******************************");
		Log("");
	}

	Log(newCharacter.get_base_agility());
	Log(newCharacter.get_current_experience());
	Log(newCharacter.get_character_name());
	Log(newCharacter.get_character_class_string());

}

	std::cout << "Press Enter to Exit." << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return(0);
}