#include "GameObject.h"

float GameObject::GetTop() const {
	return pos_.y - size_.y / 2.0f;
}

float GameObject::GetLeft() const {
	return pos_.x - size_.x / 2.0f;
}

float GameObject::GetBottom() const {
	return pos_.y + size_.y / 2.0f;
}

float GameObject::GetRight() const {
	return pos_.x + size_.x / 2.0f;;
}

bool GameObject::IsActive() const {
	return isActive_;
}

void GameObject::Able() {
	isActive_ = true;
}

void GameObject::Enable() {
	isActive_ = false;
}
