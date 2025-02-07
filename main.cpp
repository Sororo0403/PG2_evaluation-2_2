#include <Novice.h>
#include <memory>
#include "InputManager.h"
#include "SceneManager.h"
#include "TitleScene.h"

// タイトル
const char kWindowTitle[] = "LC1B_18_ハタナカタロウ_";

// ウィンドウサイズ
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(
		kWindowTitle,
		static_cast<int>(kWindowWidth),
		static_cast<int>(kWindowHeight)
	);

	// 入力管理
	InputManager &input = InputManager::GetInstance();

	// シーン管理
	SceneManager &sceneManager = SceneManager::GetInstance();
	sceneManager.SetScene(std::make_unique<TitleScene>());

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		///
		/// ↓更新処理ここから
		///

		// 入力管理の更新
		input.Update();

		// シーン管理の更新
		sceneManager.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// シーン管理の描画
		sceneManager.Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (input.WasKeyTriggered(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}