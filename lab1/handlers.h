#ifndef HANDLERS_H
#define HANDLERS_H

#include <bits/stdc++.h>
#include <limits>

namespace Handler {
    template <class Rnd>
    Rnd GetNumber(Rnd min = std::numeric_limits<Rnd>::min(),
                Rnd max = std::numeric_limits<Rnd>::max()){
        Rnd number;
        while (true){
            std::cin >> number;
            if (std::cin.eof())
                throw std::runtime_error("[ERROR]: Обнаружен конец файла (EOF)\n");

            // невосстановимая ошибка
            else if (std::cin.bad()) 
                throw std::runtime_error(std::string("[FATAL ERROR]: Невосстановимая ошибка типа: ") + strerror(errno));
                
            // некритичная ошибка
            else if(std::cin.fail()) { // прочие ошибки (неправильный формат ввода)
                std::cin.clear(); // переводим состояние потока в goodbit
                    
                // игнорируем все символы до конца строки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[WARNING]: Вы сделали что-то неверно, повторите ввод!" << std::endl;
            }

            // корректное число в нужном диапазоне
            else if (number >= min && number <= max) // если число входит в заданный диапазон
                return number;
        }

    }
}

#endif