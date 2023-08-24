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
	get_freezer().add<std::string>(name_cube, "name", name);
	get_freezer().add<std::string>(surname_cube, "surname", surname);
}

void Person::defrost_all()
{
	name = get_defroster().get_string("name");
	surname = get_defroster().get_string("surname");
}