
#pragma once

#include <string>

namespace dowa{
  void loadWalls(std::string filepath);
  void loadGimmicks(std::string filepath);
  void loadItems(std::string filepath);
  
  namespace hidden{
    void saveWalls(std::string filepath, std::string filename);
    void saveGimmicks(std::string filepath, std::string filename);
    void saveItems(std::string filepath, std::string filename);
  }
}