
#include "Select.hpp"
#include "../../resource/ResourceManager.hpp"
#include "../../window/Window.hpp"
#include "../../device/Device.hpp"
#include "../SceneManager.hpp"


Select::Select() {
  std::cout << "start select" << std::endl;
  mBackGround = dowa::ResourceManager::texture().get(TextureKey::StageSelectBack);
  mBook       = dowa::ResourceManager::texture().get(TextureKey::StageSelectBook);
  mTitle      = dowa::ResourceManager::texture().get(TextureKey::StageSelectCinderella);

  mPlaneBG    = ci::Rectf(0, 0, dowa::getWindowWidth(), dowa::getWindowHeight());
  mPlaneBook  = ci::Rectf(-mBook.getWidth(), -mBook.getHeight(),
                           mBook.getWidth(),  mBook.getHeight()) * 0.3f;
  mPlaneTitle = ci::Rectf(-mTitle.getWidth(), -mTitle.getHeight(),
                           mTitle.getWidth(),  mTitle.getHeight()) * 0.2f;
}

Select::~Select() {
  std::cout << "end select" << std::endl;
  dowa::ResourceManager::texture().clear();
  dowa::ResourceManager::audio().clear();
}

void Select::update() {
  if (!dowa::Device::isTouchBegan()) return;
  SceneManager::create(SceneType::CinderellaLoad);
}

void Select::draw() {
  // 背景
  ci::gl::draw(mBackGround, mPlaneBG);
  
  // 本
  ci::gl::pushModelView();
  ci::gl::translate(dowa::getWindowCenter());
  ci::gl::draw(mBook, mPlaneBook);
  ci::gl::popModelView();

  // title
  ci::Vec2f offset(0, 70);
  ci::gl::pushModelView();
  ci::gl::translate(dowa::getWindowCenter() + offset);
  ci::gl::draw(mTitle, mPlaneTitle);
  ci::gl::popModelView();
}

