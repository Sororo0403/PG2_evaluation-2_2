#pragma once

#include <memory>
#include "Stopwatch.h"

class Timer {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="timeLimit">制限時間</param>
	Timer(unsigned int timeLimit);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Timer() = default;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 計測を開始
	/// </summary>
	void Start();

	/// <summary>
	/// 計測を停止
	/// </summary>
	void Stop();

	/// <summary>
	/// 計測を初期化
	/// </summary>
	void Reset();

	/// <summary>
	/// 計測を初期化し、計測を開始
	/// </summary>
	void ReStart();

	/// <summary>
	/// 時間切れか判定
	/// </summary>
	/// <returns>true:時間切れである false:時間切れではない</returns>
	bool IsTimeUp() const;

private:
	// メンバ変数
	unsigned int timeLimit_;
	std::unique_ptr<Stopwatch> stopwatch_;
};