#include <iostream>
#include <memory>
#include "../../Game/include/Game.hpp"

bool Game::is_alive()
{
    if ((player1->getCurHP() > 0) && (player2->getCurHP() > 0))
        return true;
    return false;
}

Field<Tile>* generate(size_t x = 16, size_t y = 11)
{
    std::srand(time(nullptr));
    // making plain tiled field
    Field<Tile>* field_ptr = new Field<Tile>(x, y);
    
    // carving left river
    size_t cell_x = std::rand() % 4 + 3, cell_y = 0;
    auto& water_link = WATER_PATH;
    int prev = 0; // previous way of spreading
    while ((cell_y != y) && (cell_x != -1))
    {
        field_ptr->getCell(cell_x, cell_y).setBlockability(true);
        field_ptr->getCell(cell_x, cell_y).setPath(water_link);
        // 0 - right, 1 - left, 2-4 - forward
        
        if (prev > 1)
        {
            int spreading_way = std::rand() % 5;
            switch (spreading_way)
            {
                case 0:
                    prev = 0; ++cell_x;
                    break;
                case 1:
                    prev = 1; --cell_x;
                    break;
                default:
                    prev = 2; ++cell_y;
            }
        }

        // if we turned, let's go forward
        else
        {
            prev = 2;
            ++cell_y;
        }
    }

    // carving right river
    cell_x = (x - 1) - (std::rand() % 4 + 3); cell_y = 10;
    prev = 0; // previous way of spreading
    while ((cell_y != -1) && (cell_x != x))
    {
        field_ptr->getCell(cell_x, cell_y).setBlockability(true);
        field_ptr->getCell(cell_x, cell_y).setPath(water_link);
        // 0 - right, 1 - left, 2-4 - forward
        
        if (prev > 1)
        {
            int spreading_way = std::rand() % 5;
            switch (spreading_way)
            {
                case 0:
                    prev = 0; ++cell_x;
                    break;
                case 1:
                    prev = 1; --cell_x;
                    break;
                default:
                    prev = 2; --cell_y;
            }
        }

        // if we turned, let's go forward
        else
        {
            prev = 2;
            --cell_y;
        }
    }


    // organizing spawn-zones
    auto& spawn_link = SPAWN_PATH;
    field_ptr->getCell(0, 0).setPath(spawn_link);
    field_ptr->getCell(0, 1).setPath(spawn_link);
    field_ptr->getCell(1, 0).setPath(spawn_link);

    field_ptr->getCell(x - 1, y - 1).setPath(spawn_link);
    field_ptr->getCell(x - 2, y - 1).setPath(spawn_link);
    field_ptr->getCell(x - 1, y - 2).setPath(spawn_link);

    // building bridges
    auto& bridge_link = BRIDGE_PATH;
    srand(time(nullptr));
    int delay1 = std::rand() % 2;
    srand(time(nullptr) + delay1);
    int delay2 = std::rand() % 2;

    for (int i = 0; i < x; ++i)
    {
        if (field_ptr->getCell(i, 1 + delay1).getPath() == WATER_PATH)
        {
            field_ptr->getCell(i, 1 + delay1).setPath(bridge_link);
            field_ptr->getCell(i, 1 + delay1).setBlockability(false);
        }
        
        if (field_ptr->getCell(i, y - (2 + delay2)).getPath() == WATER_PATH)
        {
            field_ptr->getCell(i, y - (2 + delay2)).setPath(bridge_link);
            field_ptr->getCell(i, y - (2 + delay2)).setBlockability(false);
        }
    }
    // generating rocks


    return field_ptr;
}

void Game::print() noexcept
{
    std::pair<size_t, size_t> sizes = field->getSize();
    std::cout << "Queue Size: " << entities->getSize() << std::endl;
    std::cout << ((entities->begin() == nullptr) ? "No Nodes" : "Some Nodes") << std::endl;
    std::cout << ((entities->begin().getValue() == nullptr) ? "Empty" : "Not Empty") << std::endl;
    entities->printState(std::cout);

    size_t number = 0;
    for (auto field_iter = field->begin(); field_iter != field->end(); ++field_iter)
    {
        auto cell_ptr = *field_iter;
        auto ent_ptr  = cell_ptr->getEntity();
        
        if (number % field->getSize().first == 0) std::cout << "\n";
        std::cout << "[";

        // if entity is located in that cell
        // searching for it in the list
        if (ent_ptr)
        {
            size_t n = 0;
            auto iter = entities->begin();
            while (iter != entities->end())
            {
                std::shared_ptr<Entity> this_ent = *iter;
                if (this_ent->getInitiative() == ent_ptr->getInitiative())
                {
                    if (n < 10)
                        std::cout << "0" << n;
                    else
                        std::cout << n;
                }
                ++n; ++iter;
            }

            auto this_ent = *iter;
            if (this_ent->getInitiative() == ent_ptr->getInitiative())
            {
                if (n < 10)
                    std::cout << "0" << n;
                else
                    std::cout << n;
            }
        }
        else
            std::cout << cell_ptr->getPath();

        std::cout << "]";
        ++number;
    }
    std::cout << "\n";
}

Game::Game() : player1(nullptr), player2(nullptr)
{
    field = generate();
    entities = new LoopedQueue<std::shared_ptr<Entity>>();
}

Game::Game(std::string& name_1)
{
    // generating field with random surface
    field = generate();

    // creating players
    std::shared_ptr<Entity> ent1 = std::make_shared<Entity>(Entity(name_1,     0, 300, 1, 15, 2, 0,  0));
    std::shared_ptr<Entity> ent2 = std::make_shared<Entity>(Entity("Player 2", 1, 300, 1, 15, 2, field->getSize().first - 1, field->getSize().second - 1));

    // inserting players in the entities queue 
    entities = new LoopedQueue<std::shared_ptr<Entity>>();
    entities->insert(ent1);
    entities->insert(ent2);

    // setting entities on the field
    (*field)[0][0].setEntity(ent1);
    (*field)[(field->getSize()).second - 1][(field->getSize()).first - 1].setEntity(ent2);
}

Game::~Game()
{
    // not needed due to the smart pointers

    // if (player1)
    //     delete player1;
    
    // if (player2)
    //     delete player2;

    delete entities;
    delete field;
}

void clearConsole()
{
    #if defined _WIN32
        system("cls");
    
    #elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__)
        system("clear");
    
    #endif
}