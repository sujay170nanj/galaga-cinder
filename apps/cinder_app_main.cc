#include <visualizer/galaga_app.h>

using galaga::GalagaApp;

void prepareSettings(GalagaApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(GalagaApp, ci::app::RendererGl, prepareSettings);
