
#include "CinderellaLoad.hpp"
#include "../../resource/Resource.hpp"
#include "../SceneManager.hpp"


CinderellaLoad::CinderellaLoad() {
  std::cout << "start cinderella load" << std::endl;
}

CinderellaLoad::~CinderellaLoad() {
  std::cout << "end cinderella load" << std::endl;
}

void CinderellaLoad::load() {
  // Texture
  TextureManager::add(ResKey::CCharacterStatic);
  TextureManager::add(ResKey::CCharacterLeft);
  TextureManager::add(ResKey::CCharacterRight);
  
  TextureManager::add(ResKey::CApple);
  TextureManager::add(ResKey::CBookSide);
  TextureManager::add(ResKey::CBookOpen);
  TextureManager::add(ResKey::CBookShelf);
  TextureManager::add(ResKey::CBookPile);
  TextureManager::add(ResKey::CHungryBear);
  TextureManager::add(ResKey::CStatisfiedBrear);
  TextureManager::add(ResKey::CPiano);
  
  TextureManager::add(ResKey::CSphereBlue);
  TextureManager::add(ResKey::CSphereGreen);
  TextureManager::add(ResKey::CSphereRed);
  
  // hiramasa
  TextureManager::add(ResKey::CHandRail);
  
  // background
  TextureManager::add(ResKey::CCinderellaHouse1);
  TextureManager::add(ResKey::CCinderellaHouse2);
  TextureManager::add(ResKey::CCinderellaHouse3);
  TextureManager::add(ResKey::CCinderellaForest1);
  TextureManager::add(ResKey::CCinderellaForest2);
  TextureManager::add(ResKey::CCinderellaForest3);
  TextureManager::add(ResKey::CCinderellaForest4);
  TextureManager::add(ResKey::CCinderellaTown1);
  TextureManager::add(ResKey::CCinderellaTown2);
  TextureManager::add(ResKey::CCinderellaTown3);
  
  // hiramasa
  TextureManager::add(ResKey::CBridgeRiver);
  TextureManager::add(ResKey::CHydrant);
  TextureManager::add(ResKey::CLampPost);
  TextureManager::add(ResKey::CPlate);
  TextureManager::add(ResKey::CPlateFall);
  TextureManager::add(ResKey::CPumpkin1);
  TextureManager::add(ResKey::CPumpkin2);
  TextureManager::add(ResKey::CShop);
  TextureManager::add(ResKey::CWindow1);
  TextureManager::add(ResKey::CWindow2);
  TextureManager::add(ResKey::CWindow3);
  TextureManager::add(ResKey::CWindowOpen);
  TextureManager::add(ResKey::CWoodenBox);
  TextureManager::add(ResKey::CWitch1);
  TextureManager::add(ResKey::CWitch2);
  TextureManager::add(ResKey::CGrayCube);
  
  // Sound
  AudioManager::add(ResKey::CHitSE);
  AudioManager::add(ResKey::CGameOverSE);
  AudioManager::add(ResKey::CTown);
  AudioManager::add(ResKey::CCastle);
  AudioManager::add(ResKey::CHouse);
  AudioManager::add(ResKey::CHousePiano);
  AudioManager::add(ResKey::CBookDrop);
  AudioManager::add(ResKey::CBookHit);

  std::cout << "finish load" << std::endl;
}

void CinderellaLoad::update() {
  load();
  SceneManager::create(SceneType::Cinderella);
}

void CinderellaLoad::draw() {}
