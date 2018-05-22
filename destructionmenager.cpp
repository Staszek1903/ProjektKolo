#include "destructionmenager.h"

DestructionMenager::DestructionMenager(entityx::EventManager &events)
{
    events.subscribe<CollisionEvent>(*this);
}

void DestructionMenager::update(entityx::EntityManager &en, entityx::EventManager &events, double dt)
{
    DeathPenalty::Handle death;
    for(auto entit: en.entities_with_components(death)){
        entit.destroy();
    }
}

void DestructionMenager::receive(const CollisionEvent &event)
{

    auto en1 = event.en1;
    auto en2 = event.en2;

    if(en1.has_component<Bullet>() || en2.has_component<Bullet>()){
       // std::cout<<"DEBUG1"<<std::endl;
       // en1.assign<DeathPenalty>();
       // en2.assign<DeathPenalty>();
       // bullet.assign <DeathPenalty>();
       // std::cout<<"DEBUG2"<<std::endl;
    }
}
