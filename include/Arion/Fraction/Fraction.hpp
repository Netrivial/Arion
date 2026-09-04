// Fraction module

#pragma once
#include <iostream>
#include <cmath>
#include <numeric>

namespace Arion {
	namespace Fraction {

		class Fraction {
			double Numerator;
			double Denominator;

		public:
				// Constructs
			Fraction() = delete;
			Fraction(double Numerator, double Denominator);
			Fraction(Fraction& other);
			// Fraction(Fraction&& other) noexcept;


				//	Setters
			void SetNumerator(double Numerator);
			void SetDenominator(double Denominator);


				// Getters
			double GetNumerator() const;
			double GetDenominator() const;


				// Other functions
			double Division() const noexcept;
			void Reducing();
			void Show() const;
		};
	}
}