#pragma once

class InputManager {
public:

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
};

