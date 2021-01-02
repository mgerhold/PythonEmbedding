#include "Player.hpp"

Player::Player(float x, float y) noexcept
	: mX(x), mY(y)
{}

void Player::move(float dx, float dy) noexcept {
	mX += dx;
	mY += dy;
}

[[nodiscard]] auto Player::getX() const noexcept -> float {
	return mX;
}

[[nodiscard]] auto Player::getY() const noexcept -> float {
	return mY;
}
