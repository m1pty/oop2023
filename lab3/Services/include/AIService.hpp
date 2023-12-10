#ifndef AISERVICE_HPP
#define AISERVICE_HPP
#include "../../Game/include/Game.hpp"
#include "../../Entity/include/Entity.hpp"

class AIService
{
    private:
        std::shared_ptr<Game> related_game;

    public:
        /*!
            @brief Acting all entities on the field in a loop
        */
        void act();

        /*!
            @brief Initializing constructor for game
            @param game A pointer to the administrated game
        */
        AIService(std::shared_ptr<Game> game) : related_game(game) {};
};
#endif