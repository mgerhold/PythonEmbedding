#include <iostream>
#ifdef _MSC_VER
#include <CodeAnalysis/Warnings.h> // ALL_CODE_ANALYSIS_WARNINGS
#pragma warning (push)
#pragma warning (disable : ALL_CODE_ANALYSIS_WARNINGS)
#endif
#include <pybind11/embed.h>
#ifdef _MSC_VER
#pragma warning (pop)
#endif
#include "ModuleDefinitions/Random_Module.hpp"
#include "ModuleDefinitions/Game_Module.hpp"
#include "Clock/Clock.hpp"
#include <string>
#include <functional>

namespace py = pybind11;

int main() {
	py::scoped_interpreter guard{};

    Clock clock;
    constexpr int iterations = 2000;
    constexpr bool hotReload = false;
    constexpr bool textOutput = false;
    double elapsed = 0.0;
    try {
        auto playerModule = py::module::import("scripts.update_player");
        auto updateFunc = playerModule.attr("update");

        Player p{ 0.0f, 0.0f };
        std::cout << "x = " << p.getX() << "\n";

        clock.reset();
        for (int i = 0; i < iterations; ++i) {
            if constexpr (textOutput) { std::cout << "[C++]: iteration " << (i + 1) << "\n"; }

            if constexpr (hotReload) {
                if (i > 0) {                    
                    playerModule.reload();
                    updateFunc = playerModule.attr("update");
                }
            }

            if constexpr (textOutput) { std::cout << "[C++]: " << p.getX() << "\n"; }

            // invoke Python function
            updateFunc(py::cast(&p), textOutput); // py::cast is needed to pass by pointer

            if constexpr (textOutput) { std::cout << "[C++]: " << p.getX() << "\n"; }
        }
        elapsed = clock.elapsedTime();
        std::cout << "x = " << p.getX() << " (expected: " << iterations << ")\n\n";
    } catch (py::error_already_set& e) {
        std::cout << e.what() << std::endl;
        std::cin.get();
    }

    std::cout << iterations << " iterations\n"
        << elapsed << " seconds\n"
        << (static_cast<double>(iterations) / elapsed) << " iterations per second\n"
        << (elapsed * 1000.0 / static_cast<double>(iterations)) << " ms per iteration\n";
    std::cin.get();
}