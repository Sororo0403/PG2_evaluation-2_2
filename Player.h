#pragma once

#include "GameObject.h"

class Player : public GameObject{
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
	float moveSpeed_;

	/// <summary>
	/// キーによる移動
	/// </summary>
	void KeyMove();
};