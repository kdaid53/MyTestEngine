#include "MyInput.h"


namespace kim {

	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::END] = {
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT,VK_RIGHT,VK_UP,VK_DOWN
	};



	void Input::Initialize(){
		createKey();

	}

	void Input::Update(){
		updateKeys();

	}

	void Input::createKey(){
		for (size_t i = 0; i < (UINT)eKeyCode::END; i++) {
			Key key = {};
			key.isPressed = false;
			key.keyState = eKeyState::NONE;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}

	}

	void Input::updateKey(Input::Key& key){

		if (isKeyDown(key.keyCode)) {//Ű �Է¹���
			updateKeyDown(key);

		}else {//Ű �Է¹��� ����
			updateKeyUp(key);

		}

		
	}

	void Input::updateKeys(){
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void {updateKey(key); });

	}

	bool Input::isKeyDown(eKeyCode keycode){
		return GetAsyncKeyState(ASCII[(UINT)keycode]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key){
		if (key.isPressed) {//������ �־���
			key.keyState = eKeyState::PRESSED;
		}
		else {//���������� �ʾ��� -> ������ ������
			key.keyState = eKeyState::DOWN;
			key.isPressed = true;
		}

	}

	void Input::updateKeyUp(Input::Key& key){
		if (key.isPressed) {//�����ٰ� ��
			key.keyState = eKeyState::UP;
			key.isPressed = false;
		}
		else {// �ȴ����־��� -> ���޻���
			key.keyState = eKeyState::NONE;
		}
	}

	

}


