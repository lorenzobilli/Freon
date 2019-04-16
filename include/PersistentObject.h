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
 *  include/PersistentObject.h
 *
 *  Header of the PersistentObject abstract class.
 */

#pragma once

#include <fstream>
#include <string>

#include <Persistence.h>

class PersistentObject
{
public:
	void store(std::string object, std::string id);
	void store(std::string prefix, std::string object, std::string id);
	void load(std::string object, std::string id);
	void load(std::string prefix, std::string object, std::string id);
	Persistence::Serialize & get_storer() { return storer; }
	Persistence::Deserialize & get_loader() { return loader; }
	std::string get_filename() { return filename; }
	std::string get_nested_prefix();
private:
	Persistence::Serialize storer;
	Persistence::Deserialize loader;
	std::string prefix;
	std::string object;
	std::string id;
	std::string filename;
	virtual void store_all() = 0;
	virtual void load_all() = 0;
};