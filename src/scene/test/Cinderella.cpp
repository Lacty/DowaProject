
#include "CinderellaScene.hpp"

#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"

CinderellaScene::CinderellaScene()
{
  camera = dowa::Camera(60, 0.5, 300);
  camera.lookAt(ci::Vec3f(0, 0, 200), 
  ci::Vec3f::zero(), ci::Vec3f::yAxis());
  mWindowWidth = ci::app::getWindowWidth();
  mWindowHeight = ci::app::getWindowHeight();
  mBack1 = ci::Rectf(-150,100,450,-100);
  /*mBack2 = ci::Rectf(150,100, 300,-100);
  mBack3 = ci::Rectf(300,100,450,-100);*/
  mXPos = 0;
}


void CinderellaScene::update()
{
  mXPos -= 0.1f;
  mBack1 = ci::Rectf(-150 + mXPos, 100, 450 + mXPos, -100);
  /*mBack2 = ci::Rectf(150 + mXPos, 100, 300 + mXPos, -100);
  mBack3 = ci::Rectf(300 + mXPos, 100, 450 + mXPos, -100);*/
  
  if(dowa::Device::isTouchBegan())
  {
    SceneManager::create(SceneType::Select);
  }
}

void CinderellaScene::draw()
{
  ci::gl::pushMatrices();
  ci::gl::pushModelView();
  
  ci::gl::enable(GL_TEXTURE_2D);
  
  camera.setMatrices();
  
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack1), mBack1);
  
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::popMatrices();
  ci::gl::popModelView();
}
