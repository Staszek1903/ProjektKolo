#ifndef COLLISIONEVENT_H
#define COLLISIONEVENT_H

#include <entityx/entityx.h>

struct CollisionEvent :public entityx::Event<CollisionEvent>
{
public:
    CollisionEvent(entityx::Entity en1, entityx::Entity en2)
        :en1(en1), en2(en2){}
    entityx::Entity en1, en2;
};

#endif // COLLISIONEVENT_H
