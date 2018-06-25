#include <iostream>

int main()
{


	std::cout << "Press Enter to Exit." << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return(0);
}