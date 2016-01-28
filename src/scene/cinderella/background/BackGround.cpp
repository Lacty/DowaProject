
// mDeviceWindowWidth = 568
// mDeviceWindowHeight = 320

#include "BackGround.hpp"

#include "../../../window/Window.hpp"


BackGround::BackGround()
{
  
  float mDeviceWindowWidth  = dowa::getWindowWidth();
  float mDeviceWindowHeight = dowa::getWindowHeight();
  
  mHouse1 = TextureManager::find(ResKey::CHouse1);
  mHouse2 = TextureManager::find(ResKey::CHouse2);
  mHouse3 = TextureManager::find(ResKey::CHouse3);
  
  mForest1 = TextureManager::find(ResKey::CForest1);
  mForest2 = TextureManager::find(ResKey::CForest2);
  mForest3 = TextureManager::find(ResKey::CForest3);
  mForest4 = TextureManager::find(ResKey::CForest4);
  
  mTown1 = TextureManager::find(ResKey::CTown1);
  mTown2 = TextureManager::find(ResKey::CTown2);
  mTown3 = TextureManager::find(ResKey::CTown3);
  
  mForestGarden1 = TextureManager::find(ResKey::CForestGarden1);
  mForestGarden2 = TextureManager::find(ResKey::CForestGarden2);
  mForestGarden3 = TextureManager::find(ResKey::CForestGarden3);
  mForestGarden4 = TextureManager::find(ResKey::CForestGarden4);
  
  mDance = TextureManager::find(ResKey::CDance);

  mHouseRect1 = ci::Rectf( 0.f,
                          -mDeviceWindowHeight * 0.5f,
                           mDeviceWindowWidth * 0.901409f,
                           mDeviceWindowHeight * 0.5f);
  
  mHouseRect2_1 = ci::Rectf( mDeviceWindowWidth * 0.875f,
                            -mDeviceWindowHeight * 0.5f,
                             mDeviceWindowWidth * 1.20598592f,
                             mDeviceWindowHeight * 0.5f);
  
  mHouseRect2_2 = ci::Rectf( mDeviceWindowWidth * 1.20598592f,
                            -mDeviceWindowHeight * 0.5f,
                             mDeviceWindowWidth * 1.53697183f,
                             mDeviceWindowHeight * 0.5f);
  
  mHouseRect2_3 = ci::Rectf( mDeviceWindowWidth * 1.53697183f,
                            -mDeviceWindowHeight * 0.5f,
                             mDeviceWindowWidth * 1.86795775f,
                             mDeviceWindowHeight * 0.5f);
  
  mHouseRect2_4 = ci::Rectf( mDeviceWindowWidth * 1.86795775f,
                            -mDeviceWindowHeight * 0.5f,
                             mDeviceWindowWidth * 2.19894366f,
                             mDeviceWindowHeight * 0.5f);
  
  mHouseRect3 = ci::Rectf( mDeviceWindowWidth * 2.19894366f,
                          -mDeviceWindowHeight * 0.5f,
                           mDeviceWindowWidth * 3.10035211f, // 1761
                           mDeviceWindowHeight * 0.5f);
  
  mForestRect1 = ci::Rectf( mDeviceWindowWidth * 2.59507042253521f, // 1474
                           -mDeviceWindowHeight * 0.5f,
                            mDeviceWindowWidth * 3.04577464788732f, // 1730
                            mDeviceWindowHeight * 0.5f);
  
  mForestRect2 = ci::Rectf( mDeviceWindowWidth * 3.04577464788732f, // 1730
                           -mDeviceWindowHeight * 0.5f,
                            mDeviceWindowWidth * 3.49647887323944f, // 1986
                            mDeviceWindowHeight * 0.5f);
  
  mForestRect3 = ci::Rectf( mDeviceWindowWidth * 3.49647887323944f, // 1986
                           -mDeviceWindowHeight * 0.5f,
                            mDeviceWindowWidth * 3.94718309859155f, // 2242
                            mDeviceWindowHeight * 0.5f);
  
  mForestRect4 = ci::Rectf( mDeviceWindowWidth * 3.94718309859155f, // 2242
                           -mDeviceWindowHeight * 0.5f,
                            mDeviceWindowWidth * 4.39260563380282f, // 2495
                            mDeviceWindowHeight * 0.5f);
  
  mTownRect1 = ci::Rectf( mDeviceWindowWidth * 4.39260563380282f, // 2495
                         -mDeviceWindowHeight * 0.5f,
                          mDeviceWindowWidth * 5.39260563380282f, // 3063
                          mDeviceWindowHeight * 0.5f);
  
  mTownRect2 = ci::Rectf( mDeviceWindowWidth * 5.39260563380282f, // 3063
                         -mDeviceWindowHeight * 0.5f,
                          mDeviceWindowWidth * 6.39260563380282f, // 3631
                          mDeviceWindowHeight * 0.5f);
  
  mTownRect3 = ci::Rectf( mDeviceWindowWidth * 6.39260563380282f, // 3631
                         -mDeviceWindowHeight * 0.5f,
                          mDeviceWindowWidth * 7.39260563380282f, // 4199
                          mDeviceWindowHeight * 0.5f);
  
  
  mForestGardenRect1 = ci::Rectf ( mDeviceWindowWidth * 7.39260563380282f,
                                  -mDeviceWindowHeight * 0.5f,
                                   mDeviceWindowWidth * 7.84330985915493f,
                                   mDeviceWindowHeight * 0.5f);
  
  mForestGardenRect2 = ci::Rectf ( mDeviceWindowWidth * 7.84330985915493f,
                                  -mDeviceWindowHeight * 0.5f,
                                   mDeviceWindowWidth * 8.29401408450704f,
                                   mDeviceWindowHeight * 0.5f);
  
  mForestGardenRect3 = ci::Rectf ( mDeviceWindowWidth * 8.29401408450704f,
                                  -mDeviceWindowHeight * 0.5f,
                                   mDeviceWindowWidth * 8.74471830985915f,
                                   mDeviceWindowHeight * 0.5f);
  
  mForestGardenRect4 = ci::Rectf ( mDeviceWindowWidth * 8.74471830985915f,
                                  -mDeviceWindowHeight * 0.5f,
                                   mDeviceWindowWidth * 9.19542253521127f,
                                   mDeviceWindowHeight * 0.5f);
  
  mDanceRect1 = ci::Rectf ( mDeviceWindowWidth * 9.19542253521127f,
                           -mDeviceWindowHeight * 0.5f,
                            mDeviceWindowWidth * 10.19542253521127f,
                            mDeviceWindowHeight * 0.5f);
  
  mDanceRect2 = ci::Rectf ( mDeviceWindowWidth * 10.19542253521127,
                           -mDeviceWindowHeight * 0.5f,
                            mDeviceWindowWidth * 11.19542253521127f,
                            mDeviceWindowHeight * 0.5f);
  
}


void BackGround::setup() {}

void BackGround::update() {}

void BackGround::draw()
{
  
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  
  ci::gl::draw( mHouse1, mHouseRect1);
  ci::gl::draw( mHouse2, mHouseRect2_1);
  ci::gl::draw( mHouse2, mHouseRect2_2);
  ci::gl::draw( mHouse2, mHouseRect2_3);
  ci::gl::draw( mHouse2, mHouseRect2_4);
  ci::gl::draw( mHouse3, mHouseRect3);
  
  ci::gl::draw( mForest1, mForestRect1);
  ci::gl::draw( mForest2, mForestRect2);
  ci::gl::draw( mForest3, mForestRect3);
  ci::gl::draw( mForest4, mForestRect4);
  
  ci::gl::draw( mTown1, mTownRect1);
  ci::gl::draw( mTown3, mTownRect2);
  ci::gl::draw( mTown2, mTownRect2);
  ci::gl::draw( mTown1, mTownRect3);
  
  ci::gl::draw( mForestGarden1, mForestGardenRect1);
  ci::gl::draw( mForestGarden2, mForestGardenRect2);
  ci::gl::draw( mForestGarden3, mForestGardenRect3);
  ci::gl::draw( mForestGarden4, mForestGardenRect4);
  
  ci::gl::draw( mDance, mDanceRect1);
  ci::gl::draw( mDance, mDanceRect2);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
}
