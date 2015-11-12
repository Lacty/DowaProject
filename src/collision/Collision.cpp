
#include "Collision.hpp"


bool dowa::isCollisionRectToRect(const std::shared_ptr<Object>& obj1,
                           const std::shared_ptr<Object>& obj2)
{
  float left1   = obj1->getPos().x - obj1->getSize().x * 0.5f;
  float right1  = left1 + obj1->getSize().x;
  float bottom1 = obj1->getPos().y - obj1->getSize().y * 0.5f;
  float top1    = bottom1 + obj1->getSize().y;
  
  float left2   = obj2->getPos().x - obj2->getSize().x * 0.5f;
  float right2  = left2 + obj2->getSize().x;
  float bottom2 = obj2->getPos().y - obj2->getSize().y * 0.5f;
  float top2    = bottom2 + obj2->getSize().y;
  
  if (right1 > left2) {
    if (left1 < right2) {
      if (top1 > bottom2) {
        if (bottom1 < top2) {
          return true;
        }
      }
    }
  }
  return false;
}

bool dowa::isCollisionCircleToCircle(const std::shared_ptr<Object>& obj1,
                               const std::shared_ptr<Object>& obj2)
{
  if ((obj1->getPos().x - obj2->getPos().x) * 2 + (obj1->getPos().y - obj2->getPos().y) * 2 <= (obj1->getSize().x + obj2->getSize().x) * 2) {
    return true;
  }
  return false;
}