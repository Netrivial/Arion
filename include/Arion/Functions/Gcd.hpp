#pragma once

#include <cstdlib>
#include <utility>
#include <type_traits>

namespace Arion {
    namespace Functions {
        /*
            Calculates the greatest common divisor of two integers(signed).
            Euclidean algorithm. For negative numbers, the absolute value is used.
            T – signed integer type (e.g., int, long long)
        */

        template <typename T>
        T gcd(T value1, T value2) noexcept {
            static_assert(std::is_integral_v<t> && std::is_signed_v<t>,
                "T must be a signed integral type");

            value1 = std::abs(value1);
            value2 = std::abs(value2);

            while (value2 != 0) {
                value1 %= value2;
                std::swap(value1, value2);
            }
            return value1;
        }
    }
}