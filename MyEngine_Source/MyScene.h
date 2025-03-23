#pragma once
#include "MyEntity.h"
#include "MyGameobject.h"
#include "MyLayer.h"


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
		
		virtual void OnLoad();
		virtual void OnExit();

		void AddGameObject(Gameobject* gameObject, const enums::LayerType objectLayer);
		Layer* GetLayer(const enums::LayerType layertype) { return sceneLayers[(UINT)layertype]; }

	private:
		void CreateLayers();
		std::vector<Layer*> sceneLayers;

	};

}


