#pragma once

#include <iostream>
#include "Factorial.hpp"
using namespace std;


long double Exp(long double Value)
{
    long long Lim = 20;
    long double Sum = 0;

    for (long long Count = 0; Count < Lim; Count++)
    {
        Sum += (long double)pow(Value, Count) / (long double)Factorial(Count);
    }

    return Sum;
}
