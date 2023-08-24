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
		class primitive<std::string> : public cube<std::string> {

			void set(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer, const std::string &identifier, const std::string &value) override {
				writer.String(identifier.c_str());
				writer.String(value.c_str());
			}

			void set(rapidjson::Document &document, const std::string &identifier, const std::string &value) override {
				auto& allocator = document.GetAllocator();
				rapidjson::Value document_identifier(identifier.c_str(), allocator);
				rapidjson::Value document_value(value.c_str(), allocator);
				document.AddMember(document_identifier, document_value, allocator);
			}

			std::string get(rapidjson::Document &document, const std::string &identifier) override {
				auto value = &document[identifier.c_str()];
				return value->GetString();
			}
		};
	}
}
