#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>

class Entity 
{
    protected:
        std::string name;
        int initiative;
        int hp_max, hp_cur;
        int xp, damage;
        int attack_dist;
        std::pair<int, int> coords;

    public:
        // CONSTRUCTORS
        Entity(std::string name, int initiative, int hp_max, int xp, int damage, int attack_dist, std::pair<int, int> coords);
        Entity(std::string name, int initiative, int hp_max, int xp, int damage, int attack_dist, int x, int y);

        // SETTERS
        /*! @brief Sets new entity's name @param name New entity's name */
        void setName       (std::string& name);
        /*! @brief Sets new entity's initiative @param init New entity's initiative */
        void setInitiative (int init         );
        /*! @brief Sets new entity's hp maximum @param max_hp New entity's hp maximum */
        void setMaxHP      (int max_hp       );
        /*! @brief Sets new entity's current hp @param cur_hp New entity's current hp */
        void setCurHP      (int cur_hp       ); 
        /*! @brief Sets new entity's xp cost @param xp New entity's xp cost */
        void setXP         (int xp           ); 
        /*! @brief Sets new entity's damage maximum @param dmg New entity's damage maximum */
        void setDamage     (int dmg          ); 

        void setAttackDist (float attack_dist);
        /*! @brief Sets new entity's coordinates on field @param x New entity's x-coord @param y New entity's y-coord */
        void setCoords     (int x, int y     );
        void setCoords     (std::pair<int, int> new_coords);

        // GETTERS

        /*!
            @brief Returns the name of entity
            @returns The name of entity
        */
        std::string& getName() { 
            std::string& link = name;
            return link;
        };
        
        /*!
            @brief Returns number-representation of initiative
            @returns Number-representation of initiative
        */
        int getInitiative() { return initiative; };
        
        /*!
            @brief Returns number-representation of maximum health
            @returns Number-representation of maximum health
        */
        int getMaxHP()      { return hp_max;     };
        
        /*!
            @brief Returns number-representation of current health
            @returns Number-representation of current health
        */
        int getCurHP()      { return hp_cur;     };
        
        /*!
            @brief Returns number-representation of entity's xp cost
            @returns Number-representation of entity's xp cost
        */
        int getXP()         { return xp;         };
        
        /*!
            @brief Returns number-representation of entity's damage
            @returns Number-representation of entity's damage
        */
        int getDamage()     { return damage;     };
        
        /*!
            @brief Returns number-representation of entity's attack distance
            @returns Number-representation of entity's attack distance
        */
        float getAttackDist() { return attack_dist; };

        /*!
            @brief Returns the pair of coordinates of entity
            @returns The pair of coordinates of entity
        */
        std::pair<int, int> getCoords() { return coords; };

        // ACTION METHODS

        /*!
            @brief Generates damage from entity's attack
            @return Integer representation of damage
        */
        int attack       ();
        
        /*!
            @brief Gives damage to entity from an enemy
            @param damage The damage from attacker
        */
        virtual void hurt(int damage);

        /*!
            @brief Unalive entity
        */
        // virtual void die ();


        std::ostream& printEntity(std::ostream &stream);
};

#endif