#include "InputManager.h"
#include <Novice.h>

/*=========================
関数
=========================*/
InputManager &InputManager::GetInstance() {
	static InputManager instance;
	return instance;
}

void InputManager::Update() {
	// キー入力の更新
	UpdateKeyStates();
}

/*=========================
メンバ関数
=========================*/
void InputManager::UpdateKeyStates() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, kKeysCount);
	Novice::GetHitKeyStateAll(keys_);
}

void InputManager::UpdateStickStates() {
	// スティック入力を受け取る
	MyVector2<int> stick;
	Novice::GetAnalogInputLeft(0, &stick.x, &stick.y);

	// 
	stick / kStickCenter;
	preStickTilt_ = stickTilt_;
}
