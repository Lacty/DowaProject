
#include "TitleLoad.hpp"
#include "../../resource/ResourceManager.hpp"
#include "../SceneManager.hpp"



TitleLoad::TitleLoad() : mLoad(&TitleLoad::load, this), isFin(false), angle(0.0f) {}


void TitleLoad::load() {
  dowa::ResourceManager::texture().insert("background/title/TitleBack.png",         TextureKey::TitleBack);
  dowa::ResourceManager::texture().insert("background/title/FeatherBookResize.png", TextureKey::FeatherBook);
  dowa::ResourceManager::texture().insert("background/title/Logo.png",              TextureKey::Logo);
  dowa::ResourceManager::texture().insert("background/title/TapToStartEng.png",     TextureKey::TapToStartEng);
  dowa::ResourceManager::texture().insert("background/title/Trace.png",             TextureKey::Trace);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterTa.png",      TextureKey::LetterTa);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterMa.png",      TextureKey::LetterMa);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterKo.png",      TextureKey::LetterKo);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterRo.png",      TextureKey::LetterRo);
  dowa::ResourceManager::texture().insert("background/title/SphereBlue.png",        TextureKey::SphereBlue);
  dowa::ResourceManager::texture().insert("background/title/SphereGreen.png",       TextureKey::SphereGreen);
  dowa::ResourceManager::texture().insert("background/title/SphereRed.png",         TextureKey::SphereRed);
  isFin = true;
}

void TitleLoad::update() {
  if (isFin) {
    std::cout << "finish load" << std::endl;
    mLoad.join();
    SceneManager::create(SceneType::Title);
    isFin = false;
  }
}

void TitleLoad::draw() {
  angle+=0.1f;
  ci::gl::pushModelView();
  ci::gl::translate(ci::Vec2f(sin(angle) * 200, 0));
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), ci::Vec3f(50, 50, 50));
  ci::gl::popModelView();
}