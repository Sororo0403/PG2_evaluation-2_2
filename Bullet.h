#pragma once

#include "GameObject.h"
#include "MyVector2.h"

/// <summary>
/// 弾丸の種類
/// </summary>
enum BulletType {
	PLAYER,
	ENEMY,
};

class Bullet : public GameObject {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">初期のxy座標</param>
	/// <param name="type">種類</param>
	Bullet(const MyVector2<float> &pos, BulletType type);

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
	float moveSpeed_;
	BulletType type_;

	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();
};