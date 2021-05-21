#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <Freezable.h>

class Matrix : public freon::Freezable {
public:
	Matrix(unsigned int size);
	void insert(unsigned int row, unsigned int column, const std::string &value);
	void print();
private:
	std::vector<std::vector<std::string>> matrix;
	void freeze_all() override;
	void defrost_all() override;
};