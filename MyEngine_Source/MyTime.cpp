#include "MyTime.h"

namespace kim {
	LARGE_INTEGER Time::CpuFreq = {};
	LARGE_INTEGER Time::CurrFreq = {};
	LARGE_INTEGER Time::PrevFreq = {};
	float Time::DeltaTimeValue = 0.0f;


	void Time::Initialize()
	{
		//CPU ���� ������ ��ȯ? �Լ�
		QueryPerformanceFrequency(&CpuFreq);


		//���� ������ ��(���� ������ ��)
		QueryPerformanceCounter(&PrevFreq);


	}

	void Time::Update()
	{
		//���� ������ ��(���� ��)
		QueryPerformanceCounter(&CurrFreq);

		// (���� �� ������ - ���� ������)/���� ������ => �ð�(��) 
		float diffrence = static_cast<float>(CurrFreq.QuadPart - PrevFreq.QuadPart);
		DeltaTimeValue = diffrence / static_cast<float>(CpuFreq.QuadPart);

		//���� �������� ���� �������� �Է��� �ݺ��Ͽ� ��� �ð� ��
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

