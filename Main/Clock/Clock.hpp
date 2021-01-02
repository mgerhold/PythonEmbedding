
#pragma once

#include <chrono>

class Clock {
public:
	Clock() noexcept;
	[[nodiscard]] auto elapsedTime() const noexcept  -> double;
	void addDuration(double start) noexcept;
	auto reset() noexcept -> double;

private:
	using DurationType = std::chrono::nanoseconds;
	using RepresentationType = DurationType::rep;
	static constexpr intmax_t TickPeriodDenominator = DurationType::period::den;

private:
	std::chrono::high_resolution_clock							mHighResolutionClock;
	std::chrono::time_point<std::chrono::high_resolution_clock>	mStart;
};