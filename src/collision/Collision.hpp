
#pragma once
#include "../object/Object.hpp"


bool isCollisionRectToRect(const std::shared_ptr<Object>& obj1,
                           const std::shared_ptr<Object>& obj2);

bool isCollisionCircleTpCircle(const std::shared_ptr<Object>& obj1,
                               const std::shared_ptr<Object>& obj2);
