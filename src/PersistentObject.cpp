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
 *  src/PersistentObject.cpp
 *
 *  Implementation of all methods of the PersistentObject module.
 */

#include "PersistentObject.h"

void freon::PersistentObject::store(std::string object, std::string id)
{
	this->object = object;
	this->id = id;

	store_all();
	storer.generate_json();

	if (this->prefix != "") {
		filename = this->prefix + "_" + this->object + "_" + this->id + ".json";
	} else {
		filename = this->object + "_" + this->id + ".json";
	}

	std::ofstream writer;
	writer.open(filename);
	writer << storer.retrieve_json();
	writer.close();
}

void freon::PersistentObject::store(std::string prefix, std::string object, std::string id)
{
	this->prefix = prefix;
	store(object, id);
}

void freon::PersistentObject::load(std::string object, std::string id)
{
	this->object = object;
	this->id = id;

	if (this->prefix != "") {
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

	loader.initialize(json);
	load_all();
}

void freon::PersistentObject::load(std::string prefix, std::string object, std::string id)
{
	this->prefix = prefix;
	load(object, id);
}

std::string freon::PersistentObject::get_nested_prefix()
{
	std::string nested_prefix;

	if (prefix != "") {
		nested_prefix = prefix + "_" + object + "_" + id;
	} else {
		nested_prefix = object + "_" + id;
	}

	return nested_prefix;
}