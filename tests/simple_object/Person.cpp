#include <utility>

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

void Person::store_all()
{
	get_storer().add("name", Persistence::Serialize::Field::Type::String, name);
	get_storer().add("surname", Persistence::Serialize::Field::Type::String, surname);
}

void Person::load_all()
{
	name = get_loader().load_string("name");
	surname = get_loader().load_string("surname");
}