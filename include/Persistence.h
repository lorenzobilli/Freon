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
 *  include/Persistence.h
 *
 *  Header of the persistence module.
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/document.h>

namespace Persistence {
	class Serialize {
	public:
		class Field {
		public:
			enum class Type {
				Boolean,
				Integer,
				String,
				ArrayString,
			};
			struct Value {
				bool b;
				int i;
				std::string s;
				std::vector<std::string> vs;
			};
			Field(Type type, bool value);
			Field(Type type, int value);
			Field(Type type, std::string value);
			Field(Type type, std::vector<std::string> values);
			Type get_type();
			Value get_value();
		private:
			Type type;
			Value value;
		};
		Serialize();
		Serialize(const Serialize &serialize);
		void add(std::string identifier, Field::Type type, bool value);
		void add(std::string identifier, Field::Type type, int value);
		void add(std::string identifier, Field::Type type, std::string value);
		void add(std::string identifier, Field::Type type, std::vector<std::string> values);
		void store();
		std::string get_json();
	private:
		rapidjson::StringBuffer buffer;
		std::unordered_map<std::string, Field> buffer_area;
	};
	class Deserialize {
	public:
		Deserialize();
		Deserialize(const Deserialize &deserialize);
		void initialize(std::string json);
		bool load_bool(std::string identifier);
		int load_int(std::string identifier);
		std::string load_string(std::string identifier);
		std::vector<std::string> load_arraystring(std::string identifier);
	private:
		rapidjson::Document document;
	};
}