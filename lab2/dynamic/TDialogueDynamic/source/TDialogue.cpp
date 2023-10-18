#include <iostream>
#include <cstring>

#ifndef PROMPT
#define PROMPT "> "
#endif

#include "RDialogueDynamic/RDialogue.h"
#include "HandlersDynamic/Handlers.h"
#include "ResourceDynamic/Resource.h"
#include "TableDynamic/Table.h"
#include "TDialogueDynamic/TDialogue.h"

const int N_TABLE_OPTIONS = 11;
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
        "[10]: Увеличить оборот всех ресурсов таблицы\n----------------------------------------------------\n"
    };

    // указатели на функции, соответствующие пунктам меню
    void (*table_menu_functions[N_TABLE_OPTIONS]) (TNS::Table &) = {
        nullptr, tableInputD, tablePrintD, tableAddResD, tableGetResD,
        tableDelResNameD, tableDelResIndexD, tableRenameResD, 
        tableChangeResD, tableGetProfitD, tableIncTurnoverD
    };
    void tableMenuD  (TNS::Table &t)      // [**, +] основной выбор, меню 
    {
        int user_choice = 1;
        while (user_choice != 0)
        {
            for (int i = 0; i < N_TABLE_OPTIONS; ++i)
                std::cout << menu_points[i];
            std::cout << PROMPT;
            int user_choice = Handler::getInt(std::cin, 0, N_TABLE_OPTIONS - 1);
            if (user_choice != 0)
                table_menu_functions[user_choice](t);
                
            else
                break;
        }
    }

    void tableInputD (TNS::Table &t)      // [01, +] ввод таблицы
    { 
        t.input(std::cin);
    }

    void tablePrintD (TNS::Table &t) noexcept // [02, +] печать таблицы
    {
        t.print(std::cout);
    }
    
    void tableAddResD(TNS::Table &t)      // [03, +] добавление нового элемента
    { 
        try {
            RNS::Resource r;
            std::cout << "Введите ресурс:\n";
            r.input(std::cin);
            t.add(r);
            std::cout << "[RESULT]: Элемент успешно добавлен!";

        } 
        catch (...)
        { 
            throw; 
        }
    }

    void tableGetResD(TNS::Table &t)      // [04, +] вывести ресурс по его наименованию
    { 
        try {
            std::cout << "Введите название ресурса для поиска:\n" << PROMPT;
            std::string name = Handler::getString(std::cin);
            std::cout << "[STREAM]: " << name << std::endl;
            const std::string& link = name;
            TNS::Table new_table = t.searchResult(link);
            std::cout << "[RESULT]:\n";
            new_table.print(std::cout);
        } 
        catch (...) 
        { 
            throw; 
        }
    }

    void tableDelResNameD (TNS::Table &t) // [05, +] удаление типа ресурса по имени
    { 
        try {
            std::cout << "Введите имя удаляемого типа ресурса:\n" << PROMPT;
            std::string name = Handler::getString(std::cin);
            t.deleteByName(name);
        } 
        catch (...) 
        { 
            throw; 
        }
    }

    void tableDelResIndexD(TNS::Table &t) // [06, +] удалить ресурс по его индексу
    { 
        try {
            std::cout << "Введите индекс удаляемого элемента\n" << PROMPT;
            int index = Handler::getInt(std::cin, 0, t.getCSize());
            t.deleteByIndex(index);
        } catch (...) { throw; }
    }
    void tableRenameResD  (TNS::Table &t) // [07, +/-] переименовать тип ресурса (запрашивает дополнительный ввод)
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
    void tableChangeResD  (TNS::Table &t) // [08, +] изменение ресурса по индексу через диалоговую функцию ресурса
    {
        try {
            std::cout << "Введите индекс изменяемого элемента\n" << PROMPT;
            int index = Handler::getInt(std::cin, 0, t.getCSize());
            RNS::Resource &link = t.getResByIndex(index);
            dialogR::menuD(link);
            t.prettify();
        } catch (...) { throw; }
    } 

    void tableGetProfitD  (TNS::Table &t) noexcept // [09, +] получение прибыльности всех ресурсов таблицы
    {
        double profit = t.getProfit();
        std::cout << "[PROFIT]: " << profit << " у.е.\n";
    }

    void tableIncTurnoverD(TNS::Table &t) // [10, +] увеличение оборота всех ресурсов таблицы
    {
        try {
            std::cout << "Введите коэф. умножения\n" << PROMPT;
            double coef = Handler::getDouble(std::cin, 0.0);
            t.incTurnover(coef);
        } 
        catch (...) 
        { 
            throw; 
        }
    }
}