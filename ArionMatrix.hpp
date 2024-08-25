#pragma once
#include <vector>
#include <random>
#include <ctime>
#include "ArionConst.hpp"
#include "ArionMatrixDeterminant.cpp"
#include "ArionMatrixRank.cpp"
using namespace std;



class MatrixRow
{
	int RowSize;
	string Mode = "Row";

public:
	vector <double> Matrix;

	MatrixRow() : RowSize(MaxRow), Matrix(MaxRow)
	{
		for (int i = 0; i < MaxRow; i++)
		{
			Matrix[i] = 0;
		}
	}

	MatrixRow(int _RowSize) : RowSize(_RowSize), Matrix(_RowSize)
	{
		for (int i = 0; i < _RowSize; i++)
		{
			Matrix[i] = 0;
		}
	}

	void MatrixRand()
	{
		srand(time(nullptr));

		for (int i = 0; i < RowSize; i++)
		{
			Matrix[i] = rand() % 10;
		}
	}

	void MatrixShow()
	{
		if (Mode == "Row")
		{
			for (int i = 0; i < RowSize; i++)
			{
				cout << Matrix[i] << " ";
			}
			cout << endl << endl;
		}

		if (Mode == "Column")
		{
			for (int i = 0; i < RowSize; i++)
			{
				cout << Matrix[i] << endl;
			}
			cout << endl;
		}
	}

	int GetRowSize()
	{
		return RowSize;
	}

	string GetMode()
	{
		return Mode;
	}

	void NormalizeSize()
	{
		RowSize = Matrix.size();
	}

	void Transporation()
	{
		if (Mode == "Row")
		{
			Mode = "Column";
			return;
		}

		if (Mode == "Column")
		{
			Mode = "Row";
		}
	}
};
const MatrixRow ErrorVectorRow(1);

class MatrixColumn
{
	int ColumnSize;
	string Mode = "Column";

public:
	vector <double> Matrix;

	MatrixColumn() : ColumnSize(MaxColumn), Matrix(MaxColumn)
	{
		for (int i = 0; i < MaxColumn; i++)
		{
			Matrix[i] = 0;
		}
	}

	MatrixColumn(int _ColumnSize) : ColumnSize(_ColumnSize), Matrix(_ColumnSize)
	{
		for (int i = 0; i < _ColumnSize; i++)
		{
			Matrix[i] = 0;
		}
	}

	void MatrixRand()
	{
		srand(time(nullptr));

		for (int i = 0; i < ColumnSize; i++)
		{
			Matrix[i] = rand() % 10;
		}
	}

	void MatrixShow()
	{
		if (Mode == "Row")
		{
			for (int i = 0; i < ColumnSize; i++)
			{
				cout << Matrix[i] << " ";
			}
			cout << endl << endl;
		}

		if (Mode == "Column")
		{
			for (int i = 0; i < ColumnSize; i++)
			{
				cout << Matrix[i] << endl;
			}
			cout << endl;
		}
	}

	int GetColumnSize()
	{
		return ColumnSize;
	}

	string GetMode()
	{
		return Mode;
	}

	void NormalizeSize()
	{
		ColumnSize = Matrix.size();
	}

	void Transporation()
	{
		if (Mode == "Row")
		{
			Mode = "Column";
			return;
		}

		if (Mode == "Column")
		{
			Mode = "Row";
		}
	}
};
const MatrixColumn ErrorVectorColumn(1);

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
			cout << "ћатрица не квадратна€! (будет возращена -1)" << endl << endl;
			return ErrorDouble;
		}

		return Determinant(_Matrix);
	}

	int GetRank()
	{
		return Rank(_Matrix);
	}
};
const Matrix ErrorMatrix(2, 2);


MatrixRow SumMatrix(MatrixRow Row_1, MatrixRow Row_2);
MatrixColumn SumMatrix(MatrixColumn Column_1, MatrixColumn Column_2);
Matrix SumMatrix(Matrix Matrix_1, Matrix Matrix_2);


MatrixRow MinusMatrix(MatrixRow Row_1, MatrixRow Row_2);
MatrixColumn MinusMatrix(MatrixColumn Column_1, MatrixColumn Column_2);
Matrix MinusMatrix(Matrix Matrix_1, Matrix Matrix_2);


MatrixRow MultiplicationMatrix(MatrixRow Row, double Value);
MatrixColumn MultiplicationMatrix(MatrixColumn Column, double Value);
Matrix MultiplicationMatrix(Matrix MainMatrix, double value);
Matrix MultiplicationMatrix(MatrixColumn Column, MatrixRow Row);
double MultiplicationMatrix(MatrixRow Row, MatrixColumn Column);
MatrixRow MultiplicationMatrix(MatrixRow Row, Matrix _Matrix);
Matrix MultiplicationMatrix(Matrix Matrix_1, Matrix Matrix_2);


MatrixRow DivisionMatrix(MatrixRow Row, double Value);
MatrixColumn DivisionMatrix(MatrixColumn Column, double Value);
Matrix DivisionMatrix(Matrix _Matrix, double Value);
