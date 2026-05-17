#include "World.h"
#include "Painter.h"
#include <fstream>
#include "Ball.hpp"
static constexpr double timePerTick = 0.001; // 0.001 


World::World(const std::string& worldFilePath) {

    std::ifstream stream(worldFilePath);
    if(!stream.is_open())   return;



    stream >> topLeft.x >> topLeft.y >> bottomRight.x >> bottomRight.y;
    physics.setWorldBox(topLeft, bottomRight);


    double x;
    double y;
    double vx;
    double vy;
    double radius;

    double red;
    double green;
    double blue;

    bool isCollidable;

    
    while (stream.peek(), stream.good()) {
        stream >> x >> y >> vx >> vy;
        stream >> red >> green >> blue;
       
        stream >> radius;
         stream >> std::boolalpha >> isCollidable;

        Ball ball(Color{red,green,blue},Point{x,y},radius,Velocity(Point{vx,vy}),isCollidable);

        balls.push_back(ball);
    }
}

void World::show(Painter& painter) const {
    
    painter.draw(topLeft, bottomRight, Color(1, 1, 1));

    for (const Ball& ball : balls) {
        ball.draw(painter);
    }

    for(const auto& d: dustParticles)
    {
        painter.draw(d.center,5.0 , Color(1.0,0.0,0.0));
    }
}

void World::update(double time) {
    time += restTime;
    const auto ticks = static_cast<size_t>(std::floor(time / timePerTick));
    restTime = time - double(ticks) * timePerTick;

    // Шары сдвинулись на (ticks * timePerTick) секунд
    physics.update(balls, ticks, dustParticles);

    // Пыль тоже должна сдвинуться на это же время!
    double simulationTime = double(ticks) * timePerTick;

    for(auto it = dustParticles.begin(); it != dustParticles.end(); ) {
        it->center = it->center + it->velocity * simulationTime;
        it->lifetime -= simulationTime;
        
        if(it->lifetime <= 0) {
            it = dustParticles.erase(it);
        } else {
            ++it;
        }
    }
}
