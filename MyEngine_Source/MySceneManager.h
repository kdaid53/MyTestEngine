#pragma once
#include "MyScene.h"

namespace kim {
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			sceneMap.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name) {
			std::map<std::wstring, Scene*>::iterator iter = sceneMap.find(name);
			
			if (iter == sceneMap.end())
				return nullptr;

			activeScene = iter->second;

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void Lateupdate();
		static void Render(HDC hdc);

	private:
		static std::map<std::wstring, Scene*> sceneMap;
		static Scene* activeScene;
	};
}


