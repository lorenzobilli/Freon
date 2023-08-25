#include <iostream>

#include "Person.h"

int main()
{
	Person p1("Taka", "Mohatuson");
	std::cout << "Declared person \"p1\": " << p1.get_name() << " " << p1.get_surname() << std::endl;
	p1.freeze("Person", "p1");

	Person p2;
	p2.melt("Person", "p1");
	std::cout << "Reloaded person \"p2\": " << p2.get_name() << " " << p2.get_surname() << std::endl;

	return 0;
}