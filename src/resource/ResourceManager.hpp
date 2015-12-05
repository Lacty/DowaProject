
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

namespace dowa {

  namespace hidden {

    struct Audio {
      ci::audio::BufferPlayerNodeRef bgm;
      ci::audio::GainNodeRef gain;
    };

    class AudioResource {
    private:
      std::unordered_map <int, Audio> mMappedResource;
      bool mEnable;
      short counter;

    public:
      AudioResource();

      void enable();
      bool isEnabled();

      bool insert(std::string path, int key);
      Audio get(int key);

      void check(bool insertResult);//Not Implemented
    };
    typedef AudioResource AudioRes;
    typedef std::unordered_map<int, Audio>::const_iterator AudioIterator;

    class TextureResource {
    private:
      std::unordered_map<int, ci::gl::Texture> mMappedResource;
      bool mEnable;
      short counter;

    public:
      TextureResource();

      void enable();
      bool isEnabled();

      short getCounter();//debug

      bool insert(std::string path, int key);
      ci::gl::Texture get(int key);

      void check(bool insertResult);//Not Implemented
    };
    typedef TextureResource TexRes;
    typedef std::unordered_map<int, ci::gl::Texture>::const_iterator TextureIterator;

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