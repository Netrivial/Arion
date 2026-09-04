#include <iostream>
#include <cassert>
#include <Arion/Fraction/Fraction.hpp>

int main() {
    using namespace Arion;

    Fraction::Fraction myFrac{-1, -1};
    myFrac.Show();
    std::cout << myFrac.GetNumerator() << std::endl;
    std::cout << myFrac.GetDenominator() << std::endl;
    std::cout << myFrac.Division() << std::endl;
    std::cout << std::endl << std::endl;

    myFrac.SetNumerator(3);
    myFrac.SetDenominator(-2);
    myFrac.Show();
    std::cout << myFrac.GetNumerator() << std::endl;
    std::cout << myFrac.GetDenominator() << std::endl;
    std::cout << myFrac.Division() << std::endl;
    std::cout << std::endl << std::endl;

    myFrac.SetNumerator(3.5);
    myFrac.SetDenominator(2.75);
    myFrac.Show();
    std::cout << myFrac.GetNumerator() << std::endl;
    std::cout << myFrac.GetDenominator() << std::endl;
    std::cout << myFrac.Division() << std::endl;
    std::cout << std::endl << std::endl;

    myFrac.SetNumerator(3.5);
    myFrac.SetDenominator(2.75);
    myFrac.Show();
    myFrac.Reducing();
    myFrac.Show();
    std::cout << myFrac.GetNumerator() << std::endl;
    std::cout << myFrac.GetDenominator() << std::endl;
    std::cout << myFrac.Division() << std::endl;
    std::cout << std::endl << std::endl;

    return 0;
}