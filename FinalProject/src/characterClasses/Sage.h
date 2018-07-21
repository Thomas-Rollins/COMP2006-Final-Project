#pragma once
#include "c:\Dev\ForeverLost\FinalProject\FinalProject\src\characterClasses\CharacterClass.h"
class Sage :
	public CharacterClass
{
public:
	
	Sage(const int &level);

	~Sage();

	const std::string get_class_name() const { return m_class_name; }

private:
	static const std::string m_class_name;
	static const std::string m_class_description;
};

