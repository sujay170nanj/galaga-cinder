//
// Created by sujay on 11/17/2020.
//

#ifndef GALAGA_SPACE_H
#define GALAGA_SPACE_H

#include <core/hitbox.h>

#include "cinder/gl/gl.h"

namespace galaga {

class Space {
 public:
  Space(const glm::vec2& top_left_corner, size_t dimensions, const std::vector<Hitbox>& hitboxes = std::vector<Hitbox>());

  void Update();

  void Draw() const;

  void Clear();

};

}

#endif //GALAGA_SPACE_H
