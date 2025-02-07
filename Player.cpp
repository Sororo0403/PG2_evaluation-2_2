#include "Player.h"
#include <Novice.h>
#include <cmath>
#include "InputManager.h"
#include "MyVector2.h"

Player::Player() {
	// 初期化
	pos_ = { 640.0f,500.0f };
	size_ = { 64.0f,64.0f };
	isActive_ = true;
	moveSpeed_ = 8.0f;
	shootTimer_ = std::make_unique<Timer>(kShootInterval_);
	shootTimer_->Start();
	bullets_.clear();
}

void Player::Update() {
	if (isActive_) {
		// キーによる移動
		KeyMove();

		// 画面内に収める
		ClampToScreen();

		// 弾丸を更新
		UpdateBulletsStates();
	}
}

void Player::Draw() const {
	if (isActive_) {
		// 弾丸の描画
		for (const auto &bullet : bullets_) {
			bullet->Draw();
		}

		// 自機の描画
		Novice::DrawBox(
			static_cast<int>(pos_.x - size_.x / 2.0f),
			static_cast<int>(pos_.y - size_.y / 2.0f),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f, 0xB6FF00FF, kFillModeSolid
		);
	}
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

void Player::ShootBullet() {
	// 入力管理のインスタンスを取得
	InputManager &input = InputManager::GetInstance();

	// スペースキーで弾丸を発射
	if (input.IsKeyPressed(DIK_SPACE)) {
		if (shootTimer_->IsTimeUp()) {
			bullets_.push_back(std::make_unique<Bullet>(pos_, PLAYER));
			shootTimer_->ReStart();
		}
	}
}

void Player::ClampToScreen() {
	if (GetTop() < 0.0f) {
		pos_.y = 0.0f + size_.y / 2.0f;
	}

	if (GetLeft() < 0.0f) {
		pos_.x = 0.0f + size_.x / 2.0f;
	}

	if (GetBottom() > 720.0f) {
		pos_.y = 720.0f - size_.y / 2.0f;
	}

	if (GetRight() > 1280.0f) {
		pos_.x = 1280.0f - size_.x / 2.0f;
	}
}

void Player::UpdateBulletsStates() {
	// 発射タイマーを更新
	shootTimer_->Update();

	// 弾丸の発射
	ShootBullet();

	// 弾丸の更新
	for (auto &bullet : bullets_) {
		bullet->Update();
	}
}
