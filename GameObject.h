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
	MyVector2<float> pos_;
	MyVector2<float> size_;
	float angle_;
	bool isActive_;
};

