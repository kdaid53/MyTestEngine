#include "MyTexture.h"
#include "MyEnApplication.h"

extern kim::Application app;

namespace kim::graphics{

	Texture::Texture() :
		Resource(enums::ResourceType::Texture)
	{}

	Texture::~Texture()
	{}

	HRESULT Texture::Load(const std::wstring& path)
	{
		//path에서 확장자 추출
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp") {
			type = TextureType::Bmp;

			bitmap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (bitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(bitmap, sizeof(BITMAP), &info);

			width = info.bmWidth;
			height = info.bmHeight;

			HDC mainDC = app.GetHdc();
			hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(hdc, bitmap);

			DeleteObject(oldBitmap);
		}
		else if (ext == L"png") {
			type = TextureType::Png;
			image = Gdiplus::Image::FromFile(path.c_str());
			if (image == nullptr)
				return S_FALSE;

			width = image->GetWidth();
			height = image->GetHeight();


		}

		return S_OK;
	}
}




 
