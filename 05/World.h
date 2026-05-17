#pragma once
#include "Ball.hpp"
#include "Physics.h"
#include <vector>
#include "Dust.h"

class Painter;

class World {
  public:
    World(const std::string& worldFilePath);
    void show(Painter& painter) const;
    void update(double time);

  private:
    Point topLeft;
    Point bottomRight;
    Physics physics;
    std::vector<Ball> balls;
   
    double restTime = 0.;
    std::vector<Dust> dustParticles;
};
