#include "Loading.hpp"
#include "../SceneManager.hpp"

Loading::Loading() {
  dowa::Resource::createTextures();
  mAudioInitOnce = false;
  mFont = ci::Font(ci::app::loadAsset("font/HoboStd.otf"), 100);
}

void Loading::update() {
  if (!dowa::Resource::texture().isEnabled()) {
    dowa::Resource::texture().enable();
    ci::app::console() << dowa::Resource::texture().getCounter() << std::endl;
  }

  if (dowa::Resource::texture().isEnabled()) {
    if (!mAudioInitOnce) {
      dowa::Resource::createAudio();
      ci::app::console() << "createAudio" << std::endl;
      mAudioInitOnce = true;
    }

    if (!dowa::Resource::audio().isEnabled()) {
      dowa::Resource::audio().enable();
      //ci::app::console() << dowa::Resource::audio().getCounter() << std::endl;
    }

    if (dowa::Resource::audio().isEnabled()) {
      SceneManager::create(SceneType::Cinderella);
    }
  }
}

void Loading::draw() {
  ci::gl::enableAlphaBlending();
  ci::gl::clear(ci::ColorA(0.5f,0.5f,0.5f));
  ci::gl::drawStringCentered("Loading...", ci::Vec2f(ci::app::getWindowWidth()/2,ci::app::getWindowHeight()/2),ci::Color::white(),mFont);
  ci::gl::disableAlphaBlending();
}