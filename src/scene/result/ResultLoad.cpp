
#include "ResultLoad.hpp"
#include "../SceneManager.hpp"


ResultLoad::ResultLoad() {
  std::cout << "start result load" << std::endl;
  count = -1;
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
  ++count;
  if (!count) return;

  load();
  SceneManager::create(SceneType::Result);
}

void ResultLoad::draw() {}
