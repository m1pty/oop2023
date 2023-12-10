#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "../../Entity/include/Entity.hpp"
#include "../../Assets/Textures/Constants.hpp"

template <typename T>
class Line;

class Tile 
{
    protected:
        std::string texture_path;
        std::shared_ptr<Entity> entity_standing;
        bool is_blocked; // заблокировано препятствием/существом
    
    public:
        Tile();
        Tile(std::string& path);
        Tile(std::string& path, bool is_blocked);

        std::string& getPath()
        {
            std::string& link = texture_path;
            return link;
        };
        bool getBlockability() { return is_blocked;      };
        std::shared_ptr<Entity> getEntity()    { return entity_standing; };

        void setPath         ( const std::string& path ) { texture_path = path;      };
        void setBlockability ( bool blocked      ) { is_blocked = blocked;     };
        void setEntity       ( std::shared_ptr<Entity> entity ) 
        {
            is_blocked = (!entity) ? false : true;
            entity_standing = entity; 
        };

        std::ostream& printState(std::ostream &stream)
        {
            stream << "Texture Path: " << texture_path << std::endl;
            stream << "Entity: ";
            if (entity_standing == nullptr)
                stream << std::endl;
            
            else
            {
                entity_standing->printEntity(stream);
                stream << "NOT_EMPTY" << std::endl;
            }
            
            stream << "Is Blocked: " << ((is_blocked) ? "Yes" : "No") << std::endl;
            return stream;
        };
};

class ExpirableObstacle: public Tile 
{
    private:
        int ticks_left; // обозначает оставшееся время жизни препятствия
    
    public:
        void decTicks()
        {
            --ticks_left;
            if (ticks_left == 0)
                expire();
        };
        void expire();
};

template<typename T>
class Field
{
    private:
        std::pair<size_t, size_t> size;
        T** field;
    
    public:
        /*!
            @brief Initializing constructor
            @throws bad_alloc in case of a memory lack
        */
        Field(size_t x = 1, size_t y = 1)
        {
            try
            {
                size = std::make_pair(x, y);
                field    = new T*[y];
                for (int i = 0; i < y; ++i)
                    field[i] = new T[x];
            }
            catch(const std::bad_alloc& e)
            {
                std::cout << "Not enough memory for initializing!\n";
            }
        };

        /*!
            @brief Default destructor
        */
        ~Field()
        {
            for (int i = 0; i < size.second; ++i)
                delete[] field[i];
            
            delete[] field;
        }

        /*!
            @brief Returns a pair of scales of a field (x, y)
            @returns A pair of scales of a field (x, y)
        */
        std::pair<size_t, size_t> getSize(){ return size; };
        
        Tile& getCell(size_t x, size_t y)
        {
            if ((x >= size.first) || (y >= size.second))
                throw std::invalid_argument("Invalid coordinates!\n");
            
            Tile& tile_link = field[y][x];
            return tile_link;
        };

        /*!
            @brief Sets entity to a cell
            @param ent A pointer to entity
            @param coords Coordinates to set
            @throws invalid_argument in case of invalid coordinates
        */
        void setEntity(Entity* ent, std::pair<size_t, size_t> coords)
        {
            if ((coords.first >= size.first) || (coords.second >= size.second))
                throw std::invalid_argument("Invalid coordinates!\n");
            field[coords.second][coords.first].setEntity(ent);
        };

        /*!
            @brief Sets entity to a cell
            @param ent A pointer to entity
            @param x_coord X-coordinate to set on
            @param y_coord Y-coordinate to set on
            @throws invalid_argument in case of invalid coordinates
        */
        void setEntity(Entity* ent, size_t x_coord, size_t y_coord)
        {
            if ((x_coord >= size.first) || (y_coord >= size.second))
                throw std::invalid_argument("Invalid coordinates!\n");
            field[y_coord][x_coord].setEntity(ent);
        };

        /*!
            @brief Sets a new pair of field's scales
            @param newsize pair of new scales
            @throws invalid_argument in case of equality to 0 of any coordinate
        */
        void setSize ( std::pair<size_t, size_t> new_size )
        {
            if ((new_size.first == 0) || (new_size.second == 0))
                throw std::invalid_argument("All the scales must be > 0");

            size = new_size; 
        };
        
        /*!
            @brief Sets a new pair of field's scales
            @param x_size Scale of x-coordinate
            @param y_size Scale of y-coordinate
            @throws invalid_argument in case of equality to 0 of any coordinate
        */
        void setSize ( size_t x_size, size_t y_size )
        { 
            if ((x_size == 0) || (y_size == 0))
                throw std::invalid_argument("All the scales must be > 0");
            
            size = std::make_pair(x_size, y_size); 
        };
        
        /*!
            @brief Sets a specific cell to it's place in field if possible
            @throws invalid_argument in case of invalid coordinates
        */
        void setCell ( size_t x , size_t y , T cell )
        {
            if ((x >= size.first) || (y >= size.second))
                throw std::invalid_argument("Incorrect coordinates of a cell\n");
            
            field[y][x] = cell;
        };

        std::ostream& printState(std::ostream& stream)
        {
            for (int i = 0; i < size.second; ++i)
            {
                for (int j = 0; j < size.first; ++j)
                {
                    stream << "Coordinates: (" << j << ", " << i << ")\n";
                    field[i][j].printState(stream);
                    stream << std::endl;
                }
            }
            return stream;
        };


        // ========================================================== //
        Line<T> operator[] (size_t y)
        {
            if (y >= size.second)
                throw std::invalid_argument("Invalid index!\n");
            return Line(field[y], size.first);
        };

        // void generate(); - transfer to the game's class to avoid pattern's miscommunications
        // void draw();
};

template <typename T>
class Line 
{
    private:
        size_t length;
        T* row;
            
    public:
        Line(T* line, size_t len) : length(len), row(line) {};
        T& operator[] (size_t x)
        {
            if (x >= length)
                throw std::invalid_argument("Invalid index!\n");
            T& link = row[x];
            return link;
        }
};
#endif