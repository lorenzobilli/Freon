#pragma once

#include <string>

#include <Freezable.h>

class Person : public freon::Freezable {
public:
	Person();
	Person(std::string name, std::string surname);
	std::string get_name();
	std::string get_surname();
private:
	std::string name;
	std::string surname;
	void store_all() override;
	void load_all() override;
};