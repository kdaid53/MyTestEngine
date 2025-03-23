#include "MyCamera.h"
#include "MyEnApplication.h"
#include "MyTransform.h"
#include "MyGameobject.h"

extern kim::Application app;

namespace kim {
	Camera::Camera():
		Component(enums::ComponentType::Camera),
		distance(math::Vector2::Zero),
		resolution(math::Vector2::Zero),
		lookPosition(math::Vector2::Zero),
		cameraTarget(nullptr)
		
	{}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		resolution.x = app.GetWidth();
		resolution.y = app.GetHeight();
	}
	void Camera::Update()
	{
		if (cameraTarget) {

			Transform* targetTF = cameraTarget->GetComponent<Transform>();

			lookPosition = targetTF->GetPos();

		}
		else {
			Transform* cameraTF = GetOwner()->GetComponent<Transform>();

			lookPosition = cameraTF->GetPos();
		}

		

		distance = lookPosition - (resolution / 2.0f);
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}
