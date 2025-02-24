#include "MySceneManager.h"

namespace kim {

	std::map<std::wstring, Scene*> SceneManager::sceneMap = {};
	Scene* SceneManager::activeScene = nullptr;

	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		activeScene->Update();
	}
	void SceneManager::Lateupdate()
	{
		activeScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		activeScene->Render(hdc);
	}
}