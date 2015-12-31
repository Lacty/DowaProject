
// mDeviceWindowWidth = 568
// mDeviceWindowHeight = 320

#include "CinderellaScene.hpp"

#include "background/BackGround.hpp"
#include "cinderella/Cinderella.hpp"
#include "floor/Floor.hpp"
#include "ball/Ball.hpp"
#include "bookshelf/BookShelf.hpp"
#include "chandelier/Chandelier.hpp"
#include "chandelierhit/ChandelierHit.hpp"
#include "book/Book.hpp"
#include "piano/Piano.hpp"
#include "handrail/HandRail.hpp"
#include "apple/Apple.hpp"
#include "bear/Bear.hpp"
#include "stairs/Stairs.hpp"
#include "townwindow/Townwindow.hpp"
#include "townwindowhit/TownwindowHit.hpp"
#include "hydrant/Hydrant.hpp"
#include "lamppost/LampPost.hpp"
#include "bridge/Bridge.hpp"
#include "plate/Plate.hpp"
#include "shop/Shop.hpp"
#include "pumpkin/Pumpkin.hpp"
#include "woodenbox/WoodenBox.hpp"
#include "river/River.hpp"
#include "horse/Horse.hpp"

#include "graycube/GrayCube.hpp"

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
  
  // 一回実行に使用
  mOnceRunFlag = true;
  
  // findは処理が重いので変数にサウンドを保存
  mHouse = AudioManager::find(ResKey::CHouse);
  mTown = AudioManager::find(ResKey::CTown);
  mCastle = AudioManager::find(ResKey::CCastle);
  
  // SE
  mGameOver = AudioManager::find(ResKey::CGameOverSE);
  
  // サウンドの音量を変更
  mHouse.setVolume(0.5f);
  mTown.setVolume(0.5f);
  mCastle.setVolume(0.5f);
  mGameOver.setVolume(0.8f);
  
  // 再生
  mHouse.play();
  
  // 背景
  Task::add("BackGround", std::make_shared<BackGround>());
  
  
  // 地面
  Task::add("Floor1", std::make_shared<Floor>(ci::Vec3f( mDeviceWindowWidth * 0.24471831f,
                                                        -mDeviceWindowHeight * 0.03125f, 0.f),
                                              ci::Vec3f( mDeviceWindowWidth * 0.48415493f,
                                                         mDeviceWindowHeight * 0.015625f, 0.f)));
  
  // 階段
  Task::add("Stairs", std::make_shared<Stairs>(ci::Vec3f( 353.f, -40.f, 0.f),
                                               ci::Vec3f( 145.f, 208.f, 0.f)));
  
  
  // 地面 一番下
  Task::add("Floor_Floor", std::make_shared<Floor>(ci::Vec3f( 1646, -157.f, 0.f), // 1646, -157
                                                   ci::Vec3f( 3291, 5, 0.f))); // 3291, 5
  
  Task::add("Floor_Floor2", std::make_shared<Floor>(ci::Vec3f( 5000, -157.f, 0.f), //
                                                    ci::Vec3f( 3180, 5, 0.f))); // 3291, 5
  
  Task::add("Chandelier1", std::make_shared<Chandelier>(ci::Vec3f( 400, 113, 0),
                                                        ci::Vec3f( 100, 100, 0)));
  
  
  Task::add("Chandelier2", std::make_shared<Chandelier>(ci::Vec3f( 580, 113, 0),
                                                        ci::Vec3f( 100, 100, 0)));
  
  
  Task::add("ChandelierHit1", std::make_shared<ChandelierHit>(ci::Vec3f( 760, 113, 0),
                                                              ci::Vec3f( 100, 100, 0)));
  
  
  Task::add("ChandelierHit2", std::make_shared<ChandelierHit>(ci::Vec3f( 940, 113, 0),
                                                              ci::Vec3f( 100, 100, 0)));
  
  
  Task::add("Chandelier3", std::make_shared<Chandelier>(ci::Vec3f( 1120, 113, 0),
                                                        ci::Vec3f( 100, 100, 0)));
  
  
  Task::add("ChandelierHit3", std::make_shared<ChandelierHit>(ci::Vec3f( 1300, 113, 0),
                                                              ci::Vec3f( 100, 100, 0)));
  
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
  Task::add("HungryBear1", std::make_shared<Bear>(ci::Vec3f( 1800.f, -90, 0.f),
                                                    ci::Vec3f( 80.f, 130.f, 0.f), "HungryBear"));
  
  
  Task::add("HungryBear2", std::make_shared<Bear>(ci::Vec3f( 2000.f, -90, 0.f),
                                                 ci::Vec3f( 80.f, 130.f, 0.f), "HungryBear"));
  
  
  Task::add("HungryBear3", std::make_shared<Bear>(ci::Vec3f( 2150.f, -90, 0.f),
                                                  ci::Vec3f( 80.f, 130.f, 0.f), "HungryBear"));
  
  
  Task::add("HungryBear4", std::make_shared<Bear>(ci::Vec3f( 2400.f, -90, 0.f),
                                                  ci::Vec3f( 80.f, 130.f, 0.f), "HungryBear"));
  
  
  Task::add("Apple1", std::make_shared<Apple>(ci::Vec3f( 1650, 50, 0),
                                             ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("Apple2", std::make_shared<Apple>(ci::Vec3f( 1750, 75, 0),
                                              ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("Apple3", std::make_shared<Apple>(ci::Vec3f( 1850, 55, 0),
                                              ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("Apple4", std::make_shared<Apple>(ci::Vec3f( 2050, 85, 0),
                                              ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("Apple5", std::make_shared<Apple>(ci::Vec3f( 2150, 95, 0),
                                              ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("Apple6", std::make_shared<Apple>(ci::Vec3f( 2250, 65, 0),
                                              ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("Apple7", std::make_shared<Apple>(ci::Vec3f( 2350, 78, 0),
                                              ci::Vec3f( 50, 50, 0)));
  
  
  Task::add("TownWindowRight_1", std::make_shared<Townwindow>(ci::Vec3f( 2664, -7, 0), // 2664, -7
                                                              ci::Vec3f( 77, 105, 0), "TownWindowRight")); // 77, 105
  
  
  Task::add("TownWindowLeft_1", std::make_shared<TownwindowHit>(ci::Vec3f( 2559, -7, 0), // 2559, -7
                                                                ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowTop_1", std::make_shared<Townwindow>(ci::Vec3f( 2607, 68, 0), // 2607, 68
                                                            ci::Vec3f( 75, 90, 0), "TownWindowTop")); // 75, 90
  
  
  Task::add("TownWindowLeft_2", std::make_shared<Townwindow>(ci::Vec3f( 2905, -7, 0), // 2905, -7
                                                             ci::Vec3f( 77, 105, 0), "TownWindowLeft")); // 77, 105
  
  
  Task::add("TownWindowRight_2", std::make_shared<Townwindow>(ci::Vec3f( 3009, -7, 0), // 3009, -7
                                                              ci::Vec3f( 77, 105, 0), "TownWindowRight")); // 77, 105
  
  
  Task::add("TownWindowOpen_2", std::make_shared<TownwindowHit>(ci::Vec3f( 2953, 74, 0), // 2953, 74
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

  
  Task::add("Hydrant1", std::make_shared<Hydrant>(ci::Vec3f( 2825, -110, 0), // 2825, -110
                                                  ci::Vec3f( 40, 70, 0))); // 40, 70
  
  
  Task::add("Hydrant2", std::make_shared<Hydrant>(ci::Vec3f( 3045, -110, 0), // 3045, -110
                                                  ci::Vec3f( 40, 70, 0))); // 40, 70
  
  
  Task::add("LampPost1", std::make_shared<LampPost>(ci::Vec3f( 2740, -50, 0), // 2740, -50
                                                    ci::Vec3f( 80, 190, 0))); // 80, 190
  
  
  Task::add("LampPost2", std::make_shared<LampPost>(ci::Vec3f( 3960, -50, 0), // 3960, -50
                                                    ci::Vec3f( 80, 190, 0))); // 80, 190
  
  
  Task::add("Bridge", std::make_shared<Bridge>(ci::Vec3f( 3350, -125, 0), // 3350, -125
                                               ci::Vec3f( 200, 69, 0))); // 200, 69
  
  
  Task::add("Shop", std::make_shared<Shop>(ci::Vec3f( 3723, -70, 0), // 3723, -70
                                           ci::Vec3f( 210, 155, 0))); // 210, 155
  
  
  Task::add("WoodenBox", std::make_shared<WoodenBox>(ci::Vec3f( 3858, -110, 0), // 3858, -110
                                                     ci::Vec3f( 75, 80, 0))); // 75, 80
  
  
  Task::add("Pumpkin2", std::make_shared<Pumpkin>(ci::Vec3f( 3858, -50, 0), // 3858, -50
                                                  ci::Vec3f( 80, 50, 0), "Pumpkin2")); // 80, 50
  
  
  Task::add("Pumpkin1", std::make_shared<Pumpkin>(ci::Vec3f( 3858, -18, 0), // 3858, -18
                                                  ci::Vec3f( 40, 50, 0), "Pumpkin1")); // 40, 50
  
  
  Task::add("Horse", std::make_shared<Horse>(ci::Vec3f( 2500, -50, 0),
                                             ci::Vec3f( 200, 150, 0)));
  
  
  mBall = std::make_shared<Ball>(ci::Vec3f( 2950, 50, 0), ci::Vec3f( 40.f, 40.f, 0.f), 0.2f); // 50
  Task::add("Ball", mBall);
  
  
  mCinderella = std::make_shared<Cinderella>(ci::Vec3f( 3000, 50, 0), ci::Vec3f( 75, 75, 0)); // 150
  Task::add("Cinderella", mCinderella);
  
  
  Task::add("HandRail", std::make_shared<HandRail>(ci::Vec3f( 324.f, -40.f, 0.f),
                                                   ci::Vec3f( 145.f, 208.f, 0.f)));
  
  
  Task::add("River", std::make_shared<River>(ci::Vec3f( 3350, -152, 0),
                                             ci::Vec3f( 113, 20, 0)));
  
  
  Task::add("Plate", std::make_shared<Plate>(ci::Vec3f( 3247, -125, 0), // 3247, -123
                                             ci::Vec3f( 50, 147, 0))); // 50, 147
  
  
  Task::add("GrayCube", std::make_shared<GrayCube>(ci::Vec3f( 3350, -165, 0.f),
                                                   ci::Vec3f( 113, 20, 0.f)));
  
  
  Task::add("GameOver", std::make_shared<Floor>(ci::Vec3f( 3350, -187, 0.f),
                                               ci::Vec3f( 113, 20, 0.f)));
  
  
  mCameraPos = ci::Vec3f( 250.f, 0.f, 300.f);
  camera = dowa::Camera(60.f, 0.5f, 300.f);
  
  camera.lookAt(mCameraPos,
                ci::Vec3f(mCameraPos.x, mCameraPos.y, 0.f),
                ci::Vec3f::yAxis());
  
  camera.setStageSize( 0.0f, 5000.0f);
  camera.setForcusObj(Task::find("Cinderella"));
  
  // シンデレラの右側にカメラの焦点をあてる
  camera.setOffset(100.0f);
  
}

CinderellaScene::~CinderellaScene()
{
  ci::gl::popMatrices();
  ci::gl::popModelView();
  
  std::cout << "end cinderella" << std::endl; // Debug
  
  Task::clear();
  TextureManager::clear();
  AudioManager::clear();
}

void CinderellaScene::update()
{
  camera.update();
  
  mBall -> setViewSize(camera.getViewLeft(), camera. getViewRight(),
                       camera.getViewTop(), camera.getViewBottom());
  
  // ballが左画面外にでたらtrueを返す
  if(mBall -> isOutOfStage())
  {
//    SceneManager::create(SceneType::CinderellaLoad);
//    mHouse.stop();
  }
  
  // Gameover 一回しか実行しない
  if (mCinderella -> mGameOverRturen && mOnceRunFlag)
  {
    camera.setGameOver(mCinderella -> mGameOverOffset);
    mGameOver.play();
    mHouse.stop();
    mTown.stop();
    AudioManager::find(ResKey::CHitSE).stop();
    AudioManager::find(ResKey::CHousePiano).stop();
    mOnceRunFlag = false;
  }

  if(mCinderella -> getPos().x >= 2499 && mCinderella -> getPos().x <= 2501)
  {
    if (AudioManager::find(ResKey::CHousePiano).getVolume() >= 0.9f)
    {
      AudioManager::addCrossFade(ResKey::CHousePiano, ResKey::CTown);
    }
    else
    {
      AudioManager::addCrossFade(ResKey::CHouse, ResKey::CTown);
    }
  }
}

void CinderellaScene::draw()
{
  camera.setMatrices();
  camera.draw();
}
