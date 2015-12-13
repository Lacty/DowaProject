
#pragma ones

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

class BookShelf : public Object
{
private:
  
  ci::gl::Texture mBookShelf; // 本棚
  ci::gl::Texture mBookPile; // 本4冊
  
public:
  
  BookShelf(const ci::Vec3f&, const ci::Vec3f&);
//  ~BookShelf();
  
  void setup();
  void update();
  void draw();
};

void onCollisionUpdate(const std::shared_ptr<Object>& compare);
