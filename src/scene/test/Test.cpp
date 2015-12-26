
#include "Test.hpp"
#include "../../device/Device.hpp"
#include "../../object/Task.hpp"


Test::Test() {
  std::cout << "start test" << std::endl;
  mT = std::make_shared<T>();
  Task::add("T", mT);
}

Test::~Test() {
  std::cout << "end test" << std::endl;
}

void Test::update() {}

void Test::draw() {}