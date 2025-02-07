#pragma once

class Stopwatch {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Stopwatch();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Stopwatch() = default;

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
	/// 経過フレームを取得
	/// </summary>
	/// <returns>経過フレーム</returns>
	unsigned int GetElapsedFrame() const;

private:
	// メンバ変数
	unsigned int currentFrame_;
	bool isRunning_;
};