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
    memcpy(preKeys_, keys_, 256);
    Novice::GetHitKeyStateAll(keys_);
}
