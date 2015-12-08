
#include "SceneMaker.hpp"
#include "Scene.hpp"

#include "title/Title.hpp"
#include "select/Select.hpp"
#include "gameMain/GameMain.hpp"
#include "result/Result.hpp"
#include "test/Test.hpp"
#include "loading/Loading.hpp"

#include <functional>
#include <unordered_map>


std::unique_ptr<Scene> SceneMaker::create(const SceneType& type) const {
  using namespace std;
  unordered_map<SceneType, function<unique_ptr<Scene>()>> list = {
    { SceneType::Title,    []{ return make_unique<Title>();    } },
	  { SceneType::Select,   []{ return make_unique<Select>();   } },
    { SceneType::GameMain, []{ return make_unique<GameMain>(); } },
    { SceneType::Result,   []{ return make_unique<Result>();   } },
    
    { SceneType::Test,     []{ return make_unique<Test>();     } },
    { SceneType::Loading,  []{return make_unique<Loading>();   } }
  };
  
  return std::move((list.find(type)->second)());
}