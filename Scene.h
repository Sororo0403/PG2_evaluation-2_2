#pragma once

class Scene {
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Scene() = default;

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() const = 0;
};
