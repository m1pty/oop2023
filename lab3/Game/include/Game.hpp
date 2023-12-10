#ifndef GAME_HPP
#define GAME_HPP
#include "../../Entity/include/Entity.hpp"
#include "../../Graphics/include/Graphics.hpp"
#include "../../Assets/Textures/Constants.hpp"

template <typename T> class QueueIterator;
template <typename T> class LoopedQueue;
template <typename T> struct Node;

/*! 
    @brief Node for list-based Queue Structure 
*/
template <typename T>
struct Node
{
    T* value;
    Node* next;
    Node(T* val) : value(val), next(nullptr) {};
};

/*! 
    @brief List-based Queue Structure 
*/
template <typename T>
class LoopedQueue
{
    private:
        Node<T>* head; 
        Node<T>* tail;
        size_t quantity;
    
    public:
        LoopedQueue() : head(nullptr), tail(nullptr), quantity(0) {};
        ~LoopedQueue()
        {
            for (auto iter = begin(); iter != end(); )
            {
                QueueIterator<T> prev = iter;
                ++iter;
                delete (prev.current);
            }

            if (end() != nullptr)
                delete tail;
        };

        /*!
            @brief Inserting a value to the end of a queue
            @param value a value to put in the end of a queue
            @throws bad_alloc in case of a memory lack
        */
        void insert(T value)
        {
            try
            {
                Node<T>* node = new Node<T>(&value);
                if (!head)
                {
                    head = node;
                    tail = node;
                }

                // if not empty
                else 
                {
                    tail->next = node;
                    tail = node;
                }
                ++quantity;
                tail->next = head; 
            }
            catch (const std::bad_alloc& e)
            {
                std::cout << "Not enough memory for allocating!\n";
            }
        }

        /*!
            @brief Inserting a value to the end of a queue by it's pointer
            @param value a value to put in the end of a queue
            @throws bad_alloc in case of a memory lack
        */
        void insert(T* value)
        {
            try
            {
                Node<T>* node = new Node<T>(value);
                if (!head)
                {
                    head = node;
                    tail = node;
                }

                // if not empty
                else 
                {
                    tail->next = node;
                    tail = node;
                }
                ++quantity;
                tail->next = head; 
            }
            catch (const std::bad_alloc& e)
            {
                std::cout << "Not enough memory for allocating!\n";
            }
        }
        /*!
            @brief Erasing a node from the queue
            @param node a pointer to the erased node
        */
        void erase (Node<T>* node) noexcept
        {
            if (!head)
                throw std::invalid_argument("Set pointer is not a type of a queue\n");

            Node<T>* prevoius = head;
            Node<T>* current = head->next;

            if (prevoius == node)
            {
                head = head->next;
                return;
            }

            while ((current != node) || (current))
            {
                current  = current->next;
                prevoius = prevoius->next;
            }
            
            if (current)
            {
                if (tail == node)
                    tail = prevoius;
                
                prevoius->next = current->next;
            }
        };

        QueueIterator<T> begin()
        {
            return QueueIterator<T>(head);
        };

        QueueIterator<T> end()
        {
            return QueueIterator<T>(tail);
        }
};

// добавить итератор по очереди
template <typename T>
class QueueIterator
{
    friend LoopedQueue<T>;
    private:
        Node<T>* current;
    
    public:
        QueueIterator(Node<T>* ptr) : current(ptr){};

        QueueIterator& operator = (Node<T>* node)
        {
            this->current = node;
            return *this;
        }

        QueueIterator& operator ++ ()
        {
            if (current)
                current = current->next;
            return *this;
        }
        
        bool operator != (QueueIterator& iterator){ return current != iterator.current; }
        bool operator != (QueueIterator  iterator){ return current != iterator.current; }
        bool operator == (QueueIterator& iterator){ return current == iterator.current; }
        bool operator == (QueueIterator  iterator){ return current == iterator.current; }
        T* operator * (){ return current->value; }
};


class Game 
{
    friend class AIService;
    private: 
        Entity* player1;
        Entity* player2;
        LoopedQueue<std::shared_ptr<Entity>>* entities;
        Field<Tile>* field;
    
    public: 
        ~Game(); Game();
        Game(std::string& name_1);
        Game(std::string& name_1, std::string& name_2);
        bool is_alive();
        void print();    // graphical print
};

Field<Tile>* generate(size_t x, size_t y);
void clearConsole();

#endif