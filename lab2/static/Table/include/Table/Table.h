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

    public:
        // метод сортировки
        // метод shrink
        // метод ввода
        // метод вывода

        // инициализирующий конструктор
        Table() : msize(MAX_SIZE), csize(0) {}
        // конструктор по умолчанию
        Table(int msz = MAX_SIZE, RNS::Resource vector[], int csize = 0);
        // деструктор по умолчанию
        ~Table(){ delete[] table_vector; }

        /*!
            Prints the current state of the table
            @param stream A link to the output stream
            @returns A link to the output stream
        */
        std::ostream &print(std::ostream &stream) const;

        /*!
            Returns a state of the table (full / partly full / empty)
            @returns A state of the table (full / partly full / empty)
        */
        Fullness checkFullness();

        /*!
            Adding the resource to the table by it's link
            @param r a link to the adding resource
        */
        void add(const RNS::Resource &r);   // (+=) добавление ресурса в таблицу
        
        /*!
            Deletes the resource from the table by it's name
            @param name The name of the deleting resource
        */
        void deleteByName(std::string name); // удаляет ресурс из таблицы по наименованию

        /*!
            Deletes the resource from the table by it's index
            @param index The index of the deleting resource
        */
        void deleteByIndex(int index); // удаляет ресур по индексу

        /*!
            Returns the first index of resource appearance or -1
            @param name the name of the searched resource 
            @returns the first index of resource appearance or -1
        */
        int searchByName(std::string name);

        /*!
            Returns a link to the new printable table, containing all examples of this result
            @param indices a pointer to array of integers, containing indecies of resource
            @returns a link to the new printable table, containing all examples of this result
        */
        Table &searchResult(std::string name); // ([]) получение таблицы найденных ресурсов, при помощи двоичного поиска
    
        /*!
            Changing the name of the resource
            @param old_name An old name of the resource
            @param new_name A new name of the resource
        */
        void rename(std::string old_name, std::string new_name);

        /*!
            Increasing the turnover of all resources in <multiplier> times
            @param multiplier A multuiplier for increasing the turnover of all resources
        */
        void incTurnover(double multipliter); // (*) увеличение оборота всех ресурсов

        /*!
            Returns a profit for all of the resources in summary
            @returns A profit for all of the resources in summary
        */
        double getProfit();
    };
}
#endif