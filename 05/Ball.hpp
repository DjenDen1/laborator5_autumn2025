#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"
#include "Color.h"


class Ball {
public:
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getisCollidable() const;
    void setColor(const Color& new_color);
    Ball(Color color, Point center, double radius, Velocity velocity, bool isCollidable);

    Color color_;
    Point center_;
    double radius_;
    Velocity velocity_;
    bool isCollidable_;
};
