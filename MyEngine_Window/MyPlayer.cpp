#include "MyPlayer.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MySpriteRenderer.h"

namespace kim {
	void Player::Initialize()
	{
		Gameobject::Initialize();
	}

	void Player::Update()
	{
		Gameobject::Update();
	}

	void Player::LateUpdate()
	{
		Gameobject::LateUpdate();
		
	}

	void Player::Render(HDC hdc)
	{
		Gameobject::Render(hdc);
	}
}