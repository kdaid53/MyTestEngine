#include "MyScene.h"

namespace kim {

	Scene::Scene():
		sceneGameObjects{}
	{}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		for (Gameobject* gameObject : sceneGameObjects) {
			gameObject->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Gameobject* gameObject : sceneGameObjects) {
			gameObject->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Gameobject* gameObject : sceneGameObjects) {
			gameObject->Render(hdc);
		}
	}

	void Scene::AddGameObject(Gameobject* gameObject)
	{
		sceneGameObjects.push_back(gameObject);
	}


}
