// Fraction module

#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <numeric>

namespace Arion {
	namespace Fraction {

		class Fraction {
			double Numerator;
			double Denominator;

		public:
				// Constructors
			Fraction() = delete;
			Fraction(double Numerator, double Denominator);
			Fraction(const Fraction& other);
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


				// Operations with fracions
			friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
				os << frac.Numerator << "/" << frac.Denominator;
				return os;
			}

			Fraction& operator=(const Fraction& other);
			
			Fraction operator-() const;
			Fraction& operator++();
			Fraction operator++(int);
			Fraction& operator--();
			Fraction operator--(int);

			Fraction operator+(Fraction other);

			template <typename T>
			friend auto operator+(const Fraction& frac, const T& other) {
				return frac.Division() + other;
			}

			template <typename T>
			friend auto operator+(const T& other, const Fraction& frac) {
				return frac.Division() + other;
			}

			Fraction operator-(Fraction other);

			template <typename T>
			friend auto operator-(const Fraction& frac, const T& other) {
				return frac.Division() - other;
			}

			template <typename T>
			friend auto operator-(const T& other, const Fraction& frac) {
				return other - frac.Division();
			}

			Fraction operator*(Fraction other);

			template <typename T>
			friend auto operator*(const Fraction& frac, const T& other) {
				return frac.Numerator * other / frac.Denominator;
			}

			template <typename T>
			friend auto operator*(const T& other, const Fraction& frac) {
				return frac.Numerator * other / frac.Denominator;
			}

			Fraction operator/(Fraction other);

			template <typename T>
			friend auto operator/(const Fraction& frac, const T& other) {
				return frac.Numerator / (frac.Denominator * other);
			}

			template <typename T>
			friend auto operator/(const T& other, const Fraction& frac) {
				return other * frac.Denominator / frac.Numerator;
			}


			bool operator==(Fraction other);

			template <typename T>
			friend bool operator==(Fraction& frac, const T& other) {
				return frac.Division() == other;
			}

			template <typename T>
			friend bool operator==(const T& other, Fraction& frac) {
				return frac.Division() == other;
			}

			bool operator!=(Fraction other);
		};

		template <typename T>
		Fraction GetFraction(T value) {
			return Fraction { value, 1 };
		}
	}
}