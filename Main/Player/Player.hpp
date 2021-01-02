#pragma once

class Player {
public:
	Player(float x, float y) noexcept;
	void move(float dx, float dy) noexcept;
	[[nodiscard]] auto getX() const noexcept -> float;
	[[nodiscard]] auto getY() const noexcept -> float;

private:
	float mX;
	float mY;
};