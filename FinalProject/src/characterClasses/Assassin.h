#pragma once
#include "CharacterClass.h"

class Assassin :
	public CharacterClass
{
public:
	Assassin(const int &level);

	~Assassin();

private:
	static const std::string m_class_name;
	static const std::string m_class_description;
	
public:
	const std::string get_class_name() const { return m_class_name; }
};

