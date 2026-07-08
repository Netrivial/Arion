#include <iostream>
#include "Arion.hpp"

using namespace std;
using namespace ArionMatrix;

int main()
{
	Matrix m{2, 3};
	m.MatrixRand();
	m.MatrixShow();

	VectorRow TempRow = m.GetRow(2);
	TempRow.VectorShow();

	VectorColumn TempColumn = m.GetColumn(2);
	TempColumn.VectorShow();

	//m.AddRow(1, TempRow.GetVector());
	//m.MatrixShow();

	m.AddColumn(2, TempColumn);
	m.MatrixShow();

	m.SetElement(2, 3, 999);
	m.MatrixShow();

	cout << m.GetElement(2, 3) << endl << endl;

	return 0;
}
