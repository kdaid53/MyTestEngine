#include "MyStaticObject.h"

namespace kim {
	void StaticObject::Initialize()
	{
		Gameobject::Initialize();
	}
	void StaticObject::Update()
	{
		Gameobject::Update();
	}
	void StaticObject::LateUpdate()
	{
		Gameobject::LateUpdate();
	}
	void StaticObject::Render(HDC hdc)
	{
		Gameobject::Render(hdc);
	}
}