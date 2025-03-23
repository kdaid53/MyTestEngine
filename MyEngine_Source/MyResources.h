#pragma once
#include "MyResource.h"

namespace kim {
	class Resources {
	public:
		template <typename T>
		static T* Find(const std::wstring& key){
			
			
			//std::map<std::wstring, Resource*>::iterator iter = resourceMap.find(key);
			auto iter = resourceMap.find(key);

			if (iter == resourceMap.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);

		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path) {
			T* resource = Find<T>(key);

			if (resource != nullptr)
				return resource;

			resource = new T();

			if (FAILED(resource->Load(path)))
				assert(false);

			resource->SetName(key);
			resource->SetPath(path);
			resourceMap.insert(std::make_pair(key, resource));
			return resource;

		}



	private:
		static std::map<std::wstring, Resource*> resourceMap;
	};

 }

