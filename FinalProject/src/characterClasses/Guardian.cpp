#include "Guardian.h"
#include "CharacterClass.h"

Guardian::~Guardian()
{

}


Guardian::Guardian(std::string name, Low_Statistics inital_stats)
	: CharacterClass(name, inital_stats)
{

	/*get_low_stats()->agility.set_base_value(inital_stats->agility->m_base_value);
	get_low_stats()->dexterity.set_base_value(inital_stats->base_dexterity);
	get_low_stats()->focus.set_base_value(inital_stats->base_focus);
	get_low_stats()->intelligence.set_base_value(inital_stats->base_intelligence);
	get_low_stats()->luck.set_base_value(inital_stats->base_luck);
	get_low_stats()->strength.set_base_value(inital_stats->base_strength);
	get_low_stats()->technique.set_base_value(inital_stats->base_technique);
	get_low_stats()->vitality.set_base_value(inital_stats->base_vitality);
	get_low_stats()->wisdom.set_base_value(inital_stats->base_wisdom);

	get_low_stats()->agility.set_growth_value(inital_stats->growth_agility);
	get_low_stats()->dexterity.set_growth_value(inital_stats->growth_dexterity);
	get_low_stats()->focus.set_growth_value(inital_stats->growth_focus);
	get_low_stats()->intelligence.set_growth_value(inital_stats->growth_intelligence);
	get_low_stats()->luck.set_growth_value(inital_stats->growth_luck);
	get_low_stats()->strength.set_growth_value(inital_stats->growth_strength);
	get_low_stats()->technique.set_growth_value(inital_stats->growth_technique);
	get_low_stats()->vitality.set_growth_value(inital_stats->growth_vitality);
	get_low_stats()->wisdom.set_growth_value(inital_stats->growth_wisdom);*/


}

