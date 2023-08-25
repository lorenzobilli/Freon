#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <liquid.h>

class Array : public freon::liquid {
public:
	Array();
	void populate(const std::vector<std::string>&);
	void print();
private:
	std::vector<std::string> array;
	void freeze_all() override;
	void melt_all() override;
};