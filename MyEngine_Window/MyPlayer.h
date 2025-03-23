#pragma once
#include "..\\MyEngine_Source\\\MyGameobject.h"

namespace kim {
	class Player : public Gameobject
	{
	public:

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:


	};
}

