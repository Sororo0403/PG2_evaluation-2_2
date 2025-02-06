#pragma once

#include "MyVector2.h"

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
	変数
	=========================*/
	// キー入力
	static constexpr int kKeysCount = 256;
	char keys_[kKeysCount];
	char preKeys_[kKeysCount];

	// スティック入力
	static constexpr int kStickCenter = 0x8000;
	MyVector2<float> stickTilt_;
	MyVector2<float> preStickTilt_;

	/*=========================
	関数
	=========================*/
	/// <summary>
	/// キー入力の更新
	/// </summary>
	void UpdateKeyStates();

	/// <summary>
	/// スティック入力の更新
	/// </summary>
	void UpdateStickStates();

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

