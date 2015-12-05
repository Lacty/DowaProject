#include "Loading.hpp"
#include "../SceneManager.hpp"

Loading::Loading() {
  dowa::Resource::createTextures();
  mAudioInitOnce = false;
  ci::app::console() <<  "Loading Ctor" + dowa::Resource::texture().getCounter() << std::endl;
}

void Loading::update() {
  if (!dowa::Resource::texture().isEnabled()) {
    dowa::Resource::texture().enable();
    ci::app::console() << dowa::Resource::texture().getCounter() << std::endl;
  }

  if (dowa::Resource::texture().isEnabled()) {
    if (!mAudioInitOnce) {
      dowa::Resource::createAudio();
      ci::app::console() << dowa::Resource::audio().getCounter() << std::endl;
      mAudioInitOnce = true;
    }

    if (!dowa::Resource::audio().isEnabled()) {
      dowa::Resource::audio().enable();
      ci::app::console() << dowa::Resource::audio().getCounter() << std::endl;
    }

    if (dowa::Resource::audio().isEnabled()) {
      SceneManager::create(SceneType::Title);
    }
  }
}

void Loading::draw() {
  ci::gl::clear(ci::ColorA(1, 0, 0, 1));
}