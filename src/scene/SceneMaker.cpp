
#include "SceneMaker.hpp"
#include "Scene.hpp"

#include "title/Title.hpp"
#include "select/Select.hpp"
#include "gameMain/GameMain.hpp"
#include "result/Result.hpp"
#include "test/Test.hpp"

#include "loading/TitleLoad.hpp"
#include "loading/SelectLoad.hpp"
#include "loading/ResultLoad.hpp"

#include "cinderella/CinderellaScene.hpp"

#include <functional>
#include <unordered_map>


std::unique_ptr<Scene> SceneMaker::create(const SceneType& type) const {
  using namespace std;
  unordered_map<SceneType, function<unique_ptr<Scene>()>> list = {
    { SceneType::Title,           []{ return make_unique<Title>();           } },
	  { SceneType::Select,          []{ return make_unique<Select>();          } },
    { SceneType::GameMain,        []{ return make_unique<GameMain>();        } },
    { SceneType::Result,          []{ return make_unique<Result>();          } },
    
    { SceneType::Test,            []{ return make_unique<Test>();            } },
    
    { SceneType::TitleLoad,       []{ return make_unique<TitleLoad>();       } },
    { SceneType::SelectLoad,      []{ return make_unique<SelectLoad>();      } },
    { SceneType::ResultLoad,      []{ return make_unique<ResultLoad>();      } },
    
    { SceneType::Cinderella,      []{ return make_unique<CinderellaScene>(); } }
  };
  
  return std::move((list.find(type)->second)());
}
