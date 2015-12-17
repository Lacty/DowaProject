
#pragma ones

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class BookShelf : public Object
{
private:
  
  ci::gl::Texture mBookShelf;
  
public:
  
  BookShelf(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
};

void onCollisionUpdate(const std::shared_ptr<Object>& compare);
