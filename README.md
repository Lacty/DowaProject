# DowaProject
## フォルダ名
-  小文字、大文字繋げ

## ファイル名
- 大文字、大文字繋げ

## クラス名
- 大文字、大文字繋げ

## メンバ変数
- m始まり、大文字繋げ

## メンバ関数
- 小文字、大文字繋げ


    #include "scene/gameMain/GameMain.hpp"
    
    class GameMain {
    private:
      Vec2f mPos;
      Player mPlayer;
      
    public:
      GameMain();
      
      void update();
      void draw();
      
      Vec2f getPos();
    };