
#include "ResultLoad.hpp"
#include "../SceneManager.hpp"


ResultLoad::ResultLoad() {
  std::cout << "start result load" << std::endl;
}

ResultLoad::~ResultLoad() {
  std::cout << "end result load" << std::endl;
}

void ResultLoad::load() {
  // Texture
  // Back
  // Retry
  // Select
  // Fin
  // Font

  // Sound
  
  std::cout << "finish load" << std::endl;
}

void ResultLoad::update() {
  load();
  SceneManager::create(SceneType::Result);
}

void ResultLoad::draw() {}
