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
			void Show() const;


				// Operations with fracions
			friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
				os << f.Numerator << "/" << f.Denominator;
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
			friend auto operator*(const Fraction& frac, const T&) {
				return frac.Numerator * T / frac.Denominator;
			}

			template <typename T>
			friend auto operator*(const T&, const Fraction& frac) {
				return frac.Numerator * T / frac.Denominator;
			}

			Fraction operator/(Fraction other);

			template <typename T>
			friend auto operator/(const Fraction& frac, const T&) {
				frac.Numerator / (frac.Denominator * T);
			}

			template <typename T>
			friend auto operator/(const T&, const Fraction& frac) {
				T * frac.Numerator 
			}
		};

		template <typename T>
		Fraction GetFraction(T value) {
			return Fraction { value, 1 };
		}
	}
}