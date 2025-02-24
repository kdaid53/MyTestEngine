#include "MyEnApplication.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MySceneManager.h"



namespace kim {
	Application::Application():
		appHwnd(nullptr),
		appHdc(nullptr),
		workHeight(0),
		workWidth(0),
		backHdc(NULL),
		backBitmap(NULL)
	
	{}

	Application::~Application(){}
	void Application::Initalize(HWND hwnd, UINT width, UINT height) {

		appHwnd = hwnd;
		appHdc = GetDC(appHwnd);
		
		adjustWindowRect(hwnd, width, height);

		creatBuffer(width, height);

		initializeEtc();

		SceneManager::Initialize();

	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update(){
		Input::Update();
		Time::Update();
		
		SceneManager::Update();

	}

	void Application::LateUpdate(){
		
		//SceneManager::Lateupdate();
	}

	void Application::Render(){
		cleatRenderTarget();

		Time::Render(backHdc);

		SceneManager::Render(backHdc);

		copyRenderTarget(backHdc, appHdc);
		
	}





	void Application::cleatRenderTarget()
	{
		Rectangle(backHdc, -1, -1, workWidth+1, workHeight+1);
	}

	void Application::copyRenderTarget(HDC srchdc, HDC dest)
	{
		BitBlt(dest, 0, 0, workWidth, workHeight, srchdc, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		workWidth = rect.right - rect.left;
		workHeight = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0, width, height, 0);
		ShowWindow(hwnd, true);
	}

	void Application::creatBuffer(UINT width, UINT height)
	{
		backBitmap = CreateCompatibleBitmap(appHdc, width, height);
		backHdc = CreateCompatibleDC(appHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(backHdc, backBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Time::Initialize();
		Input::Initialize();
	}

	
	
}