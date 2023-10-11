#include <iostream>
#include <stdexcept>
#include "Resource/Resource.h"
#include "Handlers/Handlers.h"
#include "Table/Table.h"

namespace TNS {

    // конструктор по умолчанию
    Table::Table(){
        csize = 0;
        for (int i = 0; i < MAX_SIZE; ++i)
            table_vector[i] = RNS::Resource{};
    }

    // иниц. конструктор (при отрицательном csz копирует последние csz эл-тов)
    // Table::Table(int msz, RNS::Resource* vector, int csz){
    //     if (msz <= 0)
    //         throw std::invalid_argument("Invalid <msize> occured, while initializing! Must be > 0");
        
    //     // если пустой вектор
    //     if (!vector){ csize = 0; }
    //     // если вектор не пуст    
    //     else {
    //         int v_size = sizeof(vector) / sizeof(RNS::Resource);
    //         // если нужно заполнить весь массив элементами из начала 
    //         if ((std::abs(csz) >= msz) && (csz > 0)){
    //             csize = (msz < v_size) ? msz : v_size;
    //             for (int i = 0; i < csize; ++i)
    //                 table_vector[i] = vector[i];
    //         }
    //         // если нужно заполнить весь массив элементами из конца
    //         else if ((std::abs(csz) >= msz) && (csz < 0)){
    //             csize = (msz < v_size) ? msz : v_size;
    //             for (int i = 0; i < csize; ++i)
    //                 table_vector[i] = vector[v_size - csize + i];
    //         }
    //         // если нужно заполнить массив частично элементами из начала 
    //         else if ((std::abs(csz) < msz) && (csz >= 0)){
    //             csize = (csz < v_size) ? csz : v_size;
    //             for (int i = 0; i < csize; ++i)
    //                 table_vector[i] = vector[i];
    //         }
    //         // если нужно заполнить массив частично элементами из конца
    //         else if ((std::abs(csz) < msz) && (csz <= 0)){
    //             csize = (std::abs(csz) < v_size) ? std::abs(csz) : v_size;
    //             for (int i = 0; i < csize; ++i)
    //                 table_vector[i] = vector[v_size - csize + i];
    //         }
    //     }
    // }


    void Table::garbageCollector(int start_index) noexcept         // [+] удаляет лишние пробелы в таблице
    {   
        if (msize == csize)
            return;

        for (int i = start_index; i < csize; ++i){
            if (table_vector[i].getName() == ""){
                for (int j = i + 1; j < msize; ++j){
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
        RNS::Resource empty_resource;
        for (int i = 0; i < csize; ++i)
            table_vector[i] = empty_resource;
        csize = 0;
    }


    void Table::deleteByIndex(int index)                    // [+] удаление по индексу
    {
        if ((index >= csize) || (index < 0))
            throw std::invalid_argument("[ERROR]: Table[Index] is not declared");
        
        RNS::Resource r{};
        table_vector[index] = r;
        --csize;
        garbageCollector(index);
    }
    void Table::deleteByName(const std::string &name) noexcept           // [+] удаление по имени
    {
        std::pair<bool, size_t> search = searchByName(name);
        if (!search.first)
            return;
        
        int index = search.second;
        std::cout << "Deleting from index of " << index << std::endl;
        while ((index != csize) && (table_vector[index].getName().compare(name) == 0)){
            RNS::Resource r;
            table_vector[index] = r;
            --csize;
            garbageCollector(index);
        }
    }
    std::ostream &Table::print(std::ostream &stream) const  // [+] вывод
    {
        // считаем кол-во пробелов для форматированого вывода индекса
        int spaces_n = Handler::countIntLength(msize - 1);

        // считаем кол-во символов в максимальном названии
        int spaces_str = 1; // "Empty"
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
        for (int i = 0; i < msize; ++i){
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
                std::cout << "Введите число элементов для заполнения: (max = " << MAX_SIZE << ")\n" << PROMPT;
            int quantity = Handler::getInt(stream, 0, MAX_SIZE);
            csize = quantity;
            for (int i = 0; i < quantity; ++i){
                if (&stream == &std::cin)
                    std::cout << "Введите элемент " << i << ":\n";
                table_vector[i].input(stream);
            }
            return stream;
        } catch (...) { throw; }
    }
    
    std::pair<bool, size_t> Table::searchByName(const std::string &name)               // [+] поиск по имени
    {
        int left     = 0, right  = csize - 1;
        int comp_res = 0, middle = 0;
        std::pair<bool, size_t> answer{false, 0};
        while (left <= right){
            std::cout << "Left: " << left << " Mid: " << middle << " Right: " << right << std::endl;
            middle = (left + right) / 2;
            comp_res = table_vector[middle].getName() == (name);
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
                left  = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        std::string result = (answer.first) ? "True" : "False";
        std::cout << result << " " << answer.second << std::endl;
        // если элемент не был найден
        if (!answer.first)
            return answer;
        
        // если найден, откатываем до первого вхождения
        while ((table_vector[middle].getName().compare(name) == 0) && (middle != -1)){
            middle -= 1;
        }
        ++middle;
        answer.second = middle;

        std::cout << answer.first << answer.second << std::endl;
        return answer;
    }
    
    Fullness Table::checkFullness() const                       // [+] проверка заполненности таблицы
    {
        if (csize == 0)
            return Fullness::empty;
        if (csize < msize)
            return Fullness::partly_full;
        return Fullness::full;
    }

    void Table::add(const RNS::Resource &r)                       // (+=) [+] добавление ресурса в таблицу
    {
        if (csize == msize){
            std::cout << "[ERROR]: Таблица заполнена, добавление нового ресурса невозможно!\n";
            return;
        }
        // если такого элемента ранее не было
        std::pair<bool, size_t> search = searchByName(r.getName()); 
        if (!search.first){
            table_vector[csize] = r;
            ++csize;
            sort();
        }
        // если такие элемненты уже есть
        else {
            for (int i = csize; i > search.second; --i)
                table_vector[i] = table_vector[i - 1];
            table_vector[search.second] = r;
            ++csize;
            // уже отсортировано по имени
        }
    }
    void Table::rename(const std::string &old_name, const std::string &new_name) // переименование типа ресурса 
    {
        try {
            std::pair<bool, size_t> search = searchByName(old_name);
            if (!search.first)
                return;
            std::cout << "Renaming started from index " << search.second << std::endl;
            while ((table_vector[search.second].getName() == old_name) && (search.second < csize)){
                table_vector[search.second].setName(new_name);
                ++search.second;
            }
            sort();
        } catch (...) { throw; }    
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
        TNS::Table table;
        std::pair<bool, size_t> search = searchByName(name);
        if (search.first){
            int index = search.second;
            std::string tmp_name = table_vector[index].getName();;

            while ((tmp_name.compare(name) == 0) && (index != msize)){
                tmp_name = table_vector[index].getName();
                table.add(table_vector[index]);
                ++index;

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
    // const RNS::Resource &Table::operator[] (const std::string& name) const
    // {
    //     continue;
    // }
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