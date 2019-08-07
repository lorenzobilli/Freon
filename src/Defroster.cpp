/*
 *  Project: "Freon" (Codename: "Knight") - Created by Lorenzo Billi, 22nd April 2018
 *
 *
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2018-2019 Lorenzo Billi
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 *  documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 *  right to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of
 *  the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 *  OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 *  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 *  src/Defroster.cpp
 *
 *  Implementation of all methods of the Defroster module.
 */

#include <Defroster.h>


freon::Defroster::Defroster() = default;

freon::Defroster::Defroster(const freon::Defroster &deserialize)
{
}

void freon::Defroster::initialize(std::string json)
{
	this->document.Parse(json.c_str());
}

bool freon::Defroster::add_bool(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	return value.GetBool();
}

int freon::Defroster::add_int(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	return value.GetInt();
}

std::string freon::Defroster::add_string(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	return value.GetString();
}

std::vector<std::string> freon::Defroster::add_arraystring(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	std::vector<std::string> vector;
	for (auto & v : value.GetArray()) {
		vector.push_back(v.GetString());
	}
	return vector;
}

std::vector<std::vector<std::string>> freon::Defroster::add_matrixstring(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	std::vector<std::vector<std::string>> matrix;
	for (auto & array : value.GetArray()) {
		std::vector<std::string> new_row;
		for (auto & v : array.GetArray()) {
			new_row.push_back(v.GetString());
		}
		matrix.push_back(new_row);
	}
	return matrix;
}

std::vector<std::vector<std::vector<std::string>>> freon::Defroster::add_tensorstring(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	std::vector<std::vector<std::vector<std::string>>> tensor;
	for (auto & array : value.GetArray()) {
		std::vector<std::vector<std::string>> new_row;
		for (auto & row : array.GetArray()) {
			std::vector<std::string> new_layer;
			for (auto & layer : row.GetArray()) {
				new_layer.push_back(layer.GetString());
			}
			new_row.push_back(new_layer);
		}
		tensor.push_back(new_row);
	}
	return tensor;
}
