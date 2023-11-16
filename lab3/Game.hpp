#ifndef GAME_HPP
#define GAME_HPP
#include <Entity/Entity.hpp>
#include <Graphics/Graphics.hpp>

class LoopedQueue
{
    private:
        int size, state; // размер очереди и инициатива ходящего (определяет положение в циклической очереди)
        Entity* entities;
    
    public:

}

class Game 
{
    private: 
        LoopedQueue* entities;
        Field* field;

}

#endif