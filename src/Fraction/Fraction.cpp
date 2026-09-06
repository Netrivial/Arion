#include <Arion/Fraction/Fraction.hpp>
#include <Arion/Consts.hpp>

namespace Arion {
	namespace Fraction {

		// Constructs
		Fraction::Fraction(double Numerator, double Denominator) : Numerator(Numerator), Denominator(Denominator) {
			if (Denominator == 0.f) {
				throw std::exception("The denominator can't be equal to 0");
			}

			if (Denominator < 0) {
				this->Numerator = -Numerator;
				this->Denominator = -Denominator;
			}
		}

		Fraction::Fraction(const Fraction& other) : Numerator(other.Numerator), Denominator(other.Denominator) {}

		//Fraction::Fraction(Fraction&& other) noexcept;


			// Setters
		void Fraction::SetNumerator(double Numerator) {
			this->Numerator = Numerator;
		}

		void Fraction::SetDenominator(double Denominator) {
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
		double Fraction::GetNumerator() const {
			return Numerator;
		}

		double Fraction::GetDenominator() const {
			return Denominator;
		}


		// Other function
		double Fraction::Division() const noexcept {
			return Numerator / Denominator;
		}

		void Fraction::Reducing() {
			double num = std::abs(Numerator);
			double den = std::abs(Denominator);

			while (std::abs(num - std::round(num)) > Consts::doubleEps || std::abs(den - std::round(den)) > Consts::doubleEps) {
				num *= 10.0;
				den *= 10.0;
			}

			long long int_n = std::round(num);
			long long int_d = std::round(den);

			long long gcd = std::gcd(int_n, int_d);

			//while (std::floor(Numerator) != Numerator || std::floor(Denominator) != Denominator) {
			//	Numerator *= 10;
			//	Denominator *= 10;
			//}

			//auto gcd = std::gcd(std::abs((int)Numerator), std::abs((int)Denominator));
			Numerator /= gcd;
			Denominator /= gcd;
		}


		// Operations with fracions
		Fraction& Fraction::operator=(const Fraction& other)
		{
			if (this == &other) {
				return *this;
			}

			this->Numerator = other.Numerator;
			this->Denominator = other.Denominator;
			return *this;
		}

		Fraction Fraction::operator-() const {
			return Fraction{ -Numerator, Denominator };
		}

		Fraction& Fraction::operator++() {
			Numerator += Denominator;
			return *this;
		}

		Fraction Fraction::operator++(int) {
			Fraction old = *this;
			Numerator += Denominator;
			return old;
		}

		Fraction& Fraction::operator--() {
			Numerator -= Denominator;
			return *this;
		}

		Fraction Fraction::operator--(int) {
			Fraction old = *this;
			Numerator -= Denominator;
			return old;
		}

		Fraction Fraction::operator+(Fraction other) {
			Fraction tempFrac{ this->Numerator * other.Denominator + other.Numerator * this->Denominator,
								this->Denominator * other.Denominator
			};
			tempFrac.Reducing();
			return tempFrac;
		}

		Fraction Fraction::operator-(Fraction other) {
			Fraction tempFrac{ this->Numerator * other.Denominator - other.Numerator * this->Denominator,
								this->Denominator * other.Denominator
			};
			tempFrac.Reducing();
			return tempFrac;
		}

		Fraction Fraction::operator*(Fraction other) {
			Fraction frac{ this->Numerator * other.Numerator, this->Denominator * other.Denominator };
			// frac.Reducing();
			return frac;
		}

		Fraction Fraction::operator/(Fraction other) {
			Fraction frac{ this->Numerator * other.Denominator, this->Denominator * other.Numerator };
			// frac.Reducing();
			return frac;
		}

		bool Fraction::operator==(Fraction other) {
			return this->Numerator / this->Denominator == other.Division();
		}
	}
}