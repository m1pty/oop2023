#include <iostream>
#include <cstring>

#ifndef PROMPT
#define PROMPT "> "
#endif

#include "RDialogue/RDialogue.h"
#include "Handlers/Handlers.h"
#include "Resource/Resource.h"
#include "Table/Table.h"
#include "TDialogue/TDialogue.h"

const int N_TABLE_OPTIONS = 12;
namespace dialogueT {
    const char* menu_points[N_TABLE_OPTIONS] = {
        "\n----------------------------------------------------\n[ 0]: Выйти из программы\n",
        "[ 1]: Ввести таблицу\n",
        "[ 2]: Вывести таблицу\n",
        "[ 3]: Добавить ресурс в таблицу\n",
        "[ 4]: Вывести ресурс по его наименованию\n",
        "[ 5]: Удалить ресурс по его наименованию\n",
        "[ 6]: Удалить ресурс по его индексу\n",
        "[ 7]: Переименовать тип ресурса\n",
        "[ 8]: Перейти в меню ресурса\n",
        "[ 9]: Посчитать прибыльность ресурсов таблицы\n",
        "[10]: Вывести состояние полноты таблицы\n",
        "[11]: Увеличить оборот всех ресурсов таблицы\n\n----------------------------------------------------\n"
    };
    // указатели на функции, соответствующие пунктам меню
    void (*table_menu_functions[N_TABLE_OPTIONS]) (TNS::Table &) = {
        nullptr, tableInputD, tablePrintD, tableAddResD, tableGetResD,
        tableDelResNameD, tableDelResIndexD, tableRenameResD, 
        tableChangeResD, tableGetProfitD, tableCheckStateD, tableIncTurnoverD
    };

    void tableMenuD(TNS::Table &t)        // [**] основной выбор, меню 
    {
        int user_choice = 1;
        while (user_choice != 0){
            for (int i = 0; i < N_TABLE_OPTIONS; ++i)
                std::cout << menu_points[i];
            std::cout << PROMPT;
            try {
                int user_choice = Handler::getInt(std::cin, 0, N_TABLE_OPTIONS - 1);
                if (user_choice != 0)
                    table_menu_functions[user_choice](t);
                
                else
                    break;
                
            } catch (...) { throw; }
        }
    }
    
    void tableInputD(TNS::Table &t) { int a = 0; }
    void tablePrintD(TNS::Table &t)       // [02] печать таблицы
    {
        try {
            t.print(std::cout);
        } catch (...) { throw; }
    }
    void tableAddResD(TNS::Table &t) { int a = 0; }
    void tableGetResD(TNS::Table &t) { int a = 0; }
    void tableDelResNameD(TNS::Table &t) { int a = 0; }
    void tableDelResIndexD(TNS::Table &t) { int a = 0; }

    void tableRenameResD(TNS::Table &t)   // [07] переименовать тип ресурса
    {
        try {
            std::cout << "Введите старое имя переименовываемого ресурса:\n" << PROMPT;
            std::string old_name = Handler::getString(std::cin);
            std::cout << "Введите новое имя переименовываемого ресурса:\n" << PROMPT;
            std::string new_name = Handler::getString(std::cin);
            t.rename(old_name, new_name);
            std::cout << "[RESULT]: Переименовывание прошло успешно!\n";

        } catch (...) { throw; }
    }
    void tableChangeResD(TNS::Table &t)   // [08] изменение ресурса по индексу через диалоговую функцию ресурса
    {
        try {
            std::cout << "Введите индекс изменяемого элемента\n" << PROMPT;
            int index = Handler::getInt(std::cin, 0, t.getCSize());
            RNS::Resource &link = t.getResByIndex(index);
            dialogR::menuD(link);
        } catch (...) { throw; }
    } 
    void tableGetProfitD(TNS::Table &t)    // [09] получение прибыльности всех ресурсов таблицы
    {
        try {
            double profit = t.getProfit();
            std::cout << "[PROFIT]: " << profit << " у.е.\n";
        } catch (...) { throw; }
    }
    void tableCheckStateD (TNS::Table &t) // [10] проверка заполненности таблицы
    {
        try {
            TNS::Fullness state = t.checkFullness();
            if (state == TNS::Fullness::full)
                std::cout << "[STATE]: Заполнена (" << t.getCSize() << "/" << t.getMSize() << ")\n";
            
            if (state == TNS::Fullness::partly_full)
                std::cout << "[STATE]: Частично заполнена (" << t.getCSize() << "/" << t.getMSize() << ")\n";

            if (state == TNS::Fullness::empty)
                std::cout << "[STATE]: Пуста (" << t.getCSize() << "/" << t.getMSize() << ")\n";

        } catch (...) { throw; }
    }
    void tableIncTurnoverD(TNS::Table &t) // [11] увеличение оборота всех ресурсов таблицы
    {
        try {
            std::cout << "Введите коэф. умножения\n" << PROMPT;
            double coef = Handler::getDouble(std::cin, 0.0);
            t.incTurnover(coef);
        } catch (...) { throw; }
    }
}