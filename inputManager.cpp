#include "InputManager.h"

InputManager &InputManager::GetInstance() {
    static InputManager instance;
    return instance;
}

void InputManager::Update() {
}
