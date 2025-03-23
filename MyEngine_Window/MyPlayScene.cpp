#include "MyPlayScene.h"
#include "MyGameobject.h"
#include "MyPlayer.h"
#include "MyStaticObject.h"
#include "MyTransform.h"
#include "MySpriteRenderer.h"
#include "MyInput.h"
#include "MyTitleScene.h"
#include "MySceneManager.h"
#include "MyObject.h"
#include "MyResources.h"
#include "MyTexture.h"
#include "MyPlayerScript.h"
#include "MyCamera.h"
#include "MyRenderer.h"


namespace kim {
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{

		background = object::Instantiate<StaticObject>(enums::LayerType::BackGround);
		player = object::Instantiate<Player>(enums::LayerType::Player);
		
		Transform* background_transform = background->AddComponent<Transform>();
		Transform* player_transform = player->AddComponent<Transform>();
		
		background_transform->SetPos(math::Vector2::Zero);
		player_transform->SetPos(math::Vector2(400, 400));

		PlayerScript* player_script = player->AddComponent<PlayerScript>();

		SpriteRenderer* bg_sr = background->AddComponent<SpriteRenderer>();
		bg_sr->SetName(L"BG_SR");
		SpriteRenderer* player_sr = player->AddComponent<SpriteRenderer>();
		player_sr->SetName(L"PLAYER_SR");

		graphics::Texture* bg_texture = Resources::Find<graphics::Texture>(L"BG_T");
		graphics::Texture* player_texture = Resources::Find<graphics::Texture>(L"PLAYER_T");

		bg_sr->SetTexture(bg_texture);
		player_sr->SetTexture(player_texture);

		Camera* player_camera = player->AddComponent<Camera>();

		
		
		renderer::mainCamera = player_camera;

		Scene::Initialize();

	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 30, 30, str, 10);
	}
	void PlayScene::OnLoad()
	{
	}
	void PlayScene::OnExit()
	{
	//	Transform* tf = bg->GetComponent<Transform>();
	//	tf->SetPos(math::Vector2(0, 0));
	}
}
