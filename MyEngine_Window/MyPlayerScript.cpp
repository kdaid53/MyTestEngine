#include "MyPlayerScript.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyGameobject.h"

namespace kim {
	PlayerScript::PlayerScript():
		Script()
	{}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (Input::GetKey(eKeyCode::D)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPos();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::A)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPos();
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::W)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPos();
			pos.y -= 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::S)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			math::Vector2 pos = tr->GetPos();
			pos.y += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}

		int a = 0;
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}
