
#include "Test.hpp"
#include "../../device/Device.hpp"


Test::Test() {
  std::cout << "start test" << std::endl;
  
  // リソースマネージャーに音をロードさせる
  dowa::ResourceManager::audio().insert("sound/se/Hit.m4a", AudioKey::HitSE);
  
  // リソースマネージャーから音を取得
  se = dowa::ResourceManager::audio().get(AudioKey::HitSE);
  
  // 音量をmaxに設定
  se.gain->setValue(1.0f);
}

Test::~Test() {
  std::cout << "end test" << std::endl;
}

void Test::update() {
  // タッチしたら
  if (dowa::Device::isTouchBegan()) {
    // 音を鳴らす
    se.bgm->start();
  }
}

void Test::draw() {

}
