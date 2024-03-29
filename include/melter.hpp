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
 *  include/melter.h
 *
 *  Public header of the melter module.
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/document.h>

#include <cubes/cube.hpp>

namespace freon {
	class melter {
	public:
		melter();
		melter(const melter &deserialize);
		void initialize(const std::string& json);
		template <typename T>
		T melt(freon::cubes::cube<T> &cube, const std::string &identifier);
		void from_json(const std::string &json);
		bool get_boolean(const std::string& identifier);
		int get_integer(const std::string& identifier);
		long get_long_integer(const std::string& identifier);
		unsigned int get_unsigned_integer(const std::string& identifier);
		unsigned long get_unsigned_long_integer(const std::string& identifier);
		double get_double(const std::string& identifier);
		std::string get_string(const std::string& identifier);
		std::vector<bool> get_array_boolean(const std::string& identifier);
		std::vector<int> get_array_integer(const std::string& identifier);
		std::vector<long> get_array_long_integer(const std::string& identifier);
		std::vector<unsigned int> get_array_unsigned_integer(const std::string& identifier);
		std::vector<unsigned long> get_array_unsigned_long_integer(const std::string& identifier);
		std::vector<double> get_array_double(const std::string& identifier);
		std::vector<std::string> get_array_string(const std::string& identifier);
	private:
		rapidjson::Document document;
	};
}

template <typename T>
T freon::melter::melt(freon::cubes::cube<T> &cube, const std::string &identifier)
{
	return cube.melt(this->document, identifier);
}