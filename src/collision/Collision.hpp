
#pragma once
#include "../object/Object.hpp"

namespace dowa{

bool isCollisionRectToRect(const std::shared_ptr<Object>& obj1,
                           const std::shared_ptr<Object>& obj2);

bool isCollisionCircleToCircle(const std::shared_ptr<Object>& obj1,
                               const std::shared_ptr<Object>& obj2);

}
