#include "lifetimesystem.h"

LifeTimeSystem::LifeTimeSystem()
{

}

void LifeTimeSystem::update(entityx::EntityManager &en, entityx::EventManager &events, double dt)
{
    LifeTime::Handle life;

    for(auto entit: en.entities_with_components(life)){
        life->ticks++;
        if(life->ticks >= life->max_ticks)
            entit.destroy();
    }
}
