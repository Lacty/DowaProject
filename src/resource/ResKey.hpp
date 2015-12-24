
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

  // hiramasa
  CBridgeRiver,
  CHydrant,
  CLampPost,
  CPlate,
  CPlateFall,
  CPumpkin1,
  CPumpkin2,
  CShop,
  CWindow1,
  CWindow2,
  CWindow3,
  CWindowOpen,
  CWoodenBox,
  CWitch1,
  CWitch2,
  CGrayCube,
  CHandRail,
  
  // background
  CHouse1,
  CHouse2,
  CHouse3,
  CForest1,
  CForest2,
  CForest3,
  CForest4,
  CTown1,
  CTown2,
  CTown3,
  CForestGarden1,
  CForestGarden2,
  CForestGarden3,
  CForestGarden4,
  CDance1,
  CDance2,
  CDance3,
  CDance4,
  
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
    
    // Cinderella
    { CCharacterStatic,  "character/cinderella/1" + tex_ext },
    { CCharacterLeft,    "character/cinderella/2" + tex_ext },
    { CCharacterRight,   "character/cinderella/3" + tex_ext },
    
    // Sphere
    { CSphereBlue,       "background/title/SphereBlue" + tex_ext },
    { CSphereGreen,      "background/title/SphereGreen" + tex_ext },
    { CSphereRed,        "background/title/SphereRed" + tex_ext },

    // House
    { CBookSide,         "object/house/BookSide" + tex_ext },
    { CBookOpen,         "object/house/BookOpen" + tex_ext },
    { CBookShelf,        "object/house/BookShelf" + tex_ext },
    { CBookPile,         "object/house/BookPile" + tex_ext },
    { CPiano,            "object/house/Piano" + tex_ext },
    { CHandRail,         "object/house/HandRail" + tex_ext },
    
    // Forest
    { CApple,            "object/forest/Apple" + tex_ext },
    { CHungryBear,       "object/forest/HungryBear" + tex_ext },
    { CStatisfiedBrear,  "object/forest/SatisfiedBear" + tex_ext },
    
    // Town
    { CBridgeRiver,   "object/town/BridgeRiver" + tex_ext },
    { CHydrant,       "object/town/Hydrant" + tex_ext },
    { CLampPost,      "object/town/LampPost" + tex_ext },
    { CPlate,         "object/town/Plate" + tex_ext },
    { CPlateFall,     "object/town/PlateFall" + tex_ext },
    { CPumpkin1,      "object/town/Pumpkin1" + tex_ext },
    { CPumpkin2,      "object/town/Pumpkin2" + tex_ext },
    { CShop,          "object/town/Shop" + tex_ext },
    { CWindow1,       "object/town/Window1" + tex_ext },
    { CWindow2,       "object/town/Window2" + tex_ext },
    { CWindow3,       "object/town/Window3" + tex_ext },
    { CWindowOpen,    "object/town/WindowOpen" + tex_ext },
    { CWoodenBox,     "object/town/WoodenBox" + tex_ext },
    { CWitch1,        "object/town/Witch1" + tex_ext },
    { CWitch2,        "object/town/Witch2" + tex_ext },
    { CGrayCube,      "object/town/GrayCube" + tex_ext },
    
    // Background
    { CHouse1,        "background/house/1" + tex_ext },
    { CHouse2,        "background/house/2" + tex_ext },
    { CHouse3,        "background/house/3" + tex_ext },
    { CForest1,       "background/forest/1" + tex_ext },
    { CForest2,       "background/forest/2" + tex_ext },
    { CForest3,       "background/forest/3" + tex_ext },
    { CForest4,       "background/forest/4" + tex_ext },
    { CTown1,         "background/town/1" + tex_ext },
    { CTown2,         "background/town/2" + tex_ext },
    { CTown3,         "background/town/3" + tex_ext },
    { CForestGarden1, "background/forestgarden/1" + tex_ext },
    { CForestGarden2, "background/forestgarden/2" + tex_ext },
    { CForestGarden3, "background/forestgarden/3" + tex_ext },
    { CForestGarden4, "background/forestgarden/4" + tex_ext },
    { CDance1,        "background/dance/1" + tex_ext },
    { CDance2,        "background/dance/2" + tex_ext },
    { CDance3,        "background/dance/3" + tex_ext },
    { CDance4,        "background/dance/4" + tex_ext },
    
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
