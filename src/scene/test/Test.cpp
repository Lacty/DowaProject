
#include "Test.hpp"
#include "../../device/Device.hpp"
#include "../../resource/Resource.hpp" // AudioManager, TextureManager, ResKey

#include "../../object/Task.hpp"
#include "Rotater.hpp"


Test::Test() {
  std::cout << "start test" << std::endl;
  
  // TaskにRotaterを追加
  // 回転処理はRotater参照
  Task::add("Rotater", std::make_shared<Rotater>());
  
  // サウンドの読み込み
  AudioManager::add(ResKey::CHitSE);
  
  // findは処理が重いので変数にサウンドを保存
//  mHitSE = AudioManager::find(ResKey::CHitSE);
  
  // サウンドの音量を変更
//  mHitSE.setVolume(1.0f);
}

Test::~Test() {
  std::cout << "end test" << std::endl;
  
  // 読み込んだサウンドの削除
  AudioManager::clear();
}

void Test::update() {
  // 画面をタップしたら音を鳴らす
  if (dowa::Device::isTouchBegan()) {
//    mHitSE.play();
  }
}

void Test::draw() {}
