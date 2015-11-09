
#include "Task.hpp"
#include "Object.hpp"
#include <assert.h>


Task& Task::get() {
  static Task instance;
  return instance;
}

void Task::add(const std::string &key, const std::shared_ptr<Object> &obj) {
  assert(get().mMap[key] == nullptr);
  get().mMap[key] = obj;
}

std::shared_ptr<Object> Task::find(const std::string &key) {
  assert(get().mMap[key] == nullptr);
  return get().mMap[key];
}

void Task::update() {
  for (auto& obj : get().mMap) {
    switch (obj.second->getState()) {
      case Object::State::Awake :
      {
        obj.second->setup();
        obj.second->setState(Object::State::Active);
        break;
      }
        
      case Object::State::Active :
      {
        obj.second->update();
        break;
      }
        
      case Object::State::Dead :
      {
        get().mMap.erase(obj.second->getName());
      }
    }
  }
}


void Task::draw() {
  for (auto& obj : get().mMap) {
    if (obj.second->isAwake()) continue;
    obj.second->draw();
  }
}