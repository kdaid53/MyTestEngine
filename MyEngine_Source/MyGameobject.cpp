#include "MyGameobject.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"


namespace kim {

	Gameobject::Gameobject(){

		objComponents.resize((UINT)enums::ComponentType::End);
	
		initializeTransform();
	}

	Gameobject::~Gameobject(){
		for (Component* comp : objComponents) {
			delete comp;
			comp = nullptr;
		}
	}

	void Gameobject::Initialize()
	{
		for (Component* comp : objComponents) {
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void Gameobject::Update() {

		for (Component* comp : objComponents) {
			if (comp == nullptr)
				continue;

			comp->Update();
		}



	}


	void Gameobject::LateUpdate() {

		for (Component* comp : objComponents) {
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}

	}


	void Gameobject::Render(HDC hdc) {

		for (Component* comp : objComponents) {
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}


	}

	void Gameobject::initializeTransform()
	{
		AddComponent<Transform>();
	}
	

}