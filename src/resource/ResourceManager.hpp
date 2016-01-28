
#pragma once

#include "cinder/app/AppNative.h"

#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"
#include "cinder/audio/NodeEffects.h"

#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

#include "ResourceKeys.hpp"

#include <string>
#include <unordered_map>

#include <memory>

namespace dowa {

  namespace hidden {

    struct Audio {
      ci::audio::BufferPlayerNodeRef bgm;
      ci::audio::GainNodeRef gain;
    };

    class AudioResource {
    private:
      std::unordered_map <int, std::shared_ptr<Audio>> mMap;

    public:
      AudioResource();

      bool insert(std::string path, int key);
      Audio get(int key);

      void clear();
    };
    typedef AudioResource AudioRes;

    class TextureResource {
    private:
      std::unordered_map<int, std::shared_ptr<ci::gl::Texture>> mMap;

    public:
      TextureResource();

      bool insert(std::string path, int key);
      ci::gl::Texture get(int key);

      void clear();
    };
    typedef TextureResource TexRes;
    
  }

  class ResourceManager {
  private:
    ResourceManager() {};
    ResourceManager(ResourceManager const &) = delete;
    void operator=(ResourceManager const &) = delete;
  
  public:

    static hidden::AudioRes& audio() {
      static hidden::AudioRes audio;
      return audio;
    }

    static hidden::TexRes& texture() {
      static hidden::TexRes tex;
      return tex;
    }

    static void enable();//deprecated

    static void createTextures();

    static void createAudio();
  };

  typedef ResourceManager Resource;

  /*
  #define DOWA_AUD Resource::audio()
  #define DOWA_TEX Resource::texture()
  */
}
