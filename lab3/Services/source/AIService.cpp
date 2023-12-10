#include <iostream>
#include "../include/AIService.hpp"
#include "../include/Handlers.hpp"
#include "../Troop/include/Troop.hpp"

void AIService::act()
{
    // Making a loop for every turn
    auto iter = related_game->entities->begin();
    while (related_game->is_alive())
    {
        // if the complete cycle happened, let the player's act firstly
        if (iter == related_game->entities->begin())
        {
            ;
        }

        // role as an entity in an iterator
        // entity is a troop, but if it's not - unknown entity
        // basic entity's behaviour is: 
        // 1. search enemy or check if the previous one is available
        // 2. if available of new found, attack
        // 3. if not available, move towards an enemy's summoner

        // block the enemy's thread while operating with wills (сбор заявок)

        Troop* troop = dynamic_cast<Troop*>(&(*iter));
        if (troop)
        {
            float attack_distance = troop->getAttackDist();
            std::pair<int, int> coords = troop->getCoords();
            
            // if entity's enemy is still available
            if (troop->getAimed())
            {
                std::pair<int, int> enemy_coords = troop->getAimed()->getCoords();
                if (checkReachability(coords, enemy_coords, attack_distance))
                    ; // <---- 
            }

            // if entity's enemy is still available or it didn't have enemy
        }

        ++iter;
    }
}