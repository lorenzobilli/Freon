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
			Character,
			Short,
			Integer,
			LongInteger,
			LongLongInteger,
			UnsignedInteger,
			UnsignedLongInteger,
			UnsignedLongLongInteger,
			Float,
			Double,
			String,
			ArrayBoolean,
			ArrayCharacter,
			ArrayShort,
			ArrayInteger,
			ArrayLongInteger,
			ArrayLongLongInteger,
			ArrayUnsignedInteger,
			ArrayUnsignedLongInteger,
			ArrayUnsignedLongLongInteger,
			ArrayFloat,
			ArrayDouble,
			ArrayString
		};

		enum class Container {
			None,
			Array
		};

		struct Value {
			bool b;
			char c;
			short s;
			int i;
			long l;
			long long ll;
			unsigned int ui;
			unsigned long ul;
			unsigned long long ull;
			float f;
			double d;
			std::string ss;
			std::vector<bool> vb;
			std::vector<char> vc;
			std::vector<short> vs;
			std::vector<int> vi;
			std::vector<long> vl;
			std::vector<long long> vll;
			std::vector<unsigned int> vui;
			std::vector<unsigned long> vul;
			std::vector<unsigned long long> vull;
			std::vector<float> vf;
			std::vector<double> vd;
			std::vector<std::string> vss;
		};

		Item(Type type, bool value);
		Item(Type type, char value);
		Item(Type type, int value);
		Item(Type type, long value);
		Item(Type type, long long value);
		Item(Type type, unsigned int value);
		Item(Type type, unsigned long value);
		Item(Type type, unsigned long long value);
		Item(Type type, float value);
		Item(Type type, double value);
		Item(Type type, std::string value);

		Item(Type type, Container container, bool value);
		Item(Type type, Container container, char value);
		Item(Type type, Container container, int value);
		Item(Type type, Container container, long value);
		Item(Type type, Container container, long long value);
		Item(Type type, Container container, unsigned int value);
		Item(Type type, Container container, unsigned long value);
		Item(Type type, Container container, unsigned long long value);
		Item(Type type, Container container, float value);
		Item(Type type, Container container, double value);
		Item(Type type, Container container, std::string value);



		Item(Type type, std::vector<bool> values);
		Item(Type type, std::vector<char> values);
		Item(Type type, std::vector<short> values);
		Item(Type type, std::vector<int> values);
		Item(Type type, std::vector<long> values);
		Item(Type type, std::vector<long long> value);
		Item(Type type, std::vector<unsigned int> values);
		Item(Type type, std::vector<unsigned long> values);
		Item(Type type, std::vector<unsigned long long> values);
		Item(Type type, std::vector<float> values);
		Item(Type type, std::vector<double> values);
		Item(Type type, std::vector<std::string> values);
		Type get_type();
		Container get_container();
		Value get_value();
	private:
		Type type;
		Container container;
		Value value;
	};
}