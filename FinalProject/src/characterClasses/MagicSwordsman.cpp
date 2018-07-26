#include "MagicSwordsman.h"

const std::string MagicSwordsman::m_class_name = "Magic Swordsman";
const std::string MagicSwordsman::m_class_description = "Magic Swordsman Description Here";
const Class_id MagicSwordsman::m_class_id = magic_swordsman_id;

MagicSwordsman::MagicSwordsman(const int &level)
	: CharacterClass(level)
{

}


MagicSwordsman::~MagicSwordsman()
{
}
