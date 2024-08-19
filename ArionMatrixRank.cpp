#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


inline int Rank(vector <vector <double>> Matrix)
{
	int n = Matrix.size();
	int m = Matrix[0].size() - 1;

	vector <int> where (m, -1);

	for (int col = 0, row = 0; col < m && row < n; col++)
	{
		int sel = row;

		for (int i = row; i < n; i++)
		{
			if (abs(Matrix[i][col]) > abs(Matrix[sel][col]))
			{
				sel = i;
			}
		}

		if (abs(Matrix[sel][col]) < EPS)
		{
			continue;
		}

	}
}
