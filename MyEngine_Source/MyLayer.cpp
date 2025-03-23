#include "MyLayer.h"

namespace kim {
	Layer::Layer():
		layerGameObjects{}
	{}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (Gameobject* obj : layerGameObjects) {
			if (obj == nullptr)
				continue;

			obj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (Gameobject* obj : layerGameObjects) {
			if (obj == nullptr)
				continue;

			obj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (Gameobject* obj : layerGameObjects) {
			if (obj == nullptr)
				continue;

			obj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (Gameobject* obj : layerGameObjects) {
			if (obj == nullptr)
				continue;

			obj->Render(hdc);
		}
	}

	void Layer::AddGameObject(Gameobject* gameobject)
	{
		if (gameobject == nullptr)
			return;

		layerGameObjects.push_back(gameobject);
	}
}