#pragma once

#include "../Factorial.hpp"
#include "../../../ArionConsts.hpp"
using namespace std;


long double Ctg(long double Value, bool IsDegree = true)
{
    long double Sum = 0;

    if (!IsDegree)
    {
        if (Value >= Pi)
        {
            Value -= Pi * (int)(Value / Pi);
        }

        if (fmod(Value / (Pi / 2), 1) == 0)
        {
            if ((int)(Value / (Pi / 2)) % 2 == 0)
            {
                return INF;
            }
            else
            {
                return 0;
            }
        }
    }

    if (IsDegree)
    {
        if (Value >= 180)
        {
            Value -= 180 * (int)(Value / 180);
        }

        if (fmod(Value / 90, 1) == 0)
        {
            if (((int)Value / 90) % 2 == 0)
            {
                return INF;
            }
            else
            {
                return 0;
            }
        }

        Value = Value * Pi / 180;
    }


    return Cos(Value, 0) / Sin(Value, 0);
}
