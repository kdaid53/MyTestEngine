#pragma once
#include "MyComponent.h"
#include "MyGameobject.h"
#include "MyLayer.h"
#include "MyScene.h"
#include "MySceneManager.h"
#include "MyTransform.h"


namespace kim::object {

	template <typename T>
	static T* Instantiate(kim::enums::LayerType layerType) {
		
		T* object = new T();

		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(layerType);
		layer->AddGameObject(object);

		return object;
	}

	template <typename T>
	static T* Instantiate(kim::enums::LayerType layerType, math::Vector2 pos) {

		T* object = new T();

		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(layerType);

		Transform* tf = object->GetComponent<Transform>();
		tf->SetPos(pos);

		layer->AddGameObject(object);

		return object;
	}

}
