#pragma once

namespace dowa {
  namespace hidden {

    enum TextureConst {
      Common = 1000,
      Cinderella = 2000,
      RedHood = 3000
    };

    enum AudioConst {
      Common = 100000,
      Cinderella = 200000,
      RedHood = 300000
    };

  }

  typedef hidden::AudioConst AudConst;
  typedef hidden::TextureConst TexConst;
}

class AudioKey {
public:
  static const int Key = dowa::AudConst::Common;
};

class TextureKey {
public:
  static const int _debugFinalLogo = 1;
  static const int _debugFinalTitle = 2;

  static const int DownVeil = dowa::TexConst::Common;
  static const int VeilSpace = dowa::TexConst::Common + 1;
  static const int TitleBack = dowa::TexConst::Common + 2;
  static const int FeatherBook = dowa::TexConst::Common + 3;
  static const int Logo = dowa::TexConst::Common + 4;
  static const int TapToStartEng = dowa::TexConst::Common + 5;
  static const int TapToStartJap = dowa::TexConst::Common + 6;
  static const int Trace = dowa::TexConst::Common + 7;
  static const int LetterTa = dowa::TexConst::Common + 8;
  static const int LetterMa = dowa::TexConst::Common + 9;
  static const int LetterKo = dowa::TexConst::Common + 10;
  static const int LetterRo = dowa::TexConst::Common + 11;
  static const int SphereBlue = dowa::TexConst::Common + 12;
  static const int SphereGreen = dowa::TexConst::Common + 13;
  static const int SphereRed = dowa::TexConst::Common + 14;
};

class CinderellaTextureKey{
public:
  static const int CharacterStatic = dowa::TexConst::Cinderella;
  static const int CharacterLeft = dowa::TexConst::Cinderella + 1;
  static const int CharacterRight = dowa::TexConst::Cinderella + 2;
  static const int House = dowa::TexConst::Cinderella + 3;
  static const int Forest = dowa::TexConst::Cinderella + 4;
  static const int Town3Houses = dowa::TexConst::Cinderella + 5;
  static const int TownBridge = dowa::TexConst::Cinderella + 6;
  static const int Town2Houses = dowa::TexConst::Cinderella + 7;
  static const int Bridge = dowa::TexConst::Cinderella + 8;
  static const int Castle = dowa::TexConst::Cinderella + 9;
};

class RedHoodTextureKey{
public:
  static const int Background = dowa::TexConst::RedHood;
};