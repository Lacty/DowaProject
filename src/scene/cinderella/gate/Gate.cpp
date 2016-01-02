
#include "Gate.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Gate::Gate(const ci::Vec3f& Pos, const ci::Vec3f& Size, const std::string& Name)
{
  mPos = Pos;
  mSize = Size;
  
  mGateName = Name;
  
  mGate = TextureManager::find(ResKey::CGate);
  mGateBack = TextureManager::find(ResKey::CGateBack);
  mGateSide = TextureManager::find(ResKey::CGateSide);
  
}

void Gate::setup() {}

void Gate::update()
{
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  if(mCinderellaPos.x > 4400)
  {
    mPos = ci::Vec3i( 4773, 4, 0);
    mSize = ci::Vec3i( 247, 300, 0);
    mGateName = "GateBack";
  }
}

void Gate::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
//  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  if(mGateName == "Gate") drawGate(mGate);
  if(mGateName == "GateBack") drawGate(mGateBack);
  if(mGateName == "GateSide") drawGate(mGateSide);
  
  ci::gl::popModelView();
  
//  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
}

void Gate::drawGate(const ci::gl::Texture& texture)
{
  texture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  texture.unbind();
  
}
