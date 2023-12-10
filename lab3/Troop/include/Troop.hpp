#ifndef TROOP_HPP
#define TROOP_HPP
#include "Entity.hpp"

class Troop : public Entity
{
    protected:
        float speed;
        Entity* aimed;
        Entity* owner;
    
    public:
        void setSpeed(float speed);
        void setAimed(Entity* aimed);
        void setOwner(Entity* owner);

        float   getSpeed() { return speed; };
        Entity* getAimed() { return aimed; };
        Entity* getOwner() { return owner; };

        void moveToAim();
        Entity* searchEnemy();
};



#endif