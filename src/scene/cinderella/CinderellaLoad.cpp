
#include "CinderellaLoad.hpp"
#include "../../resource/ResourceManager.hpp"
#include "../SceneManager.hpp"


CinderellaLoad::CinderellaLoad() :
isFin(false)
{
  std::cout << "start cinderella load" << std::endl;
}

CinderellaLoad::~CinderellaLoad() {
  std::cout << "end cinderella load" << std::endl;
}

void CinderellaLoad::load() {
  // Texture
  dowa::ResourceManager::texture().insert("character/cinderella/1.png", CinderellaTextureKey::CharacterStatic);
  dowa::ResourceManager::texture().insert("character/cinderella/2.png", CinderellaTextureKey::CharacterLeft);
  dowa::ResourceManager::texture().insert("character/cinderella/3.png", CinderellaTextureKey::CharacterRight);
  
  dowa::ResourceManager::texture().insert("object/cinderella/Apple.png", CinderellaTextureKey::Apple);
  dowa::ResourceManager::texture().insert("object/cinderella/BookSide.png", CinderellaTextureKey::BookSide);
  dowa::ResourceManager::texture().insert("object/cinderella/BookOpen.png", CinderellaTextureKey::BookOpen);
  dowa::ResourceManager::texture().insert("object/cinderella/BookShelf.png", CinderellaTextureKey::BookShelf);
  dowa::ResourceManager::texture().insert("object/cinderella/BookPile.png", CinderellaTextureKey::BookPile);
  dowa::ResourceManager::texture().insert("object/cinderella/HungryBear.png", CinderellaTextureKey::HungryBear);
  dowa::ResourceManager::texture().insert("object/cinderella/SatisfiedBear.png", CinderellaTextureKey::SatisfiedBear);
  dowa::ResourceManager::texture().insert("object/cinderella/Piano.png", CinderellaTextureKey::Piano);
  
  dowa::ResourceManager::texture().insert("background/title/SphereBlue.png", TextureKey::SphereBlue);
  dowa::ResourceManager::texture().insert("background/title/SphereGreen.png", TextureKey::SphereGreen);
  dowa::ResourceManager::texture().insert("background/title/SphereRed.png", TextureKey::SphereRed);
  
  // hiramasa
  dowa::ResourceManager::texture().insert("background/beta/HandRail.png", CinderellaTextureKey::HandRail);
  
  // β版
  dowa::ResourceManager::texture().insert("background/beta/1.png", CinderellaTextureKey::_betaBack1);
  dowa::ResourceManager::texture().insert("background/beta/2.png", CinderellaTextureKey::_betaBack2);
  dowa::ResourceManager::texture().insert("background/beta/3.png", CinderellaTextureKey::_betaBack3);

  // Sound
  dowa::ResourceManager::audio().insert("sound/se/Hit.m4a", AudioKey::HitSE);
  dowa::ResourceManager::audio().insert("sound/se/GameOver.m4a", AudioKey::GameOverSE);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/Town.m4a", CinderellaAudioKey::Town);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/Castle.m4a", CinderellaAudioKey::Castle);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/House.m4a", CinderellaAudioKey::House);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/HousePiano.m4a", CinderellaAudioKey::HousePiano);
  dowa::ResourceManager::audio().insert("sound/se/cinderella/BookDrop.m4a", CinderellaAudioKey::BookDrop);
  dowa::ResourceManager::audio().insert("sound/se/cinderella/BookHit.m4a", CinderellaAudioKey::BookHit);

  isFin = true;
}

void CinderellaLoad::update() {
  load();
  if (isFin) {
    std::cout << "finish load" << std::endl;
    SceneManager::create(SceneType::Cinderella);
    isFin = false;
  }
}

void CinderellaLoad::draw() {}
