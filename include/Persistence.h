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
 *  src/freon.h
 *
 *  Public header of the freon module.
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/document.h>

namespace freon {
	class Freezer {
	public:
		class Field {
		public:
			enum class Type {
				Boolean,
				Integer,
				String,
				ArrayString,
				MatrixString,
			};
			struct Value {
				bool b;
				int i;
				std::string s;
				std::vector<std::string> vs;
				std::vector<std::vector<std::string>> ms;
			};
			Field(Type type, bool value);
			Field(Type type, int value);
			Field(Type type, std::string value);
			Field(Type type, std::vector<std::string> values);
			Field(Type type, std::vector<std::vector<std::string>> values);
			Type get_type();
			Value get_value();
		private:
			Type type;
			Value value;
		};
		Freezer();
		Freezer(const Freezer &serialize);
		void add(std::string identifier, Field::Type type, bool value);
		void add(std::string identifier, Field::Type type, int value);
		void add(std::string identifier, Field::Type type, std::string value);
		void add(std::string identifier, Field::Type type, std::vector<std::string> values);
		void add(std::string identifier, Field::Type type, std::vector<std::vector<std::string>> values);
		void store();
		std::string get_json();
	private:
		rapidjson::StringBuffer buffer;
		std::unordered_map<std::string, Field> buffer_area;
	};
	class Defroster {
	public:
		Defroster();
		Defroster(const Defroster &deserialize);
		void initialize(std::string json);
		bool load_bool(std::string identifier);
		int load_int(std::string identifier);
		std::string load_string(std::string identifier);
		std::vector<std::string> load_arraystring(std::string identifier);
		std::vector<std::vector<std::string>> load_matrixstring(std::string identifier);
	private:
		rapidjson::Document document;
	};
}