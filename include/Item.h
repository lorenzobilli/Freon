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
 *  include/Item.h
 *
 *  Public header of the Item module.
 */

#pragma once

#include <string>
#include <vector>

namespace freon {
	class Item {
	public:
		enum class Type {
			Boolean,
			Integer,
			String,
			ArrayString,
			MatrixString,
			TensorString
		};
		struct Value {
			bool b;
			int i;
			std::string s;
			std::vector<std::string> vs;
			std::vector<std::vector<std::string>> ms;
			std::vector<std::vector<std::vector<std::string>>> ts;
		};
		Item(Type type, bool value);
		Item(Type type, int value);
		Item(Type type, std::string value);
		Item(Type type, std::vector<std::string> values);
		Item(Type type, std::vector<std::vector<std::string>> values);
		Item(Type type, std::vector<std::vector<std::vector<std::string>>> values);
		Type get_type();
		Value get_value();
	private:
		Type type;
		Value value;
	};
}