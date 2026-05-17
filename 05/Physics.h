#pragma once
#include "Ball.hpp"
#include <vector>
#include "Dust.h"
class Physics {
  public:
    Physics(double timePerTick = 0.001);
    void setWorldBox(const Point& topLeft, const Point& bottomRight);
    void update(std::vector<Ball>& balls, size_t ticks, std::vector<Dust>& dust) const;

  private:
    void collideBalls(std::vector<Ball>& balls, std::vector<Dust>& dust) const;
    void collideWithBox(std::vector<Ball>& balls) const;
    void move(std::vector<Ball>& balls) const;
    void processCollision(Ball& a, Ball& b,
                          double distanceBetweenCenters2, std::vector<Dust>& dust) const;

  private:
    Point topLeft;
    Point bottomRight;
    double timePerTick;
    std::vector<Dust> DustParticles;
};
