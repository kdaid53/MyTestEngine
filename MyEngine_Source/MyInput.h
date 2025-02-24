#pragma once
#include "CommonIncludes.h"



namespace kim {
	enum class eKeyState {
		DOWN,
		PRESSED,
		UP,
		NONE
	};

	enum class eKeyCode {
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		LEFT, RIGHT, UP, DOWN,
		END
	};



	class Input
	{

	public:
		struct Key{
			eKeyCode keyCode;
			eKeyState keyState;
			bool isPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode keycode) { return Keys[(UINT)keycode].keyState == eKeyState::DOWN; }
		static bool GetKeyUp(eKeyCode keycode) { return Keys[(UINT)keycode].keyState == eKeyState::UP; }
		static bool GetKey(eKeyCode keycode) { return Keys[(UINT)keycode].keyState == eKeyState::PRESSED; }

	private:

		static std::vector<Key> Keys;

		static void createKey();
		static void updateKey(Input::Key& key);
		static void updateKeys();
		static bool isKeyDown(eKeyCode keycode);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);

	};



}


