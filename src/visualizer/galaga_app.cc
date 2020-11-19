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
}

void galaga::GalagaApp::draw() {
  AppBase::draw();
  ci::Color8u background_color(255, 246, 148);  // yellow
  ci::gl::clear(background_color);

  space_.Draw();
}

void galaga::GalagaApp::keyDown(ci::app::KeyEvent event) {
  AppBase::keyDown(event);
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_z:
      // left shoot
      // space_.BattleshipLeftShoot();
      break;
    case ci::app::KeyEvent::KEY_x:
      // right shoot
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
