#include "spawnsystem.h"

SpawnSystem::SpawnSystem(entityx::EntityManager & entities, entityx::EventManager &events)
    :entities(entities)
{
    events.subscribe<SpawnEvent>(*this);
}

void SpawnSystem::update(entityx::EntityManager &en, entityx::EventManager &events, double dt)
{
    Spawn::Handle spawn;
    Timer::Handle timer;
    Position::Handle pos;
    Velocity::Handle vel;

    for(auto entity: en.entities_with_components(spawn, pos, vel, timer)){
        float radius = std::sqrt(pos->pos.x*pos->pos.x + pos->pos.y*pos->pos.y);
        //std::cout<<"radius " <<radius<<std::endl;
        float velocity = std::sqrt(vel->vel.x*vel->vel.x + vel->vel.y*vel->vel.y);
        sf::Vector2f normal = pos->pos / radius;
        sf::Vector2f acceleration = -normal * ((velocity*velocity)/ radius);

        vel->vel += acceleration * static_cast<float>(dt);

        timer->time += timer->clock.restart();
        if(timer->time > timer->tick){
            timer->time = sf::Time::Zero;
            events.emit<SpawnEvent>(SpawnEvent::ASTEROID, pos->pos, acceleration*20.0f);
        }
    }
}

void SpawnSystem::receive(const SpawnEvent & event)
{
    switch (event.type) {
    case SpawnEvent::ASTEROID:
        spawnAsteroid(event.pos, event.vel);
        break;
    case SpawnEvent::BULLET:
        spawnBullet(event.pos, event.vel);
    default:
        break;
    }
}

void SpawnSystem::spawnAsteroid(sf::Vector2f pos, sf::Vector2f vel)
{
    auto asteroid = entities.create();
    asteroid.assign<CircleShape>(6,30);
    asteroid.assign<Position>(pos);
    asteroid.assign<Velocity>(vel);
    asteroid.assign<Rotation>(0.1);
    asteroid.assign<LifeTime>(1000);
    asteroid.assign<Color>(sf::Color::Blue);
}

void SpawnSystem::spawnBullet(sf::Vector2f pos, sf::Vector2f vel)
{
    auto bullet = entities.create();
    bullet.assign <CircleShape>(5,5);
    bullet.assign <Position>(pos);
    bullet.assign <Velocity>(vel);
    bullet.assign <Bullet>();
    bullet.assign <Rotation>(0);
    bullet.assign <LifeTime>(200);
    bullet.assign <Color>(sf::Color::White);
}
