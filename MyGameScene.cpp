#include "MyGameScene.h"
#include <Novice.h>
#include "InputManager.h"
#include "SceneManager.h"

MyGameScene::MyGameScene() {
	// 初期化
	player_ = std::make_unique<Player>();
	enemies_.clear();
	enemies_.push_back(std::make_unique<Enemy>());
	isGameOver_ = false;
}

void MyGameScene::Update() {		
	// 入力管理のインスタンスを取得
	InputManager &input = InputManager::GetInstance();

	if (isGameOver_) {
		// シーン管理のインスタンスを取得
		SceneManager &sceneManager = SceneManager::GetInstance();

		// スペースでリスタート
		if (input.WasKeyTriggered(DIK_SPACE)) {
			sceneManager.SetScene(std::make_unique<MyGameScene>());
			return;
		}

		return;
	}

	// 自機の更新
	player_->Update();

	// Rキーで敵をリスポーン
	if (input.WasKeyTriggered(DIK_R)) {
		// 入力管理のインスタンスを取得
		enemies_.clear();
		enemies_.push_back(std::make_unique<Enemy>());
	}

	// 敵の更新
	for (auto &enemy : enemies_) {
		enemy->Update();
	}

	// 自機と敵の当たり判定
	for (auto it = enemies_.begin(); it != enemies_.end();) {
		auto *enemy = it->get();

		if (IsHit(player_.get(), enemy)) {
			// ゲームオーバーにする
			isGameOver_ = true;
		}

		++it;
	}

	// 弾丸と敵の当たり判定
	for (auto bulletIt = player_->BulletsBegin(); bulletIt != player_->BulletsEnd();) {
		bool isHit = false;
		auto *bullet = bulletIt->get();

		for (auto enemyIt = enemies_.begin(); enemyIt != enemies_.end();) {
			auto *enemy = enemyIt->get();

			if (IsHit(bullet, enemy)) {
				// 敵を削除
				enemyIt = enemies_.erase(enemyIt);

				// 弾丸を削除
				bulletIt = player_->RemoveBullet(bulletIt);

				isHit = true;
				break;
			} else {
				++enemyIt;
			}
		}

		if (!isHit) {
			++bulletIt;
		}
	}
}

void MyGameScene::Draw() const {
	// 自機の描画
	player_->Draw();

	// 敵の描画
	for (const auto &enemy : enemies_) {
		enemy->Draw();
	}

	// ゲームオーバーの文字
	if (isGameOver_) {
		Novice::ScreenPrintf(600, 340, "GAME OVER!");
		Novice::ScreenPrintf(580, 360, "SPACE TO RESTART");
	}
}

bool MyGameScene::IsHit(const GameObject *obj1, const GameObject *obj2) const {
	// 各オブジェクトの矩形情報を取得
	const float left1 = obj1->GetLeft();
	const float right1 = obj1->GetRight();
	const float top1 = obj1->GetTop();
	const float bottom1 = obj1->GetBottom();

	const float left2 = obj2->GetLeft();
	const float right2 = obj2->GetRight();
	const float top2 = obj2->GetTop();
	const float bottom2 = obj2->GetBottom();

	// 左上と右下の座標を用いて判定
	if (left1 < right2 &&
		right1 > left2 &&
		top1 < bottom2 &&
		bottom1 > top2) {
		return true;
	}

	return false;
}
