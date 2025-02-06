#pragma once

class InputManager {
public:
	/*=========================
	関数
	=========================*/
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
	/*=========================
	メンバ関数
	=========================*/
	/// <summary>
	/// キー入力の更新
	/// </summary>
	void UpdateKeyStates();

private:
	/*=========================
	メンバ変数
	=========================*/
	// キー入力
	static constexpr int kKeysCount_ = 256;
	char keys_[kKeysCount_];
	char preKeys_[kKeysCount_];

private:
	/*=========================
	シングルトンパターン
	=========================*/
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

