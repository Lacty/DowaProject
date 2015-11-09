
#include "ResourceManager.hpp"

using namespace ci;
using namespace dowa;

//Audio Resource

hidden::AudioResource::AudioResource() {
  //insert(filepath, AudioKey.TheKey);  
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

  std::pair<int, hidden::Audio> res (key, temp);

  mMappedResource.insert(res);

  return true;
}

hidden::Audio hidden::AudioResource::get(int key) {
  return mMappedResource.find(key)->second;
}

//Audio Resource

//Texture Resource

hidden::TextureResource::TextureResource() {
  //Tweak & Fix : Place the insert function where you will use the textures
  //It will work the same way
  //inserting all the textures here may cause the program to be slower

  //Use it Right : When you insert some texture, do a fail check with it
  //the insert function returns a bool value when executed

  insert("object/DownVeil.png", TextureKey::DownVeil);
  insert("object/VeilSpace.png", TextureKey::VeilSpace);

  insert("background/title/TitleBack.jpg", TextureKey::TitleBack);
  insert("background/title/FeatherBook.png", TextureKey::FeatherBook);
  insert("background/title/Logo.png", TextureKey::Logo);
  insert("background/title/TapToStartEng.png", TextureKey::TapToStartEng);
  insert("background/title/TapToStartJap.png", TextureKey::TapToStartJap);
  insert("background/title/Trace.png", TextureKey::Trace);
  insert("background/title/KanaLetterTa.png", TextureKey::LetterTa);
  insert("background/title/KanaLetterMa.png", TextureKey::LetterMa);
  insert("background/title/KanaLetterKo.png", TextureKey::LetterKo);
  insert("background/title/KanaLetterRo.png", TextureKey::LetterRo);
  insert("background/title/SphereBlue.png", TextureKey::SphereBlue);
  insert("background/title/SphereGreen.png", TextureKey::SphereGreen);
  insert("background/title/SphereRed.png", TextureKey::SphereRed);

  //Tweak it: Change the CinderellaTextureKey to something more readable
  //Make it shorter with typedef
  insert("character/cinderella/1.png", CinderellaTextureKey::CharacterStatic);
  insert("character/cinderella/2.png", CinderellaTextureKey::CharacterLeft);
  insert("character/cinderella/3.png", CinderellaTextureKey::CharacterRight);
  insert("background/gameMain/cinderella/1.jpg", CinderellaTextureKey::House);
  insert("background/gameMain/cinderella/2.jpg", CinderellaTextureKey::Forest);
  insert("background/gameMain/cinderella/3.jpg", CinderellaTextureKey::Town3Houses);
  insert("background/gameMain/cinderella/4.jpg", CinderellaTextureKey::TownBridge);
  insert("background/gameMain/cinderella/5.png", CinderellaTextureKey::Town2Houses);
  insert("background/gameMain/cinderella/6.png", CinderellaTextureKey::Bridge);
  insert("background/gameMain/cinderella/7.jpg", CinderellaTextureKey::Castle);
}

bool hidden::TextureResource::insert(std::string path, int key) {
  hidden::TextureIterator it = mMappedResource.find(key);

  if (it != mMappedResource.end()) {
    return false;
  }

  gl::Texture temp;

  temp = gl::Texture(loadImage(ci::app::loadAsset(path)));

  std::pair<int, gl::Texture> res (key, temp);

  mMappedResource.insert(res);

  return true;
}

ci::gl::Texture hidden::TextureResource::get(int key) {
  return mMappedResource.find(key)->second;
}

//Texture Resource