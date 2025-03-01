﻿#pragma once

#include "GameObject.h"
#include "MyVector2.h"

class Bullet : public GameObject {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">初期のxy座標</param>
	Bullet(const MyVector2<float> &pos);

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

	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();
};