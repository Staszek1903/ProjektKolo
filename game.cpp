#include "game.h"


Game::Game()
{

}

void Game::init()
{
    auto & resource = ResourcesManager::getInstanceRef();
    text.setFont(resource.font);
    text.setCharacterSize(32);
    text.setPosition(sf::Vector2f(100,100));
    text.setString("SAMPLE TEXT");

    auto en = entities.create();
    en.assign<Position>(sf::Vector2f(200,200));
    en.assign<Shape>(resource.vertex_arrays.at(0));
    en.assign<Velocity>(sf::Vector2f(-0.5,0));

    en = entities.create();
    en.assign<Position>(sf::Vector2f(300,250));
    en.assign<Shape>(resource.vertex_arrays.at(0));
    en.assign<Velocity>(sf::Vector2f(0,0.5));

    en = entities.create();
    en.assign<Position>(sf::Vector2f(400,200));
    en.assign<Shape>(resource.vertex_arrays.at(1));
    en.assign<Velocity>(sf::Vector2f(0.5,0));


    systems.add<RenderSystem>(resource.window);
    systems.add<MovementSystem>();
    systems.configure();
}

void Game::update()
{
    systems.update<MovementSystem>(1);
}

void Game::draw()
{    
    auto & resource = ResourcesManager::getInstanceRef();
    resource.window.draw(text);
    systems.update<RenderSystem>(0.0f);
}
