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
	get_freezer().add("name", freon::Item::Type::String, name);
	get_freezer().add("surname", freon::Item::Type::String, surname);
}

void Person::defrost_all()
{
	name = get_defroster().add_string("name");
	surname = get_defroster().add_string("surname");
}