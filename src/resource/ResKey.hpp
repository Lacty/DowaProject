
#pragma once
#include <string>
#include <unordered_map>


namespace ResKey {

enum {
  //         _________         //
  // ------- |Texture| ------- //
  //         ¯¯¯¯¯¯¯¯¯         //
  TBack,
  TFeatherBook,
  TLogo,
  TTapToStartEng,
  TTrance,
  TTa, TMa, TKo, TRo,
  TSphereBlue,
  TSphereGreen,
  TSphereRed,
  
  CCharacterStatic,
  CCharacterLeft,
  CCharacterRight,
  
  CApple,
  CBookSide,
  CBookOpen,
  CBookShelf,
  CBookPile,
  CHungryBear,
  CStatisfiedBrear,
  CPiano,
  CSphereBlue,
  CSphereGreen,
  CSphereRed,
  CHandRail,
  CBetaBack1,
  CBetaBack2,
  CBetaBack3,
  
  //          _______          //
  // -------- |Audio| -------- //
  //          ¯¯¯¯¯¯¯          //
  TMenu,
  TGameStartSE,
  
  CHitSE,
  CGameOverSE,
  CTown,
  CCastle,
  CHouse,
  CHousePiano,
  CBookDrop,
  CBookHit,
};

static std::string getPath(int key) {
  std::string tex_ext = ".png";
  std::string snd_ext = ".m4a";
  
  std::unordered_map<int, std::string> list = {
    
    //         _________         //
    // ------- |Texture| ------- //
    //         ¯¯¯¯¯¯¯¯¯         //
    
    { TBack,           "background/title/TitleBack" + tex_ext },
    { TFeatherBook,    "background/title/FeatherBookResize" + tex_ext },
    { TLogo,           "background/title/Logo" + tex_ext },
    { TTapToStartEng,  "background/title/TapToStartEng" + tex_ext },
    { TTrance,         "background/title/Trace" + tex_ext },
    { TTa,             "background/title/KanaLetterTa" + tex_ext },
    { TMa,             "background/title/KanaLetterMa" + tex_ext },
    { TKo,             "background/title/KanaLetterKo" + tex_ext },
    { TRo,             "background/title/KanaLetterRo" + tex_ext },
    { TSphereBlue,     "background/title/SphereBlue" + tex_ext },
    { TSphereGreen,    "background/title/SphereGreen" + tex_ext },
    { TSphereRed,      "background/title/SphereRed" + tex_ext },
    
    { CCharacterStatic,  "character/cinderella/1" + tex_ext },
    { CCharacterLeft,    "character/cinderella/2" + tex_ext },
    { CCharacterRight,   "character/cinderella/3" + tex_ext },

    { CApple,            "object/cinderella/Apple" + tex_ext },
    { CBookSide,         "object/cinderella/BookSide" + tex_ext },
    { CBookOpen,         "object/cinderella/BookOpen" + tex_ext },
    { CBookShelf,        "object/cinderella/BookShelf" + tex_ext },
    { CBookPile,         "object/cinderella/BookPile" + tex_ext },
    { CHungryBear,       "object/cinderella/HungryBear" + tex_ext },
    { CStatisfiedBrear,  "object/cinderella/SatisfiedBear" + tex_ext },
    { CPiano,            "object/cinderella/Piano" + tex_ext },
    { CSphereBlue,       "background/title/SphereBlue" + tex_ext },
    { CSphereGreen,      "background/title/SphereGreen" + tex_ext },
    { CSphereRed,        "background/title/SphereRed" + tex_ext },
    { CHandRail,         "background/beta/HandRail" + tex_ext },
    { CBetaBack1,        "background/beta/1" + tex_ext },
    { CBetaBack2,        "background/beta/2" + tex_ext },
    { CBetaBack3,        "background/beta/3" + tex_ext },
    
    //          _______          //
    // -------- |Audio| -------- //
    //          ¯¯¯¯¯¯¯          //
    
    { TMenu,         "sound/bgm/Menu" + snd_ext },
    { TGameStartSE,  "sound/se/GameStart" + snd_ext },
    
    { CHitSE,       "sound/se/Hit" + snd_ext },
    { CGameOverSE,  "sound/se/GameOver" + snd_ext },
    { CTown,        "sound/bgm/cinderella/Town" + snd_ext },
    { CCastle,      "sound/bgm/cinderella/Castle" + snd_ext },
    { CHouse,       "sound/bgm/cinderella/House" + snd_ext },
    { CHousePiano,  "sound/bgm/cinderella/HousePiano" + snd_ext },
    { CBookDrop,    "sound/se/cinderella/BookDrop" + snd_ext },
    { CBookHit,     "sound/se/cinderella/BookHit" + snd_ext },
  };
  
  return list[key];
}

}
