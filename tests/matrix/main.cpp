#include <iostream>
#include <vector>
#include "Matrix.hpp"

int main()
{
	Matrix first(5);
	Matrix second(5);

	first.insert(0, 0, "1");
	first.insert(1, 1, "1");
	first.insert(2, 2, "1");
	first.insert(3, 3, "1");
	first.insert(4, 4, "1");

	std::cout << "First matrix:" << std::endl;
	first.print();
	first.freeze("Matrix", "first");
	second.defrost("Matrix", "first");
	std::cout << "\nSecond matrix:" << std::endl;
	second.print();
}