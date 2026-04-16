#include "ArionMatrix.hpp"
#include "../ArionConsts.hpp"

using namespace ArionMatrix;


// Basic functions for working with matrixes

ArionMatrix::Matrix::Matrix() : _RowSize(MaxRow), _ColumnSize(MaxRow), _Matrix(MaxColumn, std::vector <double>(MaxRow))
{
	for (size_t ColumnIndex = 0; ColumnIndex < _ColumnSize; ColumnIndex++)
	{
		std::vector <double> Temp;
		for (size_t RowIndex = 0; RowIndex < _RowSize; RowIndex++)
		{
			Temp.push_back(0);
		}
		_Matrix.push_back(Temp);
	}
}

ArionMatrix::Matrix::Matrix(int ColumnSize, int RowSize) : _RowSize(RowSize), _ColumnSize(ColumnSize), _Matrix(_ColumnSize, std::vector <double>(_RowSize))
{
	for (size_t ColumnIndex = 0; ColumnIndex < _ColumnSize; ColumnIndex++)
	{
		std::vector <double> Temp;
		for (int RowIndex = 0; RowIndex < _RowSize; RowIndex++)
		{
			Temp.push_back(0);
		}
		_Matrix.push_back(Temp);
	}
}

void ArionMatrix::Matrix::matrixrand()
{
	srand(time(nullptr));

	for (size_t ColumnIndex = 0; ColumnIndex < _ColumnSize; ColumnIndex++)
	{
		for (size_t RowIndex = 0; RowIndex < _RowSize; RowIndex++)
		{
			_Matrix[ColumnIndex][RowIndex] = rand() % 10;
		}
	}
}

void ArionMatrix::Matrix::NormalizeSizes()
{
	_RowSize = _Matrix[0].size();
	_ColumnSize = _Matrix.size();
}


// setters (Warning: Set/add rows and coloumn by number (not index!))
void ArionMatrix::Matrix::SetMatrix(std::vector <std::vector <double>> Matrix)
{
	_Matrix = Matrix;
	NormalizeSizes();
}

void ArionMatrix::Matrix::SetRowByNumber(int Number, std::vector <double> Row) // Attention: the number is not equal to the index! (number = index + 1)
{
	if (Row.size() != _RowSize)
	{
		throw std::exception("Invalid row vector size");
	}

	_Matrix[Number - 1] = Row;
}

void ArionMatrix::Matrix::SetRowByNumber(int Number, VectorRow Row) // Attention: the number is not equal to the index! (number = index + 1)
{
	if (Row.GetRowSize() != _RowSize)
	{
		throw std::exception("Invalid row vector size");
	}

	_Matrix[Number - 1] = Row.GetVector();
}

void ArionMatrix::Matrix::SetColumnByNumber(int Number, std::vector<double> Column) // Attention: the number is not equal to the index! (number = index + 1)
{
	if (Column.size() != _ColumnSize)
	{
		throw std::exception("Invalid column vector size");
	}

	_Matrix[Number - 1] = Column;
}

void ArionMatrix::Matrix::SetColumnByNumber(int Number, VectorColumn Column)
{
	if (Column.GetColumnSize() != _ColumnSize)
	{
		throw std::exception("Invalid row vector size");
	}

	_Matrix[Number - 1] = Column.GetVector();
}

// getters
// ...

void ArionMatrix::Matrix::AddRowByNumber(int Number, std::vector <double> Row)
{
	std::vector <std::vector <double>> Temp;
	// ...
}
