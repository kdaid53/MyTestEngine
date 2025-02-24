#pragma once
#include "CommonIncludes.h"

namespace kim {

	class Gameobject
	{
	public:
		Gameobject();
		~Gameobject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		
		void SetPosition(float x, float y) {
			obX = x;
			obY = y;
		}

		float GetPositionX() { return obX; }
		float GetPositionY() { return obY; }

		void Move();

	private:

		float obX;
		float obY;
		float obSpeed;

	
		

		

	};

}

