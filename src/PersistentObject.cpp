/*
 *  Project: "Vagli" - Created by Lorenzo Billi, 22nd April 2018
 *
 *
 *  Copyright (c) 2018 Lorenzo Billi - All rights reserved
 *
 *  THIS FILE IS PART OF THE "VAGLI" CODEBASE. YOU MAY NOT, UNDER ANY CIRCUMSTANCE, DEAL WITH THIS
 *  FILE AND/OR THE "VAGLI" CODEBASE, INCLUDING BUT NOT LIMITED TO: USE, COPY, MODIFY, MERGE,
 *  PUBLISH, DISTRIBUTE, AND/OR SUBLICENSE IT.
 *
 *
 *  Persistence/PersistentObject.cpp
 *
 *  Implementation of the PersistentObject abstract class.
 */

#include "PersistentObject.h"

void PersistentObject::store(std::string object, std::string id)
{
	this->object = object;
	this->id = id;

	store_all();
	storer.store();

	if (this->prefix != "") {
		filename = this->prefix + "_" + this->object + "_" + this->id + ".json";
	} else {
		filename = this->object + "_" + this->id + ".json";
	}

	std::ofstream writer;
	writer.open(filename);
	writer << storer.get_json();
	writer.close();
}

void PersistentObject::store(std::string prefix, std::string object, std::string id)
{
	this->prefix = prefix;
	store(object, id);
}

void PersistentObject::load(std::string object, std::string id)
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

void PersistentObject::load(std::string prefix, std::string object, std::string id)
{
	this->prefix = prefix;
	load(object, id);
}

std::string PersistentObject::get_nested_prefix()
{
	std::string nested_prefix;

	if (prefix != "") {
		nested_prefix = prefix + "_" + object + "_" + id;
	} else {
		nested_prefix = object + "_" + id;
	}

	return nested_prefix;
}