#pragma once

#include <memory>
#include "Scene.h"

class SceneManager {
public:	
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static SceneManager &GetInstance();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() const;

	/// <summary>
	/// シーンを設定
	/// </summary>
	/// <param name="scene">設定するシーン</param>
	void SetScene(std::unique_ptr<Scene> scene);

private:
	// メンバ変数
	std::unique_ptr<Scene> currentScene_;

	/// <summary>
	/// コンストラクタ(外部からのインスタンス化を禁止)
	/// </summary>
	SceneManager() = default;

	/// <summary>
	/// コピーコンストラクタ(コピーを禁止)
	/// </summary>
	SceneManager(const SceneManager &) = delete;

	/// <summary>
	/// 代入演算子(コピーを禁止)
	/// </summary>
	SceneManager &operator=(const SceneManager &) = delete;
};