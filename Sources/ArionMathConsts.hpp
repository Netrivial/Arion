#pragma once

#include <limits>

namespace ArionMathConsts
{
	const long double NotANumber = std::numeric_limits<long double>::quiet_NaN();
	// constexpr long double POSITIVE_INF = std::numeric_limits<long double>::infinity();
	// constexpr long double NEGATIVE_INF = -std::numeric_limits<long double>::infinity();
	constexpr long double INF = std::numeric_limits<long double>::infinity();

	// old conts:
	// constexpr int DefaultRow = 1000;
	// constexpr int DefaultColumn = 1000;
	// constexpr long long DefaultMaxLim = 1'000'000'000'000'000;
	// constexpr long double DefaultMinLim = 1/DefaultMaxLim;


	// MATH CONSTS
	constexpr long double Pi = 3.14159265358979323846L;
	constexpr long double E = 2.71828182845904523536L;
	constexpr long double Ln10 = 2.30258509299404568402L;
}

namespace AMC = ArionMathConsts;
