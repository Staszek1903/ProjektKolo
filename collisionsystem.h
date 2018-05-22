#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <entityx/entityx.h>
#include "position.h"
#include "circleshape.h"
#include "collisionevent.h"
#include "vector_common.h"

class CollisionSystem : public entityx::System<CollisionSystem>
{
public:
    CollisionSystem();

    void update(entityx::EntityManager &en, entityx::EventManager &events, double dt) override;
};

#endif // COLLISIONSYSTEM_H
