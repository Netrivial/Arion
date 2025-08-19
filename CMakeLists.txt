cmake_minimum_required(VERSION 3.31.6 FATAL_ERROR)

project(Arion VERSION 0.1.1)

add_executable(Arion 
			Sources/main.cpp
			Sources/Arion.hpp 
			Sources/ArionConsts.hpp
			Sources/Arion_Matrix/ArionMatrix.cpp
			Sources/Arion_Matrix/ArionMatrix.hpp
			Sources/Arion_Matrix/Arion_MatrixFunctions/ArionMatrixDeterminant.cpp
			Sources/Arion_Matrix/Arion_MatrixFunctions/ArionMatrixRank.cpp
			Sources/Arion_MathFunctions/ImportMathFunctions.hpp
			Sources/Arion_MathFunctions/MathFunctions/Factorial.hpp
			Sources/Arion_MathFunctions/MathFunctions/Subfactorial.hpp
			Sources/Arion_MathFunctions/MathFunctions/Exp.hpp
			Sources/Arion_MathFunctions/MathFunctions/Trigonometry/Sin.hpp
			Sources/Arion_MathFunctions/MathFunctions/Trigonometry/Cos.hpp
			Sources/Arion_MathFunctions/MathFunctions/Trigonometry/Tan.hpp
   			Sources/Arion_MathFunctions/MathFunctions/Trigonometry/Ctg.hpp)
