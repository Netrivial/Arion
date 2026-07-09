#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "../ArionMathConsts.hpp"


namespace ArionMatrix
{
	double Determinant(std::vector <std::vector <double>> Matrix); // Determinant of matrix
	int Rank(std::vector<std::vector<double>> Matrix); // Rank of matrix


	// for the future (will be soon):
	// double VectorNorm(); for two vectors (i wanna kill myself :(  )
	// double ManhattanNorm(); // L_1 norm distance

	// на будущее: отдельно от классов захерачить нормы для векторов/матриц



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

		// setters
		void SetVector(std::vector <double> Vector);


		// getters
		int GetRowSize();

		std::vector <double> GetVector();

		double GetElement(int Number);

		std::string GetType();


		void Add(int Number, double Element);

		void Append(double Elemnt);

		void RemoveElement(int Number);

		void VectorShow(); // or ShowVector?

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

		// setters
		void SetVector(std::vector <double> Vector);


		// getters
		int GetColumnSize();

		std::vector <double> GetVector();

		double GetElement(int Number);

		std::string GetType();


		void Add(int Number, double Element);

		void Append(double Elemnt);

		void RemoveElement(int Number);

		void VectorShow(); // or ShowVector?

		void Reverse();

		void Clear();


		// Functions for working with linear transformations

		void Transporation();
		
		double ManhattanNorm(); // L_1 norm: ∥x∥_1, where x∈R²
		
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
		// Functions for working with row vectors

		Matrix();

		Matrix(int ColumnSize, int RowSize);

		void MatrixRand();

		void NormalizeSizes();

		// setters
		void SetMatrix(std::vector <std::vector <double>> Matrix);

		void SetRow(int Number, std::vector <double> Row); // for std::vector <double> Row
		void SetRow(int Number, VectorRow Row); // for ArionMatrix::VectorRow Row
		
		void SetColumn(int Number, std::vector <double> Column); // for std::vector <double> Column
		void SetColumn(int Number, VectorColumn Column); // for ArionMatrix::VectorColumn Column

		void SetElement(int RowNumber, int ColumnNumber, double Element);


		// getters
		int GetRowSize();
		int GetColumnSize();
		std::vector <int> GetSizes();

		std::vector <std::vector <double>> GetMatrix();

		std::vector <double> GetVectorRow(int Number); // for std::vector <double> Row
		VectorRow GetRow(int Number); // for ArionMatrix::VectorRow Row

		std::vector <double> GetVectorColumn(int Number); // for std::vector <double> Column
		VectorColumn GetColumn(int Number); // for ArionMatrix::VectorColumn Column

		double GetElement(int RowNumber, int ColumnNumber);


		void AddRow(int Number, std::vector <double> Row); // for std::vector <double> Row
		void AddRow(int Number, VectorRow Row); // for ArionMatrix::VectorRow Row

		void AddColumn(int Number, std::vector <double> Column); // for std::vector <double> Column
		void AddColumn(int Number, VectorColumn Column); // for ArionMatrix::VectorColumn Column

		void AppendRow(std::vector <double> Row); // for std::vector <double> Row
		void AppendRow(VectorRow Row);  // for ArionMatrix::VectorColumn Colum

		void AppendColumn(std::vector <double> Column); // for std::vector <double> Column
		void AppendColumn(VectorColumn Column); // for ArionMatrix::VectorColumn Column

		void RemoveRow(int Number);
		void RemoveColumn(int Number);

		void MatrixShow(); // or ShowMatrix?

		// void Reverse(); <- idk :(

		void Clear();



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