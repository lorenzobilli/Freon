#include <string>

#include "Person.h"

Person::Person() = default;

Person::Person(std::string name, std::string surname)
{
	this->name = std::move(name);
	this->surname = std::move(surname);
}

std::string Person::get_name()
{
	return name;
}

std::string Person::get_surname()
{
	return surname;
}

void Person::freeze_all()
{
	auto name_cube = freon::cubes::primitive<std::string>();
	auto surname_cube = freon::cubes::primitive<std::string>();
	get_freezer().freeze(name_cube, "name", name);
	get_freezer().freeze(surname_cube, "surname", surname);
}

void Person::melt_all() {
	auto name_cube = freon::cubes::primitive<std::string>();
	auto surname_cube = freon::cubes::primitive<std::string>();
	name = get_melter().melt(name_cube, "name");
	surname = get_melter().melt(surname_cube, "surname");
}