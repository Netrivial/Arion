#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "../ArionConsts.hpp"


namespace ArionMatrix
{
	double Determinant(std::vector <std::vector <double>> Matrix); // Determinant of matrix
	int Rank(std::vector<std::vector<double>> Matrix); // Rank of matrix

	// for the future (will be soon):
	// double VectorNorm(); for two vectors (i wanna kill myself :(  )
	// double ManhattanNorm(); // L_1 norm distance


	class VectorRow // Row
	{
		int _RowSize;
		std::string _Type = "Row";
		std::vector <double> _Vector;

	public:

		// Functions for working with row vectors

		VectorRow();

		VectorRow(int RowSize);

		void VectorRand();

		void NormalizeSize();

		void SetVector(std::vector<double> Vector);

		void AddElementByNumber(int Number, double Element);

		void Append(double Elemnt);

		void RemoveElementByNumber(int Number);

		void VectorShow(); // or ShowVector?

		int GetRowSize();

		std::vector <double> GetVector();

		double GetElementByNumber(int Number);

		std::string GetType();

		void Reverse();

		void Clear();


		// Functions for working with linear transformations

		void Transporation();

		double ManhattanNorm(); // L_1 norm

		double VectorNorm(); // L_2 norm: Length of a vector 

		double VectorNormL_p(int p); // L_p norm

		double ChebyshevNorm(); // L_inf
	};


	class VectorColumn // Column
	{
		int _ColumnSize;
		std::string _Type = "Column";
		std::vector <double> _Vector;

	public:

		// Functions for working with row vectors

		VectorColumn();

		VectorColumn(int _ColumnSize);

		void VectorRand();

		void NormalizeSize();

		void SetVector(std::vector<double> Vector);

		void AddElementByNumber(int Number, double Element);

		void Append(double Elemnt);

		void RemoveElementByNumber(int Number);

		void VectorShow(); // or ShowVector?

		int GetColumnSize();

		std::vector <double> GetVector();

		double GetElementByNumber(int Number);

		std::string GetType();

		void Reverse();

		void Clear();


		// Functions for working with linear transformations

		void Transporation(); 

		double ManhattanNorm(); // L_1 norm

		double VectorNorm(); // L_2 norm: Length of a vector

		double VectorNormL_p(int p); // L_p norm

		double ChebyshevNorm(); // L_inf
	};


	class Matrix // Matrix
	{
		int _RowSize;
		int _ColumnSize;
		std::vector <std::vector <double>> _Matrix;

	public:

		Matrix();

		Matrix(int ColumnSize, int RowSize);

		void matrixrand();

		void NormalizeSizes();

		void SetMatrix(std::vector <std::vector <double>> Matrix);

		void SetRowByNumber(int Number, std::vector <double> Row); // for std::vector <double> Row
		void SetRowByNumber(int Number, VectorRow Row); // for ArionMatrix::VectorRow Row

		void SetColumnByNumber(int Number, std::vector <double> Column);

		void AddRowByNumber(int Number);

		void AddColumnByNumber(int Number);

		//void MatrixShow()
		//{
		//	for (int i = 0; i < ColumnSize; i++)
		//	{
		//		for (int j = 0; j < RowSize; j++)
		//		{
		//			std::cout << _Matrix[i][j] << " ";
		//		}
		//		std::cout << std::endl;
		//	}
		//	std::cout << std::endl;
		//}

		//int GetRowSize()
		//{
		//	return RowSize;
		//}

		//int GetColumnSize()
		//{
		//	return ColumnSize;
		//}

		//void Transporation()
		//{
		//	std::vector <std::vector <double>> HelpMatrix(RowSize, std::vector <double>(ColumnSize));

		//	for (int i = 0; i < RowSize; i++)
		//	{
		//		for (int j = 0; j < ColumnSize; j++)
		//		{
		//			HelpMatrix[i][j] = _Matrix[j][i];
		//		}
		//	}

		//	_Matrix.resize(RowSize);
		//	_Matrix[0].resize(ColumnSize);
		//	_Matrix = HelpMatrix;

		//	NormalizeSizes();
		//}

		//double GetDeterminant()
		//{
		//	setlocale(LC_ALL, "Russian");

		//	if (RowSize != ColumnSize || RowSize == 0 || ColumnSize == 0)
		//	{
		//		std::cout << "Ìàòðèöà íå êâàäðàòíàÿ! (áóäåò âîçðàùåíà -1)" << std::endl << std::endl;
		//		return -1.0;
		//	}

		//	return ArionMatrix::Determinant(_Matrix);
		//}

		//int GetRank()
		//{
		//	return ArionMatrix::Rank(_Matrix);
		//}
	};
}
