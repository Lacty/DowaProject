
#pragma once
#include "../../../object/Object.hpp"
#include "../../../resource/Resource.hpp"


class BackGround : public Object {
private:
  ci::Rectf mCinderellaHouseRect1; // 1
  
  ci::Rectf mCinderellaHouseRect2_1; // 4
  ci::Rectf mCinderellaHouseRect2_2; // 4
  ci::Rectf mCinderellaHouseRect2_3; // 4
  ci::Rectf mCinderellaHouseRect2_4; // 4
  
  ci::Rectf mCinderellaHouseRect3; // 1
  
  ci::Rectf mCinderellaForestRect1; // 1
  ci::Rectf mCinderellaForestRect2; // 1
  ci::Rectf mCinderellaForestRect3; // 1
  ci::Rectf mCinderellaForestRect4; // 1
  
  ci::Rectf mCinderellaTownRect1;
  ci::Rectf mCinderellaTownRect2;
  ci::Rectf mCinderellaTownRect3;
  
  ci::gl::Texture mCinderellaHouse1;
  ci::gl::Texture mCinderellaHouse2;
  ci::gl::Texture mCinderellaHouse3;
  
  ci::gl::Texture mCinderellaForest1;
  ci::gl::Texture mCinderellaForest2;
  ci::gl::Texture mCinderellaForest3;
  ci::gl::Texture mCinderellaForest4;
  
  ci::gl::Texture mCinderellaTown1;
  ci::gl::Texture mCinderellaTown2;
  ci::gl::Texture mCinderellaTown3;

public:
  BackGround();
  
  void setup();
  void update();
  void draw();
};