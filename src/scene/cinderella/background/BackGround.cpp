
#include "BackGround.hpp"
#include "../../../window/Window.hpp"


BackGround::BackGround() {
  float mDeviceWindowWidth  = dowa::getWindowWidth();
  float mDeviceWindowHeight = dowa::getWindowHeight();
  
  mCinderellaHouse1 = TextureManager::find(ResKey::CHouse1);
  mCinderellaHouse2 = TextureManager::find(ResKey::CHouse2);
  mCinderellaHouse3 = TextureManager::find(ResKey::CHouse3);
  
  mCinderellaForest1 = TextureManager::find(ResKey::CForest1);
  mCinderellaForest2 = TextureManager::find(ResKey::CForest2);
  mCinderellaForest3 = TextureManager::find(ResKey::CForest3);
  mCinderellaForest4 = TextureManager::find(ResKey::CForest4);
  
  mCinderellaTown1 = TextureManager::find(ResKey::CTown1);
  mCinderellaTown2 = TextureManager::find(ResKey::CTown2);
  mCinderellaTown3 = TextureManager::find(ResKey::CTown3);

  mCinderellaHouseRect1 = ci::Rectf( 0.f,
                                    -mDeviceWindowHeight * 0.5f,
                                    mDeviceWindowWidth * 0.901409f,
                                    mDeviceWindowHeight * 0.5f);
  
  mCinderellaHouseRect2_1 = ci::Rectf( mDeviceWindowWidth * 0.875f,
                                      -mDeviceWindowHeight * 0.5f,
                                      mDeviceWindowWidth * 1.20598592f,
                                      mDeviceWindowHeight * 0.5f);
  
  mCinderellaHouseRect2_2 = ci::Rectf( mDeviceWindowWidth * 1.20598592f,
                                      -mDeviceWindowHeight * 0.5f,
                                      mDeviceWindowWidth * 1.53697183f,
                                      mDeviceWindowHeight * 0.5f);
  
  mCinderellaHouseRect2_3 = ci::Rectf( mDeviceWindowWidth * 1.53697183f,
                                      -mDeviceWindowHeight * 0.5f,
                                      mDeviceWindowWidth * 1.86795775f,
                                      mDeviceWindowHeight * 0.5f);
  
  mCinderellaHouseRect2_4 = ci::Rectf( mDeviceWindowWidth * 1.86795775f,
                                      -mDeviceWindowHeight * 0.5f,
                                      mDeviceWindowWidth * 2.19894366f,
                                      mDeviceWindowHeight * 0.5f);
  
  mCinderellaHouseRect3 = ci::Rectf( mDeviceWindowWidth * 2.19894366f,
                                    -mDeviceWindowHeight * 0.5f,
                                    mDeviceWindowWidth * 3.10035211f, // 1761
                                    mDeviceWindowHeight * 0.5f);
  
  mCinderellaForestRect1 = ci::Rectf( 1474, // 1474
                                     -mDeviceWindowHeight * 0.5f,
                                     1730, // 1730
                                     mDeviceWindowHeight * 0.5f);
  
  mCinderellaForestRect2 = ci::Rectf( 1730, // 1730
                                     -mDeviceWindowHeight * 0.5f,
                                     1986, // 1986
                                     mDeviceWindowHeight * 0.5f);
  
  mCinderellaForestRect3 = ci::Rectf( 1986, // 1986
                                     -mDeviceWindowHeight * 0.5f,
                                     2242, // 2242
                                     mDeviceWindowHeight * 0.5f);
  
  mCinderellaForestRect4 = ci::Rectf( 2242, // 2242
                                     -mDeviceWindowHeight * 0.5f,
                                     2495, // 2495
                                     mDeviceWindowHeight * 0.5f);
  
  mCinderellaTownRect1 = ci::Rectf( 2495, // 2495
                                   -mDeviceWindowHeight * 0.5f,
                                   3063, // 3063
                                   mDeviceWindowHeight * 0.5f);
  
  mCinderellaTownRect2 = ci::Rectf( 3063, // 3063
                                   -mDeviceWindowHeight * 0.5f,
                                   3631, // 3631
                                   mDeviceWindowHeight * 0.5f);
  
  mCinderellaTownRect3 = ci::Rectf( 3631, // 3631
                                   -mDeviceWindowHeight * 0.5f,
                                   4199, // 4199
                                   mDeviceWindowHeight * 0.5f);
}


void BackGround::setup() {}

void BackGround::update() {}

void BackGround::draw() {
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  
  ci::gl::draw( mCinderellaHouse1, mCinderellaHouseRect1);
  
  ci::gl::draw( mCinderellaHouse2, mCinderellaHouseRect2_1);
  ci::gl::draw( mCinderellaHouse2, mCinderellaHouseRect2_2);
  ci::gl::draw( mCinderellaHouse2, mCinderellaHouseRect2_3);
  ci::gl::draw( mCinderellaHouse2, mCinderellaHouseRect2_4);
  
  ci::gl::draw( mCinderellaHouse3, mCinderellaHouseRect3);
  
  ci::gl::draw( mCinderellaForest1, mCinderellaForestRect1);
  ci::gl::draw( mCinderellaForest2, mCinderellaForestRect2);
  ci::gl::draw( mCinderellaForest3, mCinderellaForestRect3);
  ci::gl::draw( mCinderellaForest4, mCinderellaForestRect4);
  
  ci::gl::draw( mCinderellaTown1, mCinderellaTownRect1);
  
  ci::gl::draw( mCinderellaTown3, mCinderellaTownRect2);
  ci::gl::draw( mCinderellaTown2, mCinderellaTownRect2);
  
  ci::gl::draw( mCinderellaTown1, mCinderellaTownRect3);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
}