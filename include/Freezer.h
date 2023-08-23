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
 *  include/Freezer.h
 *
 *  Public header of the Freezer module.
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/document.h>

#include <Item.h>

namespace freon {
	class Freezer {
	public:
		Freezer();
		Freezer(const Freezer &serialize);
		void add(const std::string& identifier, Item::Type type, bool value);
		void add(const std::string& identifier, Item::Type type, int value);
		void add(const std::string& identifier, Item::Type type, long value);
		void add(const std::string& identifier, Item::Type type, unsigned int value);
		void add(const std::string& identifier, Item::Type type, unsigned long value);
		void add(const std::string& identifier, Item::Type type, double value);
		void add(const std::string& identifier, Item::Type type, std::string value);
		void add(const std::string& identifier, Item::Type type, std::vector<bool> values);
		void add(const std::string& identifier, Item::Type type, std::vector<int> values);
		void add(const std::string& identifier, Item::Type type, std::vector<long> values);
		void add(const std::string& identifier, Item::Type type, std::vector<unsigned int> values);
		void add(const std::string& identifier, Item::Type type, std::vector<unsigned long> values);
		void add(const std::string& identifier, Item::Type type, std::vector<double> values);
		void add(const std::string& identifier, Item::Type type, std::vector<std::string> values);
		void generate_json();
		std::string retrieve_json();
	private:
		rapidjson::StringBuffer buffer;
		std::unordered_map<std::string, Item> buffer_area;
	};
}