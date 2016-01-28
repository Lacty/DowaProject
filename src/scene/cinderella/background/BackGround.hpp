
#pragma once

#include "../../../object/Object.hpp"
#include "../../../resource/Resource.hpp"


class BackGround : public Object
{
  
  ci::gl::Texture mHouse1;
  ci::gl::Texture mHouse2;
  ci::gl::Texture mHouse3;
  
  ci::gl::Texture mForest1;
  ci::gl::Texture mForest2;
  ci::gl::Texture mForest3;
  ci::gl::Texture mForest4;
  
  ci::gl::Texture mTown1;
  ci::gl::Texture mTown2;
  ci::gl::Texture mTown3;
  
  ci::gl::Texture mForestGarden1;
  ci::gl::Texture mForestGarden2;
  ci::gl::Texture mForestGarden3;
  ci::gl::Texture mForestGarden4;
  
  ci::gl::Texture mDance;
  
  ci::Rectf mHouseRect1;
  ci::Rectf mHouseRect2_1;
  ci::Rectf mHouseRect2_2;
  ci::Rectf mHouseRect2_3;
  ci::Rectf mHouseRect2_4;
  ci::Rectf mHouseRect3;
  
  ci::Rectf mForestRect1;
  ci::Rectf mForestRect2;
  ci::Rectf mForestRect3;
  ci::Rectf mForestRect4;
  
  ci::Rectf mTownRect1;
  ci::Rectf mTownRect2;
  ci::Rectf mTownRect3;
  
  ci::Rectf mForestGardenRect1;
  ci::Rectf mForestGardenRect2;
  ci::Rectf mForestGardenRect3;
  ci::Rectf mForestGardenRect4;
  
  ci::Rectf mDanceRect1;
  ci::Rectf mDanceRect2;

public:
  
  BackGround();
  
  void setup();
  void update();
  void draw();
  
};
