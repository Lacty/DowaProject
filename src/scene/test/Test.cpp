
#include "Test.hpp"
#include "../SceneManager.hpp"
#include "../../device/Device.hpp"
#include "../../resource/Resource.hpp"
#include "../../object/Task.hpp"


Test::Test() {
  std::cout << "start test" << std::endl;
  
  // 使いたい画像の読み込み
  TextureManager::add(ResKey::TBack);
  
  // 追加は必ず最後にすること
  // コンストラクタに使いたいResKeyを指定
  //end = std::make_shared<End>(ResKey::TBack);
  //Task::add("end", end);
}

Test::~Test() {
  std::cout << "end test" << std::endl;
}

void Test::update() {
  // enableStartを呼べば開始される
  if (dowa::Device::isTouchBegan()) {
    //end->enableStart();
  }
}

void Test::draw() {}