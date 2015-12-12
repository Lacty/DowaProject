
#include "DataManager.hpp"

//FIXIT : Change the return type when it was already implemented

pObject dowa::loadObjects(std::string filepath){
  ci::JsonTree json = ci::JsonTree(ci::app::loadAsset(filepath));
  ci::JsonTree stage = json.getChild(0);
  std::shared_ptr<Object> temp;
  for (auto object : stage){
    switch (object["Object Type"].getValue<int>()){
      case 1:
        break;
      case 2:
        break;
      default:
        temp = std::make_shared<Object>();
        break;
    }
    temp->setName(object["Name"].getValue<std::string>());
    temp->setState((Object::State)object["Initial State"].getValue<int>());
    temp->setColliderType((Object::Collider)object["Collider Type"].getValue<int>());
  }
}


//Maybe we don't need these, just for debugging

void dowa::hidden::saveObjects(std::string filepath, std::string filename){

}