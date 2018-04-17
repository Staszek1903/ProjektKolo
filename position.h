#ifndef POSITION_H
#define POSITION_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>

struct Position : public entityx::Component<Position>
{
    Position(sf::Vector2f pos)
        :pos(pos){}
    sf::Vector2f pos;
};

#endif // POSITION_H
