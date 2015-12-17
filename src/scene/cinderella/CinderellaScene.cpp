
// mDeviceWindowWidth = 568
// mDeviceWindowHeight = 320

// 林さん要望 ステージの端から端までの移動で
// オブジェクトになにも干渉しなかった場合、約30秒にする

#include "CinderellaScene.hpp"

#include "floor/Floor.hpp"
#include "cinderella/Cinderella.hpp"
#include "ball/Ball.hpp"
#include "bookshelf/BookShelf.hpp"
#include "book/Book.hpp"
#include "piano/Piano.hpp"

#include "../../object/Task.hpp"

CinderellaScene::CinderellaScene()
{
  std::cout << "start cinderella" << std::endl;
  
  ci::gl::pushMatrices();
  ci::gl::pushModelView();
  
  mDeviceWindowWidth = ci::app::getWindowWidth();
  mDeviceWindowHeight = ci::app::getWindowHeight();
  
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
  
  // デレキャラ
  Task::add("Cinderella", std::make_shared<Cinderella>(ci::Vec3f( 150.f, 50.f, 0),
                                                       ci::Vec3f( 75.f, 75.f, 0)));
  
  // 地面
  Task::add("Floor1", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.24471831f,
                                                        -mDeviceWindowHeight * 0.03125f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.48415493f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // 地面
  Task::add("Floor2", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.50176056f,
                                                        -mDeviceWindowHeight * 0.1015625f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.04401408f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // 地面
  Task::add("Floor3", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.53873239f,
                                                        -mDeviceWindowHeight * 0.171875f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.04401408f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // 地面
  Task::add("Floor4", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.57394366f,
                                                        -mDeviceWindowHeight * 0.2453125f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.04401408f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // 地面
  Task::add("Floor5", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.61179577f,
                                                        -mDeviceWindowHeight * 0.3171875f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.04401408f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // 地面
  Task::add("Floor6", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.64700704f,
                                                        -mDeviceWindowHeight * 0.3859375f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.04401408f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // 地面 一番下
  Task::add("Floor_Floor", std::make_shared<Floor>(ci::Vec3f( 0.f,
                                                        -155.f, 0.f),
                                                   ci::Vec3f( 10000.0f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // ボール
  Task::add("Ball", std::make_shared<Ball>(ci::Vec3f( 50.f, 50.f, 0.f),
                                           ci::Vec3f( 40.f, 40.f, 0.f),
                                           0.2f));
  
  
  // 本棚
  Task::add("BookShelf", std::make_shared<BookShelf>(ci::Vec3f( 1300.f, 0.f, 0.f),
                                                     ci::Vec3f( 130.f, 50.f, 0.f)));
  
  
  // 本４冊
  Task::add("BookPile", std::make_shared<Book>(ci::Vec3f( 1260.f, 48.f, 0.f),
                                               ci::Vec3f( 100.f, 50.f, 0.f), "BookPile"));
  
  
  // 本 横向き
  Task::add("BookSide", std::make_shared<Book>(ci::Vec3f( 1218.f, 75.f, 0.f),
                                               ci::Vec3f( 55.f, 10.f, 0.f), "BookSide"));
  
  
  // ピアノ
  Task::add("Piano", std::make_shared<Piano>(ci::Vec3f( 800.f, -90.f, 0.f),
                                             ci::Vec3f( 150.f, 125.f, 0.f)));
  
  
  // やないコード
  mcameraPos = ci::Vec3f( 100, 0, 300);
  camera = dowa::Camera(60, 0.5f, 300);
  camera.lookAt(mcameraPos,
                ci::Vec3f(0, 0, 0),
                ci::Vec3f::yAxis());
  
  // BGM
  dowa::ResourceManager::audio().get(CinderellaAudioKey::House).gain->setValue(0.f);
  dowa::ResourceManager::audio().get(CinderellaAudioKey::House).bgm->enable();
}

CinderellaScene::~CinderellaScene()
{
  ci::gl::popMatrices();
  ci::gl::popModelView();
  
  std::cout << "end cinderella" << std::endl;
  dowa::ResourceManager::texture().clear();
  dowa::ResourceManager::audio().clear();
  
//  Task::clear();
}


void CinderellaScene::update()
{
  // やないコード
  mcameraPos.x = Task::find("Cinderella")->getPos().x;
  
  camera.lookAt(mcameraPos,
                ci::Vec3f(mcameraPos.x, mcameraPos.y, 0),
                ci::Vec3f::yAxis());
  
  // BGM 音量 Set
  dowa::ResourceManager::audio().get(CinderellaAudioKey::House).gain->setValue(1.0f);
}

void CinderellaScene::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  
  camera.setMatrices(); // カメラセット
  
  ci::gl::pushModelView();
  
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack1), mBack1);
  
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack21);
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack22);
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack23);
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack24);
  
  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack3), mBack3);
  
  ci::gl::popModelView();
  
  ci::gl::disable(GL_TEXTURE_2D);
}
