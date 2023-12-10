#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include "../../Entity/include/Entity.hpp"

Entity::Entity(std::string name, int initiative, int hp_max, int xp, int damage, int attack_dist, std::pair<int, int> coords)
{
    this->name = name;
    if (initiative < 0)
        throw std::invalid_argument("Initiative must be >= 0\n");

    this->initiative = initiative;
    if (hp_max <= 0)
        throw std::invalid_argument("Maximum HP must be > 0\n");
    
    this->hp_max = hp_max;
    this->hp_cur = hp_max;
    if (xp <= 0)
        throw std::invalid_argument("XP cost must be > 0\n");

    this->xp = xp;
    if (damage <= 0)
        throw std::invalid_argument("Damage must be > 0\n");

    this->damage = damage;
    if (attack_dist <= 0)
        throw std::invalid_argument("Attack distance must be > 0");

    this->attack_dist = attack_dist;
    if ((coords.first < 0) || (coords.second < 0))
        throw std::invalid_argument("Every coordinate must be >= 0\n");

    this->coords = coords;
}

Entity::Entity(std::string name, int initiative, int hp_max, int xp, int damage, int attack_dist, int x, int y)
{
    this->name = name;
    if (initiative < 0)
        throw std::invalid_argument("Initiative must be >= 0\n");

    this->initiative = initiative;
    if (hp_max <= 0)
        throw std::invalid_argument("Maximum HP must be > 0\n");
    
    this->hp_max = hp_max;
    this->hp_cur = hp_max;
    if (xp <= 0)
        throw std::invalid_argument("XP cost must be > 0\n");

    this->xp = xp;
    if (damage <= 0)
        throw std::invalid_argument("Damage must be > 0\n");

    this->damage = damage;
    if (attack_dist <= 0)
        throw std::invalid_argument("Attack distance must be > 0");

    this->attack_dist = attack_dist;
    if ((x < 0) || (y < 0))
        throw std::invalid_argument("Every coordinate must be >= 0\n");

    this->coords = std::make_pair(x, y);
}

void Entity::hurt(int damage)
{
    if (damage < 0)
        throw std::runtime_error("Damage must be >= 0\n");
    this->hp_cur -= damage;
    //if (hp_cur <= 0)
    //    this->die();
}

int Entity::attack()
{
    std::srand(std::time(nullptr));
    std::random_device rd;
    std::mt19937 gen(rd()); // 0 - <=20%, 1-3 - 20-80%, 4 - 80-100%
    std::discrete_distribution<int> distribution({1, 1, 4, 2, 1});
    
    int min_dmg = distribution(gen) * 20;
    
    std::srand(std::time(nullptr));
    float damage = (min_dmg + std::rand() % 20);

    std::cout << damage << std::endl;
    int final_damage = ceil(damage * this->damage / 100);
    std::cout << "---> " << final_damage << std::endl;
    return final_damage;
}

std::ostream& Entity::printEntity(std::ostream &stream)
{
    stream << "Name: "<< name << std::endl;
    stream << "Initiative: " << initiative << std::endl;
    stream << "HP: ("<< hp_cur << "/" << hp_max << ")" << std::endl;
    stream << "XP: "<< xp << std::endl;
    stream << "Damage: " << damage << std::endl;
    stream << "Attack Distance: "<< attack_dist << std::endl;
    stream << "X: "<< coords.first  << std::endl;
    stream << "Y: "<< coords.second << std::endl;
    return stream;
}