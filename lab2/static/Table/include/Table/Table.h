#ifndef TABLE_H
#define TABLE_H
#include "Resource/Resource.h"
#include "Table/Table.h"

static const int MAX_SIZE = 10;
namespace TNS {
    enum class Fullness{full, partly_full, empty};
    // класс таблицы
    class Table {
    private:
        const int msize = MAX_SIZE;
        RNS::Resource table_vector[MAX_SIZE];
        int csize;

        /*!
            @brief Sorting the Table's entities by their names (Bubble Sort)
        */
        void sort();

    public:
        ~Table() = default;
        Table();
        

        /*!
            @brief Returns the msize of a Table
            @returns the msize of a Table
        */
        int getMSize(){ return msize; }
        /*!
            @brief Returns the csize of a Table
            @returns the csize of a Table
        */
        int getCSize(){ return csize; }
        /*!
            @brief Returns a link to the resource of index <index>
            @returns a link to the resource of index <index>
        */
        RNS::Resource &getResByIndex(int index) {
            if ((index < 0) || (index > getCSize()))
                throw std::invalid_argument("[ERROR]: Invalid index");
            return table_vector[index];
        }

        /*!
            @brief Refreshes the table, deleting all gaps between resources
            @param start_index Index to start cleaning with
        */
        void garbageCollector(int start_index = 0);

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
            @brief Returns a state of the table (full / partly full / empty)
            @returns A state of the table (full / partly full / empty)
        */
        Fullness checkFullness();

        /*!
            @brief Adding the resource to the table by it's link
            @param r a link to the adding resource
        */
        void add(RNS::Resource &r);   // (+=) добавление ресурса в таблицу
        
        /*!
            @brief Deletes the resource from the table by it's name
            @param name The name of the deleting resource
        */
        void deleteByName(std::string name); // удаляет ресурс из таблицы по наименованию

        /*!
            @brief Deletes the resource from the table by it's index
            @param index The index of the deleting resource
        */
        void deleteByIndex(int index); // удаляет ресур по индексу

        /*!
            @brief Returns the first index of resource appearance or -1
            @param name the name of the searched resource 
            @returns the first index of resource appearance or -1
        */
        int searchByName(std::string name);

        /*!
            @brief Returns a link to the new printable table, containing all examples of this result
            @param indices a pointer to array of integers, containing indecies of resource
            @returns a link to the new printable table, containing all examples of this result
        */
        void searchResult(std::string name, Table &result); // ([]) получение таблицы найденных ресурсов, при помощи двоичного поиска
    
        /*!
            @brief Changing the name of the resource
            @param old_name An old name of the resource
            @param new_name A new name of the resource
        */
        void rename(std::string old_name, std::string new_name);

        /*!
            @brief Increasing the turnover of all resources in <multiplier> times
            @param multiplier A multuiplier for increasing the turnover of all resources
        */
        void incTurnover(double multipliter); // (*) увеличение оборота всех ресурсов

        /*!
            @brief Returns a profit for all of the resources in summary
            @returns A profit for all of the resources in summary
        */
        double getProfit();





        /*!
            @brief An overloaded operator "*" of increasing turnover for all table in <multiplier> times
            @param multiplier A multiplier of increasing
        */
        Table operator *  (double multiplier) const;
        
        /*!
            @brief An overloaded operator "+=" of adding the Resource to the Table
            @param multiplier A link to the added Resource
        */
        Table &operator += (RNS::Resource &r);

        /*!
            @brief An overloaded operator "[]" of indexing the Resource in the Table
            @param name The name of the indexing Resource
        */
       // Resource& operator[] (const string&)
       // const Resource& operator (const string&) const;
        int operator[] (std::string name);

        friend std::ostream &operator << (std::ostream &stream, const Table &t);
        friend std::istream &operator >> (std::istream &stream, Table &t);
    };
}
#endif