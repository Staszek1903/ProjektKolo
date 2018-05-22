#include <iostream>
#include "ResourcesManager.h"
#include "game.h"

using namespace std;

int main()
{
    auto &resources_manager = ResourcesManager::getInstanceRef();
    Game game;
    game.init();

    sf::Clock clock;
    while (resources_manager.window.isOpen())
    {
        // EVENTS
        {
            sf::Event event;
            while (resources_manager.window.pollEvent(event))
            {
                // Window closed or escape key pressed: ExitStage
                if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
                {
                    resources_manager.window.close();
                    break;
                }
            }
        }

        // UPDATE
        {
            float delta_time = clock.restart().asSeconds();

            game.update();

            resources_manager.window.clear(sf::Color::Black);
            game.draw();

            resources_manager.window.display();
        }
    }

    ResourcesManager::deleteInstance();

    return 0;
}
