#include "InputManager.h"
#include <Novice.h>

void InputManager::Update() {
    // キー入力の更新
    UpdateKeyStates();
}

InputManager &InputManager::GetInstance() {
    static InputManager instance;
    return instance;
}

void InputManager::UpdateKeyStates() {
    // キー入力を受け取る
    memcpy(preKeys_, keys_, 256);
    Novice::GetHitKeyStateAll(keys_);
}
