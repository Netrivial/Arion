cmake_minimum_required(VERSION 3.31.6 FATAL_ERROR)

project(Arion VERSION 0.1.1)

add_executable(Arion 
			Sources/main.cpp
			Sources/Arion.hpp 
			Sources/ArionConsts.hpp
			Sources/Arion_Matrix/ArionMatrix.cpp
			Sources/Arion_Matrix/ArionMatrix.hpp
			Sources/Arion_Matrix/Arion_MatrixFunctions/ArionMatrixDeterminant.cpp
			Sources/Arion_Matrix/Arion_MatrixFunctions/ArionMatrixRank.cpp)
