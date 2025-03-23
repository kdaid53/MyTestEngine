#include "MyTitleScene.h"
#include "MyInput.h"
#include "MyPlayScene.h"
#include "MySceneManager.h"
#include "MyStaticObject.h"
#include "MyObject.h"
#include "MySpriteRenderer.h"

namespace kim {
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		
		
		//StaticObject* title = object::Instantiate<StaticObject>
		//	(enums::LayerType::BackGround);
		//
		//SpriteRenderer* title_sr = title->AddComponent<SpriteRenderer>();
		//title_sr->SetName(L"Title_SR");
		//title_sr->ImageLoad(L"C:\\Users\\user\\source\\repos\\MyTestEngine\\Resources\\title.png");

		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		
	}

	void TitleScene::OnLoad()
	{
	}

	void TitleScene::OnExit()
	{
	}
}