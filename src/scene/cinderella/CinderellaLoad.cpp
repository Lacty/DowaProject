
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
  dowa::ResourceManager::texture().insert("object/cinderella/BarrelSide.png", CinderellaTextureKey::BarrelSide);
  dowa::ResourceManager::texture().insert("object/cinderella/BookOpen.png", CinderellaTextureKey::BookOpen);
  dowa::ResourceManager::texture().insert("object/cinderella/BookShelf.png", CinderellaTextureKey::BookShelf);
  dowa::ResourceManager::texture().insert("object/cinderella/BookPile.png", CinderellaTextureKey::BookPile);
  dowa::ResourceManager::texture().insert("object/cinderella/HungryBear.png", CinderellaTextureKey::HungryBear);
  dowa::ResourceManager::texture().insert("object/cinderella/SatisfiedBear.png", CinderellaTextureKey::SatisfiedBear);
  dowa::ResourceManager::texture().insert("object/cinderella/Piano.png", CinderellaTextureKey::Piano);

  // Sound
  dowa::ResourceManager::audio().insert("sound/se/Hit.ogg", AudioKey::HitSE);
  dowa::ResourceManager::audio().insert("sound/se/GameOver.ogg", AudioKey::GameOverSE);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/Town.ogg", CinderellaAudioKey::Town);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/Castle.ogg", CinderellaAudioKey::Castle);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/House.ogg", CinderellaAudioKey::House);
  dowa::ResourceManager::audio().insert("sound/bgm/cinderella/HousePiano.ogg", CinderellaAudioKey::HousePiano);
  dowa::ResourceManager::audio().insert("sound/se/cinderella/BookDrop.ogg", CinderellaAudioKey::BookDrop);
  dowa::ResourceManager::audio().insert("sound/se/cinderella/BookHit.ogg", CinderellaAudioKey::BookHit);

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
