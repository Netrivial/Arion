#pragma once

#include <iostream>
#include "Factorial.hpp"
using namespace std;


unsigned long long int Subfactorial(int Value)
{
    setlocale(LC_ALL, "Russian");

    if (Value < 0)
    {
        cout << "Аргумент не может быть отрицательным! (будет возращён 0)" << endl << endl;

        return 0;
    }

    long double Result = 1;

    if (Value == 0)
    {
        return 1;
    }
    else
    {
        for (int Count = 1; Count < Value + 1; Count++)
        {
            Result += pow(-1, Count) / Factorial(Count);
        }
    }

    return Result * Factorial(Value);
}

