#include "Matrix.hpp"

Matrix::Matrix(unsigned int size)
{
	for (auto i = 0; i < size; i++) {
		std::vector<std::string> row;
		for (auto j = 0; j < size; j++) {
			row.emplace_back("");
		}
		this->matrix.emplace_back(row);
	}
}

void Matrix::insert(unsigned int row, unsigned int column, const std::string &value)
{
	matrix.at(row).at(column) = value;
}

void Matrix::print()
{
	for (auto i = 0; i < matrix.size(); i++) {
		for (auto j = 0; j < matrix.size(); j++) {
			std::cout << matrix.at(i).at(j).c_str();
		}
		std::cout << std::endl;
	}
}

void Matrix::freeze_all()
{
	get_freezer().add("matrix", freon::Item::Type::MatrixString, matrix);
}

void Matrix::defrost_all()
{
	matrix = get_defroster().add_matrixstring("matrix");
}