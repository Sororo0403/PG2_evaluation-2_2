#include "TitleScene.h"
#include <Novice.h>
#include "InputManager.h"
#include "SceneManager.h"
#include "MyGameScene.h"

TitleScene::TitleScene() {
}

void TitleScene::Update() {
	// 入力管理のインスタンスを取得
	InputManager &input = InputManager::GetInstance();

	// シーン管理のインスタンスを取得
	SceneManager &sceneManager = SceneManager::GetInstance();

	if (input.WasKeyTriggered(DIK_SPACE)) {
		sceneManager.SetScene(std::make_unique<MyGameScene>());
	}
}

void TitleScene::Draw() const {
}
