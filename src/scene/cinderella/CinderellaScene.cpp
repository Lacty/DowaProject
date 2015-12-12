
// mDeviceWindowWidth = 568
// mDeviceWindowHeight = 320

// 画像１　サイズ 1024 577

#include "CinderellaScene.hpp"

#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"
#include "../../object/Task.hpp"
#include "../../collision/Collision.hpp"

#include "Floor.hpp"
#include "Cinderella.hpp"
#include "Ball.hpp"
#include "BookShelf.hpp"
#include "Book.hpp"

CinderellaScene::CinderellaScene()
{
  // コンストラクタでプッシュ
  ci::gl::pushMatrices();
  ci::gl::pushModelView();
  
  // デバイスの座標を代入
  mDeviceWindowWidth = ci::app::getWindowWidth();
  mDeviceWindowHeight = ci::app::getWindowHeight();
  
  // 背景 1
  mBack1 = ci::Rectf(0, -mDeviceWindowHeight / 2, 1024, mDeviceWindowHeight / 2);
  
  // 背景 2
  mBack21 = ci::Rectf(1000, -mDeviceWindowHeight / 2, 1469, mDeviceWindowHeight / 2);
  mBack22 = ci::Rectf(1469, -mDeviceWindowHeight / 2, 1938, mDeviceWindowHeight / 2);
  mBack23 = ci::Rectf(1938, -mDeviceWindowHeight / 2, 2407, mDeviceWindowHeight / 2);
  mBack24 = ci::Rectf(2407, -mDeviceWindowHeight / 2, 2876, mDeviceWindowHeight / 2);
  
  // 背景３
  mBack3 = ci::Rectf(2876, -mDeviceWindowHeight / 2, 3431, mDeviceWindowHeight / 2);
  
  // シンデレラさん
  Task::add("Cinderella", std::make_shared<Cinderella>(ci::Vec3f( 50.f, 50.f, 0.f),
                                                       ci::Vec3f( 50.f , 50.f, 0.f)));
  
  // 地面
  Task::add("Floor1", std::make_shared<Floor>(ci::Vec3f( 277.f,
                                                        -10.f, 0.f),
                                              ci::Vec3f( 548.f,
                                                        5.f, 0.f)));
  
  // 地面
  Task::add("Floor2", std::make_shared<Floor>(ci::Vec3f( 570.f,
                                                        -32.5f, 0.f),
                                              ci::Vec3f( 49.f,
                                                        5.f, 0.f)));
  
  // 地面
  Task::add("Floor3", std::make_shared<Floor>(ci::Vec3f( 612.f,
                                                        -55.5f, 0.f),
                                              ci::Vec3f( 49.f,
                                                        5.f, 0.f)));
  
  // 地面
  Task::add("Floor4", std::make_shared<Floor>(ci::Vec3f( 652.f,
                                                        -78.5f, 0.f),
                                              ci::Vec3f( 49.f,
                                                        5.f, 0.f)));
  
  // 地面
  Task::add("Floor5", std::make_shared<Floor>(ci::Vec3f( 695.f,
                                                        -101.5f, 0.f),
                                              ci::Vec3f( 49.f,
                                                        5.f, 0.f)));
  
  // 地面
  Task::add("Floor6", std::make_shared<Floor>(ci::Vec3f( 735.f,
                                                        -123.5f, 0.f),
                                              ci::Vec3f( 49.f,
                                                        5.f, 0.f)));
  
  // 地面 一番下
  Task::add("Floor_Floor", std::make_shared<Floor>(ci::Vec3f( 0.f,
                                                        -136.f, 0.f),
                                              ci::Vec3f( 10000.0f,
                                                         5.f, 0.f)));
  
  // ボール
  Task::add("Ball", std::make_shared<Ball>(ci::Vec3f( 50.f, 50.f, 0.f),
                                           ci::Vec3f( 40.f, 40.f, 0.f),
                                           0.2f));
  
  // 本棚
  Task::add("BookShelf", std::make_shared<BookShelf>(ci::Vec3f( 1200.f, 100.f, 0.f),
                                                     ci::Vec3f( 100.f, 50.f, 0.f)));
  
  // 本４冊
  Task::add("BookPile", std::make_shared<Book>(ci::Vec3f( 1200.f, 147.f, 0.f),
                                                   ci::Vec3f( 100.f, 50.f, 0.f)));
  
  // やないコード
  mcameraPos = ci::Vec3f( 100, 0, 300);
  camera = dowa::Camera(60, 0.5f, 300);
  camera.lookAt(mcameraPos,
                ci::Vec3f(0, 0, 0),
                ci::Vec3f::yAxis());
}

CinderellaScene::~CinderellaScene()
{
  // デストラクタでポップ
  ci::gl::popMatrices();
  ci::gl::popModelView();
}


void CinderellaScene::update()
{
  // やないコード
  mcameraPos.x = Task::find("Cinderella")->getPos().x;
  
  camera.lookAt(mcameraPos,
                ci::Vec3f(mcameraPos.x, mcameraPos.y, 0),
                ci::Vec3f::yAxis());
}

void CinderellaScene::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  camera.setMatrices(); // カメラセット
  ci::gl::pushModelView();
  
//  ci::gl::translate(ci::Vec3f(0, 180, 0)); // 位置を変えるならここ
  
  ci::gl::rotate(ci::Vec3f(180, 0, 0)); // 反転
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack1), mBack1);
  
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack21);
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack22);
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack23);
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack24);
  
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack3), mBack3);

  ci::gl::popModelView();
  ci::gl::disable(GL_TEXTURE_2D);
}
