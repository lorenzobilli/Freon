cmake_minimum_required(VERSION 3.12)

project(Freon
		VERSION 0.1.0
		LANGUAGES CXX)

message("> Project: \"${PROJECT_NAME}\" - Version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 11)

find_package(RapidJSON CONFIG REQUIRED)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(CMAKE_CXX_FLAGS "/Wall")
	set(CMAKE_CXX_FLAGS_RELEASE "-O2")
elseif ("$CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "$CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

if (CMAKE_BUILD_TYPE MATCHES Debug)
	message("- Debug mode selected")
	message("- Using compiler flags: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
	message("- Release mode selected")
	message("- Using compiler flags: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
endif()

include_directories(${RAPIDJSON_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)