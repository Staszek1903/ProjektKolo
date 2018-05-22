#ifndef DESTRUCTIONMENAGER_H
#define DESTRUCTIONMENAGER_H

#include <entityx/entityx.h>
#include "collisionevent.h"
#include "bullet.h"
#include "deathpenalty.h"

class DestructionMenager : public entityx::System<DestructionMenager>, public entityx::Receiver<DestructionMenager>
{
    std::vector <entityx::Entity> to_destroy;

public:
    DestructionMenager(entityx::EventManager & events);

    void update(entityx::EntityManager &en, entityx::EventManager &events, double dt) override;

    void receive(const CollisionEvent &event);
};

#endif // DESTRUCTIONMENAGER_H
