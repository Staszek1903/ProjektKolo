#ifndef ROTATION_H
#define ROTATION_H

#include <entityx/entityx.h>

class Rotation: public entityx::Component<Rotation>
{
public:
    Rotation(float angle)
        :angle(angle){}
    float angle;
};

#endif // ROTATION_H
