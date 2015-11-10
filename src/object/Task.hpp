
#pragma once
#include <memory>
#include <list>
#include <unordered_map>


class Object;

class Task {
private:
  std::unordered_map<std::string, std::shared_ptr<Object>> mMap;
  
  Task() = default;
  
  static Task& get();
  
public:
  
  static void add(const std::string& key,
                  const std::shared_ptr<Object>& obj);
  static std::shared_ptr<Object> find(const std::string& key);
  
  static void clear();
  
private: void collisionUpdate(const std::shared_ptr<Object>& obj);
public:
  static void update();
  static void draw();
};