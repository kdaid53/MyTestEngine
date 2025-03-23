#pragma once
#include "MyResource.h"

namespace kim::graphics {

	class Texture : public Resource
	{
	public:
		
		enum class TextureType {
			Bmp,
			Png,
			None
		};

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return width; }
		UINT GetHeight() { return height; }
		HDC GetHdc() { return hdc; }
		TextureType GetTextureType() { return type; }
		Gdiplus::Image* GetImage() { return image; }

	private:
		TextureType type;
		Gdiplus::Image* image;
		HBITMAP bitmap;
		HDC hdc;

		UINT width;
		UINT height;


	};
}

