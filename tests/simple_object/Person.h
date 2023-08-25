#pragma once

#include <string>

#include <freon.h>
#include <cubes/primitive.hpp>

class Person : public freon::liquid {
public:
	Person();
	Person(std::string name, std::string surname);
	std::string get_name();
	std::string get_surname();
private:
	std::string name;
	std::string surname;
	void freeze_all() override;
	void melt_all() override;
};