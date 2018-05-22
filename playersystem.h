#ifndef PLAYERSYSTEM_H
#define PLAYERSYSTEM_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "velocity.h"
#include "position.h"
#include "rotation.h"
#include "vector_common.h"
#include "spawnevent.h"
#include "timer.h"


class PlayerSystem  : public entityx::System<PlayerSystem>
{
public:
    PlayerSystem();

    void update(entityx::EntityManager &en, entityx::EventManager &events, double dt) override;
};

#endif // PLAYERSYSTEM_H
