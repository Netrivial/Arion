#pragma once

#include <limits>

namespace Arion {
    namespace Consts {

        inline const     long double NotANumber = std::numeric_limits<long double>::quiet_NaN();
        inline constexpr long double INF = std::numeric_limits<long double>::infinity();
        inline constexpr long double POSITIVE_INF = std::numeric_limits<long double>::infinity();
        inline constexpr long double NEGATIVE_INF = -std::numeric_limits<long double>::infinity();
        inline constexpr      double doubleEps = 1e-9;

        inline constexpr long double Pi = 3.14159265358979323846L;
        inline constexpr long double E = 2.71828182845904523536L;
        inline constexpr long double Ln10 = 2.30258509299404568402L;
        inline constexpr long double Sqrt2 = 1.41421356237309504880L;
        inline constexpr long double Sqrt3 = 1.73205080756887729352L;
        inline constexpr long double GoldenRatio = 1.61803398874989484820L;

    }
}

namespace AC = Arion::Consts;