#pragma once
#include "CharacterClass.h"

class Archer :
	public CharacterClass
{
public:
	//Constructors
	Archer(const int &level);
	
	//Destructors
	~Archer();

	const std::string get_class_name() const { return m_class_name; }

private:
	static const std::string m_class_name;
	static const std::string m_class_description;

};

