#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include "position.h"
#include "velocity.h"

class MovementSystem : public entityx::System<MovementSystem>
{
public:
    MovementSystem();

    void update(entityx::EntityManager &en, entityx::EventManager &ev, double dt);
};

#endif // MOVEMENTSYSTEM_H
