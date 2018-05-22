#include "vector_common.h"

float lenghtSq(sf::Vector2f v)
{
    return(v.x * v.x + v.y * v.y);
}

float lenght(sf::Vector2f v)
{
    return std::sqrt(lenghtSq(v));
}

float distance(sf::Vector2f v1, sf::Vector2f v2)
{
    return lenght(v1-v2);
}

void normalize(sf::Vector2f &v)
{
    float l = lenght(v);
    v /= l;
}


sf::Vector2f angle_to_normal(float angle)
{
    angle *= 2*M_PI / 360;
    return sf::Vector2f(std::cos(angle), std::sin(angle));
}
