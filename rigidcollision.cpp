#include "rigidcollision.h"

RigidCollision::RigidCollision(entityx::EventManager &events)
{
    events.subscribe<CollisionEvent>(*this);
}

void RigidCollision::receive(const CollisionEvent &event)
{
    auto en1 = event.en1;
    auto en2 = event.en2;
    Position::Handle pos1 = en1.component<Position>();
    Position::Handle pos2 = en2.component<Position>();
    Velocity::Handle vel1 = en1.component<Velocity>();
    Velocity::Handle vel2 = en2.component<Velocity>();

    sf::Vector2f colision_normal = pos1->pos - pos2->pos;
    normalize(colision_normal);

    float relative_vel = distance(vel1->vel, vel2->vel);

    vel1->vel += 0.4f * colision_normal * relative_vel;
}
