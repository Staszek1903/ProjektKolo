#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include "ResourcesManager.h"
#include "position.h"
#include "shape.h"

struct RenderSystem : public entityx::System<RenderSystem>
{
    sf::RenderWindow &window;

    RenderSystem(sf::RenderWindow & win);
    void update(entityx::EntityManager &es, entityx::EventManager &events, double dt) override;
};

#endif // RENDERSYSTEM_H
