#include <iostream>
#include <memory>
#include "Entity/include/Entity.hpp"
#include "Graphics/include/Graphics.hpp"
#include "Game/include/Game.hpp"
#include "Services/include/AIService.hpp"

int main()
{
    std::string name = "Winner";
    std::shared_ptr game = std::make_shared<Game>(name);
    std::unique_ptr service = std::make_unique<AIService>(game);

    std::shared_ptr ent1 = std::make_shared<Entity>("Archers",  2, 50, 10, 10, 3, 2, 2);
    std::shared_ptr ent2 = std::make_shared<Entity>("Warriors", 3, 50, 10, 20, 1, 1, 2);

    game->print();
    //clearConsole();    
    return 0;
}