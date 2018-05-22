#ifndef SPAWNSYSTEM_H
#define SPAWNSYSTEM_H

#include <entityx/entityx.h>
#include "spawn.h"
#include "position.h"
#include <rotation.h>
#include "velocity.h"
#include "circleshape.h"
#include "spawnevent.h"
#include "bullet.h"
#include "timer.h"
#include "lifetime.h"
#include "color.h"
#include "deathpenalty.h"
#include <cmath>

class SpawnSystem : public entityx::System<SpawnSystem>, public entityx::Receiver<SpawnSystem>
{
    entityx::EntityManager & entities;
public:
    SpawnSystem(entityx::EntityManager &entities, entityx::EventManager &events);
    void update(entityx::EntityManager &en, entityx::EventManager &events, double dt) override;

    void receive(const SpawnEvent &event);

private:
    void spawnAsteroid(sf::Vector2f pos, sf::Vector2f vel);
    void spawnBullet(sf::Vector2f pos, sf::Vector2f vel);
};

#endif // SPAWNSYSTEM_H
