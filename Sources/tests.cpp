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

	//m.AddColumn(2, TempColumn);
	//m.MatrixShow();

	//m.SetElement(2, 3, 999);
	//m.MatrixShow();

	//cout << m.GetElement(2, 3) << endl << endl;

	//m.AppendRow(TempRow);
	//m.MatrixShow();
	//m.AppendRow(TempRow.GetVector());
	//m.MatrixShow();

	//m.AppendColumn(TempColumn);
	//m.MatrixShow();
	//m.AppendColumn(TempColumn.GetVector());
	//m.MatrixShow();

	m.AppendRow(TempRow);
	m.MatrixShow();
	cout << m.GetDeterminant() << endl << endl;
	m.AppendColumn(TempRow.GetVector());
	m.MatrixShow();

	m.RemoveColumn(4);
	m.MatrixShow();
	m.RemoveRow(2);
	m.MatrixShow();

	m.Clear();
	m.MatrixShow();

	vector <double> Temp{ 2 };

	m.AppendColumn(Temp);
	m.MatrixShow();
	m.AppendRow({ 1, 3 });
	cout << m.GetDeterminant() << endl << endl;
	cout << m.GetRank() << endl << endl;
	m.MatrixShow();
	m.AppendColumn({ 4, 5 });
	m.MatrixShow();
	cout << m.GetSizes()[0] << " " << m.GetSizes()[1] << endl << endl;

	m.Transporation();
	m.MatrixShow();

	cout << m.GetSizes()[0] << " " << m.GetSizes()[1] << endl << endl;
	cout << m.GetRank() << endl << endl;

	return 0;
}
