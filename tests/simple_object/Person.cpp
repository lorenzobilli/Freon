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
	get_freezer().add(name_cube, "name", name);
	get_freezer().add(surname_cube, "surname", surname);
}

void Person::defrost_all()
{
	auto name_cube = freon::cubes::primitive<std::string>();
	auto surname_cube = freon::cubes::primitive<std::string>();
	name = get_defroster().get(name_cube, "name");
	surname = get_defroster().get(surname_cube, "surname");
}