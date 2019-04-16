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
 *  Persistence/Persistence.cpp
 *
 *  Implementation of the persistence module.
 */

#include <Persistence.h>

Persistence::Serialize::Serialize() = default;

Persistence::Serialize::Serialize(const Serialize &serialize)
{
}

void Persistence::Serialize::add(std::string identifier, Field::Type type, bool value)
{
	Field field = Field(type, value);
	buffer_area.insert({identifier, field});
}

void Persistence::Serialize::add(std::string identifier, Field::Type type, int value)
{
	Field field = Field(type, value);
	buffer_area.insert({identifier, field});
}

void Persistence::Serialize::add(std::string identifier, Field::Type type, std::string value)
{
	Field field = Field(type, value);
	buffer_area.insert({identifier, field});
}

void Persistence::Serialize::add(std::string identifier, Field::Type type, std::vector<std::string> values)
{
	Field field = Field(type, values);
	buffer_area.insert({identifier, field});
}

void Persistence::Serialize::store()
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
		}
	}
	writer.EndObject();
}

std::string Persistence::Serialize::get_json()
{
	return buffer.GetString();
}

Persistence::Serialize::Field::Field(Type type, bool value)
{
	this->type = type;
	this->value.b = value;
}

Persistence::Serialize::Field::Field(Type type, int value)
{
	this->type = type;
	this->value.i = value;
}

Persistence::Serialize::Field::Field(Type type, std::string value)
{
	this->type = type;
	this->value.s = value;
}

Persistence::Serialize::Field::Field(Type type, std::vector<std::string> values)
{
	this->type = type;
	this->value.vs = values;
}

Persistence::Serialize::Field::Type Persistence::Serialize::Field::get_type()
{
	return type;
}

Persistence::Serialize::Field::Value Persistence::Serialize::Field::get_value()
{
	return value;
}

Persistence::Deserialize::Deserialize() = default;

Persistence::Deserialize::Deserialize(const Persistence::Deserialize &deserialize)
{
}

void Persistence::Deserialize::initialize(std::string json)
{
	this->document.Parse(json.c_str());
}

bool Persistence::Deserialize::load_bool(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	return value.GetBool();
}

int Persistence::Deserialize::load_int(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	return value.GetInt();
}

std::string Persistence::Deserialize::load_string(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	return value.GetString();
}

std::vector<std::string> Persistence::Deserialize::load_arraystring(std::string identifier)
{
	rapidjson::Value &value = this->document[identifier.c_str()];
	std::vector<std::string> vector;
	for (auto & v : value.GetArray()) {
		vector.push_back(v.GetString());
	}
	return vector;
}