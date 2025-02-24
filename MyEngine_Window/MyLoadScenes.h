#pragma once
#include "..\\MyEngine_Source\\MySceneManager.h"

#include "MyPlayScene.h"

namespace kim {

	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}

}