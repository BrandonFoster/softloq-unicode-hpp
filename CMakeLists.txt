cmake_minimum_required(VERSION 3.10...3.29)
project(softloq-unicode-project VERSION 1.1.0 LANGUAGES CXX)
option(BUILD_SHARED_LIBS "Generate Shared Library" OFF)
option(SOFTLOQ_UNICODE_BUILD_TESTING "Generate Unit-Testing" OFF)

# Build settings
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()
if(NOT CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED)
endif()
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# Catch2
include(CTest)
if(NOT TARGET Catch2)
    add_subdirectory(Catch2)
endif()

# Default values
set(LIBRARY_TYPE STATIC)
set(PUBLIC_DEFINITIONS "")
set(PRIVATE_DEFINITIONS "")

# Library settings
if(BUILD_SHARED_LIBS)
    set(LIBRARY_TYPE SHARED)
    set(PUBLIC_DEFINITIONS SOFTLOQ_UNICODE_USE_API)
    set(PRIVATE_DEFINITIONS SOFTLOQ_UNICODE_BUILD_API)
endif()

# Library build
file(GLOB_RECURSE CXX_FILES src/**.cpp)
add_library(softloq-unicode ${LIBRARY_TYPE} ${CXX_FILES})
add_library(softloq::unicode ALIAS softloq-unicode)
target_include_directories(softloq-unicode PUBLIC include)
target_compile_definitions(softloq-unicode PUBLIC ${PUBLIC_DEFINITIONS})
target_compile_definitions(softloq-unicode PRIVATE ${PRIVATE_DEFINITIONS})

# Unit testing
if(BUILD_TESTING AND SOFTLOQ_UNICODE_BUILD_TESTING)
    add_executable(softloq-unicode-test tests/unicode_test.cpp tests/unicode_macros.cpp)
    add_dependencies(softloq-unicode-test softloq::unicode Catch2::Catch2WithMain)
    target_link_libraries(softloq-unicode-test softloq::unicode Catch2::Catch2WithMain)
    include(Catch)
    catch_discover_tests(softloq-unicode-test)
endif()
