#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include "ResourcesManager.h"
#include "position.h"
#include "rotation.h"
#include "shape.h"
#include "circleshape.h"
#include "spawn.h"
#include "bullet.h"
#include "color.h"

struct RenderSystem : public entityx::System<RenderSystem>
{
    sf::RenderWindow &window;

    RenderSystem(sf::RenderWindow & win);
    void update(entityx::EntityManager &en, entityx::EventManager &events, double dt) override;
};

#endif // RENDERSYSTEM_H
