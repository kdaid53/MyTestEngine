#pragma once
#include "CommonIncludes.h"

namespace kim {
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { enName = name; }
		std::wstring& GetName() { return enName; }


	private:
		std::wstring enName;
	};
}


