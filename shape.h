#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>

struct Shape : public entityx::Component<Shape>
{
    Shape(sf::VertexArray & v)
        :v(v){}
    sf::VertexArray v;
};
#endif // SHAPE_H
