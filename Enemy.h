#pragma once

#include "GameObject.h"

class Enemy : public GameObject {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Enemy();

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
};