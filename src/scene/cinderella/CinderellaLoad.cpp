
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
  TextureManager::add(ResKey::CHandRail);
  TextureManager::add(ResKey::CChandelier);
  TextureManager::add(ResKey::CChandelierHit);
  
  // background
  TextureManager::add(ResKey::CHouse1);
  TextureManager::add(ResKey::CHouse2);
  TextureManager::add(ResKey::CHouse3);
  TextureManager::add(ResKey::CForest1);
  TextureManager::add(ResKey::CForest2);
  TextureManager::add(ResKey::CForest3);
  TextureManager::add(ResKey::CForest4);
  TextureManager::add(ResKey::CTown1);
  TextureManager::add(ResKey::CTown2);
  TextureManager::add(ResKey::CTown3);
  TextureManager::add(ResKey::CForestGarden1);
  TextureManager::add(ResKey::CForestGarden2);
  TextureManager::add(ResKey::CDance);
  
  // Camera
  TextureManager::add(ResKey::CamHole);
  
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
