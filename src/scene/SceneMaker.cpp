
#include "SceneMaker.hpp"
#include "Scene.hpp"

#include "title/Title.hpp"
#include "gameMain/GameMain.hpp"

#include <functional>
#include <unordered_map>


std::unique_ptr<Scene> SceneMaker::create(const SceneType& type) const {
  using namespace std;
  unordered_map<SceneType, function<unique_ptr<Scene>()>> list = {
    { SceneType::Title,    []{ return make_unique<Title>(); } },
    { SceneType::GameMain, []{ return make_unique<GameMain>(); } }
  };
  
  return std::move((list.find(type)->second)());
}