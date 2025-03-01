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

	/// <summary>
	/// 上辺の座標を取得
	/// </summary>
	/// <returns>上辺の座標</returns>
	float GetTop() const;

	/// <summary>
	/// 左辺の座標を取得
	/// </summary>
	/// <returns>左辺の座標</returns>
	float GetLeft() const;

	/// <summary>
	/// 下辺の座標を取得
	/// </summary>
	/// <returns>下辺の座標</returns>
	float GetBottom() const;

	/// <summary>
	/// 右辺の座標を取得
	/// </summary>
	/// <returns>右辺の座標</returns>
	float GetRight() const;

	/// <summary>
	/// 有効か判定
	/// </summary>
	/// <returns>true:有効 false:無効</returns>
	bool IsActive() const;

	/// <summary>
	/// 有効にする
	/// </summary>
	void Able();

	/// <summary>
	/// 無効にする
	/// </summary>
	void Enable();

protected:
	// メンバ変数
	MyVector2<float> pos_;
	MyVector2<float> size_;
	bool isActive_;
};

