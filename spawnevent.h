#ifndef SPAWNEVENT_H
#define SPAWNEVENT_H

#include "entityx/entityx.h"
#include <SFML/Graphics.hpp>

struct SpawnEvent : entityx::Event<SpawnEvent>
{
    enum{
        ASTEROID,
        BULLET
    };

    SpawnEvent(int type, sf::Vector2f pos, sf::Vector2f vel)
        :type(type), pos(pos), vel(vel){}

    int type;
    sf::Vector2f pos, vel;
};

#endif // SPAWNEVENT_H
