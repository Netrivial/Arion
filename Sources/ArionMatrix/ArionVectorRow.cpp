#include "../ArionConsts.hpp"
#include "ArionMatrix.hpp"

using namespace ArionMatrix;


// Basic functions for working with row vectors

ArionMatrix::VectorRow::VectorRow() : _RowSize(MaxRow), _Vector(MaxRow)
{
	for (std::size_t Index = 0; Index < MaxRow; Index++)
	{
		_Vector[Index] = 0;
	}
}

ArionMatrix::VectorRow::VectorRow(int RowSize) : _RowSize(RowSize), _Vector(RowSize)
{
	for (std::size_t Index = 0; Index < _RowSize; Index++)
	{
		_Vector[Index] = 0;
	}
}

void ArionMatrix::VectorRow::VectorRand()
{
	srand(time(nullptr));

	for (std::size_t Index = 0; Index < _RowSize; Index++)
	{
		_Vector[Index] = rand() % 10;
	}
}

void ArionMatrix::VectorRow::NormalizeSize()
{
	_RowSize = _Vector.size();
}

void ArionMatrix::VectorRow::SetVector(std::vector<double> Vector)
{
	_Vector = Vector;
	NormalizeSize();
}

void ArionMatrix::VectorRow::AddElementByNumber(int Number, double Element) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		_Vector.insert(_Vector.begin() + Number - 1, Element);
		NormalizeSize();
	}
	catch (const std::out_of_range& Exception)
	{
		throw exception("Index out of range of possible row vector indices");
	}
	catch (...)
	{
		throw exception("Bad element");
	}
}

void ArionMatrix::VectorRow::VectorShow()
{
	if (_Type == "Row")
	{
		for (std::size_t Index = 0; Index < _RowSize; Index++)
		{
			std::cout << _Vector[Index] << " ";
		}
		std::cout << std::endl << std::endl;
	}

	if (_Type == "Column")
	{
		for (int i = 0; i < _RowSize; i++)
		{
			std::cout << _Vector[i] << std::endl;
		}
		std::cout << std::endl;
	}
}

int ArionMatrix::VectorRow::GetRowSize()
{
	return _RowSize;
}

double ArionMatrix::VectorRow::GetElementByNumber(int Number) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		return _Vector.at(Number - 1);
	}
	catch (const std::out_of_range& Exception)
	{
		throw exception("Index out of range of possible row vector indices");
	}
}

std::string ArionMatrix::VectorRow::GetType()
{
	return _Type;
}

void ArionMatrix::VectorRow::Clear()
{
	_Vector.clear();
	NormalizeSize();
}


// Functions for working with linear transformations

void ArionMatrix::VectorRow::Transporation()
{
	if (_Type == "Row")
	{
		_Type = "Column";
		return;
	}

	_Type = "Row";
}

double ArionMatrix::VectorRow::VectorNorm()
{
	double ScalarProduct = 0;

	for (std::size_t Index = 0; Index < _RowSize; Index++)
	{
		ScalarProduct += std::pow(_Vector[Index], 2);
	}

	return std::sqrt(ScalarProduct);
}