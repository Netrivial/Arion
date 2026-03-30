cmake_minimum_required(VERSION 3.31.6 FATAL_ERROR)

project(Arion VERSION 0.1.2)

add_executable(Arion 
			Sources/main.cpp
			Sources/Arion.hpp 
			Sources/ArionConsts.hpp
			Sources/ArionMatrix/ArionMatrix.cpp
			Sources/ArionMatrix/ArionMatrix.hpp
			Sources/ArionMatrix/ArionVectorRow.cpp
			Sources/ArionMatrix/ArionMatrixFunctions/ArionMatrixDeterminant.cpp
			Sources/ArionMatrix/ArionMatrixFunctions/ArionMatrixRank.cpp
			Sources/ArionMathFunctions/MathFunctions.hpp
			Sources/ArionMathFunctions/MathFunctions/Factorial.hpp
			Sources/ArionMathFunctions/MathFunctions/Subfactorial.hpp
			Sources/ArionMathFunctions/MathFunctions/Exp.hpp
			Sources/ArionMathFunctions/MathFunctions/Trigonometry/Sin.hpp
			Sources/ArionMathFunctions/MathFunctions/Trigonometry/Cos.hpp
			Sources/ArionMathFunctions/MathFunctions/Trigonometry/Tan.hpp
   			Sources/ArionMathFunctions/MathFunctions/Trigonometry/Ctg.hpp 
			Sources/tests.cpp "Sources/ArionMatrix/ArionVectorColumn.cpp")
