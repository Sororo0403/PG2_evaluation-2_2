#include "InputManager.h"
#include <Novice.h>

/*=========================
関数
=========================*/
void InputManager::Update() {
	// キー入力の更新
	UpdateKeyStates();
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
	memcpy(preKeys_, keys_, kKeysCount_);
	Novice::GetHitKeyStateAll(keys_);
}
