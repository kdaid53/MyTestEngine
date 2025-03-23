#pragma once
#include "MyEntity.h"

namespace kim {
	class Gameobject;
	class Component : public Entity
	{
	public:
		Component(enums::ComponentType _type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(Gameobject* owner) { componentOwner = owner; }
		Gameobject* GetOwner() { return componentOwner; }
		enums::ComponentType GetType() {return type;}

	private:
		Gameobject* componentOwner;
		enums::ComponentType type;
	};

}
