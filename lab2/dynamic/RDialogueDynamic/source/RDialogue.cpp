#include <iostream>
#include <cstring>
#include <compare>

#ifndef PROMPT
#define PROMPT "> "
#endif

#include "RDialogueDynamic/RDialogue.h"
#include "ResourceDynamic/Resource.h"
#include "HandlersDynamic/Handlers.h"

const int N_OPTIONS = 11;

namespace dialogR {
    const char* menu_points[N_OPTIONS] = {
        "\n----------------------------------------------------\n[ 0]: Exit\n", 
        "[ 1]: Ввести ресурс\n",
        "[ 2]: Вывести ресурс\n",
        "[ 3]: Сравнить ресурс\n",
        "[ 4]: Сложить ресурсы\n",
        "[ 5]: Увеличить оборот\n",
        "[ 6]: Установить новое значение названия ресурса\n",
        "[ 7]: Установить новое значение потребления\n",
        "[ 8]: Установить новое значение производства\n",
        "[ 9]: Установить новое значение цены\n",
        "[10]: Вычислить прибыльность\n----------------------------------------------------\n"    
    };
    // указатели на функции, соответствующие пунктам меню
    void (*menu_functions[N_OPTIONS]) (RNS::Resource &) = {
        nullptr, inputD,
        printD, compareD, addD, incTurnoverD,
        setNameD, setDCD, setDPD, setPriceD, getProfitD
    };

    // основной выбор, меню 
    void menuD(RNS::Resource &r){
        int user_choice = 1;
        while (user_choice != 0){
            for (int i = 0; i < N_OPTIONS; ++i)
                std::cout << menu_points[i];
            std::cout << PROMPT;
            try {
                int user_choice = Handler::getInt(std::cin, 0, N_OPTIONS - 1);
                if (user_choice != 0)
                    menu_functions[user_choice](r);
                
                else
                    break;
                
            } catch (...) { throw; }
        }
    }

    // ввод ресурса
    void inputD(RNS::Resource &r){
        try {
            std::cout << "Введите название ресурса:\n" << PROMPT;
            std::string name = Handler::getString();
            std::cout << "Введите суточное потребление ресурса:\n" << PROMPT;
            double dc = Handler::getDouble(std::cin, 0.0);
            std::cout << "Введите суточное производство ресурса:\n" << PROMPT;
            double dp = Handler::getDouble(std::cin, 0.0);
            std::cout << "Введите цену ресурса:\n" << PROMPT;
            double price = Handler::getDouble(std::cin, 0.0);
            r.setName(name).setDC(dc).setDP(dp).setPrice(price);
            std::cout << "Ресурс успешно обновлён!" << std::endl; 
        } catch (...) { throw; }  
    }

    // вывод ресурса
    void printD(RNS::Resource &r){
        try {
            std::cout << "Ресурс: (Имя / Сут.Потребление / Сут.Производство / Цена)\n";
            r.print(std::cout);
        } catch (...) { throw; }
    }

    // сравнение ресурсов
    void compareD(RNS::Resource &r){
        try {
            RNS::Resource new_r{"", 0.0, 0.0, 0.0};
            RNS::Resource &link = new_r;
            std::cout << "Введите данные нового ресурса для сравнения\n";
            inputD(link);
            if (r.compare_equal(link))
                std::cout << "[RESULT]: Исходный ресурс эквивалентен заданному!\n";
            else if (r.compare_less(link))
                std::cout << "[RESULT]: Исходный ресурс меньше заданного!\n";
            else
                std::cout << "[RESULT]: Исходный ресурс больше заданного!\n";

        } catch (...) { throw; }
    }

    // слияние ресурсов
    void addD(RNS::Resource &r){
        try {
            RNS::Resource new_r{"", 0.0, 0.0, 0.0};
            RNS::Resource &link = new_r;
            std::cout << "Введите данные нового ресурса для сложения\n";
            inputD(link);
            if (r.getName().compare(link.getName()) == 0){
                RNS::Resource answer = r.add(link);
                std::cout << "Ресурс: (Имя / Сут.Потребление / Сут.Производство / Цена)\n";
                answer.print(std::cout);
            }
            else
                std::cout << "[WARNING]: Ресурсы имеют разные наименования и не могут быть сложены!\n";

        } catch (...) {throw;}
    }

    // вычисление прибыльности
    void getProfitD(RNS::Resource &r){
        try {
            std::cout << "Прибыльность ресурса составляет: ";
            std::cout << r.getProfit();
            std::cout << " у.е./неделя" << std::endl;
        } catch (...) { throw; }
    }

    // увеличение оборота
    void incTurnoverD(RNS::Resource &r){
        try {
            std::cout << "Введите коэф. умножения\n" << PROMPT;
            double coef = Handler::getDouble(std::cin, 0.0);
            r.incTurnover(coef);
        } catch (...) { throw; }
    }

    // присвоение нового названия
    void setNameD(RNS::Resource &r){
        try {
            std::cout << "Введите новое название ресурса\n" << PROMPT;
            std::string name = Handler::getString();
            r.setName(name);
        } catch (...) { throw; }
    }
    
    // присвоение нового потребления
    void setDCD(RNS::Resource &r){
        try {
            std::cout << "Введите новое суточное потребление (кг/сут)\n" << PROMPT;
            double dc = Handler::getDouble(std::cin, 0.0);
            r.setDC(dc);
        } catch (...) { throw; }
    }

    // присвоение нового производства
    void setDPD(RNS::Resource &r){
        try {
            std::cout << "Введите новое суточное производство (кг/сут)\n" << PROMPT;
            double dp = Handler::getDouble(std::cin, 0.0);
            r.setDP(dp);
        } catch (...) { throw; }
    }

    // присвоение новой цены
    void setPriceD(RNS::Resource &r){
        try {
            std::cout << "Введите новую цену ресурса\n" << PROMPT;
            double price = Handler::getDouble(std::cin, 0.0);
            r.setPrice(price);
        } catch (...) { throw; }
    }
}