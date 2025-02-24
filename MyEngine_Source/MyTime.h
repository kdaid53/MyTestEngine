#pragma once
#include "CommonIncludes.h"


namespace kim {
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFreq;
		static LARGE_INTEGER CurrFreq;
		static LARGE_INTEGER PrevFreq;
		static float DeltaTimeValue;
		
	};

}


