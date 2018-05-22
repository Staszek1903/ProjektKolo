#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::instance = nullptr;

ResourcesManager::ResourcesManager()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(800, 600, 32), "SFML Test", sf::Style::Titlebar | sf::Style::Close, settings);
	window.setVerticalSyncEnabled(true);

    camera.setCenter(0,0);
    sf::Vector2u size = window.getSize();
    camera.setSize(sf::Vector2f(size.x, size.y));

    window.setView(camera);

    font.loadFromFile("./COMIC.TTF");

    sf::Texture tex;
    tex.loadFromFile("./texture.png");
    textures.push_back(tex);

    loadVertexArray(quad_vertex, quad_texture, 4);
    loadVertexArray(shape_vertex, shape_vertex,6);
}

ResourcesManager::~ResourcesManager()
{
}

ResourcesManager* ResourcesManager::getInstance()
{
    if (!instance)
    {
        instance = new ResourcesManager();
    }

	return instance;
}

ResourcesManager& ResourcesManager::getInstanceRef()
{
	return *getInstance();
}

void ResourcesManager::deleteInstance()
{
    delete instance;
}

void ResourcesManager::loadVertexArray(sf::Vector2f v[], sf::Vector2f t[], int size)
{
    sf::VertexArray va(sf::TriangleFan, size);
    for(int i=0; i<size; ++i)
    {
        va[i].position = v[i];
        va[i].texCoords = t[i];
        va[i].color = sf::Color::Blue;
    }

    vertex_arrays.push_back(va);
}
