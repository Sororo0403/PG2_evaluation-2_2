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

	/// <summary>
	/// 弾丸の最初のイテレーターを取得
	/// </summary>
	/// <returns>弾丸の最初のイテレーター</returns>
	std::vector<std::unique_ptr<Bullet>>::const_iterator BulletsBegin() const;

	/// <summary>
	/// 弾丸の最後のイテレーターを取得
	/// </summary>
	/// <returns>弾丸の最後のイテレーター</returns>
	std::vector<std::unique_ptr<Bullet>>::const_iterator BulletsEnd() const;

	/// <summary>
	/// 弾丸を削除
	/// </summary>
	/// <param name="bullet">削除する弾丸</param>
	std::vector<std::unique_ptr<Bullet>>::iterator RemoveBullet(std::vector<std::unique_ptr<Bullet>>::const_iterator bullet);

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