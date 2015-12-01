
#pragma once

namespace dowa {
  namespace hidden {

    enum TextureConst {
      TCCommon = 1000,
      TCCinderella = 2000,
      TCRedHood = 3000
    };

    enum AudioConst {
      ACCommon = 100000,
      ACCinderella = 200000,
      ACRedHood = 300000
    };

  }

  typedef hidden::AudioConst AudConst;
  typedef hidden::TextureConst TexConst;
}

class AudioKey {
public:
  static const int Menu = dowa::AudConst::ACCommon;
  static const int GameStartSE = dowa::AudConst::ACCommon + 1;
  static const int StageSelectSE = dowa::AudConst::ACCommon + 2;
};

class CinderellaAudioKey{
public:
  static const int Town = dowa::AudConst::ACCinderella;
  static const int Castle = dowa::AudConst::ACCinderella + 1;
};

class TextureKey {
public:
  static const int _debugFinalLogo = 1;
  static const int _debugFinalTitle = 2;

  static const int DownVeil = dowa::TexConst::TCCommon;
  static const int VeilSpace = dowa::TexConst::TCCommon + 1;
  static const int TitleBack = dowa::TexConst::TCCommon + 2;
  static const int FeatherBook = dowa::TexConst::TCCommon + 3;
  static const int Logo = dowa::TexConst::TCCommon + 4;
  static const int TapToStartEng = dowa::TexConst::TCCommon + 5;
  static const int TapToStartJap = dowa::TexConst::TCCommon + 6;
  static const int Trace = dowa::TexConst::TCCommon + 7;
  static const int LetterTa = dowa::TexConst::TCCommon + 8;
  static const int LetterMa = dowa::TexConst::TCCommon + 9;
  static const int LetterKo = dowa::TexConst::TCCommon + 10;
  static const int LetterRo = dowa::TexConst::TCCommon + 11;
  static const int SphereBlue = dowa::TexConst::TCCommon + 12;
  static const int SphereGreen = dowa::TexConst::TCCommon + 13;
  static const int SphereRed = dowa::TexConst::TCCommon + 14;

  // result—p‚Ìresource

  static const int Back = dowa::TexConst::TCCommon + 15;
  static const int Retry = dowa::TexConst::TCCommon + 16;
  static const int Select = dowa::TexConst::TCCommon + 17;
  static const int Fin = dowa::TexConst::TCCommon + 18;
  static const int Font = dowa::TexConst::TCCommon + 19;


};

class CinderellaTextureKey{
public:
  static const int CharacterStatic = dowa::TexConst::TCCinderella;
  static const int CharacterLeft = dowa::TexConst::TCCinderella + 1;
  static const int CharacterRight = dowa::TexConst::TCCinderella + 2;
  static const int House = dowa::TexConst::TCCinderella + 3;
  static const int Forest = dowa::TexConst::TCCinderella + 4;
  static const int Town3Houses = dowa::TexConst::TCCinderella + 5;
  static const int TownBridge = dowa::TexConst::TCCinderella + 6;
  static const int Town2Houses = dowa::TexConst::TCCinderella + 7;
  static const int Bridge = dowa::TexConst::TCCinderella + 8;
  static const int Castle = dowa::TexConst::TCCinderella + 9;
};

class RedHoodTextureKey{
public:
  static const int Background = dowa::TexConst::TCRedHood;
};