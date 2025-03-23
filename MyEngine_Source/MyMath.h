#pragma once

namespace kim::math {

	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2() :
			x(0.0f),
			y(0.0f)
		{}

		Vector2(float _x, float _y):
			x(_x),
			y(_y)
		{}

		Vector2 operator+(Vector2 A) {
			return Vector2(x + A.x, y + A.y);
		}

		Vector2 operator-(Vector2 A) {
			return Vector2(x - A.x, y - A.y);
		}

		Vector2 operator/(float A) {
			return Vector2(x / A, y / A);
		}

		Vector2 operator*(float A) {
			return Vector2(x * A, y * A);
		}

	};

}
