#pragma once
#include "MyEntity.h"
#include "MyComponent.h"
#include "MyTexture.h"

namespace kim {
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* _texture) { texture = _texture; }
		void SetSize(math::Vector2 _size) { size = _size; }

		//void ImageLoad(const std::wstring& path);

	private:
		graphics::Texture* texture;
		math::Vector2 size;

		//Gdiplus::Image* myImage;
		//UINT imgWidth;
		//UINT imgHeight;

	};
}

