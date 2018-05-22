#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <assert.h>
#include "vertexdata.h"
//#include <iostream>

class ResourcesManager
{
private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = delete;
	ResourcesManager& operator=(const ResourcesManager&) = delete;
	ResourcesManager(ResourcesManager&&) = delete;
	ResourcesManager& operator=(ResourcesManager&&) = delete;
	~ResourcesManager();

private:
	static ResourcesManager *instance;

public:
	static ResourcesManager* getInstance();
	static ResourcesManager& getInstanceRef();
	static void deleteInstance();

private:
    void loadVertexArray(sf::Vector2f v[], sf::Vector2f t[], int size);
public:
	sf::RenderWindow window;
    sf::View camera;
    sf::Font font;
    std::vector <sf::VertexArray> vertex_arrays;
    std::vector <sf::Texture> textures;
};
