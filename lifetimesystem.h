#ifndef LIFETIMESYSTEM_H
#define LIFETIMESYSTEM_H

#include <entityx/entityx.h>
#include "lifetime.h"

class LifeTimeSystem: public entityx::System<LifeTimeSystem>
{
public:
    LifeTimeSystem();

    void update(entityx::EntityManager &en, entityx::EventManager &events, double dt) override;
};

#endif // LIFETIMESYSTEM_H
