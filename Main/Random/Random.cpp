#include "Random.hpp"

#include <chrono>

Random::Random() {
	randomize();
}

auto Random::random(std::mt19937_64::result_type upperBoundExclusive) -> std::mt19937_64::result_type {
	return mUniformIntDistribution(mGenerator) % upperBoundExclusive;
}

auto Random::random() -> float {
	return mUniformRealDistribution(mGenerator);
}

auto Random::setRandomSeed(std::mt19937_64::result_type seed) -> void {
	mGenerator.seed(seed);
	mSeed = seed;
}

auto Random::getRandomSeed() const -> std::mt19937_64::result_type {
	return mSeed;
}

auto Random::randomize() -> void {
	setRandomSeed(std::chrono::system_clock::now().time_since_epoch().count());
}