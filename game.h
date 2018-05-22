#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>
#include "ResourcesManager.h"
#include "rendersystem.h"
#include "movementsystem.h"
#include "spawnsystem.h"
#include "collisionsystem.h"
#include "position.h"
#include "shape.h"
#include "velocity.h"
#include "spawn.h"
#include "rigidcollision.h"
#include "playersystem.h"
#include "player.h"
#include "timer.h"
#include "lifetimesystem.h"
#include "destructionmenager.h"
#include "color.h"

#include <sstream>

class Game : public entityx::EntityX
{
    sf::Text text;
    sf::Text ent_count;
    RigidCollision rigid;
public:
    Game();
    void init();
    void update();
    void draw();

private:
    void createShape(sf::Vector2f pos, sf::Vector2f vel, int shape_index);
    void createCirc(sf::Vector2f pos, sf::Vector2f vel, int radius, int point_count);
};

#endif // GAME_H
