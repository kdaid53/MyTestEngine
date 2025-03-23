#pragma once
#include "..\\MyEngine_Source\\MyResources.h"
#include "..\\MyEngine_Source\\MyTexture.h"



namespace kim {

	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG_T",L"C:\\Users\\user\\source\\repos\\MyTestEngine\\Resources\\background.png");
		Resources::Load<graphics::Texture>(L"PLAYER_T", L"C:\\Users\\user\\source\\repos\\MyTestEngine\\Resources\\stand.png");
	}

}