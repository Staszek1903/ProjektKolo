#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include <entityx/entityx.h>

struct CircleShape: public entityx::Component<CircleShape>
{
public:
    CircleShape(int point_count, float radius)
        :point_count(point_count), radius(radius){}
    int point_count;
    float radius;
};

#endif // CIRCLESHAPE_H
