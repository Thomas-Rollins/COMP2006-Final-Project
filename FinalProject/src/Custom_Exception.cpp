#include <iostream>

class NotImplemented : public std::logic_error
{
public:
	NotImplemented() : std::logic_error("Function not yet implemented") { };
};

class MemberDoesNotExist : public std::logic_error
{
public:
	MemberDoesNotExist() : std::logic_error("Member does not exist in vector.") { };
};