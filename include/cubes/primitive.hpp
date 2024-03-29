//
// Created by lorenzobilli on 23/08/2023.
//

#pragma once

#include <cubes/cube.hpp>

namespace freon {
	namespace cubes {

		template <typename T>
		class primitive : public cube<T> {
		};

		template <>
		class primitive<short> : public cube<short> {

			void freeze(rapidjson::Document &document, const std::string &identifier, const short &value) override
			{
				auto &allocator = document.GetAllocator();
				rapidjson::Value document_identifier(identifier.c_str(), allocator);
				document.AddMember(document_identifier, value, allocator);
			}

			short melt(rapidjson::Document &document, const std::string &identifier) override
			{
				auto value = &document[identifier.c_str()];
				return value->GetInt();
			}
		};

		template <>
		class primitive<int> : public cube<int> {

			void freeze(rapidjson::Document &document, const std::string &identifier, const int &value) override
			{
				auto &allocator = document.GetAllocator();
				rapidjson::Value document_identifier(identifier.c_str(), allocator);
				document.AddMember(document_identifier, value, allocator);
			}

			int melt(rapidjson::Document &document, const std::string &identifier) override
			{
				auto value = &document[identifier.c_str()];
				return value->GetInt();
			}
		};

		template <>
		class primitive<std::string> : public cube<std::string> {

			void freeze(rapidjson::Document &document, const std::string &identifier, const std::string &value) override
			{
				auto& allocator = document.GetAllocator();
				rapidjson::Value document_identifier(identifier.c_str(), allocator);
				rapidjson::Value document_value(value.c_str(), allocator);
				document.AddMember(document_identifier, document_value, allocator);
			}

			std::string melt(rapidjson::Document &document, const std::string &identifier) override
			{
				auto value = &document[identifier.c_str()];
				return value->GetString();
			}
		};
	}
}
