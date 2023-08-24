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
 *  src/Freezable.cpp
 *
 *  Implementation of all methods of the Freezable module.
 */

#include "Freezable.h"

#include <utility>

void freon::Freezable::freeze(std::string object, std::string id)
{
	this->object = std::move(object);
	this->id = std::move(id);

	freeze_all();

	if (!this->prefix.empty()) {
		filename = this->prefix + "_" + this->object + "_" + this->id + ".json";
	} else {
		filename = this->object + "_" + this->id + ".json";
	}

	std::ofstream writer;
	writer.open(filename);
	writer << freezer.to_json();
	writer.close();
}

void freon::Freezable::freeze(std::string prefix, std::string object, std::string id)
{
	this->prefix = prefix;
	freeze(std::move(object), std::move(id));
}

void freon::Freezable::defrost(std::string object, std::string id)
{
	this->object = object;
	this->id = id;

	if (!this->prefix.empty()) {
		filename = this->prefix + "_" + this->object + "_" + this->id + ".json";
	} else {
		filename = this->object + "_" + this->id + ".json";
	}

	std::ifstream reader(filename);
	std::string line;
	std::string json;
	if (reader.is_open()) {
		while (getline(reader, line)) {
			json.append(line);
		}
		reader.close();
	}

	defroster.initialize(json);
	defrost_all();
}

void freon::Freezable::defrost(std::string prefix, std::string object, std::string id)
{
	this->prefix = prefix;
	defrost(std::move(object), std::move(id));
}

std::string freon::Freezable::get_nested_prefix()
{
	std::string nested_prefix;

	if (!prefix.empty()) {
		nested_prefix = prefix + "_" + object + "_" + id;
	} else {
		nested_prefix = object + "_" + id;
	}

	return nested_prefix;
}