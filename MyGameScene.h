#pragma once

#include <memory>
#include <vector>
#include "Scene.h"
#include "Enemy.h"
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
	std::vector<std::unique_ptr<Enemy>> enemies_;
	bool isGameOver_;

	/// <summary>
	/// ゲームオブジェクト同士の当たり判定
	/// </summary>
	/// <param name="obj1">判定を行うゲームオブジェクト1</param>
	/// <param name="obj2">判定を行うゲームオブジェクト2</param>
	/// <returns>true:当たっている false:当たっていない</returns>
	bool IsHit(const GameObject *obj1,const GameObject *obj2) const;
};