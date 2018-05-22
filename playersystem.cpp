#include "playersystem.h"

PlayerSystem::PlayerSystem()
{

}

void PlayerSystem::update(entityx::EntityManager &en, entityx::EventManager &events, double dt)
{
    Player::Handle player;
    Position::Handle pos;
    Velocity::Handle vel;
    Rotation::Handle rot;
    Timer::Handle timer;

    for(auto entit : en.entities_with_components(timer, player, pos, vel, rot)){

        sf::Vector2f forward_vector = angle_to_normal(rot->angle - 90);

        if(sf::Keyboard::isKeyPressed(player->up))
            vel->vel += forward_vector/10.0f;
        if(sf::Keyboard::isKeyPressed(player->down))
            vel->vel -= forward_vector/10.0f;
        if(sf::Keyboard::isKeyPressed(player->left))
            rot->angle -= 4;
        if(sf::Keyboard::isKeyPressed(player->right))
            rot->angle += 4;
        if(sf::Keyboard::isKeyPressed(player->shoot))
            if(timer->clock.getElapsedTime() > timer->tick){
                timer->clock.restart();
                events.emit<SpawnEvent>(SpawnEvent::BULLET, pos->pos+(50.0f * forward_vector), 10.0f * forward_vector);
            }

        //std::cout<<rot->angle
    }
}
