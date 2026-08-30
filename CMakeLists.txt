cmake_minimum_required(VERSION 3.15)
project(ArionMath VERSION 0.1.0 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(SOURCES
    src/Fraction/Fraction.cpp
)

if(NOT SOURCES)
    set(SOURCES src/Stub.cpp)
endif()

add_library(ArionMath ${SOURCES})

target_include_directories(ArionMath
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(ArionMath PUBLIC cxx_std_17)

file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
target_sources(ArionMath PUBLIC ${HEADER_FILES})

# attentions
if(MSVC)
    target_compile_options(ArionMath PRIVATE /W4)
else()
    target_compile_options(ArionMath PRIVATE -Wall -Wextra -Wpedantic)
endif()

# tests
enable_testing()
add_subdirectory(tests)