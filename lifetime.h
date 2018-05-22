#ifndef LIFETIME_H
#define LIFETIME_H

#include <entityx/entityx.h>

struct LifeTime: entityx::Component<LifeTime>
{
    LifeTime(int max_ticks)
        :ticks(0), max_ticks(max_ticks){}

    int ticks;
    int max_ticks;
};

#endif // LIFETIME_H
