#include "MyTime.h"

namespace kim {
	LARGE_INTEGER Time::CpuFreq = {};
	LARGE_INTEGER Time::CurrFreq = {};
	LARGE_INTEGER Time::PrevFreq = {};
	float Time::DeltaTimeValue = 0.0f;


	void Time::Initialize()
	{
		//CPU 고유 진동수 반환? 함수
		QueryPerformanceFrequency(&CpuFreq);


		//현재 진동수 값(시작 진동수 값)
		QueryPerformanceCounter(&PrevFreq);


	}

	void Time::Update()
	{
		//현재 진동수 값(동작 후)
		QueryPerformanceCounter(&CurrFreq);

		// (동작 후 진동수 - 시작 진동수)/고유 진동수 => 시간(초) 
		float diffrence = static_cast<float>(CurrFreq.QuadPart - PrevFreq.QuadPart);
		DeltaTimeValue = diffrence / static_cast<float>(CpuFreq.QuadPart);

		//시작 진동수에 현재 진동수를 입력해 반복하여 계속 시간 잼
		PrevFreq.QuadPart = CurrFreq.QuadPart;

	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t text[50] = L"";

		swprintf_s(text, 50, L"Time: %f", time);

		int len = wcsnlen_s(text,50);

		TextOut(hdc, 5, 5, text, len);

	}


}

