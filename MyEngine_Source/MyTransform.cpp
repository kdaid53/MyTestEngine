#include "MyTransform.h"
#include "MyGameobject.h"

namespace kim {
	Transform::Transform():
		Component(enums::ComponentType::Transform)
	{}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}
