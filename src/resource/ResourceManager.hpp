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
      std::unordered_map <AudioKey, Audio> mMappedResource;

    public:
      AudioResource();

      bool insert(std::string path, AudioKey key);
      Audio get(AudioKey key);
    };
    typedef AudioResource AudioRes;
    typedef std::unordered_map<AudioKey, Audio>::const_iterator AudioIterator;

    class TextureResource {
    private:
      std::unordered_map<TextureKey, ci::gl::Texture> mMappedResource;

    public:
      TextureResource();

      bool insert(std::string path, TextureKey key);
      ci::gl::Texture get(TextureKey key);
    };
    typedef TextureResource TexRes;
    typedef std::unordered_map<TextureKey, ci::gl::Texture>::const_iterator TextureIterator;

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
  };

}