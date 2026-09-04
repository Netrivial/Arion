#include "Arion/Fraction/Fraction.hpp"

namespace Arion {
		// Constructs
	Fraction::Fraction::Fraction(double Numerator, double Denominator) : Numerator(Numerator), Denominator(Denominator) {
		if (Denominator == 0.f) {
			throw std::exception("The denominator can't be equal to 0");
		}

		if (Denominator < 0) {
			this->Numerator = -Numerator;
			this->Denominator = -Denominator;
		}
	}

	Fraction::Fraction::Fraction(Fraction& other) : Numerator(other.Numerator), Denominator(other.Denominator) {}

	//Fraction::Fraction::Fraction(Fraction&& other) noexcept;


		// Setters
	void Fraction::Fraction::SetNumerator(double Numerator) {
		this->Numerator = Numerator;
	}

	void Fraction::Fraction::SetDenominator(double Denominator) {
		if (Denominator == 0) {
			throw std::exception("The denominator can't be equal to 0");
		}
		
		if (Denominator < 0) {
			Numerator = -Numerator;
			this->Denominator = -Denominator;
		}
		else {
			this->Denominator = Denominator;
		}
	}


		// Getter
	double Fraction::Fraction::GetNumerator() const {
		return Numerator;
	}

	double Fraction::Fraction::GetDenominator() const {
		return Denominator;
	}


		// Other function
	double Fraction::Fraction::Division() const noexcept{
		return Numerator / Denominator;
	}

	void Fraction::Fraction::Reducing() {
		while (std::floor(Numerator) != Numerator || std::floor(Denominator) != Denominator) {
			Numerator *= 10;
			Denominator *= 10;
		}

		auto gcd = std::gcd(std::abs((int)Numerator), std::abs((int)Denominator));	
		Numerator /= gcd;
		Denominator /= gcd;
	}

	void Fraction::Fraction::Show() const {
		std::cout << Numerator << "/" << Denominator << std::endl;
	}
}