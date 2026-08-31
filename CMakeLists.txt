cmake_minimum_required(VERSION 3.15)
project(Arion VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(SOURCES
    src/Fraction/Fraction.cpp
)

if(NOT SOURCES)
    set(SOURCES src/Stub.cpp)
endif()

add_library(Arion ${SOURCES})

target_include_directories(Arion
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(Arion PUBLIC cxx_std_17)

file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
target_sources(Arion PUBLIC ${HEADER_FILES})

# attentions
if(MSVC)
    target_compile_options(Arion PRIVATE /W4)
else()
    target_compile_options(Arion PRIVATE -Wall -Wextra -Wpedantic)
endif()

# tests
enable_testing()
add_subdirectory(tests)