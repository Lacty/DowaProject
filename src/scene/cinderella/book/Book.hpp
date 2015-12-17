
#pragma ones

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Book : public Object
{
  std::string mBookName; // 引数String
  
  ci::gl::Texture mBookPile;
  std::string mBookPileName;
  
  ci::gl::Texture mBookSide;
  std::string mBookSideName;
  
  ci::gl::Texture mBookOpen;
  std::string mBookOpenName;
  
  float mAcceleration;
  float mGravityPower, mGravityPower2;
  
  bool mFallFlag;
  
  ci::Vec3f mCinderellaPos;
  
  std::string mCinderellaStr, mFloor_FloorStr, mBallStr; // Name Decision
  
  void drawBookPile();
  void drawBookOpen();
  void drawBookSide();
  
public:
  
  Book(const ci::Vec3f&, const ci::Vec3f&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
