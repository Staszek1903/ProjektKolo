#include "rendersystem.h"

RenderSystem::RenderSystem(sf::RenderWindow &win)
    :window(win)
{

}

void RenderSystem::update(entityx::EntityManager &en, entityx::EventManager &ev, double dt)
{
    auto & resource = ResourcesManager::getInstanceRef();

    Shape::Handle shape;
    Position::Handle position;

    for(entityx::Entity entity : en.entities_with_components(shape,position))
    {
        sf::Transform trans;

        trans.translate(position->pos);
        trans.scale(sf::Vector2f(50,50));

        sf::RenderStates state;
        state.texture = &resource.textures.at(0);
        state.transform =trans;

        window.draw(shape->v,state);
    }
}
