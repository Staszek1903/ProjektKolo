#ifndef TIMER_H
#define TIMER_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

struct Timer: public entityx::Component<Timer>
{
    Timer(sf::Time tick)
        :clock(), time(sf::Time::Zero), tick(tick){}

    sf::Clock clock;
    sf::Time time;
    sf::Time tick;
};

#endif // TIMER_H
