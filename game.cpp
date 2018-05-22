#include "game.h"


Game::Game()
    :rigid(events)
{

}

void Game::init()
{
    auto & resource = ResourcesManager::getInstanceRef();
    text.setFont(resource.font);
    text.setCharacterSize(32);
    text.setPosition(sf::Vector2f(-100,250));
    text.setString("sterowanie: A,W,S,D,Spacja");

    ent_count.setFont(resource.font);
    ent_count.setCharacterSize(32);
    ent_count.setPosition(-300,-290);
    ent_count.setString("entity_count: --");

    auto en = entities.create();
    en.assign<Spawn>();
    en.assign<Timer>(sf::seconds(2.0f));
    en.assign<Position>(sf::Vector2f(0,500));
    en.assign<Velocity>(sf::Vector2f(5,0));

    en = entities.create();
    en.assign<Player>(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::Space);
    en.assign<Timer>(sf::seconds(0.2f));
    en.assign<Position>(sf::Vector2f(0,0));
    en.assign<Velocity>(sf::Vector2f(0,0));
    en.assign<Rotation>(0);
    en.assign<Color>(sf::Color::Yellow);
    en.assign<CircleShape>(3, 25);

    systems.add<DestructionMenager>(events);
    systems.add<LifeTimeSystem>();
    systems.add<PlayerSystem>();
    systems.add<RenderSystem>(resource.window);
    systems.add<SpawnSystem>(entities,events);
    systems.add<CollisionSystem>();
    systems.add<MovementSystem>();
    systems.configure();
}

void Game::update()
{
    systems.update<DestructionMenager>(1);
    systems.update<LifeTimeSystem>(1);
    systems.update<PlayerSystem>(1);
    systems.update<CollisionSystem>(1);
    systems.update<MovementSystem>(1);
    systems.update<SpawnSystem>(1);
}

void Game::draw()
{    
    auto & resource = ResourcesManager::getInstanceRef();
    resource.window.draw(text);
    systems.update<RenderSystem>(0.0f);

    int ent = entities.size();
    std::stringstream ss;
    ss<<ent;
    ent_count.setString("entity_count: " + ss.str());

    resource.window.draw(ent_count);
}

void Game::createShape(sf::Vector2f pos, sf::Vector2f vel, int shape_index)
{
    auto & resource = ResourcesManager::getInstanceRef();

    auto en = entities.create();
    en.assign<Position>(pos);
    en.assign<Shape>(resource.vertex_arrays.at(shape_index));
    en.assign<Velocity>(vel);
}

void Game::createCirc(sf::Vector2f pos, sf::Vector2f vel, int radius, int point_count)
{
    auto en = entities.create();
    en.assign<Position>(pos);
    en.assign<Rotation>(0.0f);
    en.assign<Velocity>(vel);
    en.assign<CircleShape>(point_count, radius);
}
