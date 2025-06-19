#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


inline double Determinant(vector <vector <double>> Matrix)
{
	int Det = 0, SizeMatrix = Matrix[0].size(), Position;

	if (SizeMatrix == 1)
	{
		return Matrix[0][0];
	}
	else if (SizeMatrix == 2)
	{
		return (Matrix[0][0] * Matrix[1][1]) - (Matrix[0][1] * Matrix[1][0]);
	}
	else if (SizeMatrix >= 3)
	{
		for (Position = 0; Position < SizeMatrix; Position++)
		{
			vector <vector <double>> Minor;


			for (int i = 1; i < SizeMatrix; i++)
			{
				vector <double> Temp;


				for (int j = 0; j < SizeMatrix; j++)
				{
					if (j != Position)
					{
						Temp.push_back(Matrix[i][j]);
					}
				}

				Minor.push_back(Temp);
			}

			Det += pow((-1), Position + 2) * Matrix[0][Position] * Determinant(Minor);
		}

		return Det;
	}
}
