#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
	// 初期化
	pos_ = { 640.0f,128.0f };
	size_ = { 64.0f,64.0f };
	isActive_ = true;
	moveSpeed_ = 4.0f;
}

void Enemy::Update() {
	if (isActive_) {
		// 移動
		pos_.x += moveSpeed_;

		// 移動を反転
		if (GetLeft() < 0.0f ||
			GetRight() > 1280.0f) {
			moveSpeed_ *= -1.0f;
		}
	}
}

void Enemy::Draw() const {
	if (isActive_) {
		// 敵の描画
		Novice::DrawBox(
			static_cast<int>(pos_.x - size_.x / 2.0f),
			static_cast<int>(pos_.y - size_.y / 2.0f),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f, 0xFF2600FF, kFillModeSolid
		);
	}
}
