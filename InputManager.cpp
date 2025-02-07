#include "InputManager.h"
#include <Novice.h>

InputManager &InputManager::GetInstance() {
	static InputManager instance;
	return instance;
}
void InputManager::Update() {
	UpdateKeyStates();
}

bool InputManager::IsKeyPressed(int key) const {
	return keys_[key];
}

bool InputManager::WasKeyTriggered(int key) const {
	return keys_[key] && !preKeys_[key];
}

void InputManager::UpdateKeyStates() {
	memcpy(preKeys_, keys_, kKeysCount_);
	Novice::GetHitKeyStateAll(keys_);
}
