#include "rendersystem.h"

RenderSystem::RenderSystem(sf::RenderWindow &win)
    :window(win)
{

}

void RenderSystem::update(entityx::EntityManager &en, entityx::EventManager &ev, double dt)
{
    auto & resource = ResourcesManager::getInstanceRef();

    Position::Handle position;
    Rotation::Handle rotation;
    Shape::Handle shape;
    CircleShape::Handle circ;
    Color::Handle color;

    for(auto entity : en.entities_with_components(circ, position, rotation, color)){

        sf::CircleShape circle;
        circle.setFillColor(color->col);
        circle.setPosition(position->pos);
        circle.setRotation(rotation->angle);
        circle.setRadius(circ->radius);
        circle.setPointCount(circ->point_count);
        circle.setOrigin(circ->radius, circ->radius);

        window.draw(circle);
    }

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
