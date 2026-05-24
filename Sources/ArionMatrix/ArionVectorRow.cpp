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


// setters
void ArionMatrix::VectorRow::SetVector(std::vector<double> Vector)
{
	_Vector = Vector;
	NormalizeSize();
}


// getters
int ArionMatrix::VectorRow::GetRowSize()
{
	return _RowSize;
}

std::vector <double> ArionMatrix::VectorRow::GetVector()
{
	return _Vector;
}

double ArionMatrix::VectorRow::GetElementByNumber(int Number) // Attention: the number is not equal to the index! (number = index + 1)
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

std::string ArionMatrix::VectorRow::GetType()
{
	return _Type;
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
		throw std::exception("Index out of range of possible row vector indices");
	}
}

void ArionMatrix::VectorRow::Append(double Element)
{
	_Vector.push_back(Element);
	NormalizeSize();
}

void ArionMatrix::VectorRow::RemoveElementByNumber(int Number) // Attention: the number is not equal to the index! (number = index + 1)
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

void ArionMatrix::VectorRow::VectorShow()
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

void ArionMatrix::VectorRow::Reverse()
{
	std::reverse(_Vector.begin(), _Vector.end());
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

double ArionMatrix::VectorRow::ManhattanNorm()
{
	double Sum = 0;

	for (double Element : _Vector)
	{
		Sum += std::abs(Element);
	}

	return Sum;
}

double ArionMatrix::VectorRow::VectorNorm()
{
	double ScalarProduct = 0;

	for (double Element : _Vector)
	{
		ScalarProduct += std::pow(Element, 2);
	}

	return std::sqrt(ScalarProduct);
}

double ArionMatrix::VectorRow::VectorNormL_p(int p) // for the future std::pow(Sum, 1.0 / p) ~ AMF::exp(AMF::log(Sum) * 1.0 / p)
{
	long double Sum = 0;

	for (double Element : _Vector)
	{
		Sum += std::pow(std::abs(Element), p);
	}

	return std::pow(Sum, 1.0 / p);
	// return std::exp(std::log(Sum) * (1.0 / p));
}

double ArionMatrix::VectorRow::ChebyshevNorm()
{
	double MaxElement = *std::max_element(_Vector.begin(), _Vector.end());
	return MaxElement;
}
