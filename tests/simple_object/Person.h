#pragma once

#include <string>

#include <freon.h>

class Person : public freon::Freezable {
public:
	Person();
	Person(std::string name, std::string surname);
	std::string get_name();
	std::string get_surname();
private:
	std::string name;
	std::string surname;
	void freeze_all() override;
	void defrost_all() override;
};