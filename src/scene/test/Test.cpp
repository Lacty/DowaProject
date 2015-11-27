
#include "Test.hpp"

#include "../../object/Task.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

#include "CinderOpenCV.h" // OpenCVに必要！

Test::Test()
{
  Task::add("Player", std::make_shared<Player>());
  Task::add("Enemy", std::make_shared<Enemy>());
  
  // OpenCV使ってみまーす
  
  // サーフェスで画像読み込み
  mSurface_Test = (ci::loadImage(ci::app::loadAsset("background/title/TitleBack.jpg")));
  
  // 読み込んだ画像をMatに代入 (Matは配列である)
  mInput = (ci::toOcv(mSurface_Test));
  
  // 入力画像, 出力画像, カーネルサイズ, 標準偏差
  // 標準偏差いじれば、ぼかしの強弱ができる！
  cv::GaussianBlur(mInput, mOutput, cv::Size(0, 0), 10, 1);
  
  // いじくった画像を変数に代入
  mTexture_Test = ci::gl::Texture(ci::fromOcv(mOutput));
}

void Test::update() {}

void Test::draw()
{
  ci::gl::draw(mTexture_Test, ci::app::getWindowBounds()); // 描画
}
