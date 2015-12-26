
#include "Test.hpp"
#include "../../device/Device.hpp"
#include "../../object/Task.hpp"


Test::Test() {
  std::cout << "start test" << std::endl;
<<<<<<< HEAD
  mT = std::make_shared<T>();
  Task::add("T", mT);
=======
  
  // TaskにRotaterを追加
  // 回転処理はRotater参照
  Task::add("Rotater", std::make_shared<Rotater>());
  
  // サウンドの読み込み
  AudioManager::add(ResKey::CHitSE);
  
  // findは処理が重いので変数にサウンドを保存
//  mHitSE = AudioManager::find(ResKey::CHitSE);
  
  // サウンドの音量を変更
//  mHitSE.setVolume(1.0f);
>>>>>>> c0ec9fdf4b5c44157d73d230188fe8471f4f7a91
}

Test::~Test() {
  std::cout << "end test" << std::endl;
}

<<<<<<< HEAD
void Test::update() {}
=======
void Test::update() {
  // 画面をタップしたら音を鳴らす
  if (dowa::Device::isTouchBegan()) {
//    mHitSE.play();
  }
}
>>>>>>> c0ec9fdf4b5c44157d73d230188fe8471f4f7a91

void Test::draw() {}