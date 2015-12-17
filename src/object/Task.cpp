
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
  get().mList.emplace_back(obj);
}

std::shared_ptr<Object> Task::find(const std::string& key) {
  assert(get().mMap[key] != nullptr);
  return get().mMap[key];
}

void Task::clear() {
  get().mMap.clear();
  get().mList.clear();
}

void Task::collisionUpdate(const std::shared_ptr<Object>& obj) {
  if (obj->isColliderTypeNone()) return;
  
  for (auto& compare : get().mList) {
    if (compare->isColliderTypeNone()) continue;
    else if (obj == compare) continue;
    
    else // Run if both are set ColliderType
    {
      if (dowa::isCollisionRectToRect(obj, compare)) {
        obj->onCollisionUpdate(compare);
        compare->onCollisionUpdate(obj);
      }
    }
  }
}

void Task::update() {
  auto list_itr = get().mList.begin();
  while (list_itr != get().mList.end()) {
    switch ((*list_itr)->getState()) {
      case Object::State::Awake :
      {
        (*list_itr)->setup();
        (*list_itr)->setState(Object::State::Active);
        list_itr++;
        break;
      }
      
      case Object::State::Active :
      {
        get().collisionUpdate((*list_itr));
        (*list_itr)->update();
        list_itr++;
        break;
      }
      
      case Object::State::Dead :
      {
        get().mMap.erase((*list_itr)->getName());
        list_itr = get().mList.erase(list_itr);
      }
    }
  }
}


void Task::draw() {
  for (auto& obj : get().mList) {
    if (obj->isAwake()) continue;
    obj->draw();
  }
}