#pragma once

#include "MyVector2.h"
#include "Direciton.h"

class InputManager {
public:
	/*=========================
	入力管理の関数
	=========================*/
	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/*=========================
	キー入力の関数
	=========================*/
	/// <summary>
	/// キーが押されているか判定
	/// </summary>
	/// <param name="key">判定するキー</param>
	/// <returns>true:押されている false:押されていない</returns>
	bool IsKeyPressed(int key) const;

	/// <summary>
	/// キーが押された瞬間か判定
	/// </summary>
	/// <param name="key">判定するキー</param>
	/// <returns>true:押された瞬間である false:押された瞬間でない</returns>
	bool WasKeyTriggered(int key) const;

	/*=========================
	シングルトンの関数
	=========================*/
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static InputManager &GetInstance();

private:
	/*=========================
	変数
	=========================*/
	// キー入力
	static constexpr int kKeysCount_ = 256;
	char keys_[kKeysCount_];
	char preKeys_[kKeysCount_];

	// スティック入力
	static constexpr int kStickCenter_ = 0x8000;
	MyVector2<float> stickTilt_;
	MyVector2<float> preStickTilt_;

	/*=========================
	キー入力のメンバ関数
	=========================*/
	/// <summary>
	/// キー入力の更新
	/// </summary>
	void UpdateKeyStates();

	/*=========================
	シングルトンのメンバ関数
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

