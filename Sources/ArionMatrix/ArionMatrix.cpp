#include "ArionMatrix.hpp"

using namespace ArionMatrix;


// Basic functions for working with matrixes

ArionMatrix::Matrix::Matrix() : _RowSize(0), _ColumnSize(0)
{
	//for (size_t ColumnIndex = 0; ColumnIndex < _ColumnSize; ColumnIndex++)
	//{
	//	std::vector <double> Temp;
	//	for (size_t RowIndex = 0; RowIndex < _RowSize; RowIndex++)
	//	{
	//		Temp.push_back(0);
	//	}
	//	_Matrix.push_back(Temp);
	//}
}

ArionMatrix::Matrix::Matrix(int ColumnSize, int RowSize) : _RowSize(RowSize), _ColumnSize(ColumnSize)
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

void ArionMatrix::Matrix::MatrixRand()
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
	// set matrix
void ArionMatrix::Matrix::SetMatrix(std::vector <std::vector <double>> Matrix)
{
	_Matrix = Matrix;
	NormalizeSizes();
}

	// set row
void ArionMatrix::Matrix::SetRow(int Number, std::vector <double> Row) // Attention: the number is not equal to the index! (number = index + 1)
{
	if (Row.size() != _RowSize)
	{
		throw std::exception("Invalid row vector size");
	}

	_Matrix[Number - 1] = Row;
}

void ArionMatrix::Matrix::SetRow(int Number, VectorRow Row) // Attention: the number is not equal to the index! (number = index + 1)
{
	if (Row.GetRowSize() != _RowSize)
	{
		throw std::exception("Invalid row vector size");
	}

	_Matrix[Number - 1] = Row.GetVector();
}

	// set column
void ArionMatrix::Matrix::SetColumn(int Number, std::vector <double> Column) // Attention: the number is not equal to the index! (number = index + 1)
{
	if (Column.size() != _ColumnSize)
	{
		throw std::exception("Invalid column vector size");
	}

	for (std::size_t Index = 0; Index < _RowSize; Index++)
	{
		_Matrix[Index][Number - 1] = Column[Index];
	};
}

void ArionMatrix::Matrix::SetColumn(int Number, VectorColumn Column) // Attention: the number is not equal to the index! (number = index + 1)
{
	if (Column.GetColumnSize() != _ColumnSize)
	{
		throw std::exception("Invalid column vector size");
	}

	std::vector <double> _Column = Column.GetVector();
	for (std::size_t Index = 0; Index < _RowSize; Index++)
	{
		_Matrix[Index][Number - 1] = _Column[Index];
	};
}

	// set element
void ArionMatrix::Matrix::SetElement(int RowNumber, int ColumnNumber, double Element) // Attention: the RowNumber and the ColumnNumber are not equal to the indexes! (number = index + 1)
{
	_Matrix[RowNumber - 1].insert(_Matrix[RowNumber - 1].begin() + ColumnNumber - 1, Element);
}


// getters (Warning: Get rows and coloumn by number (not index!))
int ArionMatrix::Matrix::GetRowSize()
{
	return _RowSize;
}

int ArionMatrix::Matrix::GetColumnSize()
{
	return _ColumnSize;
}

std::vector <int> ArionMatrix::Matrix::GetSizes()
{
	std::vector<int> Sizes = { _ColumnSize, _RowSize };
	return Sizes;
}

	// get matrix
std::vector<std::vector<double>> ArionMatrix::Matrix::GetMatrix()
{
	return _Matrix;
}

	// get row
std::vector <double> ArionMatrix::Matrix::GetVectorRow(int Number)  // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		return _Matrix[Number - 1];
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible matrix indices");
	}
}

ArionMatrix::VectorRow ArionMatrix::Matrix::GetRow(int Number) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		VectorRow Vector;
		Vector.SetVector(_Matrix[Number - 1]);
		return Vector;
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible matrix indices");
	}
}

	// get column
std::vector <double> ArionMatrix::Matrix::GetVectorColumn(int Number) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		std::vector <double> Vector;

		for (std::vector <double> Row : _Matrix)
		{
			Vector.push_back(Row[Number - 1]);
		}
		
		return Vector;
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible matrix indices");
	}
}

ArionMatrix::VectorColumn ArionMatrix::Matrix::GetColumn(int Number) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		VectorColumn Vector = {};

		for (std::vector <double> Row : _Matrix)
		{
			Vector.Append(Row[Number - 1]);
		}

		return Vector;
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible matrix indices");
	}
}

	// get element
double ArionMatrix::Matrix::GetElement(int RowNumber, int ColumnNumber) // Attention: the RowNumber and the ColumnNumber are not equal to the indexes! (number = index + 1)
{
	return _Matrix[RowNumber - 1][ColumnNumber - 1];
}


void ArionMatrix::Matrix::AddRow(int Number, std::vector <double> Row) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		_Matrix.insert(_Matrix.begin() + Number - 1, Row);
		NormalizeSizes();
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible Matrix indices");
	}
	
}

void ArionMatrix::Matrix::AddRow(int Number, VectorRow Row) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		_Matrix.insert(_Matrix.begin() + Number - 1, Row.GetVector());
		NormalizeSizes();
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible Matrix indices");
	}
}

void ArionMatrix::Matrix::AddColumn(int Number, std::vector<double> Column) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		for (size_t Index = 0; Index < Column.size(); Index++)
		{
			_Matrix[Index].insert(_Matrix[Index].begin() + Number - 1, Column[Index]);
		}
		NormalizeSizes();
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible Matrix indices");
	}
}

void ArionMatrix::Matrix::AddColumn(int Number, VectorColumn Column) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		for (size_t Index = 0; Index < Column.GetColumnSize(); Index++)
		{
			_Matrix[Index].insert(_Matrix[Index].begin() + Number - 1, Column.GetVector()[Index]);
		}
		NormalizeSizes();
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible Matrix indices");
	}
}