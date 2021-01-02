#include "Clock.hpp"

Clock::Clock() noexcept
	: mStart(mHighResolutionClock.now()) {}

auto Clock::elapsedTime() const noexcept -> double {
	return static_cast<double>(std::chrono::duration_cast<DurationType>(mHighResolutionClock.now() - mStart).count()) / TickPeriodDenominator;
}

void Clock::addDuration(double start) noexcept {
	mStart -= DurationType(static_cast<RepresentationType>(start * TickPeriodDenominator));
}

auto Clock::reset() noexcept -> double {
	auto result = elapsedTime();
	mStart = mHighResolutionClock.now();
	return result;
}