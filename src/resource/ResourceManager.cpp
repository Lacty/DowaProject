
#include "ResourceManager.hpp"

using namespace ci;
using namespace dowa;

//Audio Resource

hidden::AudioResource::AudioResource() {
  mEnable = false;
  mCounter = 60;
}

void hidden::AudioResource::enable(){
  if (mCounter == 60){
    insert("sound/bgm/Menu.ogg", AudioKey::Menu);
    mCounter--;
    return;
  }

  if (mCounter == 59){
    insert("sound/bgm/cinderella/Town.ogg", CinderellaAudioKey::Town);
    mCounter--;
    return;
  }

  if (mCounter == 58){
    insert("sound/bgm/cinderella/Castle.ogg", CinderellaAudioKey::Castle);
    mCounter--;
    return;
  }

  if (mCounter == 57){
    insert("sound/bgm/cinderella/House.ogg", CinderellaAudioKey::House);
    mCounter--;
    return;
  }

  if (mCounter == 56){
    insert("sound/bgm/cinderella/HousePiano.ogg", CinderellaAudioKey::HousePiano);
    mCounter = 30;
    return;
  }

  if (mCounter == 30){
    insert("sound/se/GameStart.ogg", AudioKey::GameStartSE);
    insert("sound/se/StageSelected.ogg", AudioKey::StageSelectSE);
    insert("sound/se/Hit.ogg", AudioKey::HitSE);
    mCounter--;
    return;
  }

  if (mCounter == 29){
    insert("sound/se/GameOver.ogg", AudioKey::GameOverSE);
    insert("sound/se/cinderella/BookDrop.ogg", CinderellaAudioKey::BookDrop);
    insert("sound/se/cinderella/BookHit.ogg", CinderellaAudioKey::BookHit);
    mCounter--;
    return;
  }

  if (mCounter == 28){
    mEnable = true;
  }
}

bool hidden::AudioResource::isEnabled(){
  return mEnable;
}

short hidden::AudioResource::getCounter() {
  return mCounter;
}

bool hidden::AudioResource::insert(std::string path, int key) {
  hidden::AudioIterator it = mMappedResource.find(key);

  if (it != mMappedResource.end()) {
    return false;
  }

  hidden::Audio temp;

  auto ctx = audio::Context::master();

  audio::SourceFileRef sourceFile = audio::load(ci::app::loadAsset(path));
  audio::BufferRef buffer = sourceFile->loadBuffer();
  temp.bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));
  temp.gain = ctx->makeNode(new audio::GainNode(1.0f));

  temp.bgm >> temp.gain >> ctx->getOutput();

  ctx->enable();

  mMappedResource.insert(std::make_pair(key, temp));

  return true;
}

hidden::Audio hidden::AudioResource::get(int key) {
  return mMappedResource.find(key)->second;
}

void hidden::AudioResource::check(bool insertResult){
  if (!insertResult){
  }
}

//Audio Resource

//Texture Resource

hidden::TextureResource::TextureResource() {
  mEnable = false;
  mCounter = 60;
}

void hidden::TextureResource::enable(){
  if (mCounter == 60){
    insert("object/DownVeil.png", TextureKey::DownVeil);
    insert("object/VeilSpace.png", TextureKey::VeilSpace);
    mCounter--;
    return;
  }

  if (mCounter == 59){
    insert("character/cinderella/1.png", CinderellaTextureKey::CharacterStatic);
    insert("character/cinderella/2.png", CinderellaTextureKey::CharacterLeft);
    insert("character/cinderella/3.png", CinderellaTextureKey::CharacterRight);
    mCounter--;
    return;
  }

  if (mCounter == 58){
    insert("background/gameMain/cinderella/1.png", CinderellaTextureKey::House);
    insert("background/gameMain/cinderella/2.png", CinderellaTextureKey::Forest);
    insert("background/gameMain/cinderella/3.png", CinderellaTextureKey::Town3Houses);
    insert("background/gameMain/cinderella/4.png", CinderellaTextureKey::TownBridge);
    insert("background/gameMain/cinderella/5.png", CinderellaTextureKey::Town2Houses);
    insert("background/gameMain/cinderella/6.png", CinderellaTextureKey::Bridge);
    insert("background/gameMain/cinderella/7.png", CinderellaTextureKey::Castle);
    mCounter--;
    return;
  }

  if (mCounter == 57){
    insert("object/cinderella/Apple.png", CinderellaTextureKey::Apple);
    insert("object/cinderella/Barrel.png", CinderellaTextureKey::Barrel);
    insert("object/cinderella/BarrelSide.png", CinderellaTextureKey::BarrelSide);
    mCounter--;
    return;
  }

  if (mCounter == 56){
    insert("object/cinderella/BookBack.png", CinderellaTextureKey::BookBack);
    insert("object/cinderella/BookDropped.png", CinderellaTextureKey::BookDropped);
    insert("object/cinderella/BookOpen.png", CinderellaTextureKey::BookOpen);
    insert("object/cinderella/BookShelf.png", CinderellaTextureKey::BookShelf);
    insert("object/cinderella/BookShelfEmpty.png", CinderellaTextureKey::BookShelfEmpty);
    insert("object/cinderella/BookSide.png", CinderellaTextureKey::BookSide);
    insert("object/cinderella/BookPile.png", CinderellaTextureKey::BookPile);
    mCounter--;
    return;
  }

  if (mCounter == 55){
    insert("object/cinderella/CarriageAnim1.png", CinderellaTextureKey::CarriageAnim1);
    insert("object/cinderella/CarriageAnim2.png", CinderellaTextureKey::CarriageAnim2);
    insert("object/cinderella/CarriageAnim3.png", CinderellaTextureKey::CarriageAnim3);
    insert("object/cinderella/CarriageAnim4.png", CinderellaTextureKey::CarriageAnim4);
    insert("object/cinderella/CarriageAnim5.png", CinderellaTextureKey::CarriageAnim5);
    insert("object/cinderella/CarriageAnim6.png", CinderellaTextureKey::CarriageAnim6);
    mCounter--;
    return;
  }

  if (mCounter == 54){
    insert("object/cinderella/ChoppingAxe.png", CinderellaTextureKey::ChoppingAxe);
    insert("object/cinderella/FullPlate.png", CinderellaTextureKey::FullPlate);
    insert("object/cinderella/HungryBear.png", CinderellaTextureKey::HungryBear);
    insert("object/cinderella/Hydrant.png", CinderellaTextureKey::Hydrant);
    insert("object/cinderella/SatisfiedBear.png", CinderellaTextureKey::SatisfiedBear);
    mCounter--;
    return;
  }

  if (mCounter == 53){
    insert("object/cinderella/LampPost.png", CinderellaTextureKey::LampPost);
    insert("object/cinderella/Mouse.png", CinderellaTextureKey::Mouse);
    insert("object/cinderella/Piano.png", CinderellaTextureKey::Piano);
    mCounter--;
    return;
  }

  if (mCounter == 52){
    insert("object/cinderella/PopupCastle.png", CinderellaTextureKey::PopupCastle);
    insert("object/cinderella/PopupDrop.png", CinderellaTextureKey::PopupDrop);
    insert("object/cinderella/PopupExclamation.png", CinderellaTextureKey::PopupExclamation);
    insert("object/cinderella/PopupNote.png", CinderellaTextureKey::PopupNote);
    mCounter--;
    return;
  }

  if (mCounter == 51){
    insert("object/cinderella/Pumpkin.png", CinderellaTextureKey::Pumpkin);
    insert("object/cinderella/PumpkinCarriage.png", CinderellaTextureKey::PumpkinCarriage);
    mCounter--;
    return;
  }

  if (mCounter == 50){
    insert("background/result/Back.jpg", TextureKey::Back);
    insert("background/result/Retry.jpg", TextureKey::Retry);
    insert("background/result/Select.jpg", TextureKey::Select);
    insert("background/result/Fin.jpg", TextureKey::Fin);
    insert("background/result/Font.png", TextureKey::Font);
    mCounter--;
    return;
  }

  if (mCounter == 49){
    insert("background/stageSelect/StageSelectBack.png", TextureKey::StageSelectBack);
    insert("object/stageSelect/StageSelectBook.png", TextureKey::StageSelectBook);
    insert("object/stageSelect/Cinderella.png", TextureKey::StageSelectCinderella);
    mCounter--;
    return;
  }

  if (mCounter == 48){
    insert("object/cinderella/Chandelier.png", CinderellaTextureKey::Chandelier);
    insert("object/cinderella/FlowerPot.png", CinderellaTextureKey::FlowerPot);
    insert("object/cinderella/PumpkinBad.png", CinderellaTextureKey::PumpkinBad);
    mCounter--;
    return;
  }
  
  if (mCounter == 47){
    insert("background/beta/1.png", CinderellaTextureKey::_betaBack1);
    insert("background/beta/2.png", CinderellaTextureKey::_betaBack2);
    insert("background/beta/3.png", CinderellaTextureKey::_betaBack3);
    insert("background/beta/FullBack1.png", CinderellaTextureKey::_betaFull);
    mCounter = 0;
    return;
  }

  if (mCounter <= 0){
    mEnable = true;
  }
}

bool hidden::TextureResource::isEnabled(){
  return mEnable;
}

short hidden::TextureResource::getCounter(){
  return mCounter;
}

bool hidden::TextureResource::insert(std::string path, int key) {
  hidden::TextureIterator it = mMappedResource.find(key);

  if (it != mMappedResource.end()) {
    return false;
  }

  gl::Texture temp;

  temp = gl::Texture(loadImage(ci::app::loadAsset(path)));

  mMappedResource.insert(std::make_pair(key, temp));

  return true;
}

ci::gl::Texture hidden::TextureResource::get(int key) {
  return mMappedResource.find(key)->second;
}

void hidden::TextureResource::check(bool insertResult){
  if (!insertResult){

  }
}

//Texture Resource

//Resource Manager

void ResourceManager::enable(){//deprecated
  audio();
  texture();
}

void ResourceManager::createTextures(){
  texture();
}

void ResourceManager::createAudio(){
  audio();
}

//Resource Manager