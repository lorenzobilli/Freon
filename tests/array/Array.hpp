#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <Freezable.h>

class Array : public freon::Freezable {
public:
	Array();
	void populate(std::vector<std::string>);
	void print();
private:
	std::vector<std::string> array;
	void freeze_all() override;
	void defrost_all() override;
};