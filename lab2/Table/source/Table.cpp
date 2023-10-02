#include <iostream>
#include <stdexcept>
#include "Resource/Resource.h"
#include "Table/Table.h"

namespace TNS {
    // конструктор по умолчанию (при отрицательном csz копирует последние csz эл-тов)
    Table::Table(int msz, RNS::Resource* vector, int csz){
        if (msz <= 0)
            throw std::invalid_argument("Invalid <msize> occured, while initializing! Must be > 0");
        
        msize = msz;
        table_vector = new RNS::Resource[msize];
        // если пустой вектор
        if (!vector){ csize = 0; }
        // если вектор не пуст    
        else {
            int v_size = sizeof(vector) / sizeof(RNS::Resource);
            // если нужно заполнить весь массив элементами из начала 
            if ((std::abs(csz) >= msz) && (csz > 0)){
                csize = (msz < v_size) ? msz : v_size;
                for (int i = 0; i < csize; ++i)
                    table_vector[i] = vector[i];
            }
            // если нужно заполнить весь массив элементами из конца
            else if ((std::abs(csz) >= msz) && (csz < 0)){
                csize = (msz < v_size) ? msz : v_size;
                for (int i = 0; i < csize; ++i)
                    table_vector[i] = vector[v_size - csize + i];
            }
            // если нужно заполнить массив частично элементами из начала 
            else if ((std::abs(csz) < msz) && (csz >= 0)){
                csize = (csz < v_size) ? csz : v_size;
                for (int i = 0; i < csize; ++i)
                    table_vector[i] = vector[i];
            }
            // если нужно заполнить массив частично элементами из конца
            else if ((std::abs(csz) < msz) && (csz <= 0)){
                csize = (std::abs(csz) < v_size) ? std::abs(csz) : v_size;
                for (int i = 0; i < csize; ++i)
                    table_vector[i] = vector[v_size - csize + i];
            }
        }
    }

    /*!
        Returns a state of the table (full / partly full / empty)
        @returns A state of the table (full / partly full / empty)
    */
    Fullness Table::checkFullness(){
        if (csize == 0)
            return Fullness::empty;
        if (csize < msize)
            return Fullness::partly_full;
        return Fullness::full;
    }

    /*!
        Increasing the turnover of all resources in <multiplier> times
        @param multiplier A multuiplier for increasing the turnover of all resources
    */
    void Table::incTurnover(double multipliter){
        try {
            for (int i = 0; i < csize; ++i)
                table_vector[i].RNS::Resource::incTurnover(multipliter);
        } catch (...) { throw; }
    }

    /*!
        Returns a profit for all of the resources in summary
        @returns A profit for all of the resources in summary
    */
    double Table::getProfit(){
        try {
            int summary = 0;
            for (int i = 0; i < csize; ++i)
                summary += table_vector[i].getProfit();
            return summary;
        } catch (...) { throw; }
    }
}