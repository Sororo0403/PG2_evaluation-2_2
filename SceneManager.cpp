#include "SceneManager.h"

SceneManager &SceneManager::GetInstance() {
	static SceneManager instance;
	return instance;
}

void SceneManager::Update() {
	if (currentScene_) {
		currentScene_->Update();
	}
}

void SceneManager::Draw() const {
	if (currentScene_) {
		currentScene_->Draw();
	}
}

void SceneManager::SetScene(std::unique_ptr<Scene> scene) {
	currentScene_ = std::move(scene);
}
