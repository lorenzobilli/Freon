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
 *  src/freon.cpp
 *
 *  Public header of the Freezable module.
 */

#pragma once

#include <fstream>
#include <string>

#include <Freezer.h>
#include <Defroster.h>

namespace freon {
	class Freezable {
	public:
		void freeze(std::string object, std::string id);
		void freeze(std::string prefix, std::string object, std::string id);
		void defrost(std::string object, std::string id);
		void defrost(std::string prefix, std::string object, std::string id);
		freon::Freezer &get_freezer() { return freezer; }
		freon::Defroster &get_defroster() { return defroster; }
		std::string get_filename() { return filename; }
		std::string get_nested_prefix();
	private:
		freon::Freezer freezer;
		freon::Defroster defroster;
		std::string prefix;
		std::string object;
		std::string id;
		std::string filename;
		virtual void freeze_all() = 0;
		virtual void defrost_all() = 0;
	};
}