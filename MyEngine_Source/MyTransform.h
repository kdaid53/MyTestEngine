#pragma once
#include "MyEntity.h"
#include "MyComponent.h"

namespace kim {

	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { 
			objPosition.x = pos.x; 
			objPosition.y = pos.y;
		}
		Vector2 GetPos() { return objPosition; }


	private:
		Vector2 objPosition;
	};
}

