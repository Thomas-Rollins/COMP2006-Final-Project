#include <iostream>
#include <fstream>
#include <string>

//DEBUG LOGGING
#include "logging/Log.h"

#include "../include/jsoncpp/json/json.h"

#include "statistics/Vitality.h"
#include "characterClasses/CharacterClass.h"
#include "characterClasses/Guardian.h"



class_temp_template read_classJSON()
{
	class_temp_template class_template;



	Json::Value obj;

	std::ifstream guardian("data/classes/Guardian.json", std::ifstream::binary);
	guardian >> obj;
	std::cout << "Class: " << obj["name"].asString() << std::endl;

	const Json::Value& base_stats = obj["stats"];
	
	class_template.base_agility = int(base_stats[0]["base"].asUInt());
	class_template.base_dexterity = int(base_stats[1]["base"].asUInt());
	class_template.base_focus = int(base_stats[2]["base"].asUInt());
	class_template.base_intelligence = int(base_stats[3]["base"].asUInt());
	class_template.base_luck = int(base_stats[4]["base"].asUInt());
	class_template.base_strength = int(base_stats[5]["base"].asUInt());
	class_template.base_technique = int(base_stats[6]["base"].asUInt());
	class_template.base_vitality = int(base_stats[7]["base"].asUInt());
	class_template.base_wisdom = int(base_stats[8]["base"].asUInt());

	class_template.growth_agility = (base_stats[0]["growth_rate"].asFloat());
	class_template.growth_dexterity = (base_stats[1]["growth_rate"].asFloat());
	class_template.growth_focus = (base_stats[2]["growth_rate"].asFloat());
	class_template.growth_intelligence = (base_stats[3]["growth_rate"].asFloat());
	class_template.growth_luck = (base_stats[4]["growth_rate"].asFloat());
	class_template.growth_strength =(base_stats[5]["growth_rate"].asFloat());
	class_template.growth_technique = (base_stats[6]["growth_rate"].asFloat());
	class_template.growth_vitality = (base_stats[7]["growth_rate"].asFloat());
	class_template.growth_wisdom = (base_stats[8]["growth_rate"].asFloat());



	for (unsigned int i = 0; i < base_stats.size(); i++)
	{
		std::cout << "\tname: " << base_stats[i]["name"].asString() << std::endl;
		std::cout << "\tbase value: " << base_stats[i]["base"].asUInt() << std::endl;
		std::cout << "\tgrowth value: " << base_stats[i]["growth_rate"].asFloat() << std::endl;
		std::cout << std::endl;
	}

	return class_template;
}

Low_Statistics init_statistics(class_temp_template* class_template)
{
	Low_Statistics low_statistics
	{
		Agility{ class_template->base_agility, class_template->base_agility, class_template->growth_agility },
		Dexterity{class_template->base_dexterity, class_template->base_dexterity, class_template->growth_dexterity },
		Focus{ class_template->base_focus, class_template->base_focus, class_template->growth_focus },
		Intelligence{ class_template->base_intelligence, class_template->base_intelligence, class_template->growth_intelligence },
		Luck{ class_template->base_luck, class_template->base_luck, class_template->growth_luck },
		Strength{ class_template->base_strength, class_template->base_strength , class_template->growth_strength },
		Technique{ class_template->base_technique, class_template->base_technique, class_template->growth_technique },
		Vitality{ class_template->base_vitality, class_template->base_vitality, class_template->growth_vitality },
		Wisdom{ class_template->base_wisdom, class_template->base_wisdom, class_template->growth_wisdom },
	};
	return low_statistics;
}


int main()
{
	{
		Guardian* new_guardian = new Guardian{ "Player 1", init_statistics(&read_classJSON()) };

		Log(new_guardian->get_low_stats().agility.get_current_value());

		delete new_guardian;
	}
	
	std::cout << "Press Enter to Exit." << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return(0);
}