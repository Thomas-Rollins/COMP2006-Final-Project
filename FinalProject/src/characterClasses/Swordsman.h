#pragma once
#include "c:\Dev\ForeverLost\FinalProject\FinalProject\src\characterClasses\CharacterClass.h"
class Swordsman :
	public CharacterClass
{
public:

	Swordsman(const int &level);

	~Swordsman();

	const std::string get_class_name() const { return m_class_name; }

private:
	static const std::string m_class_name;
	static const std::string m_class_description;
};

