#include <iostream>
#include "Arion.hpp"

using namespace std;
using namespace ArionMatrix;

int main()
{
	VectorRow Vec1;
	//Vec1.VectorRand();
	//Vec1.VectorShow();

	vector<double> myvec{1, 2, 3, 4, 6};
	Vec1.SetVector(myvec);
	Vec1.VectorShow();

	Vec1.AddElementByNumber(5, 5);
	Vec1.VectorShow();

	Vec1.Append(7);
	Vec1.VectorShow();

	//cout << endl << Vec1.GetRowSize() << endl;

	//cout << endl << Vec1.GetElementByNumber(4) << endl;

	//cout << endl << Vec1.GetType() << endl;

	//Vec1.Transporation();
	//Vec1.VectorShow();
	//cout << endl << Vec1.GetType() << endl;

	//cout << endl << Vec1.VectorNorm() << endl;

	Vec1.Reverse();
	Vec1.VectorShow();

	Vec1.RemoveElementByNumber(4);
	Vec1.VectorShow();

	//Vec1.Clear();
	//Vec1.VectorShow();

	//Vec1.Append(6);
	//Vec1.VectorShow();

	//Vec1.Reverse();
	//Vec1.VectorShow();

	return 0;
}
