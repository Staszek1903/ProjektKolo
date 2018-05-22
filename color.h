#ifndef COLOR_H
#define COLOR_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

struct Color : public  entityx::Component<Color>
{
    Color(sf::Color col)
        :col(col){}
    sf::Color col;
};

#endif // COLOR_H
