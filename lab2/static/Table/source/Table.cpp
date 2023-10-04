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

    // конструктор по умолчанию (при отрицательном csz копирует последние csz эл-тов)
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


    // = [METHODS] =============================================

    void Table::garbageCollector(int start_index)       // [+] удаляет лишние пробелы в таблице
    {   
        if (msize == csize)
            return;

        for (int i = start_index; i < csize; ++i){
            if (table_vector[i].getName() == "Empty"){
                for (int j = i + 1; j < msize; ++j){
                    if (table_vector[j].getName() != "Empty"){
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
    void Table::sort()                                      // [+] сортировка пузырьком для ресурсов в таблице
    {
        int i = 0;
        bool swap_made = true;
        while (swap_made){
            swap_made = false;
            for (int j = 0; j < csize - 1; ++j){
                if (table_vector[j].getName() == "Empty"){
                    if (table_vector[j + 1].getName() != "Empty"){
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
    void Table::deleteByIndex(int index)                    // [+] удаление по индексу
    {
        RNS::Resource r{};
        table_vector[index] = r;
        garbageCollector(); 
    }
    void Table::deleteByName(std::string name)              // [+] удаление по имени
    {
        int index = searchByName(name);
        if (index == -1)
            return;
            
        while ((index != csize) && (table_vector[index].getName() == name)){
            RNS::Resource r;
            table_vector[index] = r;
            ++index;
        }
        garbageCollector();
    }
    std::ostream &Table::print(std::ostream &stream) const  // [+] вывод
    {
        // считаем кол-во пробелов для форматированого вывода индекса
        int spaces_n = Handler::countIntLength(msize - 1);

        // считаем кол-во символов в максимальном названии
        int spaces_str = 5; // "Empty"
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
    int Table::searchByName(std::string name)               // [+] поиск по имени
    {
        int left     = 0, right  = csize - 1;
        int comp_res = 0, middle = 0;
        bool found = false;
        while (left < right){
            middle = (left + right) / 2;
            comp_res = table_vector[middle].getName().compare(name);
            if (comp_res == 0){
                found = true;
                break;
            }
            else if (comp_res < 0){
                left  = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        // если элемент не был найден
        if (!found)
            return -1;
        
        // если найден, откатываем до первого вхождения
        while ((table_vector[middle].getName().compare(name) == 0) && (middle != -1)){
            middle -= 1;
        }
        return middle + 1;
    }
    Fullness Table::checkFullness()                         // [+] проверка заполненности таблицы
    {
        if (csize == 0)
            return Fullness::empty;
        if (csize < msize)
            return Fullness::partly_full;
        return Fullness::full;
    }
    void Table::add(RNS::Resource &r)                       // (+=) [+] добавление ресурса в таблицу
    {
        if (csize == msize){
            std::cout << "[ERROR]: Таблица заполнена, добавление нового ресурса невозможно!\n";
            return;
        }
        // если такого элемента ранее не было
        int index = searchByName(r.getName()); 
        if (index == -1){
            table_vector[csize] = r;
            ++csize;
            sort();
        }
        // если такие элемненты уже есть
        else {
            for (int i = csize; i > index; --i)
                table_vector[i] = table_vector[i - 1];
            table_vector[index] = r;
            ++csize;
            // уже отсортировано по имени
        }
    }
    void Table::rename(std::string old_name, std::string new_name){
        try {
            int index = searchByName(old_name);
            if (index == -1)
                return;
            while ((table_vector[index].getName() == old_name) && (index < csize)){
                table_vector[index].setName(new_name);
                ++index;
            }
            sort();
        } catch (...) { throw; }    
    }
    void Table::incTurnover(double multipliter){
        try {
            for (int i = 0; i < csize; ++i)
                table_vector[i].RNS::Resource::incTurnover(multipliter);
        } catch (...) { throw; }
    }
    double Table::getProfit(){
        try {
            double summary = 0;
            for (int i = 0; i < csize; ++i)
                summary += table_vector[i].getProfit();
            return summary;
        } catch (...) { throw; }
    }
    Table &Table::searchResult(std::string name) // вывод таблицы найденного
    {
        Table result = Table{};
        int index = searchByName(name);
        if (index != -1){
            while ((table_vector[index].getName().compare(name) == 0) && (index != msize))
                result.add(table_vector[index]);
            ++index;
        }
        Table &link = result;
        return link;
    }

    
    // [ОПЕРАТОРЫ] =======================================================================

    Table &Table::operator * (double multiplier)
    {
        incTurnover(multiplier);
        return *this;
    }

}