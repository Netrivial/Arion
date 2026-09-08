#include <Arion/Fraction/Fraction.hpp>

namespace Arion {
	namespace Fraction {

		// Constructs
		Fraction::Fraction(double Numerator, double Denominator) : Numerator(Numerator), Denominator(Denominator) {
			if (Denominator == 0) {
				throw std::invalid_argument("The denominator can't be equal to 0");
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
				throw std::invalid_argument("The denominator can't be equal to 0");
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
			double sign = (Numerator < 0) ? -1.0 : 1.0;

			const int maxIterations = 15;
			int iter = 0;
			while ((std::abs(num - std::round(num)) > Consts::doubleEps ||
					std::abs(den - std::round(den)) > Consts::doubleEps)
					&& iter < maxIterations) {
				num *= 10.0;
				den *= 10.0;
				++iter;
			}

			long long intNum = std::llround(num);
			long long intDen = std::llround(den);
			if (intDen == 0) {
				return;
			}

			long long gcd = std::gcd(intNum, intDen);
			Numerator = sign * (static_cast<double>(intNum) / gcd);
			Denominator = static_cast<double>(intDen) / gcd;
		}

		void Fraction::Pow(double Power) {
			Numerator = std::pow(Numerator, Power);
			Denominator = std::pow(Denominator, Power);
		}

		void Fraction::MultiplyBoth(double factor) {
			if (factor == 0) {
				throw std::invalid_argument("Factor cannot be zero");
			}
			Numerator *= factor;
			Denominator *= factor;
		}

		void Fraction::DivideBoth(double divisor) {
			if (divisor == 0) {
				throw std::invalid_argument("Divisor cannot be zero");
			}
			Numerator /= divisor;
			Denominator /= divisor;
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
			return tempFrac;
		}

		Fraction Fraction::operator-(Fraction other) {
			Fraction tempFrac{ this->Numerator * other.Denominator - other.Numerator * this->Denominator,
								this->Denominator * other.Denominator
			};
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

		bool Fraction::operator==(Fraction other) const {
			return std::abs(this->Division() - other.Division()) < Consts::doubleEps;
		}

		bool Fraction::operator!=(Fraction other) const {
			return std::abs(this->Division() - other.Division()) > Consts::doubleEps;
		}

		bool Fraction::operator<(Fraction other) const {
			return this->Division() < other.Division();
		}

		bool Fraction::operator<=(Fraction other) const {
			return this->Division() <= other.Division();
		}

		bool Fraction::operator>(Fraction other) const {
			return this->Division() > other.Division();
		}

		bool Fraction::operator>=(Fraction other) const {
			return this->Division() >= other.Division();
		}
	}
}