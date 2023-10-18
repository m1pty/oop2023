#include <iostream>
#include <stdexcept>
#include "HandlersDynamic/Handlers.h"
#include "ResourceDynamic/Resource.h"
#include "TableDynamic/Table.h"

namespace TNS {

    // конструктор по умолчанию
    Table::Table()
    {
        table_vector = nullptr;
        csize = 0;
    }

    // копирующий конструктор
    Table::Table(const Table& link) : csize(link.csize)
    {
        table_vector = nullptr;
        if (csize != 0)
        {
            table_vector = new RNS::Resource[csize];
            std::copy(link.table_vector, link.table_vector + csize, table_vector);
        }
    }

    // копирующий оператор присваивания
    Table& Table::operator = (const Table& link)
    {
        if (this != &link)
        {
            delete[] table_vector;
            table_vector = nullptr;
            csize = link.csize;
            if ((csize = link.csize) != 0)
            {
                table_vector = new RNS::Resource[csize];
                std::copy(link.table_vector, link.table_vector + csize, table_vector);
            }
        }
        return *this;
    }

    // перемещающий конструктор
    Table::Table(Table&& link) noexcept : table_vector(link.table_vector), csize(link.csize)
    {
        link.csize = 0;
        link.table_vector = nullptr;
    }

    // перемещающий оператор
    Table& Table::operator = (Table&& link) noexcept
    {
        delete[] table_vector;
        csize = link.csize;
        table_vector = link.table_vector;
        link.csize = 0;
        link.table_vector = nullptr;
        return *this;
    }

    Table::~Table()
    {
        delete[] table_vector;
        csize = 0;
    }

    void Table::garbageCollector(int start_index) noexcept         // [+] удаляет лишние пробелы в таблице
    {
        for (int i = start_index; i < csize; ++i){
            if (table_vector[i].getName() == ""){
                for (int j = i + 1; j < csize; ++j){
                    if (table_vector[j].getName() != ""){
                        table_vector[i].setName(table_vector[j].getName());
                        table_vector[i].setDC(table_vector[j].getDC());
                        table_vector[i].setDP(table_vector[j].getDP());
                        table_vector[i].setPrice(table_vector[j].getPrice());
                        table_vector[j] = RNS::Resource();
                        break;
                    }
                }
            }
        }
    }

    void Table::sort() noexcept  // [+] сортировка пузырьком для ресурсов в таблице
    {
        int i = 0;
        bool swap_made = true;
        while (swap_made){
            swap_made = false;
            for (int j = 0; j < csize - 1; ++j){
                if (table_vector[j].getName() == ""){
                    if (table_vector[j + 1].getName() != ""){
                        swap_made = true;
                    }
                    RNS::Resource tmp = table_vector[j];
                    table_vector[j] = table_vector[j + 1];
                    table_vector[j + 1] = tmp;

                } else if (table_vector[j].getName().compare(table_vector[j + 1].getName()) > 0){
                    RNS::Resource tmp = table_vector[j];
                    table_vector[j] = table_vector[j + 1];
                    table_vector[j + 1] = tmp;
                    swap_made = true;
                }
            }
            ++i;
        }
    }

    void Table::clear() noexcept
    {
        delete[] table_vector;
        csize = 0;
    }

    void Table::deleteByIndex(int index) // [+] удаление по индексу
    {
        try {
            if ((index >= csize) || (index < 0))
                throw std::invalid_argument("[ERROR]: Table[Index] is not declared!\n");
            
            RNS::Resource * new_vector = new RNS::Resource[csize - 1];
            for (int i = index; i < csize - 1; ++i)
                table_vector[i] = table_vector[i + 1];
            std::copy(table_vector, table_vector + (csize - 1), new_vector);
            --csize;
            delete[] table_vector;
            table_vector = new_vector;
        }

        catch (std::bad_alloc &e)
        {
            std::cout << "[ERROR]: Not enough memory for safe deleting!\n";
        }

        catch (std::invalid_argument &i)
        {
            std::cout << "[ERROR]: Process corrupted due to the invalid function argument!\n";
        }
    }

    void Table::deleteByName(const std::string &name) noexcept           // [+] удаление по имени
    {
        try {
            std::pair<bool, size_t> search = searchByName(name);
            if (!search.first)
                return;
        
            // counting N of elements to delete
            int index = search.second, del_end = index;
            std::cout << "[SYSTEM]: Deleting started from index of " << index << std::endl;
            while ((del_end != csize) && (table_vector[del_end].getName().compare(name) == 0))
                ++del_end;
            --del_end;

            int quantity = del_end - index + 1;
            int new_size = csize - quantity;
            RNS::Resource* new_vector = new RNS::Resource[new_size];
            for (int i = index; i < del_end; ++i)
                table_vector[i] = table_vector[i + quantity];
            
            // realloc analogue
            std::copy(table_vector, table_vector + new_size, new_vector);
            csize = new_size;
            delete[] table_vector;
            table_vector = new_vector;
        }

        catch (std::bad_alloc &ba)
        {
            std::cout << "[ERROR]: Not enough memory for safe deleting!\n";
        }
    }

    std::ostream &Table::print(std::ostream &stream) const  // [+] вывод
    {
        // считаем кол-во пробелов для форматированого вывода индекса
        int spaces_n = Handler::countIntLength(csize - 1);

        // считаем кол-во символов в максимальном названии
        int spaces_str = 1;
        for (int i = 0; i < csize; ++i){
            int length = (int)table_vector[i].getName().length();
            spaces_str = (length > spaces_str) ? length : spaces_str;
        }

        // считаем кол-во пробелов в максимальных цифрах
        int spaces_double = 0;
        for (int i = 0; i < csize; ++i){
            int counter = Handler::countIntLength((int)(table_vector[i].getDC()));
            spaces_double = (counter > spaces_double) ? counter : spaces_double;
            counter = Handler::countIntLength((int)(table_vector[i].getDP()));
            spaces_double = (counter > spaces_double) ? counter : spaces_double;
            counter = Handler::countIntLength((int)(table_vector[i].getPrice()));
            spaces_double = (counter > spaces_double) ? counter : spaces_double;
        }
        spaces_double += 4; // разряды после точки и сама точка

        // выводим
        for (int i = 0; i < csize; ++i){
            stream << "| ";
            // вывод индекса
            int current_spaces = Handler::countIntLength(i);
            for (int j = 0; j < spaces_n - current_spaces; ++j)
                stream << " ";
            stream << i << " | ";
                
            
            // вывод имени
            int spaces_needed = spaces_str - (int)table_vector[i].getName().length();
            for (int j = 0; j < spaces_needed; ++j)
                stream << " ";
            stream << table_vector[i].getName() << " | ";

            // вывод DC, DP, Price
            stream.setf(std::ios::fixed);
            stream.precision(3);

            int diff_dc = spaces_double - Handler::countIntLength((int)table_vector[i].getDC());
            int diff_dp = spaces_double - Handler::countIntLength((int)table_vector[i].getDP());
            int diff_price = spaces_double - Handler::countIntLength((int)table_vector[i].getPrice());

            for (int i = 0; i < diff_dc; ++i)
                stream << " ";
            stream << table_vector[i].getDC() << " | ";

            for (int i = 0; i < diff_dp; ++i)
                stream << " ";
            stream << table_vector[i].getDP() << " | ";
            
            for (int i = 0; i < diff_price; ++i)
                stream << " ";
            stream << table_vector[i].getPrice() << " |\n";              
            
        }
        return stream;
    }

    std::istream &Table::input(std::istream & stream)
    {
        try {
            clear();
            if (&stream == &std::cin)
                std::cout << "Введите число элементов для заполнения:\n" << PROMPT;
            int quantity = Handler::getInt(stream, 0);
            csize = quantity;

            table_vector = new RNS::Resource[csize];
            for (int i = 0; i < csize; ++i){
                if (&stream == &std::cin)
                    std::cout << "Введите элемент " << i << ":\n";
                table_vector[i].input(stream);
            }
            sort();
            return stream;
        } 

        catch (std::bad_alloc &ba) 
        { 
            std::cout << "[ERROR]: Not enough memory to set a table of this size!\n";
            return stream;
        }
    }
    
    std::pair<bool, size_t> Table::searchByName(const std::string &name) const           // [+] поиск по имени
    {
        int comp_res = 0;
        int left = 0,  middle = 0, right  = csize - 1;
        std::pair<bool, size_t> answer{false, 0};
        while (left <= right){
            // std::cout << "Left: " << left << " Mid: " << middle << " Right: " << right << std::endl;
            middle = (left + right) / 2;
            // comp_res = table_vector[middle].getName() == (name);
            int comp_res2 = name.compare(table_vector[middle].getName());

            std::string raw_1 = table_vector[middle].getName() + " to ";
            std::string raw_2 = name;

            std::string eqaulity_res = (comp_res != 0) ? "equals" : "not_equals";
            std::cout << "Comparing: " << "(" << table_vector[middle].getName().size() << ") " << raw_1;
            std::cout << " (" << raw_2.size() << ") " << raw_2 << " " << eqaulity_res << "(" << comp_res2 << ")" << std::endl;
            
            if (comp_res2 == 0){
                answer.first = true;
                break;
            }
            else if (comp_res2 < 0){
                right = middle - 1;
            }
            else {
                left  = middle + 1;
            }
        }

        std::string result = (answer.first) ? "True" : "False";
        if (result == "False")
            std::cout << result << " " << answer.second << std::endl;
        
        // если элемент не был найден
        if (!answer.first)
            return answer;
        
        // если найден, откатываем до первого вхождения
        while ((table_vector[middle].getName() == name) && (middle != -1))
            --middle;
        ++middle;
        answer.second = middle;
        std::cout << result << " " << answer.second << std::endl;
        return answer;
    }

    void Table::add(const RNS::Resource &r) // (+=) [+] добавление ресурса в таблицу
    {
        try {

            // possible bad_alloc
            RNS::Resource* new_vector = new RNS::Resource[csize + 1];
            std::copy(table_vector, table_vector + csize, new_vector);

            // если такого элемента ранее не было
            std::pair<bool, size_t> search = searchByName(r.getName()); 
            if (!search.first){
                new_vector[csize] = r;
                ++csize;
                delete[] table_vector;
                table_vector = new_vector;
                sort();
            }
            // если такие элемненты уже есть
            else {
                int index = search.second;
                for (int i = csize; i > index; --i)
                    new_vector[i] = new_vector[i - 1];
                new_vector[index] = r;
                ++csize;
                delete[] table_vector;
                table_vector = new_vector;
                // уже отсортировано по имени
            }
        }

        catch (std::bad_alloc &e)
        {
            std::cout << "[ERROR]: Not enough memory to add!\n";
        }
    }

    void Table::rename(const std::string &old_name, const std::string &new_name) noexcept // переименование типа ресурса 
    {
        std::pair<bool, size_t> search = searchByName(old_name);
        if (!search.first)
            return;
        int index = search.second;
        std::cout << "[SYSTEM]: Renaming started from index " << index << std::endl;
        while ((table_vector[index].getName() == old_name) && (index < csize)){
            table_vector[index].setName(new_name);
            ++index;
        }
        sort();   
    }

    void Table::incTurnover(double multipliter)             // увеличение оборота всех ресурсов
    {
        try
        {
            for (int i = 0; i < csize; ++i)
                table_vector[i].RNS::Resource::incTurnover(multipliter);
        } 
        
        catch (std::invalid_argument &e)
        {
            std::cout << "[ERROR]: Increasing-Turnover process corrupted due to the wrong multiplier parameter!\n"; 
            throw std::invalid_argument("invalid <multiplier>! (must be >= 0)");
        }
    }

    double Table::getProfit() noexcept                  // вычисление прибыльности всех ресурсов таблицы
    {
        double summary = 0;
        for (int i = 0; i < csize; ++i)
            summary += table_vector[i].getProfit();
        return summary;
    }

    Table Table::searchResult(const std::string &name) // вывод таблицы найденного
    {
        Table table{};
        std::pair<bool, size_t> search = searchByName(name);
        if (search.first){
            int index = search.second;
            for (int i = index; i < csize; ++i)
            {
                if (table_vector[i].getName() == name)
                    table.add(table_vector[i]);

                else 
                    break;
            }
        }
        return table;
    }

    void Table::prettify() noexcept
    {
        garbageCollector();
        sort();
    }

    RNS::Resource &Table::operator[] (const std::string& name)
    {
        std::pair<bool, size_t> search = searchByName(name);
        if (search.first){
            RNS::Resource& link = table_vector[search.second];
            return link;
        }
        else
            throw std::runtime_error("[ERROR]: Элемента с таким наименованием нет в таблице!\n");
    }

    const RNS::Resource &Table::operator[] (const std::string& name) const
    {
        std::pair<bool, size_t> search = searchByName(name);
        if (search.first){
            const RNS::Resource& link = table_vector[search.second];
            return link;
        }
        else
            throw std::runtime_error("[ERROR]: Элемента с таким наименованием нет в таблице!\n");
    }

    Table Table::operator * (double multiplier)
    {
        incTurnover(multiplier);
        return *this;
    }

    Table &Table::operator += (RNS::Resource &r)
    {
        add(r);
        return *this;
    }
    std::ostream &operator << (std::ostream &stream, const Table &t)
    {
        std::ostream &s = t.print(stream);
        return s;
    }

    std::istream &operator >> (std::istream &stream, Table &t)
    {
        std::istream &s = t.input(stream);
        return s;
    }
}