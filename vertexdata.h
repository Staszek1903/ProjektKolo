#ifndef VERTEXDATA_H
#define VERTEXDATA_H

#include <SFML/Graphics.hpp>

static sf::Vector2f quad_vertex[] =
{
    {-0.4, -1},
    {0.4 , -1},
    {0.6 ,0.4},
    {-0.6,  0.4}
};

static sf::Vector2f quad_texture[] =
{
    {0, 0},
    {400 ,0},
    {400 ,400},
    {0,  400}
};

static sf::Vector2f shape_vertex[] =
{
    {-0.4, -0.5},
    { 0.6, -0.5},
    { 0.8, -0.2},
    { 0.3,  0.4},
    {-0.7,  0.9},
    {-0.8, -0.0}
};

static sf::Vector2f shape_texture[] =
{
    {0, 0},
    { 400, 0},
    { 400, 0},
    { 400,  400},
    {0,  400},
    {0, 0}
};
#endif // VERTEXDATA_H
