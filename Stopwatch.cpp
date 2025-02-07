#include "Stopwatch.h"

Stopwatch::Stopwatch() {
	// 初期化
	currentFrame_ = 0;
	isRunning_ = false;
}

void Stopwatch::Update() {
	if (isRunning_) {
		currentFrame_++;
	}
}

void Stopwatch::Start() {
	isRunning_ = true;
}

void Stopwatch::Stop() {
	isRunning_ = false;
}

void Stopwatch::Reset() {
	currentFrame_ = 0;
	isRunning_ = false;
}

void Stopwatch::ReStart() {
	currentFrame_ = 0;
	isRunning_ = true;
}

unsigned int Stopwatch::GetElapsedFrame() const {
	return currentFrame_;
}
