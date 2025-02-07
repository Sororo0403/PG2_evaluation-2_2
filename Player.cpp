#include "Player.h"
#include <Novice.h>
#include <cmath>
#include "InputManager.h"
#include "MyVector2.h"

Player::Player() {
	// 初期化
	pos_ = { 640.0f,500.0f };
	size_ = { 64.0f,64.0f };
	scale_ = { 1.0f,1.0f };
	isActive_ = true;
	moveSpeed_ = 8.0f;
}

void Player::Update() {
	// キーによる移動
	KeyMove();
}

void Player::Draw() const {
	// 自機の描画
	Novice::DrawBox(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f, 0xB6FF00FF, kFillModeSolid
	);
}

void Player::KeyMove() {
	// 入力管理のインスタンスを取得
	InputManager &input = InputManager::GetInstance();

	// 移動ベクトル
	MyVector2<float> moveVec = { 0.0f, 0.0f };

	// キー入力に応じて移動ベクトルを更新
	if (input.IsKeyPressed(DIK_W)) {
		moveVec.y -= 1.0f;
	}
	if (input.IsKeyPressed(DIK_A)) {
		moveVec.x -= 1.0f;
	}
	if (input.IsKeyPressed(DIK_S)) {
		moveVec.y += 1.0f;
	}
	if (input.IsKeyPressed(DIK_D)) {
		moveVec.x += 1.0f;
	}

	// 正規化
	moveVec.Normalized();

	// 移動
	pos_ += moveVec * moveSpeed_;
}
