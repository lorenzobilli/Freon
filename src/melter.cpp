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
 *  src/melter.cpp
 *
 *  Implementation of all methods of the melter module.
 */

#include <melter.hpp>


freon::melter::melter() = default;

freon::melter::melter(const freon::melter &deserialize)
{
}

void freon::melter::initialize(const std::string& json)
{
	this->document.Parse(json.c_str());
}

void freon::melter::from_json(const std::string &json)
{
	this->document.Parse(json.c_str());
}

bool freon::melter::get_boolean(const std::string& identifier)
{
	auto &value = this->document[identifier.c_str()];
	return value.GetBool();
}

int freon::melter::get_integer(const std::string& identifier)
{
	auto &value = this->document[identifier.c_str()];
	return value.GetInt();
}

long freon::melter::get_long_integer(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	return value.GetInt64();
}

unsigned int freon::melter::get_unsigned_integer(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	return value.GetUint();
}

unsigned long freon::melter::get_unsigned_long_integer(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	return value.GetUint64();
}

double freon::melter::get_double(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	return value.GetDouble();
}

std::string freon::melter::get_string(const std::string& identifier)
{
	auto &value = this->document[identifier.c_str()];
	return value.GetString();
}

std::vector<bool> freon::melter::get_array_boolean(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	std::vector<bool> vector;
	for (auto & v : value.GetArray()) {
		vector.emplace_back(v.GetBool());
	}
	return vector;
}

std::vector<int> freon::melter::get_array_integer(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	std::vector<int> vector;
	for (auto & v : value.GetArray()) {
		vector.emplace_back(v.GetInt());
	}
	return vector;
}

std::vector<long> freon::melter::get_array_long_integer(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	std::vector<long> vector;
	for (auto & v : value.GetArray()) {
		vector.emplace_back(v.GetInt64());
	}
	return vector;
}

std::vector<unsigned int> freon::melter::get_array_unsigned_integer(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	std::vector<unsigned int> vector;
	for (auto & v : value.GetArray()) {
		vector.emplace_back(v.GetUint());
	}
	return vector;
}

std::vector<unsigned long> freon::melter::get_array_unsigned_long_integer(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	std::vector<unsigned long> vector;
	for (auto & v : value.GetArray()) {
		vector.emplace_back(v.GetUint64());
	}
	return vector;
}

std::vector<double> freon::melter::get_array_double(const std::string &identifier)
{
	auto &value = this->document[identifier.c_str()];
	std::vector<double> vector;
	for (auto & v : value.GetArray()) {
		vector.emplace_back(v.GetDouble());
	}
	return vector;
}

std::vector<std::string> freon::melter::get_array_string(const std::string& identifier)
{
	auto &value = this->document[identifier.c_str()];
	std::vector<std::string> vector;
	for (auto & v : value.GetArray()) {
		vector.emplace_back(v.GetString());
	}
	return vector;
}
