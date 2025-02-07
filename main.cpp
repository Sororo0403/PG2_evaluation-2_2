#include <Novice.h>

// タイトル
const char kWindowTitle[] = "LC1B_18_ハタナカタロウ_";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(
		kWindowTitle,
		static_cast<int>(kWindowSize.x),
		static_cast<int>(kWindowSize.y)
	);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {

		// フレームの開始
		Novice::BeginFrame();

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