
// mDeviceWindowWidth = 568
// mDeviceWindowHeight = 320

// 林さん要望 ステージの端から端までの移動で
// オブジェクトになにも干渉しなかった場合、約30秒にする

#include "CinderellaScene.hpp"

#include "cinderella/Cinderella.hpp"
#include "floor/Floor.hpp"
#include "ball/Ball.hpp"
#include "bookshelf/BookShelf.hpp"
#include "book/Book.hpp"
#include "piano/Piano.hpp"
#include "handrail/HandRail.hpp"
#include "apple/Apple.hpp"
#include "bear/Bear.hpp"
#include "stairs/Stairs.hpp"

#include "../../object/Task.hpp"
#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"

CinderellaScene::CinderellaScene()
{
  std::cout << "start cinderella" << std::endl;
  
  ci::gl::pushMatrices();
  ci::gl::pushModelView();
  
  mDeviceWindowWidth = (float)ci::app::getWindowWidth();
  mDeviceWindowHeight = (float)ci::app::getWindowHeight();
  
  // 画像追加
  mBack1Texutre = TextureManager::find(ResKey::CCinderellaHouse1);
  mBack2Texutre = TextureManager::find(ResKey::CCinderellaHouse2);
  mBack3Texutre = TextureManager::find(ResKey::CCinderellaHouse3);
  
  // 背景 1
  mBack1 = ci::Rectf( 0.f, -mDeviceWindowHeight * 0.5f,
                      mDeviceWindowWidth * 0.901409f, mDeviceWindowHeight * 0.5f);
  
  // 背景 2
  mBack21 = ci::Rectf( mDeviceWindowWidth * 0.875f, -mDeviceWindowHeight * 0.5f,
                       mDeviceWindowWidth * 1.20598592f, mDeviceWindowHeight * 0.5f);
  
  mBack22 = ci::Rectf( mDeviceWindowWidth * 1.20598592f, -mDeviceWindowHeight * 0.5f,
                       mDeviceWindowWidth * 1.53697183f, mDeviceWindowHeight * 0.5f);
  
  mBack23 = ci::Rectf( mDeviceWindowWidth * 1.53697183f, -mDeviceWindowHeight * 0.5f,
                       mDeviceWindowWidth * 1.86795775f, mDeviceWindowHeight * 0.5f);
  
  mBack24 = ci::Rectf( mDeviceWindowWidth * 1.86795775f, -mDeviceWindowHeight * 0.5f,
                       mDeviceWindowWidth * 2.19894366f, mDeviceWindowHeight * 0.5f);
  
  // 背景３
  mBack3 = ci::Rectf( mDeviceWindowWidth * 2.19894366f, -mDeviceWindowHeight * 0.5f,
                      mDeviceWindowWidth * 3.10035211f, mDeviceWindowHeight * 0.5f);
  
  // 背景４
  //mBack4 = ci::Rectf( mDeviceWindowWidth * 3.10035211f, -mDeviceWindowHeight * 0.5f,
  //                    mDeviceWindowWidth * 0, mDeviceWindowHeight * 0.5f); // x2 値後で変える
  
  // 地面
  Task::add("Floor1", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.24471831f,
                                                        -mDeviceWindowHeight * 0.03125f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.48415493f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  // 階段
  Task::add("Stairs", std::make_shared<Stairs>(ci::Vec3f( 353.f, -40.f, 0.f),
                                               ci::Vec3f( 145.f, 208.f, 0.f)));
  
  // 地面 一番下
  Task::add("Floor_Floor", std::make_shared<Floor>(ci::Vec3f( 0.f,
                                                        -155.f, 0.f),
                                                   ci::Vec3f( 10000.0f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  // ボール
  Task::add("Ball", std::make_shared<Ball>(ci::Vec3f( 50.f, 50.f, 0.f),
                                           ci::Vec3f( 40.f, 40.f, 0.f),
                                           0.2f));
  
  // ピアノ
  Task::add("Piano", std::make_shared<Piano>(ci::Vec3f( 800.f, -90.f, 0.f),
                                             ci::Vec3f( 150.f, 125.f, 0.f)));
  
  // 本棚
  Task::add("BookShelf", std::make_shared<BookShelf>(ci::Vec3f( 1300.f, 0.f, 0.f),
                                                     ci::Vec3f( 130.f, 50.f, 0.f)));
  
  // 本４冊
  Task::add("BookPile", std::make_shared<Book>(ci::Vec3f( 1260.f, 48.f, 0.f),
                                               ci::Vec3f( 100.f, 50.f, 0.f), "BookPile"));
  
  // 本 横向き
  Task::add("BookSide", std::make_shared<Book>(ci::Vec3f( 1218.f, 75.f, 0.f),
                                               ci::Vec3f( 55.f, 10.f, 0.f), "BookSide"));

  // 熊
  Task::add("Bear", std::make_shared<Bear>(ci::Vec3f( 1600.f, -110, 0.f),
                                           ci::Vec3f( 50.f, 80.f, 0.f)));
  
  // りんご
  Task::add("Apple", std::make_shared<Apple>(ci::Vec3f( 0, 0, 0),
                                             ci::Vec3f( 0, 0, 0)));
  
  
  // シンデレラ
  Task::add("Cinderella", std::make_shared<Cinderella>(ci::Vec3i( mDeviceWindowWidth * 0.264084507042254f,
                                                                  mDeviceWindowHeight * 0.15625f, 0.f),
                                                       ci::Vec3i( mDeviceWindowWidth * 0.13204225352113f,
                                                                  mDeviceWindowHeight * 0.234375f, 0.f)));
  
  // 手すり
  Task::add("HandRail", std::make_shared<HandRail>(ci::Vec3f( 324.f, -40.f, 0.f),
                                                   ci::Vec3f( 145.f, 208.f, 0.f)));
  
  mCameraPos = ci::Vec3f( 250.f, 0.f, 300.f);
  camera = dowa::Camera(60.f, 0.5f, 300.f);
  
  camera.lookAt(mCameraPos,
                ci::Vec3f(mCameraPos.x, mCameraPos.y, 0.f),
                ci::Vec3f::yAxis());
  
  camera.setStageSize(0.0f, 3000.0f);
  camera.setForcusObj(Task::find("Cinderella"));
  
  // シンデレラの右側にカメラの焦点をあてる
  camera.setOffset(100.0f);
}

CinderellaScene::~CinderellaScene()
{
  ci::gl::popMatrices();
  ci::gl::popModelView();
  
  std::cout << "end cinderella" << std::endl;
  
  Task::clear();
}


void CinderellaScene::update()
{
  camera.update();
}

void CinderellaScene::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  camera.setMatrices();
  
  ci::gl::pushModelView();
  
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  
  ci::gl::draw(mBack1Texutre, mBack1);
  
  ci::gl::draw(mBack2Texutre, mBack21);
  ci::gl::draw(mBack2Texutre, mBack22);
  ci::gl::draw(mBack2Texutre, mBack23);
  ci::gl::draw(mBack2Texutre, mBack24);
  
  ci::gl::draw(mBack3Texutre, mBack3);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
}
