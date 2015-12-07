
#include "Piano.hpp"
#include <iostream>

Piano::Piano() {
	mPos = ci::Vec3f(350, 0, 0);
	mSize = ci::Vec3f(50, 50, 2);
	setColliderType(Collider::Rect);
}

void Piano::setup(){}

void Piano::update() {

}

void Piano::draw() {
	
}


void Piano::onCollisionUpdate(const std::shared_ptr<Object>& compare) {
	
	dowa::ResourceManager::audio().get(AudioKey::Menu).bgm->disable();
	dowa::ResourceManager::audio().get(AudioKey::StageSelectSE).bgm->enable();
	dowa::ResourceManager::audio().get(AudioKey::StageSelectSE).gain->setValue(1.0f);
}