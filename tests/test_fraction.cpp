#include <iostream>
#include <cassert>
#include <iomanip>
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

    Fraction::Fraction fracFromInt{ Fraction::GetFraction<double>(tempInt) };
    std::cout << fracFromInt << std::endl;
    //fracFromInt.Reducing();
    //fracFromInt.Show();
    //std::cout << fracFromInt.GetNumerator() << std::endl;
    //std::cout << fracFromInt.GetDenominator() << std::endl;
    //std::cout << fracFromInt.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    Fraction::Fraction fracFromDouble{ Fraction::GetFraction(tempDouble) };
    std::cout << fracFromDouble << std::endl;
    std::cout << std::endl;
    //fracFromDouble.Reducing();
    //fracFromDouble.Show();
    //std::cout << fracFromDouble.GetNumerator() << std::endl;
    //std::cout << fracFromDouble.GetDenominator() << std::endl;
    //std::cout << fracFromDouble.Division() << std::endl;
    //std::cout << std::endl << std::endl;

    fracFromInt = -fracFromInt;
    std::cout << fracFromInt << std::endl;
    std::cout << std::endl;

    fracFromInt++;
    std::cout << fracFromInt << std::endl;
    fracFromDouble--;
    std::cout << fracFromDouble << std::endl;
    fracFromDouble++;
    std::cout << fracFromDouble << std::endl;;

    std::cout << std::endl;

    fracFromDouble.Reducing();
    std::cout << fracFromDouble << std::endl;
    fracFromDouble--;
    std::cout << fracFromDouble << std::endl;

    std::cout << std::endl;

    Fraction::Fraction sumOfFracs{ fracFromInt + fracFromDouble };
    std::cout << sumOfFracs << std::endl;
    std::cout << sumOfFracs.Division() << std::endl;
    std::cout << sumOfFracs.Division() + fracFromDouble - fracFromInt << std::endl;

    Fraction::Fraction value{ 3, -2 };
    Fraction::Fraction someVal = Fraction::GetFraction((fracFromInt - fracFromDouble + fracFromDouble * fracFromInt - 2 * value) / (9 / (value / 3)));
    std::cout << someVal / value << std::endl;
    std::cout << (someVal / value).Division() << std::endl;
    // yo -> std::setprecision(15)

    return 0;
}