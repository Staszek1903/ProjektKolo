#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>

#define KEY sf::Keyboard::Key

struct Player : entityx::Component<Player>
{
    Player(KEY left, KEY right, KEY up, KEY down, KEY shoot)
        :left(left), right(right), up(up), down(down), shoot(shoot){}

    KEY left,
    right,
    up,
    down,
    shoot;
};

#endif // PLAYER_H
