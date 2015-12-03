
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
  static const int HitSE = dowa::AudConst::ACCommon + 3;
  static const int GameOverSE = dowa::AudConst::ACCommon + 4;
};

class CinderellaAudioKey{
public:
  static const int Town = dowa::AudConst::ACCinderella;
  static const int Castle = dowa::AudConst::ACCinderella + 1;
  static const int House = dowa::AudConst::ACCinderella + 2;
  static const int HousePiano = dowa::AudConst::ACCinderella + 3;
  static const int BookDrop = dowa::AudConst::ACCinderella + 4;
  static const int BookHit = dowa::AudConst::ACCinderella + 5;
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
  static const int Apple = dowa::TexConst::TCCinderella + 10;
  static const int Barrel = dowa::TexConst::TCCinderella + 11;
  static const int BarrelSide = dowa::TexConst::TCCinderella + 12;
  static const int BookBack = dowa::TexConst::TCCinderella + 13;
  static const int BookDropped = dowa::TexConst::TCCinderella + 14;
  static const int BookOpen = dowa::TexConst::TCCinderella + 15;
  static const int BookShelf = dowa::TexConst::TCCinderella + 16;
  static const int BookShelfEmpty = dowa::TexConst::TCCinderella + 17;
  static const int BookSide = dowa::TexConst::TCCinderella + 18;
  static const int CarriageAnim1 = dowa::TexConst::TCCinderella + 19;
  static const int CarriageAnim2 = dowa::TexConst::TCCinderella + 20;
  static const int CarriageAnim3 = dowa::TexConst::TCCinderella + 21;
  static const int CarriageAnim4 = dowa::TexConst::TCCinderella + 22;
  static const int CarriageAnim5 = dowa::TexConst::TCCinderella + 23;
  static const int CarriageAnim6 = dowa::TexConst::TCCinderella + 24;
  static const int ChoppingAxe = dowa::TexConst::TCCinderella + 25;
  static const int FullPlate = dowa::TexConst::TCCinderella + 26;
  static const int HungryBear = dowa::TexConst::TCCinderella + 27;
  static const int Hydrant = dowa::TexConst::TCCinderella + 28;
  static const int LampPost = dowa::TexConst::TCCinderella + 29;
  static const int Mouse = dowa::TexConst::TCCinderella + 30;
  static const int Piano = dowa::TexConst::TCCinderella + 31;
  static const int PopupCastle = dowa::TexConst::TCCinderella + 32;
  static const int PopupDrop = dowa::TexConst::TCCinderella + 33;
  static const int PopupExclamation = dowa::TexConst::TCCinderella + 34;
  static const int PopupNote = dowa::TexConst::TCCinderella + 35;
  static const int Pumpkin = dowa::TexConst::TCCinderella + 36;
  static const int PumpkinCarriage = dowa::TexConst::TCCinderella + 37;
  static const int SatisfiedBear = dowa::TexConst::TCCinderella + 38;
};

class RedHoodTextureKey{
public:
  static const int Background = dowa::TexConst::TCRedHood;
};