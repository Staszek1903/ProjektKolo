#include "collisionsystem.h"

CollisionSystem::CollisionSystem()
{

}

void CollisionSystem::update(entityx::EntityManager &en, entityx::EventManager &events, double dt)
{
    Position::Handle pos1;
    Position::Handle pos2;
    CircleShape::Handle circ1;
    CircleShape::Handle circ2;

    for(auto entit1: en.entities_with_components(pos1,circ1)){
        for(auto entit2 : en.entities_with_components(pos2,circ2)){
            if(entit1 == entit2)
                continue;

            float radius_sum = circ1->radius + circ2->radius;
            float dist = distance(pos1->pos, pos2->pos);

            if(radius_sum > dist){
                events.emit<CollisionEvent>(entit1, entit2);
            }
        }
    }
}
