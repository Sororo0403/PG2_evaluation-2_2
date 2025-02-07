#include "Timer.h"

Timer::Timer(unsigned int timeLimit) {
	// 初期化
	timeLimit_ = timeLimit;
	stopwatch_ = std::make_unique<Stopwatch>();
}

void Timer::Update() {
	// ストップウォッチの更新
	stopwatch_->Update();

	// 制限時間に達した場合、ストップウォッチを停止
	if (IsTimeUp()) {
		stopwatch_->Stop();
	}
}

void Timer::Start() {
	stopwatch_->Start();
}

void Timer::Stop() {
	stopwatch_->Stop();
}

void Timer::Reset() {
	stopwatch_->Reset();
}

void Timer::ReStart() {
	stopwatch_->ReStart();
}

bool Timer::IsTimeUp() const {
	return stopwatch_->GetElapsedFrame() >= timeLimit_;
}
