#pragma once
#include "..\\MyEngine_Source\\MyScene.h"

namespace kim {
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc)override;

		void OnLoad() override;
		void OnExit() override;


	private:
		class Player* player;
		class StaticObject* background;

	};
}


