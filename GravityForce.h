#pragma once

#include "Particle.h"

class GravityForce {
 public:
  GravityForce(const Vec2f &origin, const Vec2f &velocity);

  void draw();

 private:

  Particle force;
};
