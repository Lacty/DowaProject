
#include "CinderellaLoad.hpp"
#include "../../resource/Resource.hpp"
#include "../SceneManager.hpp"
#include "../../window/Window.hpp"


CinderellaLoad::CinderellaLoad() {
  std::cout << "start cinderella load" << std::endl;
  TextureManager::add(ResKey::NowLoad);
  count = -1;
}

CinderellaLoad::~CinderellaLoad() {
  std::cout << "end cinderella load" << std::endl;
}

void CinderellaLoad::load()
{
  // Texture
  TextureManager::add(ResKey::CCinderella1);
  TextureManager::add(ResKey::CCinderella2);
  TextureManager::add(ResKey::CCinderella3);
  TextureManager::add(ResKey::CCinderellaDown);
  TextureManager::add(ResKey::CCinderellaCry);
  TextureManager::add(ResKey::CCinderellaDance);
  
  // Witch
  TextureManager::add(ResKey::CWitch1);
  TextureManager::add(ResKey::CWitch2);
  
  // King
  TextureManager::add(ResKey::CKing1);
  TextureManager::add(ResKey::CKing2);
  
  // Sister
  TextureManager::add(ResKey::CSister1);
  TextureManager::add(ResKey::CSister2);
  TextureManager::add(ResKey::CSister3);
  
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
  
  // Hose
  TextureManager::add(ResKey::CHandRail);
  TextureManager::add(ResKey::CChandelier);
  TextureManager::add(ResKey::CChandelierHit);
  
  // Town
  TextureManager::add(ResKey::CBridge);
  TextureManager::add(ResKey::CGrayCube);
  TextureManager::add(ResKey::CHorse1);
  TextureManager::add(ResKey::CHorse2);
  TextureManager::add(ResKey::CHorse3);
  TextureManager::add(ResKey::CHorse4);
  TextureManager::add(ResKey::CHorse5);
  TextureManager::add(ResKey::CHorse6);
  TextureManager::add(ResKey::CHydrant);
  TextureManager::add(ResKey::CLampPost);
  TextureManager::add(ResKey::CPlate);
  TextureManager::add(ResKey::CPlateFall);
  TextureManager::add(ResKey::CPumpkin1);
  TextureManager::add(ResKey::CPumpkin2);
  TextureManager::add(ResKey::CRiver);
  TextureManager::add(ResKey::CShop);
  TextureManager::add(ResKey::CWindow1);
  TextureManager::add(ResKey::CWindow2);
  TextureManager::add(ResKey::CWindow3);
  TextureManager::add(ResKey::CWindowHit1);
  TextureManager::add(ResKey::CWindowHit2);
  TextureManager::add(ResKey::CWindowHit3);
  TextureManager::add(ResKey::CWindowOpen);
  TextureManager::add(ResKey::CWoodenBox);
  
  // ForestGarden
  TextureManager::add(ResKey::CGate);
  TextureManager::add(ResKey::CGateBack);
  TextureManager::add(ResKey::CGateSide);
  
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
  TextureManager::add(ResKey::CForestGarden3);
  TextureManager::add(ResKey::CForestGarden4);
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
  AudioManager::add(ResKey::CWindowClose);
  AudioManager::add(ResKey::CPlateFallSE);

  std::cout << "finish load" << std::endl;
}

void CinderellaLoad::update() {
  ++count;
  if (!count) return;

  load();
  SceneManager::create(SceneType::Cinderella);
}

void CinderellaLoad::draw() {
  ci::gl::clear(ci::Color(0.4f, 0.4f, 0.4f));
  
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  ci::gl::Texture image = TextureManager::find(ResKey::NowLoad);
  float offset_x = dowa::getWindowWidth() - image.getWidth();
  float offset_y = dowa::getWindowHeight() - image.getHeight();
  ci::gl::translate(offset_x, offset_y);
  ci::gl::draw(image);
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
}
