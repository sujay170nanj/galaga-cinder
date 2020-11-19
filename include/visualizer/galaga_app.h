//
// Created by sujay on 11/17/2020.
//

#ifndef GALAGA_GALAGA_APP_H
#define GALAGA_GALAGA_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "visualizer/space.h"

namespace galaga {

/**
 * Allows a user to view the container of particles, as well as generate and
 * clear
 */
class GalagaApp : public ci::app::App {
 public:
  GalagaApp();

  void update() override;

  void draw() override;

  void keyDown(ci::app::KeyEvent event) override;

  // Text font size
  const float kTitleFontSize = 50;
  const float kSubtitleFontSize = 44;
  // Size of the space container
  const size_t kBoxSize = 650;
  // Horizontal size of the window
  const size_t kWindowSizeX = 1000;
  // Vertical size of the window
  const size_t kWindowSizeY = 850;
  // Top left corner vec2 of space box
  const glm::vec2 kSpaceTopLeftCorner = glm::vec2(100, 100);

 private:
  Space space_;
};

}  // namespace galaga
#endif  // GALAGA_GALAGA_APP_H
