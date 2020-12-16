//
// Created by sujay on 11/17/2020.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "visualizer/space.h"
#include "cinder/DataSource.h"
#include "cinder/Font.h"



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
  const float kSubtitleFontSize = 44;
  // Text margin
  const float kHorizontalTextMargin = 20;
  const float kVerticalTextMargin = 20;
  // Size of the space container
  const size_t kBoxSize = 650;
  // Horizontal size of the window
  const size_t kWindowSizeX = 1050;
  // Vertical size of the window
  const size_t kWindowSizeY = 850;
  // Top left corner vec2 of space box
  const glm::vec2 kSpaceTopLeftCorner = glm::vec2(100, 125);

 private:
  // Title of the text font
  const std::string kFontTitle = "ArcadeClassic";
  // File path of Galaga title
  const std::string kTitlePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\galaga_title.png";
  Space space_;
};

}  // namespace galaga