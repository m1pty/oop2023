#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

class Tile 
{
    protected:
        std::string texture_path;
        bool is_barrier;
    
    public:
        void show();

        std::string& getPath();
        void setPath(std::string& path);

        bool getBlockability();
        void setBlockability(bool blocked);

}

class ExpirableObstacle: public Tile 
{
    private:
        int ticks_left; // обозначает оставшееся время жизни препятствия
    
    public:
        void expire();
}

class Field
{
    private:
        std::pair<int, int> size;
        std::vector<std::vector<Tile>> map;
    
    public:
        std::pair<int, int> getSize();
        void setSize(std::pair<int, int>);
        void setSize(int x_size, int y_size);
        void generate();
}

#endif