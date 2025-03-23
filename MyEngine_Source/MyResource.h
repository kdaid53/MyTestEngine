#pragma once
#include "MyEntity.h"

namespace kim {

	class Resource abstract : public Entity
	{
	public:
		Resource(enums::ResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;
		void SetPath(const std::wstring path) { rscPath = path; }



	private:
		const enums::ResourceType rscType;
		std::wstring rscPath;


	};
}

