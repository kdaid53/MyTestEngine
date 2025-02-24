#include "MyPlayScene.h"
#include "MyGameobject.h"

namespace kim {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}


	void PlayScene::Initialize()
	{
		for (size_t i = 0; i < 10; i++) {
			Gameobject* tempObj = new Gameobject();
			tempObj->SetPosition(rand() % 1200, rand() % 900);
			AddGameObject(tempObj);
		}

	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
