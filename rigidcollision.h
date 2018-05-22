#ifndef RIGIDCOLLISION_H
#define RIGIDCOLLISION_H

#include <entityx/entityx.h>
#include "collisionevent.h"

#include "circleshape.h"
#include "position.h"
#include "velocity.h"

#include "vector_common.h"

class RigidCollision: public entityx::Receiver<RigidCollision>
{
public:
    RigidCollision(entityx::EventManager & events);
    void receive(const CollisionEvent & event);
};

#endif // RIGIDCOLLISION_H
