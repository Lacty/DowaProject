
#include "Test.hpp"
#include "../../resource/ResourceManager.hpp"


Test::Test() {
  std::cout << "start test" << std::endl;
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::enableDepthRead();
  ci::gl::enableDepthWrite();
  ci::gl::enableAlphaBlending(true);
  
  image = dowa::ResourceManager::texture().get(TextureKey::TitleBack);
}

Test::~Test() {
  std::cout << "end test" << std::endl;
}

void Test::update() {}

void Test::draw() {
  ci::gl::pushModelView();
  ci::gl::rotate(ci::Vec3f(0, 0, 0));
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::TitleBack), ci::Rectf(0, 0, 100, 100));
  ci::gl::popModelView();
}
