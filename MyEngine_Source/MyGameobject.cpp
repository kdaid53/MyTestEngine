#include "MyGameobject.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyEnApplication.h"
#include "CommonIncludes.h"

namespace kim {

	Gameobject::Gameobject() :
		obSpeed(100.0f),
		obX(0.0f),
		obY(0.0f)
	{}

	Gameobject::~Gameobject(){}


	

	void Gameobject::Update() {

		Move();	

	}


	void Gameobject::LateUpdate() {

	}


	void Gameobject::Render(HDC hdc) {

		//HBRUSH newBrush = CreateSolidBrush(RGB(0,0,255));
		HBRUSH newBrush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		Rectangle(hdc, obX, obY, 50 + obX, 50 + obY);

		SelectObject(hdc, oldBrush);
		
		DeleteObject(newBrush);


	}
	
	void Gameobject::Move() {

		if (Input::GetKey(eKeyCode::D)) {
			obX += obSpeed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::A)) {
			obX -= obSpeed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W)) {
			obY -= obSpeed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S)) {
			obY += obSpeed * Time::DeltaTime();
		}

		
		
	}


}