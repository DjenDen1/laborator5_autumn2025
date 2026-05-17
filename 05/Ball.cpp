#include "Ball.hpp"
#include <cmath>

Ball::Ball(Color color, Point center, double radius, Velocity velocity, bool isCollidable):  color_(color), center_(center), radius_(radius), velocity_(velocity), isCollidable_(isCollidable) {} 

void Ball::setVelocity(const Velocity& velocity) {
    velocity_ = velocity; 
}

Velocity Ball::getVelocity() const {
    return velocity_;
    
}

void Ball::draw(Painter& painter) const {
    painter.draw(center_, radius_,color_);
}


void Ball::setCenter(const Point& center) {
    center_ = center;
}


Point Ball::getCenter() const {
    return center_;
}


double Ball::getRadius() const {
    return radius_;
}

double Ball::getMass() const {
    return M_PI*pow(radius_,3)*(4.0/3.0);
}

bool Ball::getisCollidable()  const
{
    return isCollidable_;
}


void Ball::setColor(const Color& new_color) {
    color_ = new_color;
}