//
// Created by sujay on 11/17/2020.
//

#include "visualizer/galaga_app.h"

galaga::GalagaApp::GalagaApp(Space space) : space_(space) {
}

void galaga::GalagaApp::update() {
  AppBase::update();
}

void galaga::GalagaApp::draw() {
  AppBase::draw();
  ci::Color8u background_color(255, 246, 148);  // yellow
  ci::gl::clear(background_color);
}

void galaga::GalagaApp::keyDown(ci::app::KeyEvent event) {
  AppBase::keyDown(event);
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_z:
      // left shoot
      break;
    case ci::app::KeyEvent::KEY_x:
      // right shoot
      break;
    case ci::app::KeyEvent::KEY_LEFT:
      // move right
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
      // move left
      break;
  }
}
