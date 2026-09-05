#include <iostream>
#include <cassert>
#include <Arion/Fraction/Fraction.hpp>

int main() {
    using namespace Arion;

    //Fraction::Fraction myFrac{-1, -1};
    //myFrac.Show();
    //std::cout << myFrac.GetNumerator() << std::endl;
    //std::cout << myFrac.GetDenominator() << std::endl;
    //std::cout << myFrac.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    //myFrac.SetNumerator(3);
    //myFrac.SetDenominator(-2);
    //myFrac.Show();
    //std::cout << myFrac.GetNumerator() << std::endl;
    //std::cout << myFrac.GetDenominator() << std::endl;
    //std::cout << myFrac.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    //myFrac.SetNumerator(3.5);
    //myFrac.SetDenominator(2.75);
    //myFrac.Show();
    //std::cout << myFrac.GetNumerator() << std::endl;
    //std::cout << myFrac.GetDenominator() << std::endl;
    //std::cout << myFrac.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    //myFrac.SetNumerator(3.5);
    //myFrac.SetDenominator(2.75);
    //myFrac.Show();
    //myFrac.Reducing();
    //myFrac.Show();
    //std::cout << myFrac.GetNumerator() << std::endl;
    //std::cout << myFrac.GetDenominator() << std::endl;
    //std::cout << myFrac.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    int tempInt = 8;
    double tempDouble = 3.5;

    Fraction::Fraction fracFromInt { Fraction::GetFraction<double>(tempInt) };
    fracFromInt.Show();
    //fracFromInt.Reducing();
    //fracFromInt.Show();
    //std::cout << fracFromInt.GetNumerator() << std::endl;
    //std::cout << fracFromInt.GetDenominator() << std::endl;
    //std::cout << fracFromInt.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    Fraction::Fraction fracFromDouble{ Fraction::GetFraction(tempDouble)};
    fracFromDouble.Show();
    std::cout << std::endl;
    //fracFromDouble.Reducing();
    //fracFromDouble.Show();
    //std::cout << fracFromDouble.GetNumerator() << std::endl;
    //std::cout << fracFromDouble.GetDenominator() << std::endl;
    //std::cout << fracFromDouble.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    fracFromInt = -fracFromInt;
    fracFromInt.Show();
    std::cout << std::endl;

    fracFromInt++;
    fracFromInt.Show();
    fracFromDouble--;
    fracFromDouble.Show();
    fracFromDouble++;
    fracFromDouble.Show();

    std::cout << std::endl;

    fracFromDouble.Reducing();
    fracFromDouble.Show();
    fracFromDouble--;
    fracFromDouble.Show();

    std::cout << std::endl;

    Fraction::Fraction sumOfFracs{ fracFromInt + fracFromDouble };
    sumOfFracs.Show();
    std::cout << sumOfFracs.Division() << std::endl;
    std::cout << sumOfFracs.Division() + fracFromDouble - fracFromInt << std::endl;

    return 0;
}