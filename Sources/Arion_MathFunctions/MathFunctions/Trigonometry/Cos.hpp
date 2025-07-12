#pragma once

#include "../Factorial.hpp"
using namespace std;


double long Cos(long double Value, bool IsDegree = true)
{
    long long Lim = 11;
    long double Sum = 0;

    if (!IsDegree)
    {
        if (fmod(Value / Pi, 1) == 0)
        {
            return pow(-1, Value / Pi);
        }
    }

    if (IsDegree)
    {
        if (Value >= 360)
        {
            Value -= 360 * ((int)Value / 360);
        }

        if (fmod(Value / 180, 1) == 0)
        {
            return pow(-1, Value / 180);
        }

        Value = Value * Pi / 180;
    }

    for (long long Count = 0; Count < Lim; Count++)
    {
        Sum += pow(-1, Count) * pow(Value, 2 * Count) / Factorial(2 * Count);
    }

    return Sum;
}