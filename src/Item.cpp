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
 *  src/Item.cpp
 *
 *  Implementation of the Item module.
 */

#include <Item.h>

#include <utility>

freon::Item::Item(Type type, bool value)
{
	this->type = type;
	this->container = Container::None;
	this->value.b = value;
}

freon::Item::Item(Type type, char value)
{
	this->type = type;
	this->container = Container::None;
	this->value.c = value;
}

freon::Item::Item(Type type, int value)
{
	this->type = type;
	this->container = Container::None;
	this->value.i = value;
}

freon::Item::Item(Type type, long value)
{
	this->type = type;
	this->container = Container::None;
	this->value.l = value;
}

freon::Item::Item(Type type, long long value)
{
	this->type = type;
	this->container = Container::None;
	this->value.ll = value;
}

freon::Item::Item(Type type, unsigned int value)
{
	this->type = type;
	this->container = Container::None;
	this->value.ui = value;
}

freon::Item::Item(Type type, unsigned long value)
{
	this->type = type;
	this->container = Container::None;
	this->value.ul = value;
}

freon::Item::Item(Type type, unsigned long long value)
{
	this->type = type;
	this->container = Container::None;
	this->value.ull = value;
}

freon::Item::Item(freon::Item::Type type, float value)
{
	this->type = type;
	this->container = Container::None;
	this->value.f = value;
}

freon::Item::Item(Type type, double value)
{
	this->type = type;
	this->container = Container::None;
	this->value.d = value;
}

freon::Item::Item(Type type, std::string value)
{
	this->type = type;
	this->container = Container::None;
	this->value.ss = std::move(value);
}


freon::Item::Item(Type type, Container container, bool value)
{
	this->type = type;
	this->container = container;
	this->value.b = value;
}

freon::Item::Item(Type type, Container container, char value)
{
	this->type = type;
	this->container = container;
	this->value.c = value;
}

freon::Item::Item(Type type, Container container, int value)
{
	this->type = type;
	this->container = container;
	this->value.i = value;
}

freon::Item::Item(Type type, Container container, long value)
{
	this->type = type;
	this->container = container;
	this->value.l = value;
}

freon::Item::Item(Type type, Container container, long long value)
{
	this->type = type;
	this->container = container;
	this->value.ll = value;
}

freon::Item::Item(Type type, Container container, unsigned int value)
{
	this->type = type;
	this->container = container;
	this->value.ui = value;
}

freon::Item::Item(Type type, Container container, unsigned long value)
{
	this->type = type;
	this->container = container;
	this->value.ul = value;
}

freon::Item::Item(Type type, Container container, unsigned long long value)
{
	this->type = type;
	this->container = container;
	this->value.ull = value;
}

freon::Item::Item(freon::Item::Type type, Container container, float value)
{
	this->type = type;
	this->container = container;
	this->value.f = value;
}

freon::Item::Item(Type type, Container container, double value)
{
	this->type = type;
	this->container = container;
	this->value.d = value;
}

freon::Item::Item(Type type, Container container, std::string value)
{
	this->type = type;
	this->container = container;
	this->value.ss = std::move(value);
}



freon::Item::Item(Type type, std::vector<bool> values)
{
	this->type = type;
	this->value.vb = std::move(values);
}

freon::Item::Item(Type type, std::vector<int> values)
{
	this->type = type;
	this->value.vi = std::move(values);
}

freon::Item::Item(Type type, std::vector<long> values)
{
	this->type = type;
	this->value.vl = std::move(values);
}

freon::Item::Item(Type type, std::vector<unsigned int> values)
{
	this->type = type;
	this->value.vui = std::move(values);
}

freon::Item::Item(Type type, std::vector<unsigned long> values)
{
	this->type = type;
	this->value.vul = std::move(values);
}

freon::Item::Item(Type type, std::vector<double> values)
{
	this->type = type;
	this->value.vd = std::move(values);
}

freon::Item::Item(Type type, std::vector<std::string> values)
{
	this->type = type;
	this->value.vss = std::move(values);
}

freon::Item::Item::Type freon::Item::get_type()
{
	return type;
}

freon::Item::Item::Container freon::Item::get_container()
{
	return container;
}

freon::Item::Item::Value freon::Item::get_value()
{
	return value;
}