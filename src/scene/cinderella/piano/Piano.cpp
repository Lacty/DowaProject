
#include "Piano.hpp"
#include <iostream>

Piano::Piano() {
	mPos = ci::Vec3f(350, 0, 0);
	mSize = ci::Vec3f(50, 50, 2);
	
	//mPiano = ci::Rectf(mPos.x, mPos.y, mSize.x,mSize.y);
	setColliderType(Collider::Rect);
}

void Piano::setup(){}

void Piano::update() {

}

void Piano::draw() {
	/*
	ci::gl::pushModelView();
	ci::gl::color(1.0f, 1.0f, 1.0f);
	ci::gl::draw(dowa::ResourceManager::texture().get(CinderellaTextureKey::Piano));
	ci::gl::popModelView();
	*/
}

void Piano::onCollisionUpdate(const std::shared_ptr<Object>& compare) {
	
	dowa::ResourceManager::audio().get(AudioKey::Menu).bgm->disable();
	dowa::ResourceManager::audio().get(AudioKey::StageSelectSE).bgm->enable();
	dowa::ResourceManager::audio().get(AudioKey::StageSelectSE).gain->setValue(1.0f);
}