#pragma once
#include "..\\MyEngine_Source\\MyScene.h"

namespace kim {
	class TitleScene : public Scene
	{
	public:

		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnLoad() override;
		void OnExit() override;


	};
}

