#pragma once

#include <memory>
#include "Scene.h"
#include "Player.h"

class MyGameScene : public Scene {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	MyGameScene();

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
	std::unique_ptr<Player> player_;
};