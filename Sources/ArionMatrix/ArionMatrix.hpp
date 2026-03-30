#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "../ArionConsts.hpp"

// remove soon
using namespace std;

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

		double GetElementByNumber(int Number);

		std::string GetType();

		void Reverse();

		void Clear();


		// Functions for working with linear transformations

		void Transporation();

		double VectorNorm(); // Length of a vector

		double ManhattanNorm(); // L_1 norm
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

		double GetElementByNumber(int Number);

		std::string GetType();

		void Reverse();

		void Clear();


		// Functions for working with linear transformations

		void Transporation(); 

		double VectorNorm(); // Length of a vector

		double ManhattanNorm(); // L_1 norm
	};
}

class Matrix
{
	int RowSize;
	int ColumnSize;

public:
	vector <vector <double>> _Matrix;

	Matrix() : RowSize(MaxRow), ColumnSize(MaxRow), _Matrix(MaxColumn, vector <double>(MaxRow))
	{
		for (int i = 0; i < ColumnSize; i++)
		{
			vector <double> temp;
			for (int j = 0; j < RowSize; j++)
			{
				temp.push_back(0);
			}
			_Matrix.push_back(temp);
		}
	}

	Matrix(int _ColumnSize, int _RowSize) : RowSize(_RowSize), ColumnSize(_ColumnSize), _Matrix(_ColumnSize, vector <double>(_RowSize))
	{
		for (int i = 0; i < _ColumnSize; i++)
		{
			vector <double> Temp;
			for (int j = 0; j < _RowSize; j++)
			{
				Temp.push_back(0);
			}
			_Matrix.push_back(Temp);
		}
	}

	void MatrixRand()
	{
		srand(time(nullptr));

		for (int i = 0; i < ColumnSize; i++)
		{
			for (int j = 0; j < RowSize; j++)
			{
				_Matrix[i][j] = rand() % 10;
			}
		}
	}

	void MatrixShow()
	{
		for (int i = 0; i < ColumnSize; i++)
		{
			for (int j = 0; j < RowSize; j++)
			{
				cout << _Matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int GetRowSize()
	{
		return RowSize;
	}

	int GetColumnSize()
	{
		return ColumnSize;
	}

	void NormalizeSizes()
	{
		RowSize = _Matrix[0].size();
		ColumnSize = _Matrix.size();
	}

	void Transporation()
	{
		vector <vector <double>> HelpMatrix(RowSize, vector <double>(ColumnSize));

		for (int i = 0; i < RowSize; i++)
		{
			for (int j = 0; j < ColumnSize; j++)
			{
				HelpMatrix[i][j] = _Matrix[j][i];
			}
		}

		_Matrix.resize(RowSize);
		_Matrix[0].resize(ColumnSize);
		_Matrix = HelpMatrix;

		NormalizeSizes();
	}

	double GetDeterminant()
	{
		setlocale(LC_ALL, "Russian");

		if (RowSize != ColumnSize || RowSize == 0 || ColumnSize == 0)
		{
			cout << "Ìàòðèöà íå êâàäðàòíàÿ! (áóäåò âîçðàùåíà -1)" << endl << endl;
			return -1.0;
		}

		return ArionMatrix::Determinant(_Matrix);
	}

	int GetRank()
	{
		return ArionMatrix::Rank(_Matrix);
	}
};


// MatrixRow SumMatrix(MatrixRow Row_1, MatrixRow Row_2);
// MatrixColumn SumMatrix(MatrixColumn Column_1, MatrixColumn Column_2);
// Matrix SumMatrix(Matrix Matrix_1, Matrix Matrix_2);
//
//
// MatrixRow MinusMatrix(MatrixRow Row_1, MatrixRow Row_2);
// MatrixColumn MinusMatrix(MatrixColumn Column_1, MatrixColumn Column_2);
// Matrix MinusMatrix(Matrix Matrix_1, Matrix Matrix_2);
//
//
// MatrixRow MultiplicationMatrix(MatrixRow Row, double Value);
// MatrixColumn MultiplicationMatrix(MatrixColumn Column, double Value);
// Matrix MultiplicationMatrix(Matrix MainMatrix, double value);
// Matrix MultiplicationMatrix(MatrixColumn Column, MatrixRow Row);
// double MultiplicationMatrix(MatrixRow Row, MatrixColumn Column);
// MatrixRow MultiplicationMatrix(MatrixRow Row, Matrix _Matrix);
// Matrix MultiplicationMatrix(Matrix Matrix_1, Matrix Matrix_2);
//
//
// MatrixRow DivisionMatrix(MatrixRow Row, double Value);
// MatrixColumn DivisionMatrix(MatrixColumn Column, double Value);
// Matrix DivisionMatrix(Matrix _Matrix, double Value);
