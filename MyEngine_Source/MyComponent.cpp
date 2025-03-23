#include "MyComponent.h"

namespace kim {
	Component::Component(enums::ComponentType _type):
		componentOwner(nullptr),
		type(_type)
	{
	}
	Component::~Component()
	{
	}
	void Component::Initialize()
	{
	}
	void Component::Update()
	{
	}
	void Component::LateUpdate()
	{
	}
	void Component::Render(HDC hdc)
	{
	}
}