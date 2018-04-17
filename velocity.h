#ifndef VELOCITY_H
#define VELOCITY_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>

struct Velocity : public entityx::Component<Velocity>
{
    Velocity(sf::Vector2f vel)
        :vel(vel){}
    sf::Vector2f vel;
};
#endif // VELOCITY_H
