
#pragma once

#include <string>
#include <memory>

#include "../object/Object.hpp"

#include "cinder/Json.h"

namespace dowa{
  pObject loadObjects(std::string filepath);

  namespace hidden{
    void saveObjects(std::string filepath, std::string filename);
  }
}