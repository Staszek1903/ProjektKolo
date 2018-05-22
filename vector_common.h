#ifndef VECTOR_COMMON_H
#define VECTOR_COMMON_H

#include <SFML/Graphics.hpp>
#include <cmath>

float lenghtSq(sf::Vector2f v);

float lenght(sf::Vector2f v);

float distance(sf::Vector2f v1, sf::Vector2f v2);

void normalize(sf::Vector2f &v);

sf::Vector2f angle_to_normal(float angle);

#endif // VECTOR_COMMON_H
