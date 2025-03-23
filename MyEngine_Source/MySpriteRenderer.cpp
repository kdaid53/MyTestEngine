#include "MySpriteRenderer.h"
#include "MyGameobject.h"
#include "MyTransform.h"
#include "MyRenderer.h"

namespace kim {
	SpriteRenderer::SpriteRenderer() :
		Component(enums::ComponentType::SpriteRenderer),
		texture(nullptr),
		size(Vector2::One)
	{}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (texture == nullptr)
			assert(false);

		Transform* trsf = GetOwner()->GetComponent<Transform>();
		Vector2 pos = trsf->GetPos();

		pos = renderer::mainCamera->CalculatePosition(pos);

		//https://blog.naver.com/power2845/50147965306
		if (texture->GetTextureType() == graphics::Texture::TextureType::Bmp) {

			TransparentBlt(hdc, pos.x, pos.y, texture->GetWidth() * size.x, texture->GetHeight() * size.y,
				texture->GetHdc(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255));
		}
		else if (texture->GetTextureType() == graphics::Texture::TextureType::Png) {
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(texture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y, texture->GetWidth() * size.x, texture->GetHeight() * size.y));

		}


	}

}
