#include "InputManager.h"
#include <Novice.h>

/*=========================
関数
=========================*/
void InputManager::Update() {
	// キー入力の更新
	UpdateKeyStates();

	// スティック入力の更新
	UpdateStickStates();
}

bool InputManager::IsKeyPressed(int key) const {
	return keys_[key];
}

bool InputManager::WasKeyTriggered(int key) const {
	return keys_[key] && !preKeys_[key];
}

InputManager &InputManager::GetInstance() {
	static InputManager instance;
	return instance;
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

	// スティック割合を設定
	preStickTilt_ = stickTilt_;
	stickTilt_.x = static_cast<float>(stick.x) / static_cast<float>(kStickCenter);
	stickTilt_.y = static_cast<float>(stick.y) / static_cast<float>(kStickCenter);
}
