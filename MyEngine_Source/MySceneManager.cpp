#include "MySceneManager.h"

namespace kim {

	std::map<std::wstring, Scene*> SceneManager::sceneMap = {};
	Scene* SceneManager::activeScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (activeScene)
			activeScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter = sceneMap.find(name);

		if (iter == sceneMap.end())
			return nullptr;

		activeScene = iter->second;
		activeScene->OnLoad();

		return iter->second;
	}

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