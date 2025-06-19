#include <iostream>
#include "Arion.hpp"
using namespace std;

int main()
{
	MatrixRow Row(7);
	MatrixColumn Column(7);
	Matrix _Matrix(4, 4);

	Row.MatrixRand();
	Row.MatrixShow();
	Column.MatrixRand();
	Column.MatrixShow();
	_Matrix.MatrixRand();
	_Matrix.MatrixShow();

	//cout << _Matrix.GetDeterminant() << endl << endl;
	//Matrix _Matrix_2 = MultiplicationMatrix(_Matrix, MultiplicationMatrix(_Matrix, _Matrix));
	//_Matrix_2.MatrixShow();

	//_Matrix = DivisionMatrix(_Matrix, 0);
	//_Matrix.MatrixShow();

	//Row.Transporation();
	//Column.Transporation();
	//Row.Transporation();
	//Column.Transporation();

	//int Test = MultiplicationMatrix(Row, Column);
	//cout << Test;

	//Matrix _Matrix_2 = MultiplicationMatrix(Column, Row);
	//_Matrix_2.MatrixShow();

	int matrix_1[3] = {
		1, 2, 3
	},
		matrix_2[4][4] = {
			{5, 3, 1, 2},
			{3, -1, 1, 2},
			{1, 2, 4, 8},
			{3, -1, 1, 2}
	};

	//MatrixRow Row_test_1(3);
	Matrix Matrix_test_2(4, 4);

	//for (int i = 0; i < Row_test_1.GetRowSize(); i++)
	//{
	//	Row_test_1.Matrix[i] = matrix_1[i];
	//}

	for (int i = 0; i < Matrix_test_2.GetColumnSize(); i++)
	{
		for (int j = 0; j < Matrix_test_2.GetRowSize(); j++)
		{
			Matrix_test_2._Matrix[i][j] = matrix_2[i][j];
		}
	}

	//Row_test_1.NormalizeSizes();
	//Row_test_1.MatrixRand();
	//Row_test_1.MatrixShow();
	//Matrix_test_2.MatrixRand();
	//Matrix_test_2.MatrixShow();

	//MatrixRow Matrix_test_3 = MultiplicationMatrix(Row_test_1, Matrix_test_2);
	//Matrix_test_3.MatrixShow();

	//Matrix_test_2.MatrixShow();
	//cout << Matrix_test_2.GetDeterminant() << endl << endl;
	//Matrix_test_2.Transporation();
	//Matrix_test_2.MatrixShow();
	//cout << Matrix_test_2.GetDeterminant() << endl << endl;
	//Matrix_test_2.Transporation();
	//Matrix_test_2.MatrixShow();
	//cout << Matrix_test_2.GetDeterminant() << endl << endl;
	
	//Matrix_test_2.MatrixRand();
	Matrix_test_2.MatrixShow();
	cout << Matrix_test_2.GetRank() << endl << endl;
	Matrix_test_2.Transporation();
	Matrix_test_2.MatrixShow();
	cout << Matrix_test_2.GetRank() << endl << endl;

	return 0;
}
