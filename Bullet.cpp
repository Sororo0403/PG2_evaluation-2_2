#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(const MyVector2<float> &pos, BulletType type) {
	// 初期化
	pos_ = pos;
	size_ = { 16.0f,16.0f };
	isActive_ = true;
	moveSpeed_ = 12.0f;
	type_ = type;
}

void Bullet::Update() {
	if (isActive_) {
		Move();

		// 画面外で無効化
		if (GetBottom() < 0.0f ||
			GetRight() < 0.0f ||
			GetTop() > 720.0f ||
			GetLeft() > 1280.0f) {
			isActive_ = false;
		}
	}
}

void Bullet::Draw() const {
	if (isActive_) {
		if (type_ == PLAYER) {
			Novice::DrawBox(
				static_cast<int>(pos_.x - size_.x / 2.0f),
				static_cast<int>(pos_.y - size_.y / 2.0f),
				static_cast<int>(size_.x),
				static_cast<int>(size_.y),
				0.0f, 0xBFE4FFFF, kFillModeSolid
			);
		} else if (type_ == ENEMY) {
			Novice::DrawBox(
				static_cast<int>(pos_.x - size_.x / 2.0f),
				static_cast<int>(pos_.y - size_.y / 2.0f),
				static_cast<int>(size_.x),
				static_cast<int>(size_.y),
				0.0f, 0xFF2F00FF, kFillModeSolid
			);
		}
	}
}

void Bullet::Move() {
	pos_.y -= moveSpeed_;
}
