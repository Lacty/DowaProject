
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
#include "townwindow/Townwindow.hpp"
#include "hydrant/Hydrant.hpp"

#include "../../object/Task.hpp"
#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"


CinderellaScene::CinderellaScene()
{
  std::cout << "start cinderella" << std::endl;
  
  ci::gl::pushMatrices();
  ci::gl::pushModelView();
  
  mDeviceWindowWidth = ci::app::getWindowWidth();
  mDeviceWindowHeight = ci::app::getWindowHeight();
  
  // 画像追加
  mCinderellaHouse1 = TextureManager::find(ResKey::CCinderellaHouse1);
  mCinderellaHouse2 = TextureManager::find(ResKey::CCinderellaHouse2);
  mCinderellaHouse3 = TextureManager::find(ResKey::CCinderellaHouse3);
  
  mCinderellaForest1 = TextureManager::find(ResKey::CCinderellaForest1);
  mCinderellaForest2 = TextureManager::find(ResKey::CCinderellaForest2);
  mCinderellaForest3 = TextureManager::find(ResKey::CCinderellaForest3);
  mCinderellaForest4 = TextureManager::find(ResKey::CCinderellaForest4);
  
  mCinderellaTown1 = TextureManager::find(ResKey::CCinderellaTown1);
  mCinderellaTown2 = TextureManager::find(ResKey::CCinderellaTown2);
  mCinderellaTown3 = TextureManager::find(ResKey::CCinderellaTown3);
  
  
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
  Task::add("SatisfiedBear", std::make_shared<Bear>(ci::Vec3f( 1800.f, 0, 0.f),
                                                    ci::Vec3f( 80.f, 130.f, 0.f), "SatisfiedBear"));
  
  
  Task::add("HungryBear", std::make_shared<Bear>(ci::Vec3f( 2200.f, 0, 0.f),
                                                 ci::Vec3f( 80.f, 130.f, 0.f), "HungryBear"));
  
  Task::add("Apple", std::make_shared<Apple>(ci::Vec3f( 2000, 0, 0),
                                             ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("TownWindowRight_1", std::make_shared<Townwindow>(ci::Vec3f( 2664, -7, 0), // 2664, -7
                                                              ci::Vec3f( 77, 105, 0), "TownWindowRight")); // 77, 105
  
  
  Task::add("TownWindowLeft_1", std::make_shared<Townwindow>(ci::Vec3f( 2559, -7, 0), // 2559, -7
                                                             ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowTop_1", std::make_shared<Townwindow>(ci::Vec3f( 2607, 68, 0), // 2607, 68
                                                            ci::Vec3f( 75, 90, 0), "TownWindowTop")); // 75, 90
  
  
  Task::add("TownWindowLeft_2", std::make_shared<Townwindow>(ci::Vec3f( 2905, -7, 0), // 2905, -7
                                                             ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowRight_2", std::make_shared<Townwindow>(ci::Vec3f( 3009, -7, 0), // 3009, -7
                                                              ci::Vec3f( 77, 105, 0), "TownWindowRight")); // 77, 105
  
  
  Task::add("TownWindowOpen_2", std::make_shared<Townwindow>(ci::Vec3f( 2953, 74, 0), // 2953, 74
                                                              ci::Vec3f( 110, 90, 0), "TownWindowOpen")); // 110, 90
  
  
  Task::add("TownWindowLeft_3", std::make_shared<Townwindow>(ci::Vec3f( 3127, -7, 0), // 3127, -7
                                                             ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowTop_3", std::make_shared<Townwindow>(ci::Vec3f( 3175, 68, 0), // 3175, 68
                                                            ci::Vec3f( 75, 90, 0), "TownWindowTop")); // 75, 90
  
  
  Task::add("TownWindowLeft_4", std::make_shared<Townwindow>(ci::Vec3f( 3473, -7, 0), // 3473, -7
                                                             ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowTop_4", std::make_shared<Townwindow>(ci::Vec3f( 3520, 68, 0), // 3520, 68
                                                            ci::Vec3f( 75, 90, 0), "TownWindowTop")); // 75, 90
  
  
  Task::add("TownWindowLeft_5", std::make_shared<Townwindow>(ci::Vec3f( 3695, -7, 0), // 3695, -7
                                                             ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowRight_5", std::make_shared<Townwindow>(ci::Vec3f( 3800, -7, 0), // 3800, -7
                                                              ci::Vec3f( 77, 105, 0), "TownWindowRight")); // 77, 105
  
  
  Task::add("TownWindowTop_5", std::make_shared<Townwindow>(ci::Vec3f( 3743, 68, 0), // 3743, 68
                                                            ci::Vec3f( 75, 90, 0), "TownWindowTop")); // 75, 90
  
  
  Task::add("TownWindowLeft_6", std::make_shared<Townwindow>(ci::Vec3f( 4041, -7, 0), // 4041, -7
                                                             ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowRight_6", std::make_shared<Townwindow>(ci::Vec3f( 4144, -7, 0), // 4144, -7
                                                              ci::Vec3f( 77, 105, 0), "TownWindowRight")); // 77, 105
  
  
  Task::add("TownWindowTop_6", std::make_shared<Townwindow>(ci::Vec3f( 4088, 68, 0), // 4088, 68
                                                            ci::Vec3f( 75, 90, 0), "TownWindowTop")); // 75, 90

  
  Task::add("Hydrant", std::make_shared<Hydrant>(ci::Vec3f( 2825, -110, 0),
                                                 ci::Vec3f( 40, 70, 0)));
  
  
  Task::add("Ball", std::make_shared<Ball>(ci::Vec3f( 50.f, 50.f, 0.f),
                                           ci::Vec3f( 40.f, 40.f, 0.f), 0.2f));
  
  
  Task::add("Cinderella", std::make_shared<Cinderella>(ci::Vec3f( 150, // 150
                                                                  mDeviceWindowHeight * 0.15625f, 0.f),
                                                       ci::Vec3f( mDeviceWindowWidth * 0.13204225352113f,
                                                                  mDeviceWindowHeight * 0.234375f, 0.f)));
  
  
  Task::add("HandRail", std::make_shared<HandRail>(ci::Vec3f( 324.f, -40.f, 0.f),
                                                   ci::Vec3f( 145.f, 208.f, 0.f)));
  
  
  mCameraPos = ci::Vec3f( 250.f, 0.f, 300.f);
  camera = dowa::Camera(60.f, 0.5f, 300.f);
  
  camera.lookAt(mCameraPos,
                ci::Vec3f(mCameraPos.x, mCameraPos.y, 0.f),
                ci::Vec3f::yAxis());
  
  camera.setStageSize(0.0f, 5000.0f);
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
