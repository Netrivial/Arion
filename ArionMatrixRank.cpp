#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


inline int Rank(vector<vector<double>> Matrix)
{
    int Row = Matrix.size(), Column = Matrix[0].size(), Rank = 0;
    
    if (Row == 0)
    {
        return 0;
    }


    for (int i = 0; i < Column; i++)
    {
        int PivotRow = -1;

        for (int j = Rank; j < Row; j++)
        {
            if (Matrix[j][i] != 0)
            {
                PivotRow = j;
                break;
            }
        }

        if (PivotRow == -1)
        {
            continue;
        }


        swap(Matrix[Rank], Matrix[PivotRow]);

        for (int j = Rank + 1; j < Row; j++)
        {
            double Factor = Matrix[j][i] / Matrix[Rank][i];

            for (int k = i; k < Column; k++)
            {
                Matrix[j][k] -= Factor * Matrix[Rank][k];
            }
        }

        Rank++;
    }

    return Rank;
}
