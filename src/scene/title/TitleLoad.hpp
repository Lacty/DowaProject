
#pragma once
#include "../Scene.hpp"
#include <thread>
#include <mutex>


class TitleLoad : public Scene {
private:
  std::thread mLoad;
  bool isFin;
  void load();
  
  std::mutex mtx;
  
public:
  TitleLoad();
  ~TitleLoad();

  void update();
  void draw();
};
