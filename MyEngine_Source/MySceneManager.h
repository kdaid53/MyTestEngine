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
			activeScene = scene;
			scene->Initialize();

			sceneMap.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);

		static void Initialize();
		static void Update();
		static void Lateupdate();
		static void Render(HDC hdc);

		static Scene* GetActiveScene() { return activeScene; }

	private:
		static std::map<std::wstring, Scene*> sceneMap;
		static Scene* activeScene;
	};
}


