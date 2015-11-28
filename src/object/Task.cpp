
#include "Task.hpp"
#include "Object.hpp"
#include "../collision/Collision.hpp"
#include <assert.h>


Task& Task::get() {
  static Task instance;
  return instance;
}

void Task::add(const std::string &key, const std::shared_ptr<Object>& obj) {
  assert(get().mMap[key] == nullptr);
  obj->setName(key);
  obj->setState(Object::State::Awake);
  get().mMap[key] = obj;
}

std::shared_ptr<Object> Task::find(const std::string& key) {
  assert(get().mMap[key] != nullptr);
  return get().mMap[key];
}

void Task::clear() {
  get().mMap.clear();
}

void Task::collisionUpdate(const std::shared_ptr<Object>& obj) {
  if (obj->isColliderTypeNone()) return;
  
  for (auto& compare : get().mMap) {
    if (compare.second->isColliderTypeNone()) continue;
    else if (obj == compare.second) continue;
    
    else // Run if both are set ColliderType
    {
      if (dowa::isCollisionRectToRect(obj, compare.second)) {
        obj->onCollisionUpdate(compare.second);
        compare.second->onCollisionUpdate(obj);
      }
    }
  }
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
        get().collisionUpdate(obj.second);
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