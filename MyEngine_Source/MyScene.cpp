#include "MyScene.h"

namespace kim {

	Scene::Scene():
		sceneLayers{}
	{
		CreateLayers();
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : sceneLayers) {
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}

	}

	void Scene::Update()
	{
		for (Layer* layer : sceneLayers) {
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : sceneLayers) {
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : sceneLayers) {
			if (layer == nullptr)
				continue;

			layer->Render(hdc);
		}
	}

	void Scene::OnLoad()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::CreateLayers()
	{
		sceneLayers.resize((UINT)enums::LayerType::Max);
		for (size_t i = 0; i < (UINT)enums::LayerType::Max; i++)
			sceneLayers[i] = new Layer();
		
	}

	void Scene::AddGameObject(Gameobject* gameObject, const enums::LayerType objectLayer)
	{
		sceneLayers[(UINT)objectLayer]->AddGameObject(gameObject);
	}


}
