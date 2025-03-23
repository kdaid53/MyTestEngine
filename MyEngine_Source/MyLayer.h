#pragma once
#include "MyEntity.h"
#include "CommonIncludes.h"
#include "MyGameobject.h"


namespace kim {
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(Gameobject* gameobject);

	private:
		std::vector<Gameobject*> layerGameObjects;

	};
 }

