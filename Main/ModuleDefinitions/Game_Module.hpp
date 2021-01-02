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
#include "../Player/Player.hpp"

namespace py = pybind11;

PYBIND11_EMBEDDED_MODULE(game, m) {
	py::class_<Player>(m, "Player")
		.def(py::init<float, float>())
		.def("move", &Player::move)
		.def("getX", &Player::getX)
		.def("getY", &Player::getY);
}