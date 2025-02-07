#include "MyGameScene.h"

MyGameScene::MyGameScene() {
	// 初期化
	player_ = std::make_unique<Player>();
}

void MyGameScene::Update() {
	// 自機の更新
	player_->Update();
}

void MyGameScene::Draw() const {
	// 自機の描画
	player_->Draw();
}
