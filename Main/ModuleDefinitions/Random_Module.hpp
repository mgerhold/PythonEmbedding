#pragma once

#ifdef _MSC_VER
#include <CodeAnalysis/Warnings.h> // ALL_CODE_ANALYSIS_WARNINGS
#pragma warning (push)
#pragma warning (disable : ALL_CODE_ANALYSIS_WARNINGS)
#endif
#include <pybind11/embed.h>
#ifdef _MSC_VER
#pragma warning (pop)
#endif
#include <gsl/gsl>
#include "../Random/Random.hpp"

auto getRandomNumber(int max) -> int {
    static Random random{};
    return gsl::narrow_cast<int>(random.random(max));
}

PYBIND11_EMBEDDED_MODULE(random, m) {    
    m.def("getRandomNumber", &getRandomNumber);
}