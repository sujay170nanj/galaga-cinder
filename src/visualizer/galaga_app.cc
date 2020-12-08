//
// Created by sujay on 11/17/2020.
//

#include "visualizer/galaga_app.h"

galaga::GalagaApp::GalagaApp() : space_(kSpaceTopLeftCorner, kBoxSize) {
  ci::app::setWindowSize(static_cast<int>(kWindowSizeX),
                         static_cast<int>(kWindowSizeY));
}

void galaga::GalagaApp::update() {
  AppBase::update();
  space_.Update();
}

void galaga::GalagaApp::draw() {
  AppBase::draw();
  ci::Color8u background_color(0, 0, 0);
  ci::gl::clear(background_color);

  ci::gl::TextureRef title_texture =
      cinder::gl::Texture2d::create(cinder::loadImage(kTitlePath));
  cinder::Rectf title_rect(kSpaceTopLeftCorner[0], 0,
                           kSpaceTopLeftCorner[0] + kBoxSize,
                           kSpaceTopLeftCorner[1]);
  ci::gl::draw(title_texture, title_rect);

  size_t highscore = 0;
  std::ifstream InputFile("D:\\Downloads\\Cinder\\my-projects\\final-project-sujay170nanj\\resources\\highscore.txt");
  if(InputFile.is_open())
  {
    InputFile >> highscore;
  }

  ci::gl::drawString(
      "High Score: " + std::to_string(highscore),
      glm::vec2(kSpaceTopLeftCorner[0] + kBoxSize + kHorizontalTextMargin, kSpaceTopLeftCorner[1] + kVerticalTextMargin),
      ci::Color("white"), ci::Font("ArcadeClassic", kSubtitleFontSize));

  ci::gl::drawString(
      "Score: " + std::to_string(space_.GetScore()),
      glm::vec2(kSpaceTopLeftCorner[0] + kBoxSize + kHorizontalTextMargin, kSpaceTopLeftCorner[1] + 5*kVerticalTextMargin),
      ci::Color("white"), ci::Font("ArcadeClassic", kSubtitleFontSize));

  ci::gl::drawString(
      "Lives: " + std::to_string(space_.GetBattleship().GetLives()),
      glm::vec2(kSpaceTopLeftCorner[0] + kBoxSize + kHorizontalTextMargin, kSpaceTopLeftCorner[1] + 10*kVerticalTextMargin),
      ci::Color("white"), ci::Font("ArcadeClassic", kSubtitleFontSize));

  ci::gl::drawString(
      "Level: " + std::to_string(space_.GetLevel()),
      glm::vec2(kSpaceTopLeftCorner[0] + kBoxSize + kHorizontalTextMargin, kSpaceTopLeftCorner[1] + 15*kVerticalTextMargin),
      ci::Color("white"), ci::Font("ArcadeClassic", kSubtitleFontSize));

  space_.Draw();
}

void galaga::GalagaApp::keyDown(ci::app::KeyEvent event) {
  AppBase::keyDown(event);
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_z:
      // left shoot
      space_.BattleshipLeftShoot();
      break;
    case ci::app::KeyEvent::KEY_LEFT:
      // move right
      if ((space_.GetBattleship().GenerateRectPosition().getLowerLeft()[0] -
           space_.GetBattleship().kSpeed) > kSpaceTopLeftCorner[0]) {
        space_.GetBattleship().MoveLeft();
      }
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
      // move left
      if ((space_.GetBattleship().GenerateRectPosition().getLowerRight()[0] +
           space_.GetBattleship().kSpeed) <
          (kSpaceTopLeftCorner[0] + kBoxSize)) {
        space_.GetBattleship().MoveRight();
      }
      break;
  }
}