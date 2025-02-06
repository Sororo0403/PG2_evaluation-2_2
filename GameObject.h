#pragma once

#include "MyVector2.h"

class GameObject {
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameObject() = default;

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() const = 0;

private:
	// メンバ変数
};

