#include <iostream>
#include <vector>
#include "ArionMatrix.hpp"
#include "ArionConst.hpp"



MatrixRow SumMatrix(MatrixRow Row_1, MatrixRow Row_2)
{
	setlocale(LC_ALL, "Russian");
	MatrixRow MainRow(Row_1.GetRowSize());

	if (Row_1.GetRowSize() != Row_2.GetRowSize())
	{
		cout << "¬екторы разных размеров! (будет возращЄна нулева€ строка)" << endl << endl;
		return ErrorVectorRow;
	}

	for (int i = 0; i < Row_1.GetRowSize(); i++)
	{
		MainRow.Matrix[i] = Row_1.Matrix[i] + Row_2.Matrix[i];
	}

	return MainRow;
}

MatrixColumn SumMatrix(MatrixColumn Column_1, MatrixColumn Column_2)
{
	setlocale(LC_ALL, "Russian");
	MatrixColumn MainColumn(Column_1.GetColumnSize());

	if (Column_1.GetColumnSize() != Column_2.GetColumnSize())
	{
		cout << "¬екторы разных размеров! (будет возращЄн нулевой столбец)" << endl << endl;
		return ErrorVectorColumn;
	}

	for (int i = 0; i < Column_1.GetColumnSize(); i++)
	{
		MainColumn.Matrix[i] = Column_1.Matrix[i] + Column_2.Matrix[i];
	}

	return MainColumn;
}

Matrix SumMatrix(Matrix Matrix_1, Matrix Matrix_2)
{
	setlocale(LC_ALL, "Russian");
	Matrix MainMatrix(Matrix_1.GetColumnSize(), Matrix_1.GetRowSize());

	if (Matrix_1.GetColumnSize() != Matrix_2.GetColumnSize() || Matrix_1.GetRowSize() != Matrix_2.GetRowSize())
	{
		cout << "ћатрицы разных размеров! (будет возращена нулева€ матрица)" << endl << endl;
		return ErrorMatrix;
	}

	for (int i = 0; i < Matrix_1.GetColumnSize(); i++)
	{
		for (int j = 0; j < Matrix_1.GetRowSize(); j++)
		{
			MainMatrix._Matrix[i][j] = Matrix_1._Matrix[i][j] + Matrix_2._Matrix[i][j];
		}
	}

	return MainMatrix;
}



MatrixRow MinusMatrix(MatrixRow Row_1, MatrixRow Row_2)
{
	setlocale(LC_ALL, "Russian");
	MatrixRow MainRow(Row_1.GetRowSize());

	if (Row_1.GetRowSize() != Row_2.GetRowSize())
	{
		cout << "Ќевозможно произвести разность данных векторов! (будет возращЄна нулева€ строка)" << endl << endl;
		return ErrorVectorRow;
	}

	for (int i = 0; i < Row_1.GetRowSize(); i++)
	{
		MainRow.Matrix[i] = Row_1.Matrix[i] - Row_2.Matrix[i];
	}

	return MainRow;
}

MatrixColumn MinusMatrix(MatrixColumn Column_1, MatrixColumn Column_2)
{
	setlocale(LC_ALL, "Russian");
	MatrixColumn MainColumn(Column_1.GetColumnSize());

	if (Column_1.GetColumnSize() != Column_2.GetColumnSize())
	{
		cout << "Ќевозможно произвести разность данных векторов! (будет возращЄн нулевой столбец)" << endl << endl;
		return ErrorVectorColumn;
	}

	for (int i = 0; i < Column_1.GetColumnSize(); i++)
	{
		MainColumn.Matrix[i] = Column_1.Matrix[i] - Column_2.Matrix[i];
	}

	return MainColumn;
}

Matrix MinusMatrix(Matrix Matrix_1, Matrix Matrix_2)
{
	setlocale(LC_ALL, "Russian");
	Matrix MainMatrix(Matrix_1.GetColumnSize(), Matrix_2.GetRowSize());

	if (Matrix_1.GetColumnSize() != Matrix_2.GetColumnSize() || Matrix_1.GetRowSize() != Matrix_2.GetRowSize())
	{
		cout << "Ќевозможно произвести разность данных матриц! (будет возращена нулева€ матрица)" << endl << endl;
		return ErrorMatrix;
	}

	for (int i = 0; i < Matrix_1.GetColumnSize(); i++)
	{
		for (int j = 0; j < Matrix_1.GetRowSize(); j++)
		{
			MainMatrix._Matrix[i][j] = Matrix_1._Matrix[i][j] - Matrix_2._Matrix[i][j];
		}
	}

	return MainMatrix;
}



MatrixRow MultiplicationMatrix(MatrixRow Row, double Value)
{
	MatrixRow MainRow(Row.GetRowSize());

	for (int i = 0; i < Row.GetRowSize(); i++) {
		Row.Matrix[i] = Row.Matrix[i] * Value;
	}

	return MainRow;
}

MatrixColumn MultiplicationMatrix(MatrixColumn Column, double Value)
{
	MatrixColumn MainColumn(Column.GetColumnSize());

	for (int i = 0; i < Column.GetColumnSize(); i++) {
		Column.Matrix[i] = Column.Matrix[i] * Value;
	}

	return MainColumn;
}

Matrix MultiplicationMatrix(Matrix MainMatrix, double value)
{
	Matrix _MainMatrix(MainMatrix.GetColumnSize(), MainMatrix.GetRowSize());

	for (int i = 0; i < MainMatrix.GetColumnSize(); i++)
	{
		for (int j = 0; j < MainMatrix.GetRowSize(); j++)
		{
			_MainMatrix._Matrix[i][j] = MainMatrix._Matrix[i][j] * value;
		}
	}

	return _MainMatrix;
}

Matrix MultiplicationMatrix(MatrixColumn Matrix_1, MatrixRow Matrix_2)
{
	setlocale(LC_ALL, "Russian");
	Matrix MainMatrix(Matrix_1.GetColumnSize(), Matrix_2.GetRowSize());

	if (Matrix_1.GetColumnSize() != Matrix_2.GetRowSize() || Matrix_1.GetMode() != "Column" || Matrix_1.GetMode() == Matrix_2.GetMode())
	{
		cout << "“акие векторвы не могут быть умножены! (будет возращена нулива€ матрица)" << endl << endl;
		return ErrorMatrix;
	}

	for (int i = 0; i < Matrix_1.GetColumnSize(); i++)
	{
		for (int j = 0; j < Matrix_2.GetRowSize(); j++)
		{
			MainMatrix._Matrix[i][j] = Matrix_1.Matrix[i] * Matrix_2.Matrix[j];
		}
	}

	return MainMatrix;
}

double MultiplicationMatrix(MatrixRow Matrix_1, MatrixColumn Matrix_2)
{
	setlocale(LC_ALL, "Russian");

	double MainValue = 0;

	if (Matrix_1.GetRowSize() != Matrix_2.GetColumnSize() || Matrix_1.GetMode() != "Row" || Matrix_1.GetMode() == Matrix_2.GetMode())
	{
		cout << "“акие векторы не могут быть умножены! (будет возращена -1)" << endl << endl;
		return ErrorDouble;
	}

	for (int i = 0; i < Matrix_1.GetRowSize(); i++)
	{
		MainValue += Matrix_1.Matrix[i] * Matrix_2.Matrix[i];
	}

	return MainValue;
}

MatrixRow MultiplicationMatrix(MatrixRow Row, Matrix _Matrix)
{
	setlocale(LC_ALL, "Russian");
	MatrixRow MainRow(_Matrix.GetRowSize());

	if (Row.GetRowSize() != _Matrix.GetColumnSize() || Row.GetMode() != "Row")
	{
		cout << "ћатрицы разных размеров! (будет возращена нулева€ строка)" << endl << endl;

		return ErrorVectorRow;
	}

	for (int i = 0; i < _Matrix.GetRowSize(); i++)
	{
		for (int j = 0; j < Row.GetRowSize(); j++)
		{
			MainRow.Matrix[i] += Row.Matrix[j] * _Matrix._Matrix[j][i];
		}
	}

	return MainRow;
}

Matrix MultiplicationMatrix(Matrix Matrix_1, Matrix Matrix_2)
{
	setlocale(LC_ALL, "Russian");
	Matrix MainMatrix(Matrix_1.GetColumnSize(), Matrix_2.GetRowSize());

	if (Matrix_1.GetRowSize() != Matrix_2.GetColumnSize())
	{
		cout << "ћатрицы разных размеров! (будет возращена нулева€ матрица)" << endl << endl;

		return ErrorMatrix;
	}

	for (int i = 0; i < Matrix_1.GetColumnSize(); i++)
	{
		for (int j = 0; j < Matrix_2.GetRowSize(); j++)
		{
			for (int k = 0; k < Matrix_1.GetRowSize(); k++)
			{
				MainMatrix._Matrix[i][j] += Matrix_1._Matrix[i][k] * Matrix_2._Matrix[k][j];

			}
		}
	}

	return MainMatrix;
}



MatrixRow DivisionMatrix(MatrixRow Row, double Value)
{
	setlocale(LC_ALL, "Russian");

	if (Value == 0)
	{
		cout << "Ќа ноль делить нельз€! (будет возращена нулева€ строка)" << endl << endl;
		return ErrorVectorRow;
	}

	for (int i = 0; i < Row.GetRowSize(); i++)
	{
		Row.Matrix[i] = Row.Matrix[i] / Value;
	}

	return Row;
}

MatrixColumn DivisionMatrix(MatrixColumn Column, double Value)
{
	setlocale(LC_ALL, "Russian");

	if (Value == 0)
	{
		cout << "Ќа ноль делить нельз€! (будет возращЄн нулевой столбец)" << endl << endl;
		return ErrorVectorColumn;
	}

	for (int i = 0; i < Column.GetColumnSize(); i++)
	{
		Column.Matrix[i] = Column.Matrix[i] / Value;
	}

	return Column;
}

Matrix DivisionMatrix(Matrix _Matrix, double Value)
{
	setlocale(LC_ALL, "Russian");

	if (Value == 0)
	{
		cout << "Ќа ноль делить нельз€! (будет возращена нулева€ матрица)" << endl << endl;
		return ErrorMatrix;
	}

	for (int i = 0; i < _Matrix.GetColumnSize(); i++)
	{
		for (int j = 0; j < _Matrix.GetRowSize(); j++)
		{
			_Matrix._Matrix[i][j] = _Matrix._Matrix[i][j] / Value;
		}
	}

	return _Matrix;
}
