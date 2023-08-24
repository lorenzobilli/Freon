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

#include <utility>

freon::Freezer::Freezer()
{
	this->members = 0;
	this->writer.reset(new rapidjson::PrettyWriter<rapidjson::StringBuffer>(this->buffer));
	this->document.SetObject();
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, bool value)
{
	Item field = Item(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, int value)
{
	Item field = Item(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, long value)
{
	Item field = Item(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, unsigned int value)
{
	Item field = Item(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, unsigned long value)
{
	Item field = Item(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, double value)
{
	Item field = Item(type, value);
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::string value)
{
	Item field = Item(type, std::move(value));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::vector<bool> values)
{
	Item field = Item(type, std::move(values));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::vector<int> values)
{
	Item field = Item(type, std::move(values));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::vector<long> values)
{
	Item field = Item(type, std::move(values));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::vector<unsigned int> values)
{
	Item field = Item(type, std::move(values));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::vector<unsigned long> values)
{
	Item field = Item(type, std::move(values));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::vector<double> values)
{
	Item field = Item(type, std::move(values));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::add(const std::string& identifier, Item::Type type, std::vector<std::string> values)
{
	Item field = Item(type, std::move(values));
	buffer_area.insert({identifier, field});
}

void freon::Freezer::generate_json()
{
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(this->buffer);

	writer.StartObject();
	for (auto field : buffer_area) {
		switch (field.second.get_type()) {
			case Item::Type::Boolean:
				writer.String(field.first.c_str());
				writer.Bool(field.second.get_value().b);
				break;
			case Item::Type::Character:
				writer.String(field.first.c_str());
				writer.String(reinterpret_cast<const char *>(new std::string(1, field.second.get_value().c)));
				break;
			case Item::Type::Short:
				writer.String(field.first.c_str());
				writer.Int(field.second.get_value().s);
				break;
			case Item::Type::Integer:
				writer.String(field.first.c_str());
				writer.Int(field.second.get_value().i);
				break;
			case Item::Type::LongInteger:
				writer.String(field.first.c_str());
				writer.Int64(field.second.get_value().l);
				break;
			case Item::Type::LongLongInteger:
				writer.String(field.first.c_str());
				writer.Int64(field.second.get_value().ll);
			case Item::Type::UnsignedInteger:
				writer.String(field.first.c_str());
				writer.Uint(field.second.get_value().ui);
				break;
			case Item::Type::UnsignedLongInteger:
				writer.String(field.first.c_str());
				writer.Uint64(field.second.get_value().ul);
				break;
			case Item::Type::UnsignedLongLongInteger:
				writer.String(field.first.c_str());
				writer.Uint64(field.second.get_value().ull);
				break;
			case Item::Type::Float:
				writer.String(field.first.c_str());
				writer.Double(field.second.get_value().f);
				break;
			case Item::Type::Double:
				writer.String(field.first.c_str());
				writer.Double(field.second.get_value().d);
				break;
			case Item::Type::String:
				writer.String(field.first.c_str());
				writer.String(field.second.get_value().ss.c_str());
				break;
			case Item::Type::ArrayBoolean:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (const auto& value : field.second.get_value().vb) {
					writer.Bool(value);
				}
				writer.EndArray();
				break;
			case Item::Type::ArrayCharacter:
				writer.String(field.first.c_str());
				writer.StartArray();
				break;
			case Item::Type::ArrayShort:
				writer.String(field.first.c_str());

			case Item::Type::ArrayInteger:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (const auto& value : field.second.get_value().vi) {
					writer.Int(value);
				}
				writer.EndArray();
				break;
			case Item::Type::ArrayLongInteger:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (const auto& value : field.second.get_value().vl) {
					writer.Int64(value);
				}
				writer.EndArray();
				break;
			case Item::Type::ArrayUnsignedInteger:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (const auto& value : field.second.get_value().vui) {
					writer.Uint(value);
				}
				writer.EndArray();
				break;
			case Item::Type::ArrayUnsignedLongInteger:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (const auto& value : field.second.get_value().vul) {
					writer.Uint64(value);
				}
				writer.EndArray();
				break;
			case Item::Type::ArrayDouble:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (const auto& value : field.second.get_value().vd) {
					writer.Double(value);
				}
				writer.EndArray();
				break;
			case Item::Type::ArrayString:
				writer.String(field.first.c_str());
				writer.StartArray();
				for (const auto& value : field.second.get_value().vss) {
					writer.String(value.c_str());
				}
				writer.EndArray();
				break;
		}
	}
	writer.EndObject();
}

std::string freon::Freezer::retrieve_json()
{
	this->document.Accept(*this->writer);
	return buffer.GetString();
}

std::string freon::Freezer::to_json()
{
	this->document.Accept(*this->writer);
	return buffer.GetString();
}
