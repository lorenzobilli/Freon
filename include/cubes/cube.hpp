//
// Created by lorenzobilli on 23/08/2023.
//

#pragma once

#include <string>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/document.h>

namespace freon {
	namespace cubes {
		template <typename T>
		class cube {
		public:
			virtual void set(rapidjson::Document &document, const std::string &identifier, const T &value) = 0;
			virtual T get(rapidjson::Document &document, const std::string &identifier) = 0;
		};
	}
}
