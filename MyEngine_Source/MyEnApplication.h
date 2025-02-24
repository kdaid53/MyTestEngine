#pragma once
#include "CommonIncludes.h"

namespace kim {
	class Application{
	public:
		Application();
		~Application();

		void Initalize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		
		void cleatRenderTarget();
		void copyRenderTarget(HDC hdc, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void creatBuffer(UINT width, UINT height);
		void initializeEtc();

		HWND appHwnd;
		HDC appHdc;

		HDC backHdc;
		HBITMAP backBitmap;

		UINT workWidth;
		UINT workHeight;

	};


}

