﻿#pragma once

#include "Scene.h"

class TitleScene: public Scene {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() const override;

private:

};