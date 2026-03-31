#include "../ArionConsts.hpp"
#include "ArionMatrix.hpp"

using namespace ArionMatrix;


// Basic functions for working with row vectors

ArionMatrix::VectorColumn::VectorColumn() : _ColumnSize(MaxColumn), _Vector(MaxColumn)
{
	for (std::size_t Index = 0; Index < MaxColumn; Index++)
	{
		_Vector[Index] = 0;
	}
}

ArionMatrix::VectorColumn::VectorColumn(int ColumnSize) : _ColumnSize(ColumnSize), _Vector(ColumnSize)
{
	for (std::size_t Index = 0; Index < _ColumnSize; Index++)
	{
		_Vector[Index] = 0;
	}
}

void ArionMatrix::VectorColumn::VectorRand()
{
	srand(time(nullptr));

	for (std::size_t Index = 0; Index < _ColumnSize; Index++)
	{
		_Vector[Index] = rand() % 10;
	}
}

void ArionMatrix::VectorColumn::NormalizeSize()
{
	_ColumnSize = _Vector.size();
}

void ArionMatrix::VectorColumn::SetVector(std::vector<double> Vector)
{
	_Vector = Vector;
	NormalizeSize();
}

void ArionMatrix::VectorColumn::AddElementByNumber(int Number, double Element) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		_Vector.insert(_Vector.begin() + Number - 1, Element);
		NormalizeSize();
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible row vector indices");
	}
}

void ArionMatrix::VectorColumn::Append(double Element)
{
	_Vector.push_back(Element);
	NormalizeSize();
}

void ArionMatrix::VectorColumn::RemoveElementByNumber(int Number) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		_Vector.erase(_Vector.begin() + Number - 1);
		NormalizeSize();

	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible row vector indices");
	}
}

void ArionMatrix::VectorColumn::VectorShow()
{
	if (_Type == "Row")
	{
		for (double Element : _Vector)
		{
			std::cout << Element << " ";
		}
		std::cout << std::endl << std::endl;
	}

	if (_Type == "Column")
	{
		for (double Element : _Vector)
		{
			std::cout << Element << std::endl;
		}
		std::cout << std::endl;
	}
}

int ArionMatrix::VectorColumn::GetColumnSize()
{
	return _ColumnSize;
}

double ArionMatrix::VectorColumn::GetElementByNumber(int Number) // Attention: the number is not equal to the index! (number = index + 1)
{
	try
	{
		return _Vector.at(Number - 1);
	}
	catch (const std::out_of_range& Exception)
	{
		throw std::exception("Index out of range of possible row vector indices");
	}
}

std::string ArionMatrix::VectorColumn::GetType()
{
	return _Type;
}

void ArionMatrix::VectorColumn::Reverse()
{
	std::reverse(_Vector.begin(), _Vector.end());
}

void ArionMatrix::VectorColumn::Clear()
{
	_Vector.clear();
	NormalizeSize();
}


// Functions for working with linear transformations

void ArionMatrix::VectorColumn::Transporation()
{
	if (_Type == "Row")
	{
		_Type = "Column";
		return;
	}

	_Type = "Row";
}

double ArionMatrix::VectorColumn::ManhattanNorm()
{
	double Sum = 0;

	for (double Element : _Vector)
	{
		Sum += std::abs(Element);
	}

	return Sum;
}

double ArionMatrix::VectorColumn::VectorNorm()
{
	double ScalarProduct = 0;

	for (double Element : _Vector)
	{
		ScalarProduct += std::pow(Element, 2);
	}

	return std::sqrt(ScalarProduct);
}
 
double ArionMatrix::VectorColumn::VectorNormL_p(int p) // for the future std::pow(Sum, 1.0 / p) ~ AMF::exp(AMF::log(Sum) * 1.0 / p)
{
	long double Sum = 0;

	for (double Element : _Vector)
	{
		Sum += std::pow(std::abs(Element), p);
	}

	return std::pow(Sum, 1.0 / p);
	// return std::exp(std::log(Sum) * (1.0 / p));
}
