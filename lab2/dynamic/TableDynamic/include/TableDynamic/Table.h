#ifndef TABLE_DYNAMIC_H
#define TABLE_DYNAMIC_H
#include "ResourceDynamic/Resource.h"

namespace TNS {
    enum class Fullness{full, partly_full, empty};
    // класс таблиц
    class Table {
    private:
        RNS::Resource * table_vector;
        int csize;

        /*!
            @brief Sorting the Table's entities by their names (Bubble Sort)
        */
        void sort() noexcept;

        /*!
            @brief Refreshes the table, deleting all gaps between resources
            @param start_index Index to start cleaning with
        */
        void garbageCollector(int start_index = 0) noexcept;

        /*!
            @brief Setting all the Table's entities to default Resources
        */
        void clear() noexcept;

    public:

        /*! @brief Default destructor for Table */
        ~Table();
        
        /*! @brief Default constructor for Table */
        Table();
        
        /*! @brief Copy constructor */
        Table(const Table& link);

        /*! @brief Move constructor */
        Table(Table&& link) noexcept;

        /*!
            @brief Returns the csize of a Table
            @returns the csize of a Table
        */
        int getCSize() const { return csize; }

        /*!
            @brief Returns a link to the resource of index <index>
            @returns a link to the resource of index <index>
            @throws std::invalid_argument in case of wrong index
        */
        RNS::Resource &getResByIndex(int index)
        {
            if ((index < 0) || (index >= getCSize()))
                throw std::invalid_argument("[ERROR]: Invalid index");
            return table_vector[index];
        }

        /*!
            @brief Prints the current state of the Table
            @param stream A link to the output stream
            @returns A link to the output stream
        */
        std::ostream &print(std::ostream &stream) const;

        /*!
            @brief Allows to input an instance of the Table
            @param stream The stream of input
            @returns The link to the stream
        */
        std::istream &input(std::istream &stream);

        /*!
            @brief Adding the resource to the table by it's link
            @param r a link to the adding resource
        */
        void add(const RNS::Resource &r);   // (+=) добавление ресурса в таблицу
        
        /*!
            @brief Deletes the resource from the table by it's name
            @param name The name of the deleting resource
        */
        void deleteByName(const std::string &name) noexcept; // удаляет ресурс из таблицы по наименованию

        /*!
            @brief Deletes the resource from the table by it's index
            @param index The index of the deleting resource
            @throws std::invalid_argument in case of (<index> >= <csize>) or (<index> < 0)
        */
        void deleteByIndex(int index); // удаляет ресурс по индексу

        /*!
            @brief Returns the first index of resource appearance or -1
            @param name the name of the searched resource 
            @returns the first index of resource appearance or -1
        */
        std::pair<bool, size_t> searchByName(const std::string &name) const;

        /*!
            @brief Returns a link to the new printable table, containing all examples of this result
            @param indices a pointer to array of integers, containing indecies of resource
            @returns a link to the new printable table, containing all examples of this result
        */
        Table searchResult(const std::string &name); // ([]) получение таблицы найденных ресурсов, при помощи двоичного поиска
    
        /*!
            @brief Changing the name of the resource
            @param old_name An old name of the resource
            @param new_name A new name of the resource
        */
        void rename(const std::string &old_name, const std::string &new_name) noexcept ;

        /*!
            @brief Increasing the turnover of all resources in <multiplier> times
            @param multiplier A multuiplier for increasing the turnover of all resources
            @throws std::invalid_argument - in case of <multiplier> < 0 
        */
        void incTurnover(double multipliter);

        /*!
            @brief Returns a profit for all of the resources in summary
            @returns A profit for all of the resources in summary
        */
        double getProfit() noexcept;

        /*!
            @brief Executing garbage collection and sorting
        */
       void prettify() noexcept;

        /*!
            @brief An overloaded operator "*" of increasing turnover for all table in <multiplier> times
            @param multiplier A multiplier of increasing
        */
        Table operator * (double multiplier);
        
        /*!
            @brief An overloaded operator "+=" of adding the Resource to the Table
            @param multiplier A link to the added Resource
        */
        Table &operator += (RNS::Resource &r);

        /*!
            @brief An overloaded operator "[]" of indexing the Resource in the Table
            @param name The name of the indexing Resource
        */
        RNS::Resource &operator[] (const std::string& name);
        const RNS::Resource &operator[] (const std::string& name) const;

        /*!
            @brief An overloaded operator << for output
            @param stream The link to an output stream
        */
        friend std::ostream &operator << (std::ostream &stream, const Table &t);
        
        /*!
            @brief An overloaded operator >> for output
            @param stream The link to an input stream
        */
        friend std::istream &operator >> (std::istream &stream, Table &t);
    
        /*!
            @brief An overloaded copy operator '='
            @param link The constant link to the Table being copied to the current Table
        */
        Table& operator = (const Table& link);

        /*!
            @brief An overloaded move operator '='
            @param link The constant link to the Table being copied to the current Table
        */
        Table& operator = (Table&& link) noexcept;
    };
}
#endif