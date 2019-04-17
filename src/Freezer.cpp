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
 *  src/Freezer.cpp
 *
 *  Implementation of all methods of the Freezer module.
 */

#include <Freezer.h>


freon::Freezer::Freezer() = default;

freon::Freezer::Freezer(const Freezer &serialize)
{
}

void freon::Freezer::add(std::string identifier, Field::Type type, bool value)
{
	Field field = Field(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(std::string identifier, Field::Type type, int value)
{
	Field field = Field(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(std::string identifier, Field::Type type, std::string value)
{
	Field field = Field(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(std::string identifier, Field::Type type, std::vector<std::string> values)
{
	Field field = Field(type, values);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(std::string identifier, Field::Type type, std::vector<std::vector<std::string>> values)
{
	Field field = Field(type, values);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::generate_json()
{
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(this->buffer);

	writer.StartObject();
	for (auto field : buffer_area) {
		switch (field.second.get_type()) {
			case Field::Type::Boolean:
				writer.String(field.first.c_str());
				writer.Bool(field.second.get_value().b);
				break;
			case Field::Type::Integer:
				writer.String(field.first.c_str());
				writer.Int(field.second.get_value().i);
				break;
			case Field::Type::String:
				writer.String(field.first.c_str());
				writer.String(field.second.get_value().s.c_str());
				break;
			case Field::Type::ArrayString:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (auto value : field.second.get_value().vs) {
					writer.String(value.c_str());
				}
				writer.EndArray();
				break;
			case Field::Type::MatrixString:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (auto i = 0; i < field.second.get_value().ms.size(); i++) {
					writer.StartArray();
					for (auto j = 0; j < field.second.get_value().ms.size(); j++) {
						writer.String(field.second.get_value().ms.at(i).at(j).c_str());
					}
					writer.EndArray();
				}
				writer.EndArray();
				break;
		}
	}
	writer.EndObject();
}

std::string freon::Freezer::retrieve_json()
{
	return buffer.GetString();
}

freon::Freezer::Field::Field(Type type, bool value)
{
	this->type = type;
	this->value.b = value;
}

freon::Freezer::Field::Field(Type type, int value)
{
	this->type = type;
	this->value.i = value;
}

freon::Freezer::Field::Field(Type type, std::string value)
{
	this->type = type;
	this->value.s = value;
}

freon::Freezer::Field::Field(Type type, std::vector<std::string> values)
{
	this->type = type;
	this->value.vs = values;
}

freon::Freezer::Field::Field(Type type, std::vector<std::vector<std::string>> values)
{
	this->type = type;
	this->value.ms = values;
}

freon::Freezer::Field::Type freon::Freezer::Field::get_type()
{
	return type;
}

freon::Freezer::Field::Value freon::Freezer::Field::get_value()
{
	return value;
}