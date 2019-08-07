#include "Array.hpp"

Array::Array() = default;

void Array::populate(std::vector<std::string> elems)
{
	for (const auto& e : elems) {
		this->array.push_back(e);
	}
}

void Array::print()
{
	for (const auto& e : this->array) {
		std::cout << e << " ";
	}
}

void Array::freeze_all()
{
	get_freezer().add("array", freon::Item::Type::ArrayString, array);
}

void Array::defrost_all()
{
	array = get_defroster().add_arraystring("array");
}