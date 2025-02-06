#pragma once

class InputManager {
public:

	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static InputManager &GetInstance();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

private:
	// 定数
	static constexpr int kKeysCount_ = 256;

	// メンバ変数
	char keys_[kKeysCount_];
	char preKeys_[kKeysCount_];

	/// <summary>
	/// コンストラクタ(外部からのインスタンス化を禁止)
	/// </summary>
	InputManager() = default;

	/// <summary>
	/// コピーコンストラクタ(コピーを禁止)
	/// </summary>
	InputManager(const InputManager &) = delete;

	/// <summary>
	/// 代入演算子(コピーを禁止)
	/// </summary>
	InputManager &operator=(const InputManager &) = delete;
};

