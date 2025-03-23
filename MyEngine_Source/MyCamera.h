#pragma once
#include "MyComponent.h"


namespace kim {

	class Gameobject;
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		math::Vector2 CalculatePosition(math::Vector2 pos) {
			return pos - distance;
		}
		

	private:
		class Gameobject* cameraTarget;
		math::Vector2 distance;
		math::Vector2 resolution;
		math::Vector2 lookPosition;
	};

}
