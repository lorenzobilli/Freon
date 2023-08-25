#include <iostream>
#include <vector>
#include "Array.hpp"

int main()
{
	Array first;
	Array second;
	std::vector<std::string> elems = {"Lorenzo", "Denise", "Ilaria", "Sara"};
	first.populate(elems);
	std::cout << "First array:" << std::endl;
	first.print();
	first.freeze("Array", "first");
	second.melt("Array", "first");
	std::cout << "\nSecond array: " << std::endl;
	second.print();
}