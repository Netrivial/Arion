// Fraction module

#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <Arion/Consts.hpp>

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
			void Pow(double Power);

			void MultiplyBoth(double factor);
			void DivideBoth(double divisor);


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


			bool operator==(Fraction other) const;

			template <typename T>
			friend bool operator==(const Fraction& frac, const T& other) {
				return std::abs(frac.Division() - other) < Consts::doubleEps;
			}

			template <typename T>
			friend bool operator==(const T& other, const Fraction& frac) {
				return std::abs(frac.Division() - other) < Consts::doubleEps;
			}


			bool operator!=(Fraction other) const;

			template <typename T>
			friend bool operator!=(const Fraction& frac, const T& other) {
				return std::abs(frac.Division() - other) > Consts::doubleEps;
			}

			template <typename T>
			friend bool operator!=(const T& other, const Fraction& frac) {
				return std::abs(frac.Division() - other) > Consts::doubleEps;
			}


			bool operator<(Fraction other) const;

			template <typename T>
			friend bool operator<(const Fraction& frac, const T& other) {
				return frac.Division() < other;
			}

			template <typename T>
			friend bool operator<(const T& other, const Fraction& frac) {
				return other < frac.Division();
			}


			bool operator<=(Fraction frac) const;

			template <typename T>
			friend bool operator<=(const Fraction& frac, const T& other) {
				return frac.Division() <= other;
			}

			template <typename T>
			friend bool operator<=(const T& other, const Fraction& frac) {
				return other <= frac.Division();
			}


			bool operator>(Fraction frac) const;

			template <typename T>
			friend bool operator>(const Fraction& frac, const T& other) {
				return frac.Division() > other;
			}

			template <typename T>
			friend bool operator>(const T& other, const Fraction& frac) {
				return other > frac.Division();
			}


			bool operator>=(Fraction other) const;

			template <typename T>
			friend bool operator>=(const Fraction& frac, const T& other) {
				return frac.Division() >= other;
			}

			template <typename T>
			friend bool operator>=(const T& other, const Fraction& frac) {
				return other >= frac.Division();
			}
		};

		template <typename T>
		Fraction GetFraction(T value) {
			return Fraction { value, 1 };
		}
	}
}