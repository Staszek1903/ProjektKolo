#include "movementsystem.h"

MovementSystem::MovementSystem()
{

}

void MovementSystem::update(entityx::EntityManager &en, entityx::EventManager &ev, double dt)
{
    Position::Handle pos;
    Velocity::Handle vel;

    for(entityx::Entity entity : en.entities_with_components(pos,vel))
    {
        pos->pos += sf::Vector2f(vel->vel.x * dt, vel->vel.y * dt);
    }
}
