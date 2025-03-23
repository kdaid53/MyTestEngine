#pragma once
#include "..\\MyEngine_Source\\MySceneManager.h"

#include "MyPlayScene.h"
#include "MyTitleScene.h"

namespace kim {

	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		

		SceneManager::LoadScene(L"PlayeScene");
	}

}