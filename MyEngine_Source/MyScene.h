#pragma once
#include "MyEntity.h"
#include "MyGameobject.h"


namespace kim {

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		
		void AddGameObject(Gameobject* gameObject);

	private:
		std::vector<Gameobject*> sceneGameObjects;

	};

}


