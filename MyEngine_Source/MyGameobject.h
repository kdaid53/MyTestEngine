#pragma once
#include "CommonIncludes.h"
#include "MyComponent.h"

namespace kim {

	class Gameobject
	{
	public:
		Gameobject();
		~Gameobject();
		
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);



		template <typename T>
		T* AddComponent() {
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			objComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent() {
			T* component = nullptr;
			for (Component* comp : objComponents) {
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}


	private:

		std::vector<Component*> objComponents;

		void initializeTransform();

	};

}

