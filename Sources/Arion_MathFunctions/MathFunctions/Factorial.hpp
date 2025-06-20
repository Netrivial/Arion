#pragma once

#include <iostream>
using namespace std;


unsigned long long int Factorial(int Value)
{
	setlocale(LC_ALL, "Russian");

	if (Value < 0)
	{
		cout << "Аргумент не может быть отрицательным! (будет возращён 0)" << endl << endl;
	
		return 0;
	}

	unsigned long long int Result = 1;

	if (Value == 0)
	{
		return 1;
	}
	else
	{
		for (int Count = 1; Count < Value + 1; Count++)
		{
			Result *= Count;
		}
	}
	
	return Result;

}
