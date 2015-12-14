
#pragma ones

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Book : public Object
{
private:
  
  ci::gl::Texture mBookPile; // 積み重なった
  std::string mBookPileName;
  
  ci::gl::Texture mBookBack; // 本縦
  std::string mBookBackName;
  
  ci::gl::Texture mBookDropped; // 落下
  std::string mBookDroppedName;
  
  ci::gl::Texture mBookOpen; // 開いた状態
  std::string mBookOpenName;
  
  std::string mBookName; // 引数の本の名前
  
  void drawBookPile();
  void drawBookBack();
  void drawBookDropped();
  void drawBookOpen();
  
public:
  
  Book(const ci::Vec3f&, const ci::Vec3f&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
};
