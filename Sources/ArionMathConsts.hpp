#pragma once

#include <limits>

namespace ArionMathConsts
{
	/* inline */ constexpr long double NotANumber = NAN;
	/* inline */ constexpr long double POSITIVE_INF = std::numeric_limits<long double>::infinity();
	/* inline */ constexpr long double NEGATIVE_INF = std::numeric_limits<long double>::infinity();
	/* inline */ constexpr long double INF = std::numeric_limits<long double>::infinity();

	/* inline */ constexpr int MaxRow = 1000;
	/* inline */ constexpr int MaxX = 1000;
	/* inline */ constexpr int MinX = -1000;

	/* inline */ constexpr int MaxColumn = 1000;
	/* inline */ constexpr int MaxY = 1000;
	/* inline */ constexpr int MinY = -1000;

	/* inline */ constexpr int MaxZ = 1000;
	/* inline */ constexpr int MinZ = -1000;

	/* inline */ constexpr long long MaxLim = 1e15;
	/* inline */ constexpr long long MinLim = 1e-15;


	// MATH CONSTS
	/* inline */ constexpr long double E = 2.718281828459;
	/* inline */ constexpr long double Pi = 3.141592653589793;
	/* inline */ constexpr long double Ln10 = 2.302585092994046;
}

namespace AMC = ArionMathConsts;
