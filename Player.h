#pragma once

#include <vector>
#include <memory>
#include "GameObject.h"
#include "Bullet.h"
#include "Timer.h"

class Player : public GameObject {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() const override;

private:
	// メンバ変数
	static const int kShootInterval_ = 16;
	float moveSpeed_;
	std::unique_ptr<Timer> shootTimer_;
	std::vector<std::unique_ptr<Bullet>> bullets_;

	/// <summary>
	/// キーによる移動
	/// </summary>
	void KeyMove();

	/// <summary>
	/// 弾丸を発射
	/// </summary>
	void ShootBullet();

	/// <summary>
	/// 画面内に収める
	/// </summary>
	void ClampToScreen();

	/// <summary>
	/// 弾丸の更新
	/// </summary>
	void UpdateBulletsStates();
};