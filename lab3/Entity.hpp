#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity 
{
    protected: 
        std::string name;
        int initiative;
        int hp_max, hp_cur;
        int xp, damage;
        std::pair<int, int> coords;

    public:
        std::string& getName();
        void setName(std::string&);

        int getInitiative();
        void setInitiative(int init);

        int getMaxHP();
        void setMaxHP(int max_hp);

        int getCurHP();
        void setCurHP(int cur_hp);

        int getXP();
        void setXP(int xp);

        int getDmg();
        void setDmg(int dmg);

        int attack();
        void hurt(int dmg);
}

#endif