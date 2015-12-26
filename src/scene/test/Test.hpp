
#pragma once
#include "../Scene.hpp"
#include "../../object/Object.hpp"
#include "../../resource/Resource.hpp"

#include "T.hpp"

class Test : public Scene {
private:
<<<<<<< HEAD
  std::shared_ptr<T> mT;
=======
//  Audio mHitSE;
>>>>>>> c0ec9fdf4b5c44157d73d230188fe8471f4f7a91
  
public:
  Test();
  ~Test();
  
  void update();
  void draw();
};
