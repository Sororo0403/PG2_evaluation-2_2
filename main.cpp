#include <Novice.h>

/*=========================
構造体
=========================*/
/// <summary>
/// 2次元ベクトル
/// </summary>
struct Vector2 {
	float x;
	float y;
};

/*=========================
グローバル変数
=========================*/
// タイトル
const char kWindowTitle[] = "LC1B_18_ハタナカタロウ_";

// ウィンドウサイズ
const Vector2 kWindowSize = { 1280.0f,720.0f };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(
		kWindowTitle,
		static_cast<int>(kWindowSize.x),
		static_cast<int>(kWindowSize.y)
	);

	/*=========================
	変数
	=========================*/
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {

		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		/*=========================
		の更新処理
		=========================*/


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/*=========================
		の描画処理
		=========================*/


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}