#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include "ResourcesManager.h"
#include "rendersystem.h"
#include "movementsystem.h"
#include "position.h"
#include "shape.h"
#include "velocity.h"

class Game : public entityx::EntityX
{
    sf::Text text;
public:
    Game();
    void init();
    void update();
    void draw();
};

#endif // GAME_H
